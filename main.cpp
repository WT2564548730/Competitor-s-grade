#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream win("/Users/WT20181105881/Desktop/tin.txt");
ifstream jin("/Users/WT20181105881/Desktop/fin.txt");
ofstream wout("/Users/WT20181105881/Desktop/tout.txt");

class Person{
    string school,num,name;
    double score[7]={0};
public:
    double sum=0,max=0,min=0,average=0;
    Person(string s,string nu,string na);
    ~Person();
    void display(int i);
};

void show(string judge[]){
    wout<<left<<setw(8)<<"Rank";
    wout<<left<<setw(9)<<"Name"<<left<<setw(15)<<"School"<<left<<setw(15)<<"Num";
    for(int i=0;i<7;i++)
        wout<<left<<setw(10)<<judge[i];
    wout<<left<<setw(8)<<"Average"<<endl;
}

void Person::display(int i){
    wout<<left<<setw(8)<<i+1;
    wout<<left<<setw(9)<<name<<left<<setw(15)<<school<<left<<setw(15)<<num;
    for(int i=0;i<7;i++){
        wout<<left<<setw(10)<<score[i];
    }
    wout<<left<<setw(8)<<average<<endl;
}

Person::Person(string s,string nu,string na):school(s),num(nu),name(na){
    for(int i=0;i<7;i++){
        jin>>score[i];
        sum+=score[i];
        if(i==0){
            max=score[i];
            min=score[i];
        }
        else{
            if(score[i]>max) max=score[i];
            if(score[i]<min) min=score[i];
        }
    }
    sum-=(max+min);
    average=sum/5.0;
}

int main(){
    int n;
    string school,num,name,judge[7];
    win>>n;
    Person *per[n];
    void getJudge();
    for(int i=0;i<7;i++)
        jin>>judge[i];
    for(int i=0;i<n;i++){
        win>>school>>num>>name;
        per[i] = new Person(school,num,name);
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(per[j]->average<per[j+1]->average){
                Person *tper=per[j+1];
                per[j+1]=per[j];
                per[j]=tper;
            }
        }
    }
    show(judge);
    for(int i=0;i<n;i++)
        per[i]->display(i);
}
