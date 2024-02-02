#include <iostream>
using namespace std;
const int  Num_Pupil=5;
double weightFirstDay[Num_Pupil];
double weightLastDay[Num_Pupil];
string Name[Num_Pupil];
double diff;

void getInfo(){
    for (int i=0;i<Num_Pupil;i++){
   	   cout<<"Enter the name of pupil "<< i+1<<" : ";
       cin>>Name[i];
       cout<<"Enter the weight of pupil "<< i+1<<" : ";
       cin>>weightFirstDay[i];
       while(weightFirstDay[i] < 0 || weightFirstDay[i] > 300){
            cout<<"Invalid weight. Please enter the valid weight of pupil "<< i+1<<" \n ";
	        cin>>weightFirstDay[i];
	      }
    }
}

void showDisplay(){
    for (int i=0;i<Num_Pupil;i++){
	    cout<<"Name is "<<Name[i]<<" , Weight is "<<weightFirstDay[i]<<"kg"<<"\n";
    }
}

void updatedWeight(){
    for(int i=0;i<Num_Pupil;i++){
        cout<<"\nEnter the weight of "<< Name[i] <<" : ";
        cin>>weightLastDay[i];
    }
}

void calDiff(){
    for (int i=0 ; i<Num_Pupil ; i++){
        if (weightFirstDay[i] > weightLastDay[i]){
            diff = weightFirstDay[i] - weightLastDay[i];
            if (diff >= 2.5){
            cout<<Name[i]<<"'s weight is decreased "<<diff<<"kg"<<endl;
            }
        }
        if (weightFirstDay[i] < weightLastDay[i]){
            diff = weightLastDay[i] - weightFirstDay[i];
            if (diff >= 2.5){
            cout<<Name[i]<<"'s weight is increased  "<<diff<<"kg"<<endl;
            }
        }
    }
}
int main() {
	cout<<"......................... \n";
	cout<<"First Term Day \n";
	cout<<".........................\n";
    getInfo();
    cout<<"\n";
    showDisplay();
    cout<<"\n";
	cout<<"......................... \n";
	cout<<"Last Term Day \n";
	cout<<".........................\n";
    updatedWeight();
    cout<<"\n";
    calDiff();
    cout<<"\n";
	return 0;
}
