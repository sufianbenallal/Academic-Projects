<?php
   $pais = $_GET['pais'];

   // Obtener ciudades correspondientes al país (puedes cargar esto desde un archivo de texto)
   $ciudades = obtenerCiudadesPorPais($pais);

   // Devolver las ciudades como respuesta en formato JSON
   echo json_encode($ciudades);

   function obtenerCiudadesPorPais($pais) {
      // Aquí debes implementar la lógica para obtener las ciudades del país
      // Puedes cargar esto desde un archivo de texto o cualquier otra fuente de datos
      // Ejemplo:
      switch ($pais) {
         case 'España':
            return ['Madrid', 'Barcelona', 'Valencia', 'Sevilla', 'Zaragoza'];
         // Agrega casos para otros países
         default:
            return [];
      }
   }
?>
