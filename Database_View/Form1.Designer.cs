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
            this.name_id_text = new System.Windows.Forms.TextBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.character_photo_picture = new System.Windows.Forms.PictureBox();
            this.description_text = new System.Windows.Forms.RichTextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.surname_text = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.last_name_text = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.first_name_text = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.delete_button = new System.Windows.Forms.Button();
            this.new_character_button = new System.Windows.Forms.Button();
            this.character_list = new System.Windows.Forms.ListBox();
            this.export_xml_button = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.import_photo_button = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.character_photo_picture)).BeginInit();
            this.SuspendLayout();
            // 
            // insert_character_button
            // 
            this.insert_character_button.Location = new System.Drawing.Point(518, 343);
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
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Name Id";
            // 
            // name_id_text
            // 
            this.name_id_text.Location = new System.Drawing.Point(67, 32);
            this.name_id_text.MaxLength = 50;
            this.name_id_text.Name = "name_id_text";
            this.name_id_text.Size = new System.Drawing.Size(100, 20);
            this.name_id_text.TabIndex = 3;
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
            this.tabPage1.Controls.Add(this.import_photo_button);
            this.tabPage1.Controls.Add(this.character_photo_picture);
            this.tabPage1.Controls.Add(this.description_text);
            this.tabPage1.Controls.Add(this.label5);
            this.tabPage1.Controls.Add(this.surname_text);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.last_name_text);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.first_name_text);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.delete_button);
            this.tabPage1.Controls.Add(this.new_character_button);
            this.tabPage1.Controls.Add(this.character_list);
            this.tabPage1.Controls.Add(this.export_xml_button);
            this.tabPage1.Controls.Add(this.name_id_text);
            this.tabPage1.Controls.Add(this.insert_character_button);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(678, 435);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Character";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // character_photo_picture
            // 
            this.character_photo_picture.Location = new System.Drawing.Point(242, 18);
            this.character_photo_picture.Name = "character_photo_picture";
            this.character_photo_picture.Size = new System.Drawing.Size(146, 143);
            this.character_photo_picture.TabIndex = 18;
            this.character_photo_picture.TabStop = false;
            // 
            // description_text
            // 
            this.description_text.Location = new System.Drawing.Point(7, 264);
            this.description_text.MaxLength = 1000;
            this.description_text.Name = "description_text";
            this.description_text.Size = new System.Drawing.Size(297, 161);
            this.description_text.TabIndex = 17;
            this.description_text.Text = "";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(7, 231);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(60, 13);
            this.label5.TabIndex = 16;
            this.label5.Text = "Description";
            // 
            // surname_text
            // 
            this.surname_text.Location = new System.Drawing.Point(66, 141);
            this.surname_text.MaxLength = 50;
            this.surname_text.Name = "surname_text";
            this.surname_text.Size = new System.Drawing.Size(100, 20);
            this.surname_text.TabIndex = 15;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(7, 148);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(49, 13);
            this.label4.TabIndex = 14;
            this.label4.Text = "Surname";
            // 
            // last_name_text
            // 
            this.last_name_text.Location = new System.Drawing.Point(67, 106);
            this.last_name_text.MaxLength = 50;
            this.last_name_text.Name = "last_name_text";
            this.last_name_text.Size = new System.Drawing.Size(100, 20);
            this.last_name_text.TabIndex = 13;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(3, 113);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(58, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "Last Name";
            // 
            // first_name_text
            // 
            this.first_name_text.Location = new System.Drawing.Point(66, 76);
            this.first_name_text.MaxLength = 50;
            this.first_name_text.Name = "first_name_text";
            this.first_name_text.Size = new System.Drawing.Size(100, 20);
            this.first_name_text.TabIndex = 11;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 83);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 13);
            this.label2.TabIndex = 10;
            this.label2.Text = "First Name";
            // 
            // delete_button
            // 
            this.delete_button.Location = new System.Drawing.Point(518, 402);
            this.delete_button.Name = "delete_button";
            this.delete_button.Size = new System.Drawing.Size(75, 23);
            this.delete_button.TabIndex = 9;
            this.delete_button.Text = "Delete";
            this.delete_button.UseVisualStyleBackColor = true;
            this.delete_button.Visible = false;
            this.delete_button.Click += new System.EventHandler(this.delete_button_Click);
            // 
            // new_character_button
            // 
            this.new_character_button.Location = new System.Drawing.Point(518, 262);
            this.new_character_button.Name = "new_character_button";
            this.new_character_button.Size = new System.Drawing.Size(75, 23);
            this.new_character_button.TabIndex = 8;
            this.new_character_button.Text = "New";
            this.new_character_button.UseVisualStyleBackColor = true;
            this.new_character_button.Visible = false;
            this.new_character_button.Click += new System.EventHandler(this.new_character_button_Click);
            // 
            // character_list
            // 
            this.character_list.FormattingEnabled = true;
            this.character_list.Location = new System.Drawing.Point(476, 18);
            this.character_list.Name = "character_list";
            this.character_list.Size = new System.Drawing.Size(172, 238);
            this.character_list.Sorted = true;
            this.character_list.TabIndex = 7;
            this.character_list.SelectedIndexChanged += new System.EventHandler(this.character_list_SelectedIndexChanged);
            // 
            // export_xml_button
            // 
            this.export_xml_button.Location = new System.Drawing.Point(518, 372);
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
            // import_photo_button
            // 
            this.import_photo_button.Location = new System.Drawing.Point(267, 168);
            this.import_photo_button.Name = "import_photo_button";
            this.import_photo_button.Size = new System.Drawing.Size(75, 23);
            this.import_photo_button.TabIndex = 19;
            this.import_photo_button.Text = "Import Photo";
            this.import_photo_button.UseVisualStyleBackColor = true;
            this.import_photo_button.Click += new System.EventHandler(this.import_photo_button_Click);
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
            ((System.ComponentModel.ISupportInitialize)(this.character_photo_picture)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button insert_character_button;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox name_id_text;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Button export_xml_button;
        private System.Windows.Forms.ListBox character_list;
        private System.Windows.Forms.Button new_character_button;
        private System.Windows.Forms.Button delete_button;
        private System.Windows.Forms.RichTextBox description_text;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox surname_text;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox last_name_text;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox first_name_text;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox character_photo_picture;
        private System.Windows.Forms.Button import_photo_button;
    }
}

