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

namespace WindowsFormsApp5
{
    public partial class ManageRubrics : Form
    {
        public ManageRubrics()
        {
            InitializeComponent();
            DisplayRubricData();
            
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

        }

        private void ManageRubrics_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'projectBDataSet2.Clo' table. You can move, or remove it, as needed.
            this.cloTableAdapter.Fill(this.projectBDataSet2.Clo);

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void DisplayRubricData()
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                string selectQuery = "SELECT Id, Details, CloId FROM Rubric";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(selectQuery, connection);
                    connection.Open();

                    SqlDataReader reader = command.ExecuteReader();

                    // Clear existing data in the DataGridView
                    dataGridView1.Rows.Clear();

                    while (reader.Read())
                    {
                        // Retrieve data from the reader
                        int rubricId = (int)reader["Id"];
                        
                        string details = reader["Details"].ToString();
                        int cloId = (int)reader["CloId"];

                        // Add the data to the DataGridView
                        dataGridView1.Rows.Add(rubricId, details, cloId);
                    }

                    reader.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }
        // In your form load event or constructor
        private void Form_Load(object sender, EventArgs e)
        {
            // Bind ComboBox to Clo data source
            comboBox1.DisplayMember = "Name"; // Display the Clo names
            comboBox1.ValueMember = "Id";     // Store the CloIds
            comboBox1.DataSource = GetCloData(); // Get data from your Clo table
        }

        // Function to retrieve Clo data (replace this with your actual data retrieval method)
        private DataTable GetCloData()
        {
            DataTable dataTable = new DataTable();
            // Replace this with your actual SQL query to fetch Clo data
            // Example:
            // string query = "SELECT Id, Name FROM Clo";
            // Use SqlDataAdapter to fill the DataTable from your SQL query result
            // SqlDataAdapter adapter = new SqlDataAdapter(query, connectionString);
            // adapter.Fill(dataTable);
            return dataTable;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            // Get the selected CloId from the ComboBox
            int selectedCloId = 0;
            if (comboBox1.SelectedItem != null)
            {
                DataRowView rowView = comboBox1.SelectedItem as DataRowView;
                if (rowView != null)
                {
                    selectedCloId = Convert.ToInt32(rowView["Id"]);
                }
            }

            // Get the details entered by the user
            string details = textBox2.Text.Trim(); // Trim any leading or trailing whitespace

            // Check if details are provided
            if (string.IsNullOrWhiteSpace(details))
            {
                MessageBox.Show("Please enter details for the rubric.");
                return;
            }

            // Get the Rubric Id from the textbox
            int rubricId;
            if (!int.TryParse(textBox1.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric Id.");
                return;
            }

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();
                    // Insert into the Rubric table with the selected CloId and other details
                    string insertQuery = "INSERT INTO Rubric (Id, CloId, Details) VALUES (@Id, @CloId, @Details)";
                    using (SqlCommand command = new SqlCommand(insertQuery, connection))
                    {
                        command.Parameters.AddWithValue("@Id", rubricId);
                        command.Parameters.AddWithValue("@CloId", selectedCloId);
                        command.Parameters.AddWithValue("@Details", details);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Rubric added successfully and assigned to CloId: " + selectedCloId);
                            // Refresh the DataGridView to display the updated data
                            DisplayRubricData();
                        }
                        else
                        {
                            MessageBox.Show("Failed to add rubric.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Get the Rubric Id from the textbox
            int rubricId;
            if (!int.TryParse(textBox1.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric Id.");
                return;
            }

            // Get the selected CloId from the ComboBox
            int selectedCloId = 0;
            if (comboBox1.SelectedItem != null)
            {
                DataRowView rowView = comboBox1.SelectedItem as DataRowView;
                if (rowView != null)
                {
                    selectedCloId = Convert.ToInt32(rowView["Id"]);
                }
            }

            // Get the details entered by the user
            string details = textBox2.Text.Trim(); // Trim any leading or trailing whitespace

            // Check if details are provided
            if (string.IsNullOrWhiteSpace(details))
            {
                MessageBox.Show("Please enter details for the rubric.");
                return;
            }

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Update the CloId and Details for the specified RubricId
                    string updateQuery = "UPDATE Rubric SET CloId = @CloId, Details = @Details WHERE Id = @Id";
                    using (SqlCommand command = new SqlCommand(updateQuery, connection))
                    {
                        command.Parameters.AddWithValue("@CloId", selectedCloId);
                        command.Parameters.AddWithValue("@Details", details); // Use the details entered by the user
                        command.Parameters.AddWithValue("@Id", rubricId);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("CloId and Details updated successfully for RubricId: " + rubricId);
                            // Refresh the DataGridView to display the updated data
                            DisplayRubricData();
                        }
                        else
                        {
                            MessageBox.Show("Failed to update CloId and Details for rubric.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // Get the Rubric Id from the textbox
            int rubricId;
            if (!int.TryParse(textBox1.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric Id.");
                return;
            }

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Delete the record from the Rubric table where RubricId matches
                    string deleteQuery = "DELETE FROM Rubric WHERE Id = @Id";
                    using (SqlCommand command = new SqlCommand(deleteQuery, connection))
                    {
                        command.Parameters.AddWithValue("@Id", rubricId);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Record deleted successfully for RubricId: " + rubricId);
                            // Refresh the DataGridView to display the updated data
                            DisplayRubricData();
                        }
                        else
                        {
                            MessageBox.Show("No record found for RubricId: " + rubricId);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            // Create an instance of the RubricLevel form
            RubricLevel rubricLevelForm = new RubricLevel();

            // Show the RubricLevel form
            rubricLevelForm.Show();
        }

    }
}
