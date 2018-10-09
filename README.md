# C-Filehandling
C++ File handling Readme file:
The main function contains a switch to add, delete and display records in a file named database.txt.
Add: The credentials are taken from the user and stored in a single long string. To add the record ofstream is used to open the file in append mode to prevent overwriting. By using “file << line << endl” line string is being appended in the file. After that the file is closed.
Delete: To delete the record the database is opened in read mode using ifstream. The function read the file line by line and search for a given string in each line. If the comparison returns false, the string is appended to a temporary file. After the traversal read and write modes are closed and original file is deleted by using remove. At the end name of the temporary file is changed to the name of the original file.
Display: To display the file is opened in read mode using ifstream. The function read the file line by line and display each line on the console.

 
