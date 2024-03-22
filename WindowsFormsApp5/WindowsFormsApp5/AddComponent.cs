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
    public partial class AddComponent : Form
    {
        public class AssessmentComponent
        {
            public int Id { get; set; }
            public string Name { get; set; }
            public int RubricId { get; set; }
            public int AssessmentId { get; set; }
            // Other properties...
        }

        public AddComponent()
        {
            InitializeComponent();
            DisplayAssessmentComponentData();
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                string selectQuery = "SELECT Id FROM rubric";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(selectQuery, connection);
                    connection.Open();

                    SqlDataReader reader = command.ExecuteReader();

                    // Clear existing items in the combobox
                    comboBox2.Items.Clear();

                    while (reader.Read())
                    {
                        // Add each RubricId to the combobox
                        comboBox2.Items.Add(reader["Id"].ToString());
                    }

                    reader.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            ManageAssessment form1 = new ManageAssessment();

            // Show Form1
            form1.Show();

            // Hide the current form (Form2)
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Get input data from the user
            string name = textBox1.Text.ToLower(); // Convert name to lowercase
            int rubricId;
            if (!int.TryParse(comboBox2.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric ID.");
                return;
            }
            int totalMarks;
            if (!int.TryParse(textBox2.Text, out totalMarks))
            {
                MessageBox.Show("Please enter a valid integer for Total Marks.");
                return;
            }
            DateTime dateUpdated = DateTime.Now;
            int assessmentId;
            if (!int.TryParse(comboBox1.Text, out assessmentId))
            {
                MessageBox.Show("Please enter a valid integer for Assessment ID.");
                return;
            }

            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                string query = "UPDATE AssessmentComponent SET RubricId = @RubricId, TotalMarks = @TotalMarks, DateUpdated = @DateUpdated, AssessmentId = @AssessmentId " +
                               "WHERE Name = @Name";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@RubricId", rubricId);
                    command.Parameters.AddWithValue("@TotalMarks", totalMarks);
                    command.Parameters.AddWithValue("@DateUpdated", dateUpdated);
                    command.Parameters.AddWithValue("@AssessmentId", assessmentId);
                    command.Parameters.AddWithValue("@Name", name);

                    connection.Open();
                    int rowsAffected = command.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        MessageBox.Show("Assessment Component updated successfully.");
                        // Refresh the display of AssessmentComponent data
                        DisplayAssessmentComponentData();
                    }
                    else
                    {
                        MessageBox.Show("Assessment Component with the given name does not exist.");
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }




        // Function to retrieve an Assessment Component by name
        private AssessmentComponent GetAssessmentComponentByName(string name)
        {
            string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
            string query = "SELECT * FROM AssessmentComponent WHERE LOWER(Name) = @Name";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", name);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    return new AssessmentComponent
                    {
                        Id = Convert.ToInt32(reader["Id"]),
                        RubricId = Convert.ToInt32(reader["RubricId"]),
                        AssessmentId = Convert.ToInt32(reader["AssessmentId"])
                    };
                }
                else
                {
                    return null; // No Assessment Component found with the provided name
                }
            }
        }

        // Function to update Rubric ID and Assessment ID of an Assessment Component
        private void UpdateAssessmentComponent(int id, int rubricId, int assessmentId)
        {
            string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
            string query = "UPDATE AssessmentComponent SET RubricId = @RubricId, AssessmentId = @AssessmentId WHERE Id = @Id";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@RubricId", rubricId);
                command.Parameters.AddWithValue("@AssessmentId", assessmentId);
                command.Parameters.AddWithValue("@Id", id);

                connection.Open();
                command.ExecuteNonQuery();
            }
        }

        private bool IsDuplicateName(string newName, int rubricId)
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                string query = "SELECT COUNT(*) FROM AssessmentComponent WHERE LOWER(Name) = @NewName AND RubricId = @RubricId";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@NewName", newName);
                    command.Parameters.AddWithValue("@RubricId", rubricId);

                    connection.Open();
                    int count = (int)command.ExecuteScalar();

                    // If count is greater than 1, it means the name already exists for the given RubricId
                    return count > 1;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
                return false;
            }
        }


        private void button2_Click(object sender, EventArgs e)
        {
            // Get the name from the user input
            string name = textBox1.Text.ToLower(); // Convert name to lowercase

            // Check if the name is provided
            if (string.IsNullOrWhiteSpace(name))
            {
                MessageBox.Show("Please enter the name to delete.");
                return;
            }

            // Check if the AssessmentComponent with the given name exists
            string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
            string query = "SELECT COUNT(*) FROM AssessmentComponent WHERE LOWER(Name) = @Name";

            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@Name", name);

                    connection.Open();
                    int count = (int)command.ExecuteScalar();

                    if (count == 0)
                    {
                        MessageBox.Show("Assessment Component with the provided name does not exist.");
                        return;
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
                return;
            }

            // Delete the AssessmentComponent with the provided name
            query = "DELETE FROM AssessmentComponent WHERE LOWER(Name) = @Name";

            try
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@Name", name);

                    connection.Open();
                    int rowsAffected = command.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        MessageBox.Show("Assessment Component deleted successfully.");
                        // Refresh the display of AssessmentComponent data
                        DisplayAssessmentComponentData();
                    }
                    else
                    {
                        MessageBox.Show("Failed to delete Assessment Component.");
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }




        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }


        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }
        public void DisplayAssessmentComponentData()
        {
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                string query = "SELECT * FROM AssessmentComponent";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    connection.Open();

                    SqlDataReader reader = command.ExecuteReader();

                    // Clear existing data in the DataGridView
                    dataGridView1.Rows.Clear();

                    // Display the data in the DataGridView
                    while (reader.Read())
                    {
                        dataGridView1.Rows.Add(
                            
                            reader["Name"],
                            reader["RubricId"],
                            reader["TotalMarks"],
                            
                            
                            reader["DateCreated"],
                            reader["DateUpdated"],
                            reader["AssessmentId"]
                        );
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while retrieving AssessmentComponent data: " + ex.Message);
            }
        }

        private void AddComponent_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'projectBDataSet9.Assessment' table. You can move, or remove it, as needed.
            this.assessmentTableAdapter1.Fill(this.projectBDataSet9.Assessment);
            // TODO: This line of code loads data into the 'projectBDataSet8.Rubric' table. You can move, or remove it, as needed.
            this.rubricTableAdapter.Fill(this.projectBDataSet8.Rubric);
            // TODO: This line of code loads data into the 'projectBDataSet1.Assessment' table. You can move, or remove it, as needed.
            this.assessmentTableAdapter.Fill(this.projectBDataSet1.Assessment);

        }

        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            RubricLevel rubricLevelForm = new RubricLevel();

            // Show the RubricLevel form
            rubricLevelForm.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            // Get input data from the user
            string name = textBox1.Text.ToLower(); // Convert name to lowercase
            int rubricId;
            if (!int.TryParse(comboBox2.Text, out rubricId))
            {
                MessageBox.Show("Please enter a valid integer for Rubric ID.");
                return;
            }
            int totalMarks;
            if (!int.TryParse(textBox2.Text, out totalMarks))
            {
                MessageBox.Show("Please enter a valid integer for Total Marks.");
                return;
            }
            DateTime dateCreated = DateTime.Now;
            DateTime dateUpdated = DateTime.Now;
            int assessmentId;
            if (!int.TryParse(comboBox1.Text, out assessmentId))
            {
                MessageBox.Show("Please enter a valid integer for Assessment ID.");
                return;
            }

            // Check if the combination of name, rubricId, and assessmentId already exists
            if (AssessmentComponentExists(name))
            {
                MessageBox.Show("Assessment Component with the same Name already exists.");
                return;
            }

            // Insert data into the AssessmentComponent table
            try
            {
                string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
                string query = "INSERT INTO AssessmentComponent (Name, RubricId, TotalMarks, DateCreated, DateUpdated, AssessmentId) " +
                               "VALUES (@Name, @RubricId, @TotalMarks, @DateCreated, @DateUpdated, @AssessmentId)";

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@Name", name);
                    command.Parameters.AddWithValue("@RubricId", rubricId);
                    command.Parameters.AddWithValue("@TotalMarks", totalMarks);
                    command.Parameters.AddWithValue("@DateCreated", dateCreated);
                    command.Parameters.AddWithValue("@DateUpdated", dateUpdated);
                    command.Parameters.AddWithValue("@AssessmentId", assessmentId);

                    connection.Open();
                    int rowsAffected = command.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        MessageBox.Show("Assessment Component added successfully.");
                        // Refresh the display of AssessmentComponent data
                        DisplayAssessmentComponentData();
                    }
                    else
                    {
                        MessageBox.Show("Failed to add Assessment Component.");
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
            }
        }

        // Function to check if an Assessment Component with the same Name, Rubric ID, and Assessment ID already exists
        private bool AssessmentComponentExists(string name)
        {
            string connectionString = "Data Source=THEONE;Initial Catalog=ProjectB;Integrated Security=True";
            string query = "SELECT COUNT(*) FROM AssessmentComponent WHERE LOWER(Name) = @Name";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", name);
                

                connection.Open();
                int count = (int)command.ExecuteScalar();

                return count > 0;
            }
        }

    }
}
