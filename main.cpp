//
//  main.cpp
//  Competitor's grade
//
//  Created by W20181105881 on 2019/6/19.
//  Copyright © 2019 W20181105881. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class compet{
    protected:
        string name,school,num;
    public:
        compet(string s,string nu,string na):school(s),num(nu),name(na){}
        ~compet();
        void average();
        void max();
        void min();
};

/*class judge:public compet{
    private:
        string judgename;
        int score;
    public:
        judge(string j,int s):judgename(j),score(s){}
    
    
};*/


int main() {
    ofstream wout("/Users/WT20181105881/Desktop/tout.txt");
    ifstream win("/Users/WT20181105881/Desktop/tin.txt");
    ifstream jin("/Users/WT20181105881/Desktop/fin.txt");
    if(win.is_open()){
        int i=0;
        compet *per[3];
        while(i<3){
            float score[3][7];
            string *name,*judge,*school,*num;
            win>>school[i]>>num[i]>>name[i];        //学院，编号，姓名
            per[i]=new compet(school[i],num[i],name[i]);
            if(jin.is_open()){      //裁判和打分
                for(int j=0;j<7;j++){
                    jin>>judge[i];
                }
            }
            
            
            
        }
    }
    
    return 0;
}
