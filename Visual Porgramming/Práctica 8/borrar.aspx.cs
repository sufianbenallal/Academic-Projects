using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SitioWeb
{
    public partial class borrar : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        /* protected void bt_Borrar_Click(object sender, EventArgs e)
         {
             // La carpeta raíz del sitio web es "~/"
             // ...
             string sRutaSitioWeb = Server.MapPath("~/");
             // Borramos la imagen de la carpeta fotos
             File.Delete(sRutaSitioWeb + ls_Nombres.SelectedValue);
             // Borramos la ruta de la imagen de la base de datos
             string sconexión = ConfigurationManager.ConnectionStrings["fotosConnectionString"].ConnectionString; // ver clase ConfigurationManager
             SqlConnection conexión = new SqlConnection(sconexión);
             string sOrdenSQL = "DELETE from album where foto = @FOTO";
             SqlCommand ordenSQL = new SqlCommand(sOrdenSQL, conexión);
             ordenSQL.Parameters.AddWithValue("@FOTO", ls_Nombres.SelectedValue);
             // ...
             ordenSQL.Connection.Open();
             ordenSQL.ExecuteNonQuery();
             ordenSQL.Connection.Close();
             this.Response.Redirect("Default.aspx");
         }*/

        protected void bt_Borrar_Click(object sender, EventArgs e)
        { // La carpeta raíz del sitio web es "~/"
            string sRutaSitioWeb = Server.MapPath("~/");
            // Borrar la imagen
            File.Delete(sRutaSitioWeb + ls_Nombres.SelectedValue);
            AlbumFotos.Service1Client servicio = new AlbumFotos.Service1Client();
            servicio.BorrarFoto(ls_Nombres.SelectedValue);
            this.Response.Redirect("~/Default.aspx");


        }
    }
}