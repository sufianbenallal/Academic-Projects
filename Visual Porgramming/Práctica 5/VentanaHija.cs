using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging; //para usar ColorMatrix e ImageAttributes
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practica5
{
    public partial class VentanaHija : Form
    {
        public VentanaHija(string título)
        {
            InitializeComponent();
            this.Text = título; //modificar titulo ventana
        }
        public PictureBox PictureBox
        {
            get { return m_PictureBox; }
        }

        private void ImagenAjustar_Click(object sender, EventArgs e)
        {
            // Si no estamos en modo ajustar activamos este modo
            if (this.PictureBox.SizeMode == PictureBoxSizeMode.AutoSize)
            {
                this.AutoScroll = false;
                this.PictureBox.Size = this.ClientSize;
                this.PictureBox.SizeMode = PictureBoxSizeMode.Zoom; // ajusta la imagen sin deformarla
                //this.PictureBox.SizeMode = PictureBoxSizeMode.StretchImage; //Lo ajusta a todo los bordes, se deforma
            }
            //Si estamos en modo ajustar, desactivamos este modo
            else if (this.PictureBox.SizeMode == PictureBoxSizeMode.Zoom)
            {
                this.AutoScroll = true;
                this.PictureBox.SizeMode = PictureBoxSizeMode.AutoSize;
            }

            ImagenAjustar.Checked = this.PictureBox.SizeMode == PictureBoxSizeMode.Zoom;
        }

        private void VentanaHija_Resize(object sender, EventArgs e)
        {
            if (this.PictureBox.SizeMode == PictureBoxSizeMode.Zoom)
                this.PictureBox.Size = this.ClientSize;
        }

        private void ImagenRotar_Click(object sender, EventArgs e)
        {
            this.PictureBox.Image.RotateFlip(RotateFlipType.Rotate90FlipNone);
            this.PictureBox.Refresh();
        }

        private void ImagenAñadirTexto_Click(object sender, EventArgs e)
        {
            using (Graphics gfx = Graphics.FromImage(this.PictureBox.Image))
            {
                //Método DrawString de gfx para pintar el texto
                //SolidBrush brocha = new SolidBrush(Color.White);
                //"Progrmacion visual" en la posicion (0,0) del area de cliente
                //Font fuente = new Font("Arial", 20);
                //utilizando una fuente Arial de 20 puntos y brocha color deseado
                gfx.DrawString("Programación Visual", new Font("Arial", 20), new SolidBrush(Color.White), 0, 0);
            }
            //Refrescar el picture box
            this.PictureBox.Refresh();
            // Funcion using: libera los recursos no administrados de gfx
            // meotod que se invoca: Se invoca al metodo Dispose de Graphics
        }

        private void ImagenEscalaDeGrises_Click(object sender, EventArgs e)
        {
            PictureBox pictureBox = this.PictureBox;
            Image imagen = pictureBox.Image;

            using (Graphics gfx = Graphics.FromImage(imagen))
            {   //Matriz para realizar una transformación al gris
                //manteniendo los valores de la luminancia correctos
                ColorMatrix cm = new ColorMatrix(new float[][]
                {
                    new float [] {0.3f,0.3f,0.3f,0,0},
                    new float [] {0.59f,0.59f,0.59f,0,0},
                    new float [] {0.11f,0.11f,0.11f,0,0},
                    new float [] {0,0,0,1,0},
                    new float [] {0,0,0,0,1} });
                //Información acerca de la manipulación de los colores del mapa de bits.
                ImageAttributes atrImg = new ImageAttributes();
                atrImg.SetColorMatrix(cm);
                //Dibujar imagen
                gfx.DrawImage(imagen, new Rectangle(0, 0, imagen.Width, imagen.Height), 0, 0, imagen.Width, imagen.Height, GraphicsUnit.Pixel, atrImg);
            }
            //Refrescar PictureBox
            PictureBox.Refresh();
        }

        private void ArchivoGuardarComo_Click(object sender, EventArgs e)
        {
            GuardarComo();
        }

        private void GuardarComo()
        {
            // Mostrar el diálogo SaveFileDialog y configurarlo de forma análoga al OpenFileDialog de la opción "Abrir"
            SaveFileDialog dlgGuardar = new SaveFileDialog(); // nuevo objeto OpenFileDialog
            dlgGuardar.Filter = "Archivos bmp (*.bmp)|*.bmp|Archivos jpg (*.jpg)|*.jpg|Archivos png (*.png)|*.png|" +
                "Archivos gif (*.gif)|*.gif|Archivos tiff(*.tiff)| *.tiff";
            dlgGuardar.FilterIndex = 2;
            dlgGuardar.Title = "Guardar como...";
            //Si el resultado es distinto a OK, terminar
            if (dlgGuardar.ShowDialog() != DialogResult.OK)
            {
                Close();
            }

            ImageFormat formato;

            if (dlgGuardar.FileName.ToUpper().EndsWith(".JPG"))
            {
                // Usar el método Save para guardar la imagen en formato jpg
                formato = ImageFormat.Jpeg;
                this.PictureBox.Image.Save(dlgGuardar.FileName, formato);
            }
            //Análogamente con el resto de formatos permitidos.
            else if (dlgGuardar.FileName.ToUpper().EndsWith(".BMP"))
            {
                formato = ImageFormat.Bmp;
                this.PictureBox.Image.Save(dlgGuardar.FileName, formato);
            }
            else if (dlgGuardar.FileName.ToUpper().EndsWith(".PNG"))
            {
                formato = ImageFormat.Png;
                this.PictureBox.Image.Save(dlgGuardar.FileName, formato);
            }
            else if (dlgGuardar.FileName.ToUpper().EndsWith(".GIF"))
            {
                formato = ImageFormat.Gif;
                this.PictureBox.Image.Save(dlgGuardar.FileName, formato);
            }
            else if (dlgGuardar.FileName.ToUpper().EndsWith(".TIFF"))
            {
                formato = ImageFormat.Tiff;
                this.PictureBox.Image.Save(dlgGuardar.FileName, formato);
            }
            // actualizar el titulo de la ventana
            this.Text = dlgGuardar.FileName;
        }

        private void ArchivoGuardar_Click(object sender, EventArgs e)
        {
            VentanaHija ventana = (VentanaHija)this;

            if (ventana.Text.StartsWith("Doc")) // si el título de la ventana hija activa comienza con "Doc"
            {
                GuardarComo();// invoco al método 'GuardarComo'
            }
            else // La guardamos en el mismo archivo de donde la leímos.
            {
                string ruta = ventana.Text; // ruta de la ventana donde hemos leido la imagen
                ventana.PictureBox.Image.Save(ruta); // la guardamos en el mismo sitio donde la hemos leido
            }
        }
    }
}
