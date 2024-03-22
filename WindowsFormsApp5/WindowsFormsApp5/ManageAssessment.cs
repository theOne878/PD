using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WindowsFormsApp5
{
    public partial class ManageAssessment : Form
    {
        public ManageAssessment()
        {
            InitializeComponent();
            DisplayAssessmentData();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string title = textBox1.Text;

            int totalmarks;
            if (int.TryParse(textBox2.Text, out totalmarks))
            {
                // Successfully parsed to integer
            }
            else
            {
                // Error handling for invalid input
                MessageBox.Show("Please enter a valid integer for total marks.");
            }

            int totalweightage;
            if (int.TryParse(textBox3.Text, out totalweightage))
            {
                // Successfully parsed to integer
            }
            else
            {
                // Error handling for invalid input
                MessageBox.Show("Please enter a valid integer for total weightage.");
            }
            
            AddAssessment(title,totalmarks, totalweightage);
            DisplayAssessmentData();


        }
        private void AddAssessment(string title, int totalMarks, int totalWeightage)
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    string insertQuery = "INSERT INTO Assessment (Title, DateCreated, TotalMarks, TotalWeightage) VALUES (@Title, @DateCreated, @TotalMarks, @TotalWeightage)";
                    using (SqlCommand command = new SqlCommand(insertQuery, connection))
                    {
                        command.Parameters.AddWithValue("@Title", title);
                        command.Parameters.AddWithValue("@DateCreated", DateTime.Now); // Use current date and time
                        command.Parameters.AddWithValue("@TotalMarks", totalMarks);
                        command.Parameters.AddWithValue("@TotalWeightage", totalWeightage);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Assessment data has been added successfully.");
                        }
                        else
                        {
                            MessageBox.Show("Failed to add assessment data.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void DisplayAssessmentData()
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    string selectQuery = "SELECT Title, DateCreated, TotalMarks, TotalWeightage FROM Assessment";
                    SqlDataAdapter adapter = new SqlDataAdapter(selectQuery, connection);
                    DataTable dataTable = new DataTable();
                    adapter.Fill(dataTable);

                    // Clear existing columns
                    dataGridView1.Columns.Clear();

                    dataGridView1.DataSource = dataTable;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string title = textBox1.Text;
            DeleteAssessmentByTitle(title);
            DisplayAssessmentData();
        }
        private void DeleteAssessmentByTitle(string title)
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    string deleteQuery = "DELETE FROM Assessment WHERE Title = @Title";
                    using (SqlCommand command = new SqlCommand(deleteQuery, connection))
                    {
                        command.Parameters.AddWithValue("@Title", title);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show($"Assessment data with title '{title}' has been deleted successfully.");
                        }
                        else
                        {
                            MessageBox.Show($"No assessment data found with title '{title}'.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
            DisplayAssessmentData();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string titleToUpdate = textBox1.Text;
            int newTotalMarks;
            int newTotalWeightage;

            // Parse the new total marks
            if (!int.TryParse(textBox2.Text, out newTotalMarks))
            {
                MessageBox.Show("Please enter a valid integer for new total marks.");
                return;
            }

            // Parse the new total weightage
            if (!int.TryParse(textBox3.Text, out newTotalWeightage))
            {
                MessageBox.Show("Please enter a valid integer for new total weightage.");
                return;
            }

            // Call the UpdateAssessment method
            UpdateAssessment(titleToUpdate, newTotalMarks, newTotalWeightage);

        }
        private void UpdateAssessment(string title, int newTotalMarks, int newTotalWeightage)
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Check if the assessment with the provided title exists
                    string selectQuery = "SELECT COUNT(*) FROM Assessment WHERE Title = @Title";
                    using (SqlCommand command = new SqlCommand(selectQuery, connection))
                    {
                        command.Parameters.AddWithValue("@Title", title);
                        int count = (int)command.ExecuteScalar();

                        if (count == 0)
                        {
                            MessageBox.Show($"No assessment data found with title '{title}'.");
                            return;
                        }
                    }

                    // Update the total marks and total weightage
                    string updateQuery = "UPDATE Assessment SET TotalMarks = @TotalMarks, TotalWeightage = @TotalWeightage WHERE Title = @Title";
                    using (SqlCommand command = new SqlCommand(updateQuery, connection))
                    {
                        command.Parameters.AddWithValue("@TotalMarks", newTotalMarks);
                        command.Parameters.AddWithValue("@TotalWeightage", newTotalWeightage);
                        command.Parameters.AddWithValue("@Title", title);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show($"Assessment data with title '{title}' has been updated successfully.");
                        }
                        else
                        {
                            MessageBox.Show($"Failed to update assessment data with title '{title}'.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
            DisplayAssessmentData();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            ManageAssessment form1 = new ManageAssessment();

            // Show the new instance of Form1
            form1.Show();

            // Close the current form
            this.Close();
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            AddComponent form2 = new AddComponent();

            // Show Form2 as a dialog (modal)
            form2.ShowDialog();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            ManageRubrics manageRubricsForm = new ManageRubrics();

            // Display the ManageRubrics form
            manageRubricsForm.Show();
        }
    }
}
