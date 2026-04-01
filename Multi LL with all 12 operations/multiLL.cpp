#include <iostream>
using namespace std;

struct SNode{
    int SNo;
    SNode* SNext;
};

struct CNode{
    int CNo;
    CNode* CNext;
    SNode* stu_list;
};

CNode* Clist = NULL;
void insert_course(int CNo){
    CNode* tmp = new CNode();
    tmp->CNo = CNo;
    tmp->CNext = NULL;
    tmp->stu_list = NULL;
    
    if(Clist == NULL){
        Clist = tmp;
    }else{
        CNode* ccur = Clist;
        while(ccur->CNext != NULL){
            ccur = ccur->CNext;
        }
        ccur->CNext = tmp;
    }
}

void insert_student(int SNo , int CNo){
    CNode* Ccur = Clist;
    while(Ccur != NULL){
        if(CNo == Ccur->CNo){
            SNode* stmp = new SNode();
            stmp->SNo = SNo;
            stmp->SNext = NULL;
            if(Ccur->stu_list == NULL){
                Ccur->stu_list = stmp;
                return;
            }else{
                SNode* Scur = Ccur->stu_list;
                while(Scur->SNext != NULL){
                    Scur = Scur->SNext;
                }
                    Scur->SNext = stmp;
            }
            return;
        }
        Ccur = Ccur->CNext;
    }
    cout << "Course Not Found!";
}

CNode* search_course(int CNo){
    CNode* ccur = Clist;
    while(ccur->CNext != NULL){
        if(ccur->CNo == CNo){
            return ccur;
        }
        ccur = ccur->CNext;
    }
    return NULL; 
}

void delete_Course(int CNo){
    CNode* ccur = Clist;
    CNode* prev = NULL;
    while(ccur != NULL){
        if(ccur->CNo == CNo){
            SNode* scur = ccur->stu_list;
            while(scur != NULL){
                SNode* tmp = scur;
                scur= scur->SNext;
                delete tmp;
            }
            if(prev == NULL){
                Clist = ccur->CNext;
            }else{
                prev->CNext = ccur->CNext;
            }
            delete ccur;
            return;
        }
        prev = ccur;
        ccur = ccur->CNext;
    }
}


void display_all(){
    CNode* ccur = Clist;
    while(ccur != NULL){
        cout << "Course: " <<ccur->CNo << " -> ";
        SNode* scur = ccur->stu_list;
        while(scur != NULL){
            cout << scur->SNo << " ";
            scur = scur->SNext;
        }
        cout << endl;
        ccur = ccur->CNext;
    }
}


bool search_student_in_course(int SNo, int CNo){
    CNode* course = search_course(CNo);

    if(course == NULL) return false;

    SNode* cur = course->stu_list;

    while(cur != NULL){
        if(cur->SNo == SNo)
            return true;
        cur = cur->SNext;
    }
    return false;
}

void delete_student(int SNo, int CNo){
    CNode* course = search_course(CNo);
    if(course == NULL) return;

    SNode* cur = course->stu_list;
    SNode* prev = NULL;

    while(cur != NULL){
        if(cur->SNo == SNo){

            if(prev == NULL){
                course->stu_list = cur->SNext;
            }else{
                prev->SNext = cur->SNext;
            }

            delete cur;
            return;
        }

        prev = cur;
        cur = cur->SNext;
    }
}


int main() {
    // Add some courses
    insert_course(101);
    insert_course(102);
    insert_course(103);

    // Add students to courses
    insert_student(1, 101);
    insert_student(2, 101);
    insert_student(3, 102);
    insert_student(4, 103);

    cout << "Initial list of courses and students:\n";
    display_all();

    // Search for a student
    cout << "\nSearching for student 2 in course 101...\n";
    if (search_student_in_course(2, 101)) {
        cout << "Student found!\n";
    } else {
        cout << "Student not found.\n";
    }

    // Delete a student
    cout << "\nDeleting student 2 from course 101...\n";
    delete_student(2, 101);
    display_all();

    // Delete a course
    cout << "\nDeleting course 102...\n";
    delete_Course(102);
    display_all();
}
