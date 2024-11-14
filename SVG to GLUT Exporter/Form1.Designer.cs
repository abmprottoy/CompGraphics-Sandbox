namespace SVG_to_GLUT_Exporter
{
    partial class Form1
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
            this.openSVGBtn = new System.Windows.Forms.Button();
            this.lstCoordinates = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // openSVGBtn
            // 
            this.openSVGBtn.Location = new System.Drawing.Point(12, 12);
            this.openSVGBtn.Name = "openSVGBtn";
            this.openSVGBtn.Size = new System.Drawing.Size(75, 23);
            this.openSVGBtn.TabIndex = 0;
            this.openSVGBtn.Text = "Open SVG";
            this.openSVGBtn.UseVisualStyleBackColor = true;
            this.openSVGBtn.Click += new System.EventHandler(this.openSVGBtn_Click);
            // 
            // lstCoordinates
            // 
            this.lstCoordinates.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.lstCoordinates.FormattingEnabled = true;
            this.lstCoordinates.Location = new System.Drawing.Point(0, 82);
            this.lstCoordinates.Name = "lstCoordinates";
            this.lstCoordinates.Size = new System.Drawing.Size(800, 368);
            this.lstCoordinates.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lstCoordinates);
            this.Controls.Add(this.openSVGBtn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button openSVGBtn;
        private System.Windows.Forms.ListBox lstCoordinates;
    }
}

