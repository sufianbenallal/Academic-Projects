using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace BDFamosos
{
    public class CFamosoBO : INotifyPropertyChanged
    {
        private int ID;
        private string nombre, apellidos, imagen;
        private DateTime cumple = new DateTime();
        private bool modificado;

        public int Id
        {
            get { return ID; }
            set
            {
                ID = value;
                modificado = true;
                OnPropertyChanged(new PropertyChangedEventArgs("Id"));
            }
        }

        public bool Modificado
        {
            get { return modificado; }
            set { modificado = value; }
        }

        public string Nombre
        {
            get { return nombre; }
            set
            {
                nombre = value;
                OnPropertyChanged(new PropertyChangedEventArgs("Nombre"));
            }
        }

        public string Apellidos
        {
            get { return apellidos; }
            set
            {
                apellidos = value;
                OnPropertyChanged(new PropertyChangedEventArgs("Apellidos"));
            }
        }

        public DateTime Cumple
        {
            get { return cumple; }
            set
            {
                cumple = value;
                OnPropertyChanged(new PropertyChangedEventArgs("Cumple"));
            }
        }

        public string Imagen
        {
            get { return imagen; }
            set
            {
                imagen = value;
                OnPropertyChanged(new PropertyChangedEventArgs("Imagen"));
            }
        }

        public string Edad
        {
            get
            {
                DateTime hoy = DateTime.Now;
                int edad = hoy.Year - cumple.Year;
                if (hoy.Month < cumple.Month || ((hoy.Month == cumple.Month) && hoy.Day < cumple.Day))
                    --edad;
                return String.Format("{0}", edad);
            }
        }

        public string NombreApellidosEdad
        {
            get
            {
                return nombre + ',' + ' ' + Apellidos + '(' + Edad + ')';
            }
        }

        //Constructores
        public CFamosoBO() { }
        public CFamosoBO(int id, string nom, string ape, DateTime cum, string ima = null)
        {
            Id = id;
            nombre = nom;
            apellidos = ape;
            cumple = cum;
            imagen = ima;
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(PropertyChangedEventArgs e)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, e);
            }
        }
    }
}

