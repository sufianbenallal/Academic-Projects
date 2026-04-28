using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace practica4
{
    public partial class DlgDatosZona : Form
    {
        // Cambiar valores 
        private string m_Nombre;
        private TimeSpan m_Diferencia; // TimeSpan es un objeto que representa un intervalo de tiempo
        private bool m_Positivo;

        public DlgDatosZona()
        {
            InitializeComponent();

        }
        // Propiedades públicas. Devuelven o asignan un valor
        public string Nombre
        {
            get { return m_Nombre; }
            set { m_Nombre = tb_DlgNombre.Text; }
        }

        public TimeSpan Diferencia
        {
            get { return m_Diferencia; }
            set { m_Diferencia = DateTime.Now - eh_DlgDifHoraria.Hora; } // Diferencia horaria entre la hora actual y la hora del formulario
        }

        public bool Positivo
        {
            get { return m_Positivo; }
            set { m_Positivo = rb_Positivo.Checked; } // Si el positivo está marcado = True, si no = False (está marcado el negativo)
        }

        private void bt_Aceptar_Click(object sender, EventArgs e)
        {
            if (tb_DlgNombre.Text != "")
                this.m_Nombre = tb_DlgNombre.Text;
            else
            {
                MessageBox.Show("Introduzca un nombre válido",
                                "Error en los datos",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);
                eh_DlgDifHoraria.Focus();
                eh_DlgDifHoraria.SelectAll();
                return;
            }
            if(eh_DlgDifHoraria.HoraValida)
            {
                DateTime hora = eh_DlgDifHoraria.Hora;
                this.Diferencia = new TimeSpan(hora.Hour, hora.Minute, hora.Second);
            }
            else
            {
                MessageBox.Show("Introduzca una diferencia horaria válida",
                                "Error en los datos",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);
                eh_DlgDifHoraria.Focus();
                eh_DlgDifHoraria.SelectAll();
                return;
            }
            this.Positivo = rb_Positivo.Checked;
            // Datos válidos, resultado devuelto po el diálogo debe ser OK
            DialogResult = DialogResult.OK;
        }
    }
}
