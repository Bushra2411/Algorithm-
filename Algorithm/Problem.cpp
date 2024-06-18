#include<iostream>
#include<conio.h>
using namespace std;
struct Student{
       char name[100];
       int age;
       int id;
};

void bsort(struct Student student[],int n)
{
    string temp3;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(student[j].age>student[j+1].age){
                int temp=student[j].age;
                student[j].age=student[j+1].age;
                student[j+1].age=temp;

                int temp2=student[j].id;
                student[j].id=student[j+1].id;
                student[j+1].id=temp2;

                temp3=student[j].name;
                student[j].name=student[j+1].name;
                student[j+1].name=temp3;


            }
        }
    }

     printf("\nAFter sortinggg\n");
    for(int i=0; i<n; i++){
      printf("\nUser Info of %d \n ",i+1);
        //printf("\nname : %s",user[i].name);
        cout<< "Name "<<student[i].name<<"\n";
         //printf("\nage : %d",user[i].age);
          cout<< " Age "<<student[i].age<<"\n";
     //printf("\nID : %d",user[i].id);
      cout<< " ID "<<student[i].id<<"\n";
}
}

int main()
{
    int n;
    scanf("%d",&n);
    struct Student student[n];

    for(int i=0;i<n;i++){
        printf("Enter info of person %d\n",i+1);
        cout<<"enter name:"<<endl;
        cin>>student[i].name;
        cout<<"enter age:"<<endl;
        cin>>student[i].age;
        cout<<"enter id:"<<endl;
        cin>>student[i].id;
    }
 bsort(student,n);

}
