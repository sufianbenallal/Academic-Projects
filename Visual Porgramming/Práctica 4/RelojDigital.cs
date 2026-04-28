using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;


namespace practica4
{
    public partial class RelojDigital : Form
    {
        private TimeSpan m_DesfaseHorario = new TimeSpan(0); // Desfase horario
        private bool m_DespertadorActivado = false; // 7 Menús emergentes y dinámicos
        RelojAnalogico m_RelojAnalogico = new RelojAnalogico();
        //const int MaxZonas = 4; // 7.2
        private List<ZonaHoraria> m_Zonas = new List<ZonaHoraria>(); // 8.1.4


        public RelojDigital()
        {
            InitializeComponent();

            // Cambiamos la fuente de la hora del reloj digital
            //ct_HoraActual.Font = new Font("Times New Roman", 16, FontStyle.Regular); // En puntos
            ct_HoraActual.Font = new Font("Arial", 16, FontStyle.Bold, GraphicsUnit.Pixel); // En píxeles

            // Añadimos color
            ct_HoraActual.BackColor = Color.White; // fondo de color blanco
            ct_HoraActual.ForeColor = Color.Blue; // fuente de color azul
            toolTip1.SetToolTip(menu, Properties.Resources.mensajeBarraMenus);
            MostrarHoraActual();
            m_RelojAnalogico.Show(this); // diálogo NO MODAL

            opcionesDespertadorActivar.Enabled = true; // menu contextual
            opcionesDespertadorDesactivar.Enabled = false; // menu contextual
            opcionesDespertador.Checked = false;

        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)   
        {
            Close();
        }

        private void aCercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Acercade dlg = new Acercade(); // creamos un objeto de la clase AcercaDe 
            dlg.ShowDialog(); // Diálogo MODAL
        }

        private void RelojDigital_Load(object sender, EventArgs e) // 8.2.2
        {
            try
            {
                using (Stream stream = File.Open("Reloj.dat", FileMode.Open)) // Prueba evaluación
                //using (Stream stream = File.OpenRead("Reloj.dat")) // /bin/debug/Reloj.dat  -> Ruta al archivo
                {
                    BinaryFormatter bin = new BinaryFormatter();
                    m_Zonas = (List<ZonaHoraria>) bin.Deserialize(stream); // Tenemos que forzar la conversión
                    foreach (ZonaHoraria nuevaZona in m_Zonas) // 8.2.3
                        AñadirOrdenZona(nuevaZona);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("No se pudo abrir el archivo zonas. " + "Causa: " + ex.Message);
            }
        }

        private void MostrarHoraActual() // Método para mostrar la hora actual
        {
            // Para obtener la hora y mostrarla
            //DateTime hora = DateTime.Now;
            DateTime hora = DateTime.Now + m_DesfaseHorario;
            ct_HoraActual.Text = hora.ToLongTimeString();
            m_RelojAnalogico.Hora = hora;
            m_RelojAnalogico.Owner = this; // Para que tengo referencia con su formulario principal
            
        }
        
        private void RelojDigital_Shown(object sender, EventArgs e)  // manejador para el evento Shown
        {
            m_RelojAnalogico.Location = new Point(this.Location.X + this.Width + 10, this.Location.Y); // tambien se puede usar en el evento Load
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            MostrarHoraActual();

            //Practica 3
            if (!ct_Alarma.HoraValida)
            {
                System.Diagnostics.Debug.WriteLine("Hora alarma no válida");
                return;
            }
            if (m_DespertadorActivado)
            {
                DateTime horaActual = DateTime.Now + m_DesfaseHorario;
                DateTime horaAlarma = ct_Alarma.Hora;

                //Segundos hora actual
                int segundosActual = horaActual.Second + horaActual.Minute * 60 + horaActual.Hour * 3600;

                //Segundos alarma
                int segundosAlarma = horaAlarma.Second + horaAlarma.Minute * 60 + horaAlarma.Hour * 3600;

                if (segundosActual >= segundosAlarma)
                {
                    if (segundosActual - segundosAlarma < 300)
                        System.Media.SystemSounds.Beep.Play();
                }
                else if (segundosAlarma - segundosActual > 86400 - 300)
                    System.Media.SystemSounds.Beep.Play();
            }

        }
        private void bt_Mostrar_Click(object sender, EventArgs e)
        {

            if (m_RelojAnalogico.Visible == true)
            {
                m_RelojAnalogico.Hide();
                //this.bt_Mostrar.Text = "Mostrar analógico";
            }
            else
            {
                m_RelojAnalogico.Show();
                //this.bt_Mostrar.Text = "Ocultar analógico";
            }
        }

        internal void CambiarHora(int horas, int minutos, int segundos)
        {
            DateTime actual = DateTime.Now;
            DateTime hora = new DateTime(actual.Year, actual.Month,
                                            actual.Day, horas, minutos, segundos);

            m_DesfaseHorario = hora - actual;

            MostrarHoraActual();
        }

        private void ct_HoraActual_TextChanged(object sender, EventArgs e)
        {

        }

        private void colorFondo_Click(object sender, EventArgs e)
        {
            ColorDialog colorDlg = new ColorDialog(); // Creamos el diálogo de color
            colorDlg.Color = ct_HoraActual.BackColor; // para que mantenga los valores iniciales
            if(colorDlg.ShowDialog() == DialogResult.OK) // comprobamos que se ha seleccionado color
            {
                ct_HoraActual.BackColor = colorDlg.Color; // Cambiamos el color de la caja de texto por el color seleccionado
            }
        }

        private void fuente_Click(object sender, EventArgs e)
        {
            FontDialog fontDlg = new FontDialog(); // Creamos diálogo de fuente
            fontDlg.ShowColor = true;
            fontDlg.Font = ct_HoraActual.Font; // para que mantenga los valores iniciales
            fontDlg.Color = ct_HoraActual.ForeColor;

            if (fontDlg.ShowDialog() == DialogResult.OK)
            {
                ct_HoraActual.Font = fontDlg.Font; // Cambiamos la fuente de la caja de texto por la fuente seleccionada
                ct_HoraActual.ForeColor = fontDlg.Color;
            }
        }

        private void opcionesToolStripMenuItem_DropDownOpened(object sender, EventArgs e)
        {
            //if (m_RelojAnalogico.Visible == true)
            //{
            //    opcionesMostrarAnalogico.Checked = true; // check cuando Reloj Analógico está visible
            //}
            //else if(m_RelojAnalogico.Visible == false)
            //{
            //    opcionesMostrarAnalogico.Checked = false; // quitamos el check cuando está oculto
            //}
            opcionesMostrarOcultarAnalogico.Checked = m_RelojAnalogico.Visible;
            //opcionesMostrarOcultarAnalogico.CheckOnClick = true; // Pregunta

        }

        private void bt_ZonaHoraria_Click(object sender, EventArgs e) // 6
        {
            DlgDatosZona dlg = new DlgDatosZona();
            if(dlg.ShowDialog() == DialogResult.OK)
            {
                string desfase = dlg.Diferencia.ToString();
                string signo = dlg.Positivo ? "Positivo:" : "Negativo:";
                // Visualizar la caja de diálogo que muestre los datos recogidos por el diálogo
                string cuerpo = "Nombre: " + dlg.Nombre + 
                                "\nDesfase: " + dlg.Diferencia + 
                                "\nSigno: " + dlg.Positivo; // cosntruyo el mensaje

                MessageBox.Show(cuerpo,
                                "Datos de la zona",
                                MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public bool DespertadorActivado // 7
        {
            get { return m_DespertadorActivado; }
            set
            { // Cambiamoss el valor del menu Opciones->Despertador->Activar/Desactivar
                m_DespertadorActivado = value;
                //DespertadorActivar.Text = m_DespertadorActivado ? "Desactivar" : "Activar"; // Cambio el texto
                opcionesDespertador.Checked = m_DespertadorActivado; // Activo el Check

                //Para menu conetextual
                opcionesDespertadorActivar.Enabled = !m_DespertadorActivado;
                opcionesDespertadorDesactivar.Enabled = m_DespertadorActivado;

                cv_Despertador.Checked = m_DespertadorActivado; // 8.1.1 
            }
        }

        private void opcionesDespertadorActivar_Click(object sender, EventArgs e) // 7
        {
            this.DespertadorActivado = !(this.DespertadorActivado); 
        }

        private void opcionesDespertadorDesactivar_Click(object sender, EventArgs e) // 7
        {
            this.DespertadorActivado = !(this.DespertadorActivado);
        }

        public int NumeroZonas // 7.2 , se queda igual para 7.4
        {
            get { return m_Zonas.Count; } // 8.1.4 , devuelve en número de zonas
        }

        public List<ZonaHoraria> Zonas  // 8.1.4 , Devuelve la colección de zonas
        {
            get { return m_Zonas; }
            set { m_Zonas = value; }
        }

        private void menuZona_DropDownOpened(object sender, EventArgs e) // 7.2 , manejador del evento 7.4, para el menu contextual 
                                                                         //se asocia con la propiedad Opened
        {
            //if(NumeroZonas == MaxZonas) // Alcanza el máximo de zonas
            //{
            //    añadir.Visible = false;
            //}
            //else if(NumeroZonas > 0)
            //{
            //    eliminar.Visible = true;
            //    añadir.Visible = true;
            //    separador.Visible = true;
            //}
            //else if(NumeroZonas == 0)
            //{
            //    añadir.Visible = true;
            //    eliminar.Visible = false;
            //    separador.Visible = false;
            //}
        }

        private void zonaAñadir_Click(object sender, EventArgs e) // 8.1.4 manejador del evento Click
        {
            // DlgDatosZona
            ToolStripMenuItem zonaNueva = new ToolStripMenuItem(); // Nuevo submenú que hay que añadir
            DlgDatosZona dlgZona = new DlgDatosZona(); // nuevo diálogo DlgDatosZona

            // PREDICADOS
            if (dlgZona.ShowDialog() == DialogResult.OK) // Si se han introducido correctamente los datos
            {
                // Con predicados
                bool existe = m_Zonas.Exists( // comprobamos si existe la nueva zona horaria a añadir
                                delegate (ZonaHoraria zona)
                                {
                                    return zona.Nombre == dlgZona.Nombre;
                                }
                                );
                if(existe)
                {
                    string mensaje = "La zona <" + dlgZona.Nombre + "> ya existe!!!";
                    MessageBox.Show(mensaje, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return; // Salimos
                }

               
                menuContextoZona.Items.Add(zonaNueva); // Añadimos la nueva zona al menú contextual
                zonaNueva.Click += new EventHandler(zona_Click); // Añadimos el delegado para el evento Click
                //Añadimos los datos del formulario dlgZona (DlgDatosZona) a zonaHorariaNueva (ZonaHoraria) 
                zonaNueva.Text = dlgZona.Nombre;

                // Pregunta p4
                ZonaHoraria zonaHorariaNueva = new ZonaHoraria(); // Objeto ZonaHoraria para los datos de las nueva zona
                zonaHorariaNueva.Diferencia = dlgZona.Diferencia;
                zonaHorariaNueva.Positivo = dlgZona.Positivo;
                zonaHorariaNueva.Nombre = dlgZona.Nombre;
                m_Zonas.Add(zonaHorariaNueva); // Añadimos la nueva zona horaria a la lista de zonas horarias

                

                // NuevaZona
                //zonaNueva.Text = "Zona " + (this.NumeroZonas + 1);
                //this.menuZona.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] { // Añadir una nueva zona 7.2
                //zonaNueva});
                //zonaNueva.Click += new EventHandler(this.zona_Click); // 7.2 Añadir delegado para el evento

               // this.m_Zonas.AddRange
            }
        }

        private void AñadirOrdenZona(ZonaHoraria nuevaZona) // Refactorización 8.2.3
        {
            ToolStripMenuItem nuevaZonaMenu = new ToolStripMenuItem();

            menuContextoZona.Items.Add(nuevaZonaMenu);

            nuevaZonaMenu.Text = nuevaZona.Nombre;

            nuevaZonaMenu.Click += new EventHandler(zona_Click);
        }

        private void zonaEliminar_Click(object sender, EventArgs e) // 7.2 Eliminar zona
        {
            if (this.NumeroZonas == 0) // 7.3
            {
                Console.Beep();
                return;
            }

            //int iLista = NumeroZonas - 1;
            //m_Zonas.RemoveAt(iLista); // Elimino el último elemento de la lista

            // 8.1.4
            DlgEliminarZona dlgElim = new DlgEliminarZona();
            //dlgElim.Owner = this; // Para establecer la propiedad Owner
            //dlgElim.ShowDialog();
            if(dlgElim.ShowDialog(this) == DialogResult.OK) // pag 181
            {
                m_Zonas.RemoveAt(dlgElim.ZonaSeleccionada); // Elimina el elemnto de la lista de zonas horoarias que 
                                                            //se ha seleccionado mediante el diálogo dlgEliminar
                this.menuContextoZona.Items.RemoveAt(dlgElim.ZonaSeleccionada + 3); // Sumo 3 para que no me elimine los elementos del menú
                                                    // utilizo el índice de la lista dinámina + 3 para borrar los elementos del menú

                menuContextoZona.Click -= new EventHandler(zona_Click); // Elimino el delegado para el evento Click en las zonas
            }
        }

        private void zona_Click(object sender, EventArgs e) // Método zonaClick 7.2, 8.1.4
        {
            /*Practica3
             * 
            ToolStripMenuItem elemento = (ToolStripMenuItem)sender;
            MessageBox.Show(elemento.Text); */

            //Practica 4
            ToolStripMenuItem elemento = (ToolStripMenuItem)sender;
            ZonaHoraria existe = m_Zonas.Find( // comprobamos si existe la nueva zona horaria a añadir
                                delegate (ZonaHoraria zona)
                                {
                                    return zona.Nombre == elemento.Text;
                                }
                                );

            string desfaseHorario;

            if (existe.Positivo)
                desfaseHorario = DateTime.Now.Add(existe.Diferencia).ToString("HH:mm:ss"); // Suma la diferencia
            else
                desfaseHorario = DateTime.Now.Subtract(existe.Diferencia).ToString("HH:mm:ss"); // Resta la diferencia

            string mensaje = "Hora en " + existe.Nombre + ": " + desfaseHorario; // cosntruyo el mensaje. sender tiene la información del objeto
            MessageBox.Show(mensaje, "", MessageBoxButtons.OK);
        }

        private void cv_Despertador_Click(object sender, EventArgs e)
        {
                m_DespertadorActivado = cv_Despertador.Checked;
                this.DespertadorActivado = m_DespertadorActivado;
                //DespertadorActivado = !DespertadorActivado;// Pregunta
        }

        private void bt_provisional_Click(object sender, EventArgs e)
        {

        }

        private void RelojDigital_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                using (Stream stream = File.Open("reloj.dat", FileMode.Create))
                {
                    BinaryFormatter bin = new BinaryFormatter();
                    bin.Serialize(stream, m_Zonas);
                }

            }
            catch (Exception ex)
            { Console.WriteLine("No se pudo crear el archivo de Zonas. " + " Causa: " + ex.Message); }
        }

        private void menuContextoAlarma_Opening(object sender, CancelEventArgs e)
        {

        }

        private void toolTip1_Popup(object sender, PopupEventArgs e)
        {

        }
    }
}
