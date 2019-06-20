//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ofstream wout("/Users/WT20181105881/Desktop/tout.txt");
ifstream win("/Users/WT20181105881/Desktop/tin.txt");
ifstream jin("/Users/WT20181105881/Desktop/fin.txt");

class compet{
    private:
        string name,school,num;
    public:
        compet(string s,string nu,string na):school(s),num(nu),name(na){}
        ~compet();
        void display();
};

void compet::display(){
    wout<<school<<" "<<num<<" "<<name<<endl;
}

int main() {
    compet *per[3];
    
    if(win.is_open()){          //学院，编号，姓名
        string name[3],school[3],num[3];
        for(int i=0;i<3;i++){
            win>>school[i]>>num[i]>>name[i];
            per[i]=new compet(school[i],num[i],name[i]);
        }
    }
    
    string judgename[3];
    float score[7][3];
    float max=0,min=0,sum[3],average[3];
    
    if(jin.is_open()){          //裁判和打分
        for(int i=0;i<7;i++){
            jin>>judgename[i];
            for(int j=0;j<3;j++){
                jin>>score[i][j];
            }
        }
        
        for(int i=0;i<3;i++){
            sum[i]=0;
            for(int j=0;j<7;j++){
                if(j==0){
                    max=score[j][i];
                    min=score[j][i];
                }
                else{
                    if(score[j][i]>max) max=score[j][i];
                    if(score[j][i]<min) min=score[j][i];
                }
                sum[i]+=score[j][i];
            }
            sum[i]-=(max+min);
            average[i]=sum[i]/5.0;
        }
    }
    
    for(int i=0;i<3;i++){
        per[i]->display();
        for(int j=0;j<7;j++){
            wout<<judgename[j]<<" : "<<score[j][i];
            if(j!=6)    wout<<" ";
        }
        wout<<" average = "<<average[i]<<endl;
        wout<<endl;
    }
    
    return 0;
}
