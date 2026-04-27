
namespace p1reloj
{
    partial class RelojAnalógico
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
            this.SuspendLayout();
            // 
            // RelojAnalógico
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.ControlBox = false;
            this.DoubleBuffered = true;
            this.Name = "RelojAnalógico";
            this.ShowInTaskbar = false;
            this.Text = "Reloj Analógico";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.RelojAnalógico_FormClosing_1);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.RelojAnalógico_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.RelojAnalógico_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.RelojAnalógico_MouseMove);
            this.Resize += new System.EventHandler(this.RelojAnalógico_Resize);
            this.ResumeLayout(false);

        }

        #endregion
    }
}