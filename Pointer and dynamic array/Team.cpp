#include "Team.h"

Team::Team() {
    studentInfo = nullptr;
    teamMember = 0;
}
Team::~Team()
{
	delete[] studentInfo;
}
void Team::print() {
    if (teamMember != 0) {
        cout << "TeamName = " << teamName << endl;
        cout << "Team# = " << teamMember << endl;
        for (int i = 0; i < teamMember; i++) {
            cout << studentInfo[i].name << " " << studentInfo[i].grade << endl;
        }
    }
}
    // function shift all element of right
 // side from given index in left
void Team::removeStudent(int index)
{
        if (teamMember > 0)
        {
            for (int i = index; i < teamMember - 1; i++)
            {

                // shift all element of right 
                // side from given index in left
                studentInfo[i] = studentInfo[i + 1];
            }
            studentInfo[teamMember - 1].grade = NULL;
            studentInfo[teamMember - 1].name = "";
            teamMember--;
            shrinkSize();
        }
}
void Team::shrinkSize() 
{
    Student* temp = nullptr;

    if (teamMember > 0)
    {

        // temp is a count size array
        // and store array elements
        temp = new Student[teamMember];
        for (int i = 0; i < teamMember; i++)
        {

            // copy all array value into temp
            temp[i] = studentInfo[i];
        }
        // count size array temp initialize 
        // into variable array again
        studentInfo = temp;
    }

}

void Team::find_smallest()
{
    string lname = studentInfo[0].name;
    double smallest = studentInfo[0].grade;
    int index = 0;
    for (int i = 0; i < teamMember; ++i)
    {
        if (studentInfo[i].grade < smallest && studentInfo != nullptr)
        {
            index = i;
            lname = studentInfo[i].name;
            smallest = studentInfo[i].grade;
        } // if
    } // for
   
    if (teamMember != 0) {
        cout << "lowest grade student =" << lname << " grade = " << smallest << " for team " << teamName << endl << endl;
        removeStudent(index);
    }
}
   
