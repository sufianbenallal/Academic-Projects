
namespace Practica5
{
    partial class VisorImágenes
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(VisorImágenes));
            this.menuPadre = new System.Windows.Forms.MenuStrip();
            this.menuArchivo = new System.Windows.Forms.ToolStripMenuItem();
            this.ArchivoSalir = new System.Windows.Forms.ToolStripMenuItem();
            this.ArchivoCerrar = new System.Windows.Forms.ToolStripMenuItem();
            this.ArchivoNuevo = new System.Windows.Forms.ToolStripMenuItem();
            this.ArchivoAbrir = new System.Windows.Forms.ToolStripMenuItem();
            this.menuVer = new System.Windows.Forms.ToolStripMenuItem();
            this.menuVentana = new System.Windows.Forms.ToolStripMenuItem();
            this.VentanaCascada = new System.Windows.Forms.ToolStripMenuItem();
            this.VentanaMosaicoHorizontal = new System.Windows.Forms.ToolStripMenuItem();
            this.VentanaMosaicoVertical = new System.Windows.Forms.ToolStripMenuItem();
            this.menuAyuda = new System.Windows.Forms.ToolStripMenuItem();
            this.menuAyudaAcercaDe = new System.Windows.Forms.ToolStripMenuItem();
            this.barraVisor = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.etiquetaEstado = new System.Windows.Forms.ToolStripStatusLabel();
            this.VerHerramientas = new System.Windows.Forms.ToolStripMenuItem();
            this.VerEstado = new System.Windows.Forms.ToolStripMenuItem();
            this.menuPadre.SuspendLayout();
            this.barraVisor.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuPadre
            // 
            this.menuPadre.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuArchivo,
            this.menuVer,
            this.menuVentana,
            this.menuAyuda});
            this.menuPadre.Location = new System.Drawing.Point(0, 0);
            this.menuPadre.MdiWindowListItem = this.menuVentana;
            this.menuPadre.Name = "menuPadre";
            this.menuPadre.Size = new System.Drawing.Size(800, 24);
            this.menuPadre.TabIndex = 1;
            this.menuPadre.Text = "menuStrip1";
            // 
            // menuArchivo
            // 
            this.menuArchivo.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ArchivoSalir,
            this.ArchivoCerrar,
            this.ArchivoNuevo,
            this.ArchivoAbrir});
            this.menuArchivo.Name = "menuArchivo";
            this.menuArchivo.Size = new System.Drawing.Size(60, 20);
            this.menuArchivo.Text = "Archivo";
            // 
            // ArchivoSalir
            // 
            this.ArchivoSalir.Name = "ArchivoSalir";
            this.ArchivoSalir.Size = new System.Drawing.Size(180, 22);
            this.ArchivoSalir.Text = "Salir";
            this.ArchivoSalir.Click += new System.EventHandler(this.ArchivoSalir_Click);
            // 
            // ArchivoCerrar
            // 
            this.ArchivoCerrar.Name = "ArchivoCerrar";
            this.ArchivoCerrar.Size = new System.Drawing.Size(180, 22);
            this.ArchivoCerrar.Text = "Cerrar";
            this.ArchivoCerrar.Click += new System.EventHandler(this.ArchivoCerrar_Click);
            // 
            // ArchivoNuevo
            // 
            this.ArchivoNuevo.Name = "ArchivoNuevo";
            this.ArchivoNuevo.Size = new System.Drawing.Size(180, 22);
            this.ArchivoNuevo.Text = "Nuevo";
            this.ArchivoNuevo.Click += new System.EventHandler(this.ArchivoNuevo_Click);
            this.ArchivoNuevo.MouseEnter += new System.EventHandler(this.ArchivoNuevo_MouseEnter);
            this.ArchivoNuevo.MouseLeave += new System.EventHandler(this.ArchivoNuevo_MouseLeave);
            // 
            // ArchivoAbrir
            // 
            this.ArchivoAbrir.Name = "ArchivoAbrir";
            this.ArchivoAbrir.Size = new System.Drawing.Size(180, 22);
            this.ArchivoAbrir.Text = "Abrir";
            this.ArchivoAbrir.Click += new System.EventHandler(this.ArchivoAbrir_Click);
            // 
            // menuVer
            // 
            this.menuVer.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.VerHerramientas,
            this.VerEstado});
            this.menuVer.Name = "menuVer";
            this.menuVer.Size = new System.Drawing.Size(35, 20);
            this.menuVer.Text = "Ver";
            // 
            // menuVentana
            // 
            this.menuVentana.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.VentanaCascada,
            this.VentanaMosaicoHorizontal,
            this.VentanaMosaicoVertical});
            this.menuVentana.Name = "menuVentana";
            this.menuVentana.Size = new System.Drawing.Size(61, 20);
            this.menuVentana.Text = "Ventana";
            // 
            // VentanaCascada
            // 
            this.VentanaCascada.Name = "VentanaCascada";
            this.VentanaCascada.Size = new System.Drawing.Size(180, 22);
            this.VentanaCascada.Text = "Cascada";
            this.VentanaCascada.Click += new System.EventHandler(this.VentanaCascada_Click);
            // 
            // VentanaMosaicoHorizontal
            // 
            this.VentanaMosaicoHorizontal.Name = "VentanaMosaicoHorizontal";
            this.VentanaMosaicoHorizontal.Size = new System.Drawing.Size(180, 22);
            this.VentanaMosaicoHorizontal.Text = "Mosaico horizontal";
            this.VentanaMosaicoHorizontal.Click += new System.EventHandler(this.VentanaMosaicoHorizontal_Click);
            // 
            // VentanaMosaicoVertical
            // 
            this.VentanaMosaicoVertical.Name = "VentanaMosaicoVertical";
            this.VentanaMosaicoVertical.Size = new System.Drawing.Size(180, 22);
            this.VentanaMosaicoVertical.Text = "Mosaico vertical";
            this.VentanaMosaicoVertical.Click += new System.EventHandler(this.VentanaMosaicoVertical_Click);
            // 
            // menuAyuda
            // 
            this.menuAyuda.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuAyudaAcercaDe});
            this.menuAyuda.Name = "menuAyuda";
            this.menuAyuda.Size = new System.Drawing.Size(53, 20);
            this.menuAyuda.Text = "Ayuda";
            // 
            // menuAyudaAcercaDe
            // 
            this.menuAyudaAcercaDe.Name = "menuAyudaAcercaDe";
            this.menuAyudaAcercaDe.Size = new System.Drawing.Size(180, 22);
            this.menuAyudaAcercaDe.Text = "Acerca de...";
            this.menuAyudaAcercaDe.Click += new System.EventHandler(this.menuAyudaAcercaDe_Click);
            // 
            // barraVisor
            // 
            this.barraVisor.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripButton2,
            this.toolStripButton3});
            this.barraVisor.Location = new System.Drawing.Point(0, 24);
            this.barraVisor.Name = "barraVisor";
            this.barraVisor.Size = new System.Drawing.Size(800, 25);
            this.barraVisor.TabIndex = 3;
            this.barraVisor.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "Nuevo";
            this.toolStripButton1.Click += new System.EventHandler(this.ArchivoNuevo_Click);
            this.toolStripButton1.MouseEnter += new System.EventHandler(this.ArchivoNuevo_MouseEnter);
            this.toolStripButton1.MouseLeave += new System.EventHandler(this.ArchivoNuevo_MouseLeave);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton2.Text = "Abrir";
            this.toolStripButton2.Click += new System.EventHandler(this.ArchivoAbrir_Click);
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton3.Text = "Acerca de...";
            this.toolStripButton3.Click += new System.EventHandler(this.menuAyudaAcercaDe_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.etiquetaEstado});
            this.statusStrip1.Location = new System.Drawing.Point(0, 428);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(800, 22);
            this.statusStrip1.TabIndex = 4;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // etiquetaEstado
            // 
            this.etiquetaEstado.Name = "etiquetaEstado";
            this.etiquetaEstado.Size = new System.Drawing.Size(785, 17);
            this.etiquetaEstado.Spring = true;
            this.etiquetaEstado.Text = "Selecciona";
            this.etiquetaEstado.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // VerHerramientas
            // 
            this.VerHerramientas.Name = "VerHerramientas";
            this.VerHerramientas.Size = new System.Drawing.Size(180, 22);
            this.VerHerramientas.Text = "Barra herramientas";
            this.VerHerramientas.Click += new System.EventHandler(this.VerHerramientas_Click);
            // 
            // VerEstado
            // 
            this.VerEstado.Name = "VerEstado";
            this.VerEstado.Size = new System.Drawing.Size(180, 22);
            this.VerEstado.Text = "Barra estado";
            this.VerEstado.Click += new System.EventHandler(this.VerEstado_Click);
            // 
            // VisorImágenes
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.barraVisor);
            this.Controls.Add(this.menuPadre);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuPadre;
            this.Name = "VisorImágenes";
            this.Text = "Form1";
            this.MdiChildActivate += new System.EventHandler(this.VisorImágenes_MdiChildActivate);
            this.DragDrop += new System.Windows.Forms.DragEventHandler(this.VisorImágenes_DragDrop);
            this.DragEnter += new System.Windows.Forms.DragEventHandler(this.VisorImágenes_DragEnter);
            this.menuPadre.ResumeLayout(false);
            this.menuPadre.PerformLayout();
            this.barraVisor.ResumeLayout(false);
            this.barraVisor.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuPadre;
        private System.Windows.Forms.ToolStripMenuItem menuArchivo;
        private System.Windows.Forms.ToolStripMenuItem menuVer;
        private System.Windows.Forms.ToolStripMenuItem menuVentana;
        private System.Windows.Forms.ToolStripMenuItem menuAyuda;
        private System.Windows.Forms.ToolStripMenuItem menuAyudaAcercaDe;
        private System.Windows.Forms.ToolStripMenuItem VentanaCascada;
        private System.Windows.Forms.ToolStripMenuItem VentanaMosaicoHorizontal;
        private System.Windows.Forms.ToolStripMenuItem VentanaMosaicoVertical;
        private System.Windows.Forms.ToolStripMenuItem ArchivoSalir;
        private System.Windows.Forms.ToolStripMenuItem ArchivoCerrar;
        private System.Windows.Forms.ToolStripMenuItem ArchivoNuevo;
        private System.Windows.Forms.ToolStripMenuItem ArchivoAbrir;
        private System.Windows.Forms.ToolStrip barraVisor;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripButton toolStripButton3;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel etiquetaEstado;
        private System.Windows.Forms.ToolStripMenuItem VerHerramientas;
        private System.Windows.Forms.ToolStripMenuItem VerEstado;
    }
}

