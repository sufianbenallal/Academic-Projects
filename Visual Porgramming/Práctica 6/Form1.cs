using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Practica6
{
    public partial class Principal : Form
    {

        private List<int> m_Valores = new List<int>(); // Lista de valores
        private int m_Indice = 0; // Indice

        private Thread m_HiloA;
        ManualResetEvent m_PararHiloA = new ManualResetEvent(false); //Señal activada por el hilo principal para notificar al secundario 
                                                                     //de que se debe detener, ya que la aplicación se está cerrando.
        ManualResetEvent m_ParadoHiloA = new ManualResetEvent(false); //Señal para que el hilo secundario avise al principal cuando se haya detenido.

        private Thread m_HiloB;
        private ManualResetEvent m_PararHiloB = new ManualResetEvent(false);
        private ManualResetEvent m_ParadoHiloB = new ManualResetEvent(false);

        public Principal()
        {
            InitializeComponent();
        }

        private void ct_Velocidad_ValueChanged(object sender, EventArgs e) //Actualizar limite barra progreso al modificar valor velocidad
        {
            bp_Progreso.Maximum = (int)ct_Velocidad.Value;
        }

        private void bt_Iniciar_Click(object sender, EventArgs e)
        {
            bt_Iniciar.Enabled = false; //inhabilito el boton iniciar
            ct_Velocidad.Enabled = false;
            m_Indice = 0;
            m_Valores.Clear();
            bp_Progreso.Value = 0;
            m_HiloA = new Thread(ActualizarA); // Forma abreviada de: m_HiloA = new Thread(new ThreadStart(ActualizarA));
            m_HiloB = new Thread(ActualizarB);
            m_HiloA.Start();
            m_HiloB.Start();

            ArchivoDetener.Enabled = true;
        }
        private void Progresar()
        {
            // Añadir elemento en la lista m_Valores.
            m_Valores.Add(m_Indice);
            // Actualizar barra de progreso.
            //bp_Progreso.PerformStep(); //Ahora ponemos:
            ActualizarBarraProgreso();
            // Incrementar m_Índice.
            m_Indice++;
        }

        private void ActualizarA() //mientras el índice sea menor o igual que el valor máximo de la barra de progreso.
        {
            while (m_Indice <= bp_Progreso.Maximum)
            {
                if (m_PararHiloA.WaitOne(0)) //si se ha activado la señal 'm_PararHiloA'
                {
                    m_ParadoHiloA.Set(); // señaliza que ya se ha parado
                    break;
                }

                lock (m_Valores) //sincronizacion de hilos
                {
                    Progresar(); //seccion crítica
                }
            }

            ActualizarCtVelocidad();
            ActualizarBotonIniciar();
        }
        private void ActualizarB()
        {
            while (m_Indice <= bp_Progreso.Maximum)
            {
                if (m_PararHiloB.WaitOne(0)) //si se ha activado la señal 'm_PararHiloB'
                {
                    m_ParadoHiloB.Set(); // señaliza que ya se ha parado
                    break;
                }

                lock (m_Valores) //sincronizacion de hilos
                {
                    Progresar(); //seccion crítica
                }
            }

            ActualizarCtVelocidad();
            ActualizarBotonIniciar();
        }
        private void ActualizarBarraProgreso()
        {
            if (bp_Progreso.InvokeRequired) //si el hilo no es el proceso principal, necesitamos delegado para modificar 'bp_Progreso'
            {
                MethodInvoker delegado = new MethodInvoker(ActualizarBarraProgreso); // delegado contiene referencia al metodo 'ActualizarBarraProgreso()'
                bp_Progreso.Invoke(delegado); //El delegado llama a 'ActualizarBarraProgreso' desde el hilo principal.
                //Invoke (síncrono): un hilo detiene su ejecucion para permitir que otro se ejecute
            }
            else //Estamos en el hilo principal (desde un delegado)
            {
                bp_Progreso.PerformStep();
            }
        }
        private void ActualizarCtVelocidad()
        {
            if (ct_Velocidad.InvokeRequired) //si el hilo no es el proceso principal, necesitamos delegado para modificar 'ct_Velocidad'
            {
                MethodInvoker delegado = new MethodInvoker(ActualizarCtVelocidad); // delegado contiene referencia al metodo 'ActualizarCtVelocidad()'
                ct_Velocidad.Invoke(delegado); //El delegado llama a 'ActualizarCtVelocidad' desde el hilo principal.
            }
            else //Estamos en el hilo principal (desde un delegado)
            {
                //ct_Velocidad.Value = m_Valores[m_Indice]; //incrementar el valor de la propiedad step
                ct_Velocidad.Enabled = true; //habilitar caja 'Velocidad'
            }
        }
        private void ActualizarBotonIniciar()
        {
            if (bt_Iniciar.InvokeRequired) //si el hilo no es el proceso principal, necesitamos delegado para modificar 'bt_Iniciar'
            {
                MethodInvoker delegado = new MethodInvoker(ActualizarBotonIniciar); // delegado contiene referencia al metodo 'ActualizarBotonIniciar()'
                bt_Iniciar.Invoke(delegado); //El delegado llama a 'ActualizarBotonIniciar' desde el hilo principal.
            }
            else //Estamos en el hilo principal (desde un delegado)
            {
                bt_Iniciar.Enabled = true; //habilitar boton 'Iniciar'
            }
        }
        private void PararHiloA() //le dice al hilo secundario que se detenga y espera a que dicha detención se haga efectiva.
        {
            if (m_HiloA != null && m_HiloA.IsAlive) //si exixte 'HiloA' y está activo:
            {
                // Activamos el evento para decirle al hilo que pare
                m_PararHiloA.Set(); //pasar 'm_PararHiloA' a true
                // Esperar a que el hilo haya terminado
                while (m_HiloA.IsAlive) //mientras 'HiloA' este activo:
                {
                    m_ParadoHiloA.WaitOne(200, false); // evitar una espera activa, bloqueado hasta que 'm_ParadoHiloA' valga true o se acabe el timepo
                    Application.DoEvents(); // procesar eventos pendientes
                }
            }
        }
        private void PararHiloB() //le dice al hilo secundario que se detenga y espera a que dicha detención se haga efectiva.
        {
            if (m_HiloB != null && m_HiloB.IsAlive) //si exixte 'HiloB' y está activo:
            {
                // Activamos el evento para decirle al hilo que pare
                m_PararHiloB.Set(); //pasar 'm_PararHiloB' a true
                // Esperar a que el hilo haya terminado
                while (m_HiloB.IsAlive) //mientras 'HiloB' este activo:
                {
                    m_ParadoHiloB.WaitOne(200, false); // evitar una espera activa, bloqueado hasta que 'm_ParadoHiloB' valga true o se acabe el timepo
                    Application.DoEvents(); // procesar eventos pendientes
                }
            }
        }
        private void Principal_FormClosed(object sender, FormClosedEventArgs e) //Cuadno cierro el formulario
        {
            PararHiloA();
            PararHiloB();
        }

        private void ArchivoSalir_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ArchivoDetener_Click(object sender, EventArgs e)
        {
            PararHiloA();
            PararHiloB();
            m_PararHiloA.Reset();
            m_ParadoHiloA.Reset();
            m_PararHiloB.Reset();
            m_ParadoHiloB.Reset();
            MessageBox.Show("Hilos parados.");
            ArchivoDetener.Enabled = false;
            ct_Velocidad.Enabled = true;
        }

        private void bt_Ocultar_Click(object sender, EventArgs e)
        {
            if (Imagen1.Visible == true) //Si la imagen está visible
            {
                Imagen1.Visible = false; //Oculto la imagen
                bt_Ocultar.Text = "Mostrar Imagen";
            }
            else //Si no está visible
            {
                Imagen1.Visible = true; //La muestro
                bt_Ocultar.Text = "Ocultar Imagen";
            }
        }
    }
}
