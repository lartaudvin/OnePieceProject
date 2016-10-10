namespace Database_View
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
            this.insert_character_button = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.name_text = new System.Windows.Forms.TextBox();
            this.fullname_text = new System.Windows.Forms.TextBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.export_xml_button = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.character_list = new System.Windows.Forms.ListBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.SuspendLayout();
            // 
            // insert_character_button
            // 
            this.insert_character_button.Location = new System.Drawing.Point(31, 244);
            this.insert_character_button.Name = "insert_character_button";
            this.insert_character_button.Size = new System.Drawing.Size(75, 23);
            this.insert_character_button.TabIndex = 0;
            this.insert_character_button.Text = "Insert";
            this.insert_character_button.UseVisualStyleBackColor = true;
            this.insert_character_button.Click += new System.EventHandler(this.insert_character_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(118, 39);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(54, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Full Name";
            // 
            // name_text
            // 
            this.name_text.Location = new System.Drawing.Point(6, 66);
            this.name_text.Name = "name_text";
            this.name_text.Size = new System.Drawing.Size(100, 20);
            this.name_text.TabIndex = 3;
            // 
            // fullname_text
            // 
            this.fullname_text.Location = new System.Drawing.Point(121, 66);
            this.fullname_text.Name = "fullname_text";
            this.fullname_text.Size = new System.Drawing.Size(170, 20);
            this.fullname_text.TabIndex = 4;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(1, 2);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(686, 461);
            this.tabControl1.TabIndex = 5;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.character_list);
            this.tabPage1.Controls.Add(this.export_xml_button);
            this.tabPage1.Controls.Add(this.name_text);
            this.tabPage1.Controls.Add(this.fullname_text);
            this.tabPage1.Controls.Add(this.insert_character_button);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(678, 435);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Character";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // export_xml_button
            // 
            this.export_xml_button.Location = new System.Drawing.Point(121, 244);
            this.export_xml_button.Name = "export_xml_button";
            this.export_xml_button.Size = new System.Drawing.Size(75, 23);
            this.export_xml_button.TabIndex = 6;
            this.export_xml_button.Text = "export xml";
            this.export_xml_button.UseVisualStyleBackColor = true;
            this.export_xml_button.Click += new System.EventHandler(this.export_xml_button_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(678, 435);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "tabPage2";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // character_list
            // 
            this.character_list.FormattingEnabled = true;
            this.character_list.Location = new System.Drawing.Point(480, 76);
            this.character_list.Name = "character_list";
            this.character_list.Size = new System.Drawing.Size(172, 147);
            this.character_list.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(690, 461);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button insert_character_button;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox name_text;
        private System.Windows.Forms.TextBox fullname_text;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Button export_xml_button;
        private System.Windows.Forms.ListBox character_list;
    }
}

