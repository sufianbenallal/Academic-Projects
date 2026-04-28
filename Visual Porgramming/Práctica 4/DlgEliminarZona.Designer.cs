namespace practica4
{
    partial class DlgEliminarZona
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dlg_Nombre = new System.Windows.Forms.Label();
            this.dlg_DifHoraria = new System.Windows.Forms.Label();
            this.eh_DlgDifHoraria = new practica4.EditHora();
            this.dlg_Signo = new System.Windows.Forms.Label();
            this.bt_Cancelar = new System.Windows.Forms.Button();
            this.bt_Aceptar = new System.Windows.Forms.Button();
            this.lb_Zonas = new System.Windows.Forms.ListBox();
            this.ct_Signo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // dlg_Nombre
            // 
            this.dlg_Nombre.AutoSize = true;
            this.dlg_Nombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.dlg_Nombre.Location = new System.Drawing.Point(44, 9);
            this.dlg_Nombre.Name = "dlg_Nombre";
            this.dlg_Nombre.Size = new System.Drawing.Size(73, 20);
            this.dlg_Nombre.TabIndex = 1;
            this.dlg_Nombre.Text = "Nombre:";
            // 
            // dlg_DifHoraria
            // 
            this.dlg_DifHoraria.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.dlg_DifHoraria.AutoSize = true;
            this.dlg_DifHoraria.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.dlg_DifHoraria.Location = new System.Drawing.Point(53, 300);
            this.dlg_DifHoraria.Name = "dlg_DifHoraria";
            this.dlg_DifHoraria.Size = new System.Drawing.Size(148, 20);
            this.dlg_DifHoraria.TabIndex = 4;
            this.dlg_DifHoraria.Text = "Diferencia horaria:";
            // 
            // eh_DlgDifHoraria
            // 
            this.eh_DlgDifHoraria.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.eh_DlgDifHoraria.BeepOnError = true;
            this.eh_DlgDifHoraria.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.eh_DlgDifHoraria.Hora = new System.DateTime(((long)(0)));
            this.eh_DlgDifHoraria.Location = new System.Drawing.Point(219, 294);
            this.eh_DlgDifHoraria.Mask = "90:00:99";
            this.eh_DlgDifHoraria.Name = "eh_DlgDifHoraria";
            this.eh_DlgDifHoraria.PromptChar = '-';
            this.eh_DlgDifHoraria.ReadOnly = true;
            this.eh_DlgDifHoraria.Size = new System.Drawing.Size(115, 26);
            this.eh_DlgDifHoraria.TabIndex = 5;
            this.eh_DlgDifHoraria.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.eh_DlgDifHoraria.TextMaskFormat = System.Windows.Forms.MaskFormat.IncludePromptAndLiterals;
            // 
            // dlg_Signo
            // 
            this.dlg_Signo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.dlg_Signo.AutoSize = true;
            this.dlg_Signo.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.dlg_Signo.Location = new System.Drawing.Point(561, 294);
            this.dlg_Signo.Name = "dlg_Signo";
            this.dlg_Signo.Size = new System.Drawing.Size(56, 20);
            this.dlg_Signo.TabIndex = 14;
            this.dlg_Signo.Text = "Signo:";
            // 
            // bt_Cancelar
            // 
            this.bt_Cancelar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bt_Cancelar.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.bt_Cancelar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.bt_Cancelar.Location = new System.Drawing.Point(638, 120);
            this.bt_Cancelar.Name = "bt_Cancelar";
            this.bt_Cancelar.Size = new System.Drawing.Size(135, 38);
            this.bt_Cancelar.TabIndex = 11;
            this.bt_Cancelar.Text = "Cancelar";
            this.bt_Cancelar.UseVisualStyleBackColor = true;
            // 
            // bt_Aceptar
            // 
            this.bt_Aceptar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bt_Aceptar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.bt_Aceptar.Location = new System.Drawing.Point(638, 42);
            this.bt_Aceptar.Name = "bt_Aceptar";
            this.bt_Aceptar.Size = new System.Drawing.Size(129, 38);
            this.bt_Aceptar.TabIndex = 10;
            this.bt_Aceptar.Text = "Aceptar";
            this.bt_Aceptar.UseVisualStyleBackColor = true;
            this.bt_Aceptar.Click += new System.EventHandler(this.bt_Aceptar_Click);
            // 
            // lb_Zonas
            // 
            this.lb_Zonas.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lb_Zonas.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F);
            this.lb_Zonas.FormattingEnabled = true;
            this.lb_Zonas.ItemHeight = 18;
            this.lb_Zonas.Location = new System.Drawing.Point(48, 42);
            this.lb_Zonas.Name = "lb_Zonas";
            this.lb_Zonas.Size = new System.Drawing.Size(552, 220);
            this.lb_Zonas.TabIndex = 16;
            this.lb_Zonas.TabStop = false;
            this.lb_Zonas.SelectedIndexChanged += new System.EventHandler(this.lb_Zonas_SelectedIndexChanged);
            // 
            // ct_Signo
            // 
            this.ct_Signo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.ct_Signo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F);
            this.ct_Signo.Location = new System.Drawing.Point(638, 290);
            this.ct_Signo.Name = "ct_Signo";
            this.ct_Signo.ReadOnly = true;
            this.ct_Signo.Size = new System.Drawing.Size(124, 24);
            this.ct_Signo.TabIndex = 17;
            this.ct_Signo.TabStop = false;
            // 
            // DlgEliminarZona
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(794, 354);
            this.Controls.Add(this.ct_Signo);
            this.Controls.Add(this.lb_Zonas);
            this.Controls.Add(this.dlg_Signo);
            this.Controls.Add(this.bt_Cancelar);
            this.Controls.Add(this.bt_Aceptar);
            this.Controls.Add(this.eh_DlgDifHoraria);
            this.Controls.Add(this.dlg_DifHoraria);
            this.Controls.Add(this.dlg_Nombre);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DlgEliminarZona";
            this.Text = "Eliminar zona horaria";
            this.Load += new System.EventHandler(this.DlgEliminarZona_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label dlg_Nombre;
        private System.Windows.Forms.Label dlg_DifHoraria;
        private EditHora eh_DlgDifHoraria;
        private System.Windows.Forms.Label dlg_Signo;
        private System.Windows.Forms.Button bt_Cancelar;
        private System.Windows.Forms.Button bt_Aceptar;
        private System.Windows.Forms.ListBox lb_Zonas;
        private System.Windows.Forms.TextBox ct_Signo;
    }
}