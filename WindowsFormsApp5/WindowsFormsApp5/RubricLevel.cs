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
    public partial class RubricLevel : Form
    {
        public RubricLevel()
        {
            string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
            InitializeComponent();
            DisplayRubricLevelData();
            List<string> dataSource = new List<string>();
            List<string> dataSource1 = new List<string>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {

                connection.Open();
                SqlCommand command = new SqlCommand("SELECT id from Rubric", connection);
                SqlDataReader reader = command.ExecuteReader();

                // Clear existing items in the combobox
                

                while (reader.Read())
                {
                    // Add each ID to the combobox
                    dataSource.Add(reader["Id"].ToString());
                }
            }
            comboBox1.DataSource = dataSource;
            using (SqlConnection connection = new SqlConnection(connectionString))
            {

                connection.Open();
                SqlCommand command = new SqlCommand("SELECT details from Rubric", connection);
                SqlDataReader reader = command.ExecuteReader();

                // Clear existing items in the combobox


                while (reader.Read())
                {
                    // Add each ID to the combobox
                    dataSource1.Add(reader["Details"].ToString());
                }
            }
            comboBox2.DataSource = dataSource1;


        }




            private void RubricLevel_Load(object sender, EventArgs e)
        {
           

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            // Get the details entered by the user
            string details = textBox1.Text.Trim(); // Trim any leading or trailing whitespace

            // Check if the details are empty
            if (string.IsNullOrWhiteSpace(details))
            {
                // If details are empty, display an error message
                MessageBox.Show("Details cannot be empty. Please enter valid details.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox1.Focus(); // Set focus back to textBox1
                return;
            }

            // Validation passed, you can use the 'details' variable as needed
        }
        

private void DisplayRubricLevelData()
    {
        try
        {
            string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
            string query = "SELECT Rubric.Id AS RubricId, RubricLevel.Details, RubricLevel.MeasurementLevel " +
                           "FROM Rubric " +
                           "INNER JOIN RubricLevel ON Rubric.Id = RubricLevel.RubricId";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(query, connection);
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

                // Clear existing items if any
                // Assuming you have a DataGridView named dataGridView1
                dataGridView1.Rows.Clear();

                // Loop through the rows returned by the query
                while (reader.Read())
                {
                    // Add each row to the DataGridView
                    // Assuming you have three columns: RubricId, Details, and MeasurementLevel
                    dataGridView1.Rows.Add(reader["RubricId"], reader["Details"], reader["MeasurementLevel"]);
                }

                reader.Close();
            }
        }
        catch (Exception ex)
        {
            MessageBox.Show("An error occurred while fetching RubricLevel data: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
        private void button1_Click(object sender, EventArgs e)
        {
            // Get the Rubric Id from the textbox
            int rubricId;
            if (!int.TryParse(comboBox1.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric Id.");
                return;
            }

            // Check if the Rubric Id already exists in the RubricLevel table
            if (RubricIdExists(rubricId))
            {
                MessageBox.Show("Rubric ID already exists. Please enter a unique Rubric ID.");
                return;
            }

            // Get the measurement level entered by the user for RubricLevel
            int measurementLevel;
            if (!int.TryParse(textBox2.Text, out measurementLevel))
            {
                MessageBox.Show("Please enter a valid integer for Measurement Level.");
                return;
            }

            // Get the details entered by the user for RubricLevel
            string rubricLevelDetails = textBox1.Text; // Assuming RubricLevel details are entered in textBox1

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Insert into the RubricLevel table with the RubricId, Details, and MeasurementLevel
                    string insertQuery = "INSERT INTO RubricLevel (RubricId, Details, MeasurementLevel) " +
                                         "VALUES (@RubricId, @Details, @MeasurementLevel)";
                    using (SqlCommand command = new SqlCommand(insertQuery, connection))
                    {
                        command.Parameters.AddWithValue("@RubricId", rubricId);
                        command.Parameters.AddWithValue("@Details", rubricLevelDetails); // Use the details entered by the user
                        command.Parameters.AddWithValue("@MeasurementLevel", measurementLevel);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Rubric level details added successfully for RubricId: " + rubricId);
                            // Refresh the DataGridView to display the updated data
                            DisplayRubricLevelData();
                        }
                        else
                        {
                            MessageBox.Show("Failed to add rubric level details.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        // Function to check if the Rubric Id already exists in the RubricLevel table
        private bool RubricIdExists(int rubricId)
        {
            bool exists = false;
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Check if the Rubric Id exists in the RubricLevel table
                    string selectQuery = "SELECT COUNT(*) FROM RubricLevel WHERE RubricId = @RubricId";
                    using (SqlCommand command = new SqlCommand(selectQuery, connection))
                    {
                        command.Parameters.AddWithValue("@RubricId", rubricId);
                        int count = (int)command.ExecuteScalar();
                        exists = (count > 0);
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while checking if Rubric ID exists: " + ex.Message);
            }
            return exists;
        }



        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void fillByToolStripButton_Click(object sender, EventArgs e)
        {
            try
            {
                this.rubricTableAdapter1.FillBy(this.projectBDataSet7.Rubric);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Get the Rubric ID from the textbox
            int rubricId;
            if (!int.TryParse(comboBox1.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric ID.");
                return;
            }

            
            

            // Get the measurement level entered by the user
            int measurementLevel;
            if (!int.TryParse(textBox2.Text, out measurementLevel))
            {
                MessageBox.Show("Please enter a valid integer for Measurement Level.");
                return;
            }

            // Get the details entered by the user
            string details = textBox1.Text;

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Update the RubricLevel table with the RubricId, Details, and MeasurementLevel
                    string updateQuery = "UPDATE RubricLevel SET Details = @Details, MeasurementLevel = @MeasurementLevel WHERE RubricId = @RubricId";
                    using (SqlCommand command = new SqlCommand(updateQuery, connection))
                    {
                        command.Parameters.AddWithValue("@Details", details);
                        command.Parameters.AddWithValue("@MeasurementLevel", measurementLevel);
                        command.Parameters.AddWithValue("@RubricId", rubricId);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Rubric level details updated successfully for RubricId: " + rubricId);
                            // Refresh the DataGridView to display the updated data
                            DisplayRubricLevelData();
                        }
                        else
                        {
                            MessageBox.Show("Failed to update rubric level details.");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }


        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            // Check if a valid row is clicked (not the header row and within the range of rows)
            if (e.RowIndex >= 0 && e.RowIndex < dataGridView1.Rows.Count - 1)
            {
                // Get the selected row
                DataGridViewRow row = dataGridView1.Rows[e.RowIndex];

                // Extract Rubric ID, Details, and Measurement Level from the selected row
                int rubricId = Convert.ToInt32(row.Cells["RubricIDColumn"].Value);
                string details = row.Cells["DetailsColumn"].Value.ToString();
                int measurementLevel = Convert.ToInt32(row.Cells["MeasurementLevelColumn"].Value);

                // Update the corresponding text boxes with the extracted values
                comboBox1.Text = rubricId.ToString(); // Assuming comboBox1 is used for Rubric ID
                textBox1.Text = details; // Assuming textBox1 is used for Details
                textBox2.Text = measurementLevel.ToString(); // Assuming textBox2 is used for Measurement Level
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // Get the Rubric Id from the textbox
            int rubricId;
            if (!int.TryParse(comboBox1.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric Id.");
                return;
            }

            // Get the measurement level entered by the user for RubricLevel
            int measurementLevel;
            if (!int.TryParse(textBox2.Text, out measurementLevel))
            {
                MessageBox.Show("Please enter a valid integer for Measurement Level.");
                return;
            }

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    // Delete the record from the RubricLevel table based on RubricId and MeasurementLevel
                    string deleteQuery = "DELETE FROM RubricLevel WHERE RubricId = @RubricId AND MeasurementLevel = @MeasurementLevel";
                    using (SqlCommand command = new SqlCommand(deleteQuery, connection))
                    {
                        command.Parameters.AddWithValue("@RubricId", rubricId);
                        command.Parameters.AddWithValue("@MeasurementLevel", measurementLevel);

                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Record deleted successfully for RubricId: " + rubricId + " and Measurement Level: " + measurementLevel);
                            // Refresh the DataGridView to display the updated data
                            DisplayRubricLevelData();
                        }
                        else
                        {
                            MessageBox.Show("No record found for RubricId: " + rubricId + " and Measurement Level: " + measurementLevel);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            // Create an instance of the AddComponent form
            AddComponent addComponentForm = new AddComponent();

            // Show the AddComponent form
            addComponentForm.Show();
        }

    }
}
