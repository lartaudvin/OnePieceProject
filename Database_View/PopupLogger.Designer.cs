namespace Database_View
{
    partial class PopupLogger
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
            this.inner_text = new System.Windows.Forms.RichTextBox();
            this.OK_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // inner_text
            // 
            this.inner_text.Location = new System.Drawing.Point(13, 13);
            this.inner_text.Name = "inner_text";
            this.inner_text.ReadOnly = true;
            this.inner_text.Size = new System.Drawing.Size(478, 96);
            this.inner_text.TabIndex = 0;
            this.inner_text.Text = "";
            // 
            // OK_button
            // 
            this.OK_button.Location = new System.Drawing.Point(213, 123);
            this.OK_button.Name = "OK_button";
            this.OK_button.Size = new System.Drawing.Size(75, 23);
            this.OK_button.TabIndex = 1;
            this.OK_button.Text = "OK";
            this.OK_button.UseVisualStyleBackColor = true;
            this.OK_button.Click += new System.EventHandler(this.OK_button_Click);
            // 
            // PopupLogger
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(503, 158);
            this.Controls.Add(this.OK_button);
            this.Controls.Add(this.inner_text);
            this.Name = "PopupLogger";
            this.Text = "PopupLogger";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox inner_text;
        private System.Windows.Forms.Button OK_button;
    }
}