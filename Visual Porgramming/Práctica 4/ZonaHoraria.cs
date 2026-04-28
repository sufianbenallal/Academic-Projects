using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace practica4
{
    [Serializable] // 8.2
    public class ZonaHoraria
    {
            // Atributos
            private TimeSpan m_Diferencia = new TimeSpan(); // Para diferencia horaria
            private bool m_Positivo = true;
            private string m_Nombre = "";

            // Métodos  
            public TimeSpan Diferencia  // Diferencia
            {
                get { return m_Diferencia; }
                set { m_Diferencia = value; }
            }

            public bool Positivo       // Positivo
            {
                get { return m_Positivo; }
                set { m_Positivo = value; }
            }

            public string Nombre      // Nombre
            {
                get { return m_Nombre; }
                set { m_Nombre = value; }
            }
        }
}
