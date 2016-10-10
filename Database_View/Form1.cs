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

        private void insert_character_Click(object sender, EventArgs e)
        {
            string character_name = this.name_text.Text;
            this.name_text.Text = "";
            string character_fullname = this.fullname_text.Text;
            this.fullname_text.Text = "";
            int result = insert_character_call(m_nativeAccessor_ptr, character_name, character_fullname);
            if(result != -1)
            {
                updateCharacterList();
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
    }
}
