using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

namespace Database_View
{
    public partial class Form1 : Form
    {
        private IntPtr m_nativeAccessor_ptr;
        private bool m_insert = true;
        private static string DEFAULT_RESOUCES_PATH = "F:\\Users\\Vince\\Documents\\Visual Studio 2015\\Projects\\One Piece Project\\Resources";

        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr create_native_accessor();
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int insert_character_call(IntPtr ptr, string name);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void export_xml_call(IntPtr ptr, string path);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void import_xml_call(IntPtr ptr, string path);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void delete_native_accessor(IntPtr ptr);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int count_characters_call(IntPtr instance);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_name_at_call(IntPtr instance, StringBuilder name, int len, int id);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int get_character_pos_by_name_call(IntPtr instance, string name);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void remove_character_by_name_call(IntPtr instance, string name);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_firstname_at_call(IntPtr instance, int id, StringBuilder firstname, int len);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void set_firstname_at_call(IntPtr instance, int id, string firstname);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_lastname_at_call(IntPtr instance, int id, StringBuilder lastname, int len);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void set_lastname_at_call(IntPtr instance, int id, string lastname);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_surname_at_call(IntPtr instance, int id, StringBuilder surname, int len);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void set_surname_at_call(IntPtr instance, int id, string surname);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_description_at_call(IntPtr instance, int id, StringBuilder description, int len);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void set_description_at_call(IntPtr instance, int id, string description);

        public Form1()
        {
            InitializeComponent();
            m_nativeAccessor_ptr = create_native_accessor();
            PopupLogger logger = new PopupLogger("Please load a root folder for the characters files");
            logger.ShowDialog();
            import_xml();
            this.Activate();
        }

        private void updateCharacterList()
        {
            this.character_list.Items.Clear();
            int id_count = count_characters_call(m_nativeAccessor_ptr);

            for (int i = 0; i < id_count; ++i)
            {
                StringBuilder sb = new StringBuilder(50);
                get_name_at_call(m_nativeAccessor_ptr, sb, 50, i);
                this.character_list.Items.Add(sb.ToString());
                sb.Clear();
            }
            this.setCharacterToNew();
        }

        private void update_database_character(string character_name)
        {
            int pos = get_character_pos_by_name_call(m_nativeAccessor_ptr, character_name);
            string character_firstname = this.first_name_text.Text;
            this.first_name_text.Text = "";
            string character_lastname = this.last_name_text.Text;
            this.last_name_text.Text = "";
            string character_surname = this.surname_text.Text;
            this.first_name_text.Text = "";
            string character_description = this.description_text.Text;
            this.description_text.Text = "";
            if (this.character_photo_picture.Image != null)
            {
                this.character_photo_picture.Image.Dispose();
            }
            set_firstname_at_call(m_nativeAccessor_ptr, pos, character_firstname);
            set_lastname_at_call(m_nativeAccessor_ptr, pos, character_lastname);
            set_surname_at_call(m_nativeAccessor_ptr, pos, character_surname);
            set_description_at_call(m_nativeAccessor_ptr, pos, character_description);
            updateCharacterList();
        }

        private void insert_character()
        {
            string character_name = this.name_id_text.Text;
            if(!character_name.Equals(""))
            {
                this.name_id_text.Text = "";
                int result = insert_character_call(m_nativeAccessor_ptr, character_name);
                if (result != -1)
                {
                    update_database_character(character_name);
                }
                string image_path = DEFAULT_RESOUCES_PATH + "\\Image\\Characters\\" + character_name + ".bmp";
                if (File.Exists(image_path))
                {
                    File.Delete(image_path);
                }
                this.character_photo_picture.Image.Save(image_path, System.Drawing.Imaging.ImageFormat.Bmp);
            }
        }

        private void modify_character()
        {
            string character_name = this.name_id_text.Text;
            if (!character_name.Equals(""))
            {
                string image_path = DEFAULT_RESOUCES_PATH + "\\Image\\Characters\\" + character_name + ".bmp";
                if (File.Exists(image_path))
                {
                    File.Delete(image_path);
                }
                this.character_photo_picture.Image.Save(image_path, System.Drawing.Imaging.ImageFormat.Bmp);
                update_database_character(character_name);
                updateCharacterList();
            }
        }

        private void insert_character_Click(object sender, EventArgs e)
        {
            if(m_insert)
            {
                insert_character();
            }
            else
            {
                modify_character();
            }
        }

        private void export_xml_button_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.SelectedPath = DEFAULT_RESOUCES_PATH + "\\Characters";
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                string folder_path = fbd.SelectedPath;
                export_xml_call(m_nativeAccessor_ptr, folder_path);
            }
        }

        private void import_xml()
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.SelectedPath = DEFAULT_RESOUCES_PATH + "\\Characters";
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                string folder_path = fbd.SelectedPath;
                import_xml_call(m_nativeAccessor_ptr, folder_path);
            }
            updateCharacterList();
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            //remove the image files not inserted in the database
            foreach(var item in  character_list.Items)
            {
                string character_name = (string)item;
                if(get_character_pos_by_name_call(m_nativeAccessor_ptr, character_name) == -1)
                {
                    string image_path = DEFAULT_RESOUCES_PATH + "\\Image\\Characters\\" + character_name + ".bmp";
                    if (File.Exists(image_path))
                    {
                        File.Delete(image_path);
                    }
                }
            }

            delete_native_accessor(m_nativeAccessor_ptr);
            base.OnClosing(e);
        }

        private void selectCharacter(string name)
        {
            new_character_button.Visible = true;
            m_insert = false;
            insert_character_button.Text = "Modify";
            name_id_text.ReadOnly = true;
            int pos = get_character_pos_by_name_call(m_nativeAccessor_ptr, name);
            StringBuilder sb = new StringBuilder(name_id_text.MaxLength);
            get_name_at_call(m_nativeAccessor_ptr, sb, name_id_text.MaxLength, pos);
            name_id_text.Text = sb.ToString();
            sb.Clear();
            sb = new StringBuilder(first_name_text.MaxLength);
            get_firstname_at_call(m_nativeAccessor_ptr, pos, sb, first_name_text.MaxLength);
            first_name_text.Text = sb.ToString();
            sb.Clear();
            sb = new StringBuilder(last_name_text.MaxLength);
            get_lastname_at_call(m_nativeAccessor_ptr, pos, sb, last_name_text.MaxLength);
            last_name_text.Text = sb.ToString();
            sb.Clear();
            sb = new StringBuilder(surname_text.MaxLength);
            get_surname_at_call(m_nativeAccessor_ptr, pos, sb, surname_text.MaxLength);
            surname_text.Text = sb.ToString();
            sb.Clear();
            sb = new StringBuilder(description_text.MaxLength);
            get_description_at_call(m_nativeAccessor_ptr, pos, sb, description_text.MaxLength);
            description_text.Text = sb.ToString();
            delete_button.Visible = true;
            if (this.character_photo_picture.Image != null)
            {
                this.character_photo_picture.Image.Dispose();
                this.character_photo_picture.Image = null;
            }
            string path = DEFAULT_RESOUCES_PATH + "\\Image\\Characters\\" + name + ".bmp";
            if(File.Exists(path))
            {
                this.character_photo_picture.Image = Bitmap.FromFile(path);
            }
        }

        private void character_list_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                selectCharacter(character_list.SelectedItem.ToString());
            }
            catch
            {

            }
        }

        private void setCharacterToNew()
        {
            m_insert = true;
            insert_character_button.Text = "Insert";
            name_id_text.Text = "";
            first_name_text.Text = "";
            last_name_text.Text = "";
            surname_text.Text = "";
            description_text.Text = "";
            new_character_button.Visible = false;
            name_id_text.ReadOnly = false;
            delete_button.Visible = false;
            if (this.character_photo_picture.Image != null)
            {
                this.character_photo_picture.Image.Dispose();
                this.character_photo_picture.Image = null;
            }
        }

        private void new_character_button_Click(object sender, EventArgs e)
        {
            setCharacterToNew();
        }

        private void delete_button_Click(object sender, EventArgs e)
        {
            string name_to_delete = character_list.SelectedItem.ToString();
            remove_character_by_name_call(m_nativeAccessor_ptr, name_to_delete);

            updateCharacterList();
            setCharacterToNew();
            string image_path = DEFAULT_RESOUCES_PATH + "\\Image\\Characters\\" + name_to_delete + ".bmp";
            if(File.Exists(image_path))
            {
                File.Delete(image_path);
            }
        }

        private void import_photo_button_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Image Files (.png, .jpg, .bmp)|*.png; *.jpg; *.bmp";
            if(ofd.ShowDialog() == DialogResult.OK)
            {
                if(this.character_photo_picture.Image != null)
                {
                    this.character_photo_picture.Image.Dispose();
                }
                this.character_photo_picture.Image = Bitmap.FromFile(ofd.FileName);
            }
        }
    }
}
