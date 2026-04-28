using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace practica4
{
    class EditHora : MaskedTextBox // Derivo de una clase para tener la ma propia 
    {
        private DateTime m_Hora;
        public DateTime Hora
        {
            get { return m_Hora; }
            set { m_Hora = value; }
        } // Todas las propiedades tiene un get{} y un set{}
                                           // Ej: public ColorDialog colorFondo { get; set; }

        public EditHora() // Constructor
        {
            this.Mask = "90:00:99"; // 9 = dígito o espacio, 0 = dígito obligatorio
            this.TextAlign = HorizontalAlignment.Center;
            this.BeepOnError = true;
            this.PromptChar = '-';
            this.TextMaskFormat = MaskFormat.IncludePromptAndLiterals;
            
            // Eventos enter y leave para cuando está enfocado o nó el objeto. Abajo escribimos el manejador del evento
            //this.Enter += new EventHandler(textBox_Enter);
            //this.Leave += new EventHandler(textBox_Leave);
        }

        public bool HoraValida // Comprobar que se ha introducido una hora correcta
        {
            get
            {
                if (!this.MaskCompleted)
                    return false;

                string aux = this.Text.Replace(this.PromptChar, '0');
                DateTime hora = new DateTime();
                if (!DateTime.TryParse(aux, out hora))
                    return false; // hora no correcta

                this.Hora = hora;
                return true; // hora correcta
            }
        }
    }
}
