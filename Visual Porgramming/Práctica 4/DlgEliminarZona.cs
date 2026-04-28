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
    public partial class DlgEliminarZona : Form
    {
        List<ZonaHoraria> m_Zonas = new List<ZonaHoraria>();
        private int m_ZonaSeleccionada = - 1;

        public DlgEliminarZona() // Constructor
        {
            InitializeComponent();
            this.MinimumSize = this.Size; // 8.1.3 -> límite mínimo del diálogo
            foreach (ZonaHoraria element in m_Zonas)
            {
                lb_Zonas.Items.Add(element.Nombre);
            }
        }

        private void DlgEliminarZona_Load(object sender, EventArgs e) // Manejador para el evento load
        {
            //m_Zonas = ((RelojDigital)this.Owner).Zonas; // asigno a m_Zonas la lista de las zonas horarias List<ZonaHoraria>
            RelojDigital relD = (RelojDigital)this.Owner;
            m_Zonas = relD.Zonas;


            // foreach repite un conjunto de instrucciones por cada elemento de una matriz o una colección de objetos
            int i = 0;
            foreach (ZonaHoraria elemento in m_Zonas)
                lb_Zonas.Items.Add(elemento.Nombre); // Añadimos el nombre del elemento a la lista desplegable

            if (i == 0)
                lb_Zonas.SetSelected(0, true); // Seleccionamos el primer elemento de la lista
            i++;
        }

        private void lb_Zonas_SelectedIndexChanged(object sender, EventArgs e) // 8.1.4
        {
            //ZonaHoraria zonaSel = (ZonaHoraria)sender;
            //string nombreZona = zonaSel.Nombre;

            string nombreZona = this.lb_Zonas.Text; // Texto de la zona que está seleccionada
            ZonaHoraria zonaSeleccionada =
                m_Zonas.Find(
                    delegate (ZonaHoraria zona) // Predicado anónimo
                    {
                        return zona.Nombre == nombreZona;
                    }
                    );

        }

        public int ZonaSeleccionada // 8.1.4
        {
            get { return m_ZonaSeleccionada; }
        }

        private void bt_Aceptar_Click(object sender, EventArgs e) // 8.1.4
        {
            m_ZonaSeleccionada = lb_Zonas.SelectedIndex;  // Índice de la zona seleccionada

            Console.Write("indice: " + m_ZonaSeleccionada + "");
            lb_Zonas.Items.Remove(m_ZonaSeleccionada);
            this.DialogResult = DialogResult.OK;
        }
    }
}
