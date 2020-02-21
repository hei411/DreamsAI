#include<bits/stdc++.h>
using namespace std;
bool square[10][10];
int inputn, inputk, inputi,inputj, moves, quit;
void show(){
	for(int i=0;i<50;i++){
		cout<<endl;
	}
	cout<<"  ";
	for(int i=0;i<inputn;i++){
		cout<<i<<" ";
	}cout<<endl;
	for(int i=0;i<inputn;i++){
		cout<<i<<" ";
		for(int j=0;j<inputn;j++){
			if(square[i][j]==0){
				cout<<". ";
			}else{
				cout<<"# ";
			}
		}cout<<endl;
	}
}
void home(){
	cout<<"Enter n (Max 10) to play. Enter 0 to exit"<<endl;
	cin>>inputn;
}void resetboard(){
	for(int i=0;i<inputn;i++){
		for(int j=0;j<inputn;j++){
			square[i][j]=0;
		}
	}
}
void setboard(){
	cout<<"Enter 1 to set board manually. Enter 2 to randomize board"<<endl;
	cin>>inputk;
	if(inputk==1){
		resetboard();
		show();
		cout<<"Enter up critter coordinate (0-indexed). Enter -1 -1 to finish"<<endl;
		cin>>inputi>>inputj;
		while(inputi!=-1||inputj!=-1){
			square[inputi][inputj]=1;
			show();
			cout<<"Enter up critter coordinate (0-indexed). Enter -1 -1 to finish"<<endl;
			cin>>inputi>>inputj;
		}
	}else{
		for(int i=0;i<inputn;i++){
			for(int j=0;j<inputn;j++){
				square[i][j]=rand() % 2;
			}
		}
	}
}void ask(){
	cout<<"Please enter which up critter to hit (0-indexed). Enter -1 -1 to exit"<<endl;
	cin>>inputi>>inputj;
	if(inputi==-1||inputj==-1){
		return;
	}
	while(square[inputi][inputj]==0){
		cout<<"Please enter a valid UP critter to hit (0-indexed). Enter -1 -1 to exit"<<endl;
		cin>>inputi>>inputj;
		if(inputi==-1||inputj==-1){
			return;
		}
	}
}
void toggle(){
	square[inputi][inputj]=!square[inputi][inputj];
	if(inputi!=0){
		square[inputi-1][inputj]=!square[inputi-1][inputj];
	}if(inputj!=0){
		square[inputi][inputj-1]=!square[inputi][inputj-1];
	}if(inputi!=inputn-1){
		square[inputi+1][inputj]=!square[inputi+1][inputj];
	}if(inputj!=inputn-1){
		square[inputi][inputj+1]=!square[inputi][inputj+1];
	}
}int check(){
	for(int i=0;i<inputn;i++){
		for(int j=0;j<inputn;j++){
			if(square[i][j]==1){
				return 1;
			}
		}
	}return 0;
}
void play(){
	if(inputn==0){
		quit=1;
		return;
	}moves=0;
	setboard();
	show();
	while(check()){
		ask();
		if(inputi==-1||inputj==-1){
			break;
		}moves++;
		toggle();
		show();
	}
	if(check()){
		cout<<"Sorry, you lost"<<endl;
	}else{
		cout<<"Congrats, you won in "<<moves<<" moves"<<endl;
	}
	
}
int main(){
	while(!quit){
		home();
		play();
	}
	
}
