#include<iostream>
#include<fstream>
using namespace std;

class Student{
    private:
       int Marks[5];
    public:
      string Name;
      int RollNum;
      int TotalM=0;
      float AvgM;
      string grade;
      void setMarks(){
          cout<<"Enter 5 Marks:";
         for(int i=0;i<5;i++){
             cin>>Marks[i];
         }
       }

       void calculateTotal(){
           for(int i=0;i<5;i++){
               TotalM+=Marks[i];
           }
       }

       void calculateAvg(){
           AvgM=TotalM/5.0;
       }

       void findGrade(){

           if(AvgM>91&&AvgM<100){
               grade="A+";
           }else if(AvgM>=81&&AvgM<=90){
               grade="A";
           }else if(AvgM>=71&&AvgM<=80){
               grade="B+";
           }else if(AvgM>=61&&AvgM<=70){
               grade="B";
           }
           else if(AvgM>=51&&AvgM<=60){
               grade="C";
           }
           else if(AvgM>=41&&AvgM<=50){
               grade="D";
           }
           else if(AvgM<=40&&AvgM>=0){
               grade="Fail";
           }

       }

       void displayReportCard(){
           cout<<"----------------------------------\n    STUDENT REPORT CARD  \n----------------------------------\n";
           cout<<"       Name: ";
           cout<<Name;
           cout<<"\n       Roll.NO: ";
           cout<<RollNum;
           cout<<"\n----------------------------------\n";
           cout<<"      Subject-Wise Marks: ";
           cout<<"\n----------------------------------\n";
           for(int i=0;i<5;i++){
           cout<<"       Subject Marks "<<i+1<<":"<<Marks[i]<<" "<<endl;
           }
           cout<<"\n----------------------------------\n";
           cout<<"       Total: ";
           cout<<TotalM;
           cout<<"\n       Average: ";
           cout<<AvgM;
           cout<<"\n       Grade: ";
           cout<<grade;
           cout<<"\n----------------------------------\n";
           cout<<"      Result: ";
           if(grade!="Fail"){
               cout<<"Pass";
           }else{
               cout<<"Fail";
           }
           cout<<"\n----------------------------------\n";
       }

       void saveToFile(ofstream &f){
           f<<"----------------------------------\n    STUDENT REPORT CARD  \n----------------------------------\n";
           f<<"       Name: ";
           f<<Name;
           f<<"\n       Roll.NO: ";
           f<<RollNum;
           f<<"\n----------------------------------\n";
           f<<"      Subject-Wise Marks: ";
           f<<"\n----------------------------------\n";
           for(int i=0;i<5;i++){
           f<<"       Subject Marks "<<i+1<<":"<<Marks[i]<<" "<<endl;
           }
           f<<"\n----------------------------------\n";
           f<<"       Total: ";
           f<<TotalM;
           f<<"\n       Average: ";
           f<<AvgM;
           f<<"\n       Grade: ";
           f<<grade;
           f<<"\n----------------------------------\n";
           f<<"      Result: ";
           if(grade!="Fail"){
               f<<"Pass";
           }else{
               f<<"Fail";
           }
           f<<"\n----------------------------------\n";
       }


};



int main(){
    ofstream MyFile("Students Data.txt");
    int n;
    cout<<"Enter the Number of students: ";
    cin>>n;
   Student s1[n];
   for(int i=0;i<n;i++){
   cout<<"Enter Your Name: ";
   cin>>s1[i].Name;
   cout<<"Enter Your Roll Number: ";
   cin>>s1[i].RollNum;
   s1[i].setMarks();
   s1[i].calculateTotal();
   s1[i].calculateAvg();
   s1[i].findGrade();
   s1[i].displayReportCard();
   s1[i].saveToFile(MyFile);

   }
    MyFile.close();
}
