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
    partial class RelojDigital
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
            this.components = new System.ComponentModel.Container();
            this.menu = new System.Windows.Forms.MenuStrip();
            this.Archivo = new System.Windows.Forms.ToolStripMenuItem();
            this.ArchivoSalir = new System.Windows.Forms.ToolStripMenuItem();
            this.opciones = new System.Windows.Forms.ToolStripMenuItem();
            this.opcionesMostrarOcultarAnalogico = new System.Windows.Forms.ToolStripMenuItem();
            this.opcionesSeparador1 = new System.Windows.Forms.ToolStripSeparator();
            this.opcionesColorFondo = new System.Windows.Forms.ToolStripMenuItem();
            this.opcionesFuente = new System.Windows.Forms.ToolStripMenuItem();
            this.opcionesSeparador2 = new System.Windows.Forms.ToolStripSeparator();
            this.opcionesDespertador = new System.Windows.Forms.ToolStripMenuItem();
            this.menuContextoAlarma = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.opcionesDespertadorActivar = new System.Windows.Forms.ToolStripMenuItem();
            this.opcionesDespertadorDesactivar = new System.Windows.Forms.ToolStripMenuItem();
            this.menuZona = new System.Windows.Forms.ToolStripMenuItem();
            this.menuContextoZona = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.zonaAñadir = new System.Windows.Forms.ToolStripMenuItem();
            this.zonaEliminar = new System.Windows.Forms.ToolStripMenuItem();
            this.separador = new System.Windows.Forms.ToolStripSeparator();
            this.ayuda = new System.Windows.Forms.ToolStripMenuItem();
            this.AyudaaCercaDe = new System.Windows.Forms.ToolStripMenuItem();
            this.ct_HoraActual = new System.Windows.Forms.TextBox();
            this.etHoraActual = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.et_Alarma = new System.Windows.Forms.Label();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.cv_Despertador = new System.Windows.Forms.CheckBox();
            this.bt_provisional = new System.Windows.Forms.Button();
            this.ct_Alarma = new practica4.EditHora();
            this.menu.SuspendLayout();
            this.menuContextoAlarma.SuspendLayout();
            this.menuContextoZona.SuspendLayout();
            this.SuspendLayout();
            // 
            // menu
            // 
            this.menu.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Archivo,
            this.opciones,
            this.menuZona,
            this.ayuda});
            this.menu.Location = new System.Drawing.Point(0, 0);
            this.menu.Name = "menu";
            this.menu.Padding = new System.Windows.Forms.Padding(4, 2, 0, 2);
            this.menu.Size = new System.Drawing.Size(600, 24);
            this.menu.TabIndex = 0;
            this.menu.Text = "menuStrip1";
            this.toolTip1.SetToolTip(this.menu, "Añada/Elimine una zona pulsando con el botón derecho del ratón");
            // 
            // Archivo
            // 
            this.Archivo.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ArchivoSalir});
            this.Archivo.Name = "Archivo";
            this.Archivo.Size = new System.Drawing.Size(60, 20);
            this.Archivo.Text = "Archivo";
            // 
            // ArchivoSalir
            // 
            this.ArchivoSalir.Name = "ArchivoSalir";
            this.ArchivoSalir.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.ArchivoSalir.Size = new System.Drawing.Size(136, 22);
            this.ArchivoSalir.Text = "Salir";
            this.ArchivoSalir.Click += new System.EventHandler(this.salirToolStripMenuItem_Click);
            // 
            // opciones
            // 
            this.opciones.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.opcionesMostrarOcultarAnalogico,
            this.opcionesSeparador1,
            this.opcionesColorFondo,
            this.opcionesFuente,
            this.opcionesSeparador2,
            this.opcionesDespertador});
            this.opciones.Name = "opciones";
            this.opciones.Size = new System.Drawing.Size(69, 20);
            this.opciones.Text = "Opciones";
            this.opciones.DropDownOpened += new System.EventHandler(this.opcionesToolStripMenuItem_DropDownOpened);
            // 
            // opcionesMostrarOcultarAnalogico
            // 
            this.opcionesMostrarOcultarAnalogico.Name = "opcionesMostrarOcultarAnalogico";
            this.opcionesMostrarOcultarAnalogico.Size = new System.Drawing.Size(170, 22);
            this.opcionesMostrarOcultarAnalogico.Text = "Mostrar analógico";
            this.opcionesMostrarOcultarAnalogico.Click += new System.EventHandler(this.bt_Mostrar_Click);
            // 
            // opcionesSeparador1
            // 
            this.opcionesSeparador1.Name = "opcionesSeparador1";
            this.opcionesSeparador1.Size = new System.Drawing.Size(167, 6);
            // 
            // opcionesColorFondo
            // 
            this.opcionesColorFondo.Name = "opcionesColorFondo";
            this.opcionesColorFondo.Size = new System.Drawing.Size(170, 22);
            this.opcionesColorFondo.Text = "Color fondo";
            this.opcionesColorFondo.Click += new System.EventHandler(this.colorFondo_Click);
            // 
            // opcionesFuente
            // 
            this.opcionesFuente.Name = "opcionesFuente";
            this.opcionesFuente.Size = new System.Drawing.Size(170, 22);
            this.opcionesFuente.Text = "Fuente";
            this.opcionesFuente.Click += new System.EventHandler(this.fuente_Click);
            // 
            // opcionesSeparador2
            // 
            this.opcionesSeparador2.Name = "opcionesSeparador2";
            this.opcionesSeparador2.Size = new System.Drawing.Size(167, 6);
            // 
            // opcionesDespertador
            // 
            this.opcionesDespertador.DropDown = this.menuContextoAlarma;
            this.opcionesDespertador.Name = "opcionesDespertador";
            this.opcionesDespertador.Size = new System.Drawing.Size(170, 22);
            this.opcionesDespertador.Text = "Despertador";
            // 
            // menuContextoAlarma
            // 
            this.menuContextoAlarma.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuContextoAlarma.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.opcionesDespertadorActivar,
            this.opcionesDespertadorDesactivar});
            this.menuContextoAlarma.Name = "menuContextoAlarma";
            this.menuContextoAlarma.OwnerItem = this.opcionesDespertador;
            this.menuContextoAlarma.Size = new System.Drawing.Size(170, 48);
            this.menuContextoAlarma.Opening += new System.ComponentModel.CancelEventHandler(this.menuContextoAlarma_Opening);
            // 
            // opcionesDespertadorActivar
            // 
            this.opcionesDespertadorActivar.Name = "opcionesDespertadorActivar";
            this.opcionesDespertadorActivar.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.T)));
            this.opcionesDespertadorActivar.Size = new System.Drawing.Size(169, 22);
            this.opcionesDespertadorActivar.Text = "Activar";
            this.opcionesDespertadorActivar.Click += new System.EventHandler(this.opcionesDespertadorActivar_Click);
            // 
            // opcionesDespertadorDesactivar
            // 
            this.opcionesDespertadorDesactivar.Name = "opcionesDespertadorDesactivar";
            this.opcionesDespertadorDesactivar.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.opcionesDespertadorDesactivar.Size = new System.Drawing.Size(169, 22);
            this.opcionesDespertadorDesactivar.Text = "Desactivar";
            this.opcionesDespertadorDesactivar.Click += new System.EventHandler(this.opcionesDespertadorDesactivar_Click);
            // 
            // menuZona
            // 
            this.menuZona.DropDown = this.menuContextoZona;
            this.menuZona.Name = "menuZona";
            this.menuZona.Size = new System.Drawing.Size(46, 20);
            this.menuZona.Text = "Zona";
            this.menuZona.DropDownOpened += new System.EventHandler(this.menuZona_DropDownOpened);
            // 
            // menuContextoZona
            // 
            this.menuContextoZona.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuContextoZona.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.zonaAñadir,
            this.zonaEliminar,
            this.separador});
            this.menuContextoZona.Name = "menuContextoZona";
            this.menuContextoZona.OwnerItem = this.menuZona;
            this.menuContextoZona.Size = new System.Drawing.Size(204, 54);
            this.menuContextoZona.Opened += new System.EventHandler(this.menuZona_DropDownOpened);
            // 
            // zonaAñadir
            // 
            this.zonaAñadir.Name = "zonaAñadir";
            this.zonaAñadir.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.R)));
            this.zonaAñadir.Size = new System.Drawing.Size(203, 22);
            this.zonaAñadir.Text = "Añadir";
            this.zonaAñadir.Click += new System.EventHandler(this.zonaAñadir_Click);
            // 
            // zonaEliminar
            // 
            this.zonaEliminar.Name = "zonaEliminar";
            this.zonaEliminar.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.L)));
            this.zonaEliminar.Size = new System.Drawing.Size(203, 22);
            this.zonaEliminar.Text = "Eliminar";
            this.zonaEliminar.Click += new System.EventHandler(this.zonaEliminar_Click);
            // 
            // separador
            // 
            this.separador.Name = "separador";
            this.separador.Size = new System.Drawing.Size(200, 6);
            // 
            // ayuda
            // 
            this.ayuda.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.AyudaaCercaDe});
            this.ayuda.Name = "ayuda";
            this.ayuda.Size = new System.Drawing.Size(53, 20);
            this.ayuda.Text = "Ayuda";
            // 
            // AyudaaCercaDe
            // 
            this.AyudaaCercaDe.Name = "AyudaaCercaDe";
            this.AyudaaCercaDe.Size = new System.Drawing.Size(135, 22);
            this.AyudaaCercaDe.Text = "Acerca de...";
            this.AyudaaCercaDe.Click += new System.EventHandler(this.aCercaDeToolStripMenuItem_Click);
            // 
            // ct_HoraActual
            // 
            this.ct_HoraActual.CausesValidation = false;
            this.ct_HoraActual.Cursor = System.Windows.Forms.Cursors.No;
            this.ct_HoraActual.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.ct_HoraActual.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.ct_HoraActual.Location = new System.Drawing.Point(241, 168);
            this.ct_HoraActual.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.ct_HoraActual.Name = "ct_HoraActual";
            this.ct_HoraActual.ReadOnly = true;
            this.ct_HoraActual.Size = new System.Drawing.Size(180, 23);
            this.ct_HoraActual.TabIndex = 1;
            this.ct_HoraActual.TabStop = false;
            this.ct_HoraActual.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ct_HoraActual.TextChanged += new System.EventHandler(this.ct_HoraActual_TextChanged);
            // 
            // etHoraActual
            // 
            this.etHoraActual.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.etHoraActual.Location = new System.Drawing.Point(94, 173);
            this.etHoraActual.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.etHoraActual.Name = "etHoraActual";
            this.etHoraActual.Size = new System.Drawing.Size(83, 17);
            this.etHoraActual.TabIndex = 1;
            this.etHoraActual.Text = "Hora actual";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // et_Alarma
            // 
            this.et_Alarma.AutoSize = true;
            this.et_Alarma.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.et_Alarma.Location = new System.Drawing.Point(11, 116);
            this.et_Alarma.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.et_Alarma.Name = "et_Alarma";
            this.et_Alarma.Size = new System.Drawing.Size(52, 17);
            this.et_Alarma.TabIndex = 4;
            this.et_Alarma.Text = "Alarma";
            // 
            // toolTip1
            // 
            this.toolTip1.Tag = "";
            this.toolTip1.Popup += new System.Windows.Forms.PopupEventHandler(this.toolTip1_Popup);
            // 
            // cv_Despertador
            // 
            this.cv_Despertador.AutoSize = true;
            this.cv_Despertador.Location = new System.Drawing.Point(270, 124);
            this.cv_Despertador.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.cv_Despertador.Name = "cv_Despertador";
            this.cv_Despertador.Size = new System.Drawing.Size(129, 17);
            this.cv_Despertador.TabIndex = 5;
            this.cv_Despertador.Text = "Despertador Activado";
            this.cv_Despertador.UseVisualStyleBackColor = true;
            this.cv_Despertador.Click += new System.EventHandler(this.cv_Despertador_Click);
            // 
            // bt_provisional
            // 
            this.bt_provisional.Location = new System.Drawing.Point(430, 116);
            this.bt_provisional.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.bt_provisional.Name = "bt_provisional";
            this.bt_provisional.Size = new System.Drawing.Size(107, 25);
            this.bt_provisional.TabIndex = 6;
            this.bt_provisional.Text = "DlgEliminarZona";
            this.bt_provisional.UseVisualStyleBackColor = true;
            this.bt_provisional.Click += new System.EventHandler(this.zonaEliminar_Click);
            // 
            // ct_Alarma
            // 
            this.ct_Alarma.BeepOnError = true;
            this.ct_Alarma.ContextMenuStrip = this.menuContextoAlarma;
            this.ct_Alarma.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.ct_Alarma.ForeColor = System.Drawing.SystemColors.Desktop;
            this.ct_Alarma.Hora = new System.DateTime(((long)(0)));
            this.ct_Alarma.Location = new System.Drawing.Point(97, 116);
            this.ct_Alarma.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.ct_Alarma.Mask = "90:00:99";
            this.ct_Alarma.Name = "ct_Alarma";
            this.ct_Alarma.PromptChar = '-';
            this.ct_Alarma.Size = new System.Drawing.Size(122, 23);
            this.ct_Alarma.TabIndex = 3;
            this.ct_Alarma.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ct_Alarma.TextMaskFormat = System.Windows.Forms.MaskFormat.IncludePromptAndLiterals;
            // 
            // RelojDigital
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(600, 366);
            this.ContextMenuStrip = this.menuContextoZona;
            this.Controls.Add(this.bt_provisional);
            this.Controls.Add(this.cv_Despertador);
            this.Controls.Add(this.et_Alarma);
            this.Controls.Add(this.ct_Alarma);
            this.Controls.Add(this.etHoraActual);
            this.Controls.Add(this.ct_HoraActual);
            this.Controls.Add(this.menu);
            this.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MainMenuStrip = this.menu;
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "RelojDigital";
            this.Text = "Reloj Digital";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.RelojDigital_FormClosing);
            this.Load += new System.EventHandler(this.RelojDigital_Load);
            this.Shown += new System.EventHandler(this.RelojDigital_Shown);
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.menuContextoAlarma.ResumeLayout(false);
            this.menuContextoZona.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu;
        private System.Windows.Forms.ToolStripMenuItem Archivo;
        private System.Windows.Forms.ToolStripMenuItem ArchivoSalir;
        private System.Windows.Forms.ToolStripMenuItem ayuda;
        private System.Windows.Forms.ToolStripMenuItem AyudaaCercaDe;
        private TextBox ct_HoraActual;
        private Label etHoraActual; // Definimos el nombre de la etiqueta de "Hora Actual"
        private Timer timer1;
        private ToolStripMenuItem opciones;
        private ToolStripMenuItem opcionesColorFondo;
        private ToolStripMenuItem opcionesFuente;
        private ToolStripMenuItem opcionesMostrarOcultarAnalogico;
        private EditHora ct_Alarma;
        private Label et_Alarma;
        private ToolStripMenuItem opcionesDespertador;
        private ToolStripSeparator opcionesSeparador1;
        private ToolStripSeparator opcionesSeparador2;
        private ToolStripMenuItem menuZona;
        private ContextMenuStrip menuContextoAlarma;
        private ToolStripMenuItem opcionesDespertadorActivar;
        private ToolStripMenuItem opcionesDespertadorDesactivar;
        private ContextMenuStrip menuContextoZona;
        private ToolStripMenuItem zonaAñadir;
        private ToolStripMenuItem zonaEliminar;
        private ToolStripSeparator separador;
        private ToolTip toolTip1;
        private CheckBox cv_Despertador;
        private Button bt_provisional;
    }
}

