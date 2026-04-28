using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace practica4
{
    public partial class RelojAnalogico : Form
    {
        private Point m_Centro = new Point();
        private int m_Radio;
        private DateTime m_Hora;

        public RelojAnalogico()
        {
            InitializeComponent();
            m_Hora = DateTime.Now;
            ActualizarDimensiones();
        }
        public DateTime Hora
        {
            set
            {
                m_Hora = value;
                Invalidate();
            }
        }

        private void RelojAnalogico_Load(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Cross; // ---- MEJORA ---- cambiar el cursor

        }

        private void RelojAnalogico_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (this.Focused)
                e.Cancel = true;
        }



        private void RelojAnalogico_Resize(object sender, EventArgs e)
        {
            ActualizarDimensiones();
            Invalidate();
        }

        private void ActualizarDimensiones()
        {
            // Iniciar m_Hora con los datos actuales
            m_Centro.X = this.ClientSize.Width / 2;
            m_Centro.Y = this.ClientSize.Height / 2;
            m_Radio = Math.Min(m_Centro.X, m_Centro.Y);
        }

        private void RelojAnalogico_Paint(object sender, PaintEventArgs e) // Manejador para el evento Paint
        {
            if (m_Radio <= 10)
                return;

            Graphics gfx = e.Graphics;

            Pen lápizMuyGordoAzul = new Pen(Color.Blue, 4); // Manecilla de las horas 
            Pen lápizGordoRojo = new Pen(Color.Red, 2); // Manecilla de los minutos 
            Pen lápizNormal = new Pen(Color.Black, 1); // Manecilla de los segundos
            Pen lápizGordoNegro = new Pen(Color.Black, 2);

            HatchBrush brochaGris = new HatchBrush(HatchStyle.Sphere, Color.Gray, Color.Gray);

            float alfa, x, y;

            // Llevamos el origen de coordenadas al centro de la ventana y hacemos
            // que el eje Y aumente hacia arriba 
            Matrix matriz = new Matrix(1, 0, 0, -1, m_Centro.X, m_Centro.Y);

            gfx.Transform = matriz;

            // Esfera
            float radioEsfera = m_Radio * .95f;
            gfx.DrawEllipse(lápizNormal, -radioEsfera, -radioEsfera, radioEsfera * 2, radioEsfera * 2);

            // Marcas de los minutos
            
            for(int i=0; i<60; i++)
            {
                alfa = (float)(i * Math.PI * 2 / 60);
                x = (float)(Math.Sin(alfa) * m_Radio);
                y = (float)(Math.Cos(alfa) * m_Radio);

                if (i % 5 == 0)
                    gfx.DrawLine(lápizGordoNegro, x * .85f, y * .85f, x * .95f, y * .95f);
                else
                    gfx.DrawLine(lápizNormal, x * .9f, y * .9f, x * .95f, y * .95f);
            }


            // Manecilla de las horas
            alfa = (float)((m_Hora.Hour % 12) * Math.PI * 2 / 12);
            alfa += (float)((m_Hora.Minute) * Math.PI * 2 / 12 / 60);

            x = (float)(Math.Sin(alfa) * m_Radio);
            y = (float)(Math.Cos(alfa) * m_Radio);

            gfx.DrawLine(lápizMuyGordoAzul, 0, 0, x * .6f, y * .6f); // Manecilla AZUL

            //Manecilla de los minutos
            alfa = (float)((m_Hora.Minute % 60) * Math.PI * 2 / 60);

            x = (float)(Math.Sin(alfa) * m_Radio);
            y = (float)(Math.Cos(alfa) * m_Radio);

            gfx.DrawLine(lápizGordoNegro, 0, 0, x * .8f, y * .8f); // Manecilla NEGRA

            //Manecilla de los segundos
            alfa = (float)((m_Hora.Second % 60) * Math.PI * 2 / 60 );

            x = (float)(Math.Sin(alfa) * m_Radio);
            y = (float)(Math.Cos(alfa) * m_Radio);

            gfx.DrawLine(lápizGordoRojo, 0, 0, x * .92f, y * .92f); // Manecilla ROJA

            // Botón Central
            float radioBoton = m_Radio * .1f / 2;

            gfx.DrawEllipse(lápizGordoNegro, -radioBoton, -radioBoton, radioBoton * 2, radioBoton * 2);
            gfx.FillEllipse(brochaGris, -radioBoton, -radioBoton, radioBoton * 2, radioBoton * 2);
        }

        private void ArrastrarAgujas(object sender, MouseEventArgs e) // Práctica 2
        {
            bool pulsadoCentro = (e.X == m_Centro.X && e.Y == m_Centro.Y);
            bool botonDer = e.Button == MouseButtons.Right; // Botón derecho
            bool botonIzq = e.Button == MouseButtons.Left; // Botón izquierdo

            if (m_Radio < 10 || pulsadoCentro)
                return;

            double alfa;
            int horas, minutos, minutosAntes;

            alfa = Math.Atan2(m_Centro.X - e.X, e.Y - m_Centro.Y); // calcular la posición del ratón

            /*if (e.Button == MouseButtons.Right)
                horas += 12;
                */

            if (e.Button == MouseButtons.Left) // Control para el botón IZQUIERDO. Ajuste horas y minutos con Ctrl
            {
                minutosAntes = m_Hora.Minute; // lo obtenemos de la hora del reloj
                minutos = (int)((alfa / Math.PI / 2 * 12 + 6) * 60);
                horas = (minutos / 60) % 12;
                minutos %= 60;

                // Si se pulsa Ctrl o nó pag 94
                if (Control.ModifierKeys == Keys.Control) // Si se ha pulsado Ctrl
                    horas += 12;

                RelojDigital relojD = (RelojDigital)this.Owner;
                relojD.CambiarHora(horas, minutos, m_Hora.Second);
            }


            if (e.Button == MouseButtons.Right) // Control para el botón DERECHO. Ajuste minutos
            {
                minutosAntes = m_Hora.Minute;
                minutos = (int)(alfa / Math.PI / 2 * 60 + 30) % 60;
                horas = m_Hora.Hour;
                //minutos %= 60; 

                if (minutos > minutosAntes && minutos - minutosAntes > 30) // Si pasamos por las 12 hacia atrás -> Hora menos
                    horas--;

                else if (minutos < minutosAntes && minutosAntes - minutos > 30) // Si pasamos por las 12 hacia adelante -> Hora más
                    horas++;

                if (horas == -1)
                    horas = 23;
                else if (horas == 24)
                    horas = 0;

                RelojDigital relojD = (RelojDigital)this.Owner;
                relojD.CambiarHora(horas, minutos, m_Hora.Second);
            }


            //para la 2.10 //
            //Console.WriteLine(horas + ":" + minutos + ":" + m_Hora.Second);
            //RelojDigital relojD = (RelojDigital)this.Owner; 
            //relojD.CambiarHora(horas, minutos, m_Hora.Second); 
        }


        private void RelojAnalogico_MouseDown(object sender, MouseEventArgs e)
        {
            ArrastrarAgujas(sender, e);
        }

        private void RelojAnalogico_MouseMove(object sender, MouseEventArgs e)
        {
            ArrastrarAgujas(sender, e);
        }

    }
}
