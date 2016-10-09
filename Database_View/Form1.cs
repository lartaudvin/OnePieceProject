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

        [DllImport("NativeAccessor.dll")]
        public static extern IntPtr create_native_accessor();
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void insert_character_call(IntPtr ptr, string name, string fullname);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void export_xml_call(string path);
        [DllImport("NativeAccessor.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void import_xml_call(string path);

        public Form1()
        {
            InitializeComponent();
            m_nativeAccessor_ptr = create_native_accessor();
        }

        private void insert_character_Click(object sender, EventArgs e)
        {
            string character_name = this.name_text.Text;
            string character_fullname = this.fullname_text.Text;
            insert_character_call(m_nativeAccessor_ptr, character_name, character_fullname);
        }

        private void export_xml_button_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if(fbd.ShowDialog() == DialogResult.OK)
            {
                string folder_path = fbd.SelectedPath;
                export_xml(folder_path);
            }
        }

        private void import_xml_button_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                string folder_path = fbd.SelectedPath;
                import_xml(folder_path);
            }
        }
    }
}
