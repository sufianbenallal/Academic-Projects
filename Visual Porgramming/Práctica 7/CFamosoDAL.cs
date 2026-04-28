using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace BDFamosos
{
    public class CFamosoDAL
    {
        private string strConexion;

        public CFamosoDAL()
        {
            // Obtener la cadena de conexión: elija la adecuada para su instalación
            //strConexion = @"Data Source=.\sqlexpress;" +
            // @"Initial Catalog=bd_famosos; Integrated Security=True";

            strConexion = @"Data Source=(LocalDB)\MSSQLLocalDB;" +
             @"AttachDbFilename=|DataDirectory|\bd_famosos.mdf; " +
             @"Integrated Security=True";
            //Si no es válido MSSQLLocalDB pruebe con v11.0
        }

        public ColCFamosos ObtenerFilasFamosos()
        {
            try
            {
                using (SqlConnection Conexion = new SqlConnection(strConexion))
                {
                    SqlCommand OrdenSql =
                    new SqlCommand("stproObtenerFilasFamosos", Conexion);
                    OrdenSql.CommandType = CommandType.StoredProcedure;
                    // Crear una colección para todos los famosos
                    ColCFamosos colFamosos = new ColCFamosos();
                    // Abrir la base de datos
                    Conexion.Open();
                    SqlDataReader lector = OrdenSql.ExecuteReader();
                    while (lector.Read())
                    {
                        CFamosoBO fila = new CFamosoBO((int)lector["ID"],
                        (string)lector["nombre"], (string)lector["apellidos"],
                        (DateTime)lector["cumple"], (string)lector["imagen"]);
                        colFamosos.Add(fila);
                    }
                    return colFamosos;
                }
            }
            catch (SqlException err)
            {
                throw new ApplicationException("Error SELECT famoso");
            }
        }

        public void ActualizarFamosos(CFamosoBO bo)
        {
            try
            {
                using (SqlConnection Conexion = new SqlConnection(strConexion))
                {
                    SqlCommand OrdenSql = new SqlCommand("stproActualizarFamosos", Conexion);
                    OrdenSql.CommandType = CommandType.StoredProcedure;
                    // Crear una colección para todos los famosos
                    OrdenSql.Parameters.AddWithValue("@ID", bo.Id);
                    OrdenSql.Parameters.AddWithValue("@nombre", bo.Nombre);
                    OrdenSql.Parameters.AddWithValue("@apellidos", bo.Apellidos);
                    OrdenSql.Parameters.AddWithValue("@cumple", bo.Cumple);
                    OrdenSql.Parameters.AddWithValue("@imagen", bo.Imagen);
                    // Abrir la base de datos
                    Conexion.Open();
                    OrdenSql.ExecuteNonQuery();
                }
            }
            catch (SqlException err)
            {
                throw new ApplicationException("Error INSERT famoso");
            }
        }
    }
}
