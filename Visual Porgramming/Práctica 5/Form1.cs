using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO; //para usar clase 'File'
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practica5
{
    public partial class VisorImágenes : Form
    {
        public VisorImágenes()
        {
            InitializeComponent();

            //Elementos del menu que no tienen sentido al inicio (sin hijos)
            ArchivoCerrar.Enabled = false;
            VentanaCascada.Enabled = false;
            VentanaMosaicoHorizontal.Enabled = false;
            VentanaMosaicoVertical.Enabled = false;

            this.VerHerramientas.Checked = true;
            this.VerEstado.Checked = true;
        }

        private void menuAyudaAcercaDe_Click(object sender, EventArgs e)
        {
            AboutBox1 boxAyuda = new AboutBox1();
            boxAyuda.ShowDialog();
        }

        private void VentanaCascada_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.Cascade); //El método LayoutMdi permite organizar los formularios hijos en un formulario padre.
        }

        private void VentanaMosaicoHorizontal_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void VentanaMosaicoVertical_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileVertical);
        }

        private void ArchivoSalir_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void ArchivoNuevo_Click(object sender, EventArgs e)
        {
            int númeroHijas = this.MdiChildren.Length; // numero de ventanas abiertas
            string título = "Doc" + (númeroHijas + 1);
            NuevaHija(título); // crea una nueva ventana con el titulo creado
        }

        private void NuevaHija(string título)
        {
            VentanaHija hija = new VentanaHija(título); // nuevo objeto de la clase 'VentanaHija'
            hija.MdiParent = this; //Establecer el formulario padre del nuevo hijo
            hija.PictureBox.SizeMode = PictureBoxSizeMode.AutoSize; //AutoSize: El tamaño del PictureBox debe ajustarse al tamaño de la imagen que contiene.
            hija.AutoScroll = true;
            hija.Show(); //Mostrar la nueva ventana hija
            this.HijaActiva.PictureBox.Image = Properties.Resources.Imagen1; // Carga la imagen en la ventana hija que está activa
        }
        public VentanaHija HijaActiva // Propiedad
        {
            get { return (VentanaHija)this.ActiveMdiChild; } //ActiveMdiChild: propiedad que devuelve referencia a la ventana hija MDI activa.
        }

        private void ArchivoCerrar_Click(object sender, EventArgs e)
        {
            this.HijaActiva.Close(); //cerramos la ventana hija que este activa.
        }

        private void ArchivoAbrir_Click(object sender, EventArgs e)
        {
            //Mostrar diálogo OpenFileDialog     
            OpenFileDialog dlg = new OpenFileDialog();
            //Mediante la propiedad Filter indicamos el tipo de archivos que se pueden abrir 
            //y mediante Title especificamos el título especifico para la ventana 
            dlg.Filter = "Archivos bmp (*.bmp)|*.bmp|Archivos jpg (*.jpg)|*.jpg|Archivos png (*.png)|*.png|Archivos gif (*.gif)|*.gif";
            dlg.FilterIndex = 2;
            dlg.Title = "Abrir imagen";

            //Si el resultado del diálogo es distinto de OK, terminar
            if (dlg.ShowDialog() != DialogResult.OK)
            {
                Close();
            }
            string rutaArchivo = dlg.FileName; // obtengo el nombre del fichero
            AbrirArchivo(rutaArchivo);

        }

        private void AbrirArchivo(string rutaArchivo)
        {
            // Creamos un flujo de tipo MemoryStream pasándole el contenido del archivo.
            byte[] contenidoArchivo = File.ReadAllBytes(rutaArchivo); // cargo en contenido del archivo 
            // Usamos el método FromStream de la clase Image para crear una "imagen" a partir del flujo anterior.
            Image imagen = Image.FromStream(new MemoryStream(contenidoArchivo));
            // Creamos una nueva ventana hija con el método NuevaHija,
            // pasándole como título el nombre del archivo abierto (dlg.FileName)
            NuevaHija(rutaArchivo);
            // Obtenemos una referencia a la nueva ventana mediante la propiedad HijaActiva.
            VentanaHija ventana = this.HijaActiva;
            // Asignamos "imagen" al picture box de la nueva ventana
            ventana.PictureBox.Image = imagen;
        }

        private void VisorImágenes_MdiChildActivate(object sender, EventArgs e) //evento: cada vez que se cambia de ventana hija activa
        {
            ActualizaMenús();

            //Llamar al metodo Merge para la barra de herramientas
            ToolStripManager.RevertMerge(this.barraVisor);// si lo deactivamos duplica la barra de herramientas
            VentanaHija VentanaHijaActiva = this.ActiveMdiChild as VentanaHija;
            if (VentanaHijaActiva != null)
            { //Icluye la barra de herramientas hija en la barra principal
                ToolStripManager.Merge(VentanaHijaActiva.barraHija, this.barraVisor);
                //RevertMerge deshace cualquier fusion y Merge realiza la fusion de la bara de herrameintas
            }
        }

        private void ActualizaMenús() //Metodo refactorizado para actualizar el menu
        {
            ArchivoCerrar.Enabled = this.HijaActiva != null;
            VentanaCascada.Enabled = this.HijaActiva != null;
            VentanaMosaicoHorizontal.Enabled = this.HijaActiva != null;
            VentanaMosaicoVertical.Enabled = this.HijaActiva != null;
        }

        private void VisorImágenes_DragEnter(object sender, DragEventArgs e)
        {
            // Nos aseguramos de que lo que se está arrastrando son archivos
            if (!e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.None;
                return;
            }
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            foreach (string file in files)
            {
                if (!file.ToUpper().EndsWith(".JPG") &&
                   !file.ToUpper().EndsWith(".BMP") &&
                   !file.ToUpper().EndsWith(".PNG") &&
                   !file.ToUpper().EndsWith(".GIF"))
                {
                    e.Effect = DragDropEffects.None; //Alguno de los archivos no es una imagen.
                    return;
                }
            }
            e.Effect = DragDropEffects.Copy; //Correcto, son todo imágenes.
        }

        private void VisorImágenes_DragDrop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            foreach (string file in files)
                AbrirArchivo(file);
        }

        private void ArchivoNuevo_MouseEnter(object sender, EventArgs e)
        {
            etiquetaEstado.Text = "Crea una nueva ventana con una imagen predefinida";
        }

        private void ArchivoNuevo_MouseLeave(object sender, EventArgs e)
        {
            etiquetaEstado.Text = "Selecciona";
        }

        //PREGUNTA EXAMEN
        private void VerHerramientas_Click(object sender, EventArgs e)
        {
            if (this.barraVisor.Visible == true)// si está visible la barra
                this.barraVisor.Visible = false; // la escondemos
            else
                this.barraVisor.Visible = true;

            this.VerHerramientas.Checked = this.barraVisor.Visible;
        }

        private void VerEstado_Click(object sender, EventArgs e)
        {
            if (this.etiquetaEstado.Visible == true)// si está visible la barra
                this.etiquetaEstado.Visible = false; // la escondemos
            else
                this.etiquetaEstado.Visible = true;

            this.VerEstado.Checked = this.etiquetaEstado.Visible;
        }
    }
}

/*private void verBarraHerramientasMenu_DropDownOpened(object sender, EventArgs e)
{
    this.VerBarraHerramientas.Checked = this.barraVisor.Visible;
    this.VerBarraEstado.Checked = this.etiquetaEstado.Visible;
}

private void VerHerramientas_Click(object sender, EventArgs e)
        {
            if (this.barraVisor.Visible == true)// si está visible la barra
                this.barraVisor.Visible = false; // la escondemos
            else
                this.barraVisor.Visible = true;

        }

        private void VerEstado_Click(object sender, EventArgs e)
        {
            if (this.etiquetaEstado.Visible == true)// si está visible la barra
                this.etiquetaEstado.Visible = false; // la escondemos
            else
                this.etiquetaEstado.Visible = true;

        }
*/