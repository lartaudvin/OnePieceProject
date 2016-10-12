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
        private static extern int insert_character_call(IntPtr ptr, string name, string fullname);
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
        private static extern void set_name_at_call(IntPtr instance, int id, string name);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_fullname_at_call(IntPtr instance, StringBuilder name, int len, int id);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void set_fullname_at_call(IntPtr instance, int id, string fullname);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int get_character_pos_by_name_call(IntPtr instance, string name);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void remove_character_by_name_call(IntPtr instance, string name);

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
        }

        private void insert_character()
        {
            string character_name = this.name_text.Text;
            if(!character_name.Equals(""))
            {
                this.name_text.Text = "";
                string character_fullname = this.fullname_text.Text;
                this.fullname_text.Text = "";
                int result = insert_character_call(m_nativeAccessor_ptr, character_name, character_fullname);
                if (result != -1)
                {
                    updateCharacterList();
                }
            }
        }

        private void modify_character()
        {
            string character_name = this.name_text.Text;
            if (!character_name.Equals(""))
            {
                int pos = get_character_pos_by_name_call(m_nativeAccessor_ptr, character_name);
                set_fullname_at_call(m_nativeAccessor_ptr, pos, this.fullname_text.Text);
                StringBuilder sb = new StringBuilder(50);
                get_fullname_at_call(m_nativeAccessor_ptr, sb, 50, pos);
                string name = sb.ToString();
                Console.Write(name);
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
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            delete_native_accessor(m_nativeAccessor_ptr);
            base.OnClosing(e);
        }

        private void selectCharacter(string name)
        {
            new_character_button.Visible = true;
            m_insert = false;
            insert_character_button.Text = "Modify";
            name_text.ReadOnly = true;
            int pos = get_character_pos_by_name_call(m_nativeAccessor_ptr, name);
            StringBuilder sb = new StringBuilder(50);
            get_name_at_call(m_nativeAccessor_ptr, sb, 50, pos);
            name_text.Text = sb.ToString();
            sb.Clear();
            sb = new StringBuilder(50);
            get_fullname_at_call(m_nativeAccessor_ptr, sb, 50, pos);
            fullname_text.Text = sb.ToString();
            delete_button.Visible = true;
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
            name_text.Text = "";
            fullname_text.Text = "";
            new_character_button.Visible = false;
            name_text.ReadOnly = false;
            delete_button.Visible = false;
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
        }
    }
}
