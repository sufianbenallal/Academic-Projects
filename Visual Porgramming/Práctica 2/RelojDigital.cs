using practica2;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace practica2
{
    public partial class RelojDigital : Form
    {
        private TimeSpan m_DesfaseHorario = new TimeSpan(0);

        RelojAnalógico m_RelojAnalógico = new RelojAnalógico();

       

        public RelojDigital()
        {
            InitializeComponent();
            MostrarHoraActual();
            this.salirToolStripMenuItem.Click += new EventHandler(this.salirToolStripMenuItem_Click);
            m_RelojAnalógico.Show(this);//dialogo no modal
           

        }
        private void aCercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Acercade dlg = new Acercade(); // creamos un objeto de la clase AcercaDe 
            dlg.ShowDialog(); // Diálogo MODAL
        }
       

        private void  MostrarHoraActual()
        {
            DateTime hora = DateTime.Now + m_DesfaseHorario;
            ct_HoraActual.Text = hora.ToLongTimeString();
            m_RelojAnalógico.Hora = hora;
            m_RelojAnalógico.Owner = this; // Para que tengo referencia con su formulario principal
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void exit()
        {
            throw new NotImplementedException();
        }

        private void acercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Acercade dlg = new Acercade();
            dlg.ShowDialog(); //dialogo modal
        }

       

        private void RelojDigital_Shown_1(object sender, EventArgs e)
        {
            m_RelojAnalógico.Location = new Point(this.Location.X + this.Width + 10, this.Location.Y);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            MostrarHoraActual();
        }

        private void bt_Mostrar_Click(object sender, EventArgs e)
        {
            if (m_RelojAnalógico.Visible== true){ m_RelojAnalógico.Hide();
                this.bt_Mostrar.Text = "Mostrar analógico";
            }
            else{
                m_RelojAnalógico.Show();
                this.bt_Mostrar.Text = "Ocultar analógico";
            }
        }

        internal void CambiarHora(int horas, int minutos, int second)
        {
            
                DateTime actual = DateTime.Now;
                DateTime hora = new DateTime(actual.Year, actual.Month, actual.Day, horas, minutos, second);
                m_DesfaseHorario = hora - actual;
            MostrarHoraActual();

        }

        private void opcionesToolStripMenuItem_DropDownOpened(object sender, EventArgs e)
        {
            if (m_RelojAnalógico.Visible == true)
            {
                mostrarAnalógicoToolStripMenuItem.Checked = true; // check cuando Reloj Analógico está visible
            }
            else if (m_RelojAnalógico.Visible == false)
            {
                mostrarAnalógicoToolStripMenuItem.Checked = false; // quitamos el check cuando está oculto
            }
        }

        private void cambiarColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog colorDlg = new ColorDialog(); // Creamos el diálogo de color
            colorDlg.Color = ct_HoraActual.BackColor; // para que mantenga los valores iniciales
            if (colorDlg.ShowDialog() == DialogResult.OK) // comprobamos que se ha seleccionado color
            {
                ct_HoraActual.BackColor = colorDlg.Color; // Cambiamos el color de la caja de texto por el color seleccionado
            }
        }

        private void cambiarLetraToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fontDlg = new FontDialog(); // Creamos diálogo de fuente
            fontDlg.Font = ct_HoraActual.Font; // para que mantenga los valores iniciales
            if (fontDlg.ShowDialog() == DialogResult.OK)
            {
                ct_HoraActual.Font = fontDlg.Font; // Cambiamos la fuente de la caja de texto por la fuente seleccionada
            }
        }
    }
}
