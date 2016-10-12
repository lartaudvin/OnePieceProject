using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Database_View
{
    public partial class PopupLogger : Form
    {
        public PopupLogger(string message)
        {
            InitializeComponent();
            this.inner_text.Text = message;
        }

        private void OK_button_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
