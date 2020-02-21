#include<bits/stdc++.h>
using namespace std;
int n, inputi, inputj;
vector<vector<bool> > target,current; 
map<vector<vector<bool> >,int > visited, dist;
map<vector<vector<bool> > ,pair<int,int> > prev;
queue<vector<vector<bool> > >toexplore;
void show(vector<vector<bool> > v,int clearscreen){
	if(clearscreen){
		for(int i=0;i<40;i++){
			cout<<endl;
		}
	}
	cout<<"  ";
	for(int i=0;i<n;i++){
		cout<<i<<" ";
	}cout<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<" ";
		for(int j=0;j<n;j++){
			if(v[i][j]==0){
				cout<<". ";
			}else{
				cout<<"# ";
			}
		}cout<<endl;
	}
}
bool isfinal(vector<vector<bool> > v){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]==1){
				return 0;
			}
		}
	}return 1;
}
vector<vector<bool> >  toggle(vector<vector<bool> >v, int i, int j){
	vector<vector<bool> > now=v;
	now[i][j]=!now[i][j];
	if(i!=0){
		now[i-1][j]=!now[i-1][j];
	}if(j!=0){
		now[i][j-1]=!now[i][j-1];
	}if(i!=n-1){
		now[i+1][j]=!now[i+1][j];
	}if(j!=n-1){
		now[i][j+1]=!now[i][j+1];
	}
	return now;
}
void exhaust(vector<vector<bool> > v){
	vector<vector<bool> > now;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]==true){
				now=toggle(v,i,j);
				if(visited[now]==0){
					visited[now]=1;
					dist[now]=dist[v]+1;
					prev[now]=make_pair(i,j);
					toexplore.push(now);
				}
			}			
		}
	}
}

int main(){
	
	cout<<"Insert n (suggested to be less than or equal to 4)"<<endl;
	cin>>n;
	vector<bool> v1(n);
	vector<vector<bool> > start (n,v1);
	target=start;
	vector<vector<bool> >v;
	show(start,1);
	cout<<"Insert coordinates of up critter. Insert -1 -1 to end"<<endl;
	cin>>inputi>>inputj;
	while(inputi!=-1&&inputj!=-1){
		start[inputi][inputj]=1;
		show(start,1);
		cout<<"Insert coordinates of up critter. Insert -1 -1 to end"<<endl;
		cin>>inputi>>inputj;
	}
	visited[start]=1;
	toexplore.push(start);
	while(toexplore.size()!=0){
		v=toexplore.front();
		//show(v,0);
		toexplore.pop();
		if(isfinal(v)){
			break;
		}
		exhaust(v);
	}for(int i=0;i<40;i++){
		cout<<endl;
	}
	if(visited[target]==1){
		cout<<"Game is solved in "<<dist[target]<<" steps"<<endl;
	}else{
		cout<<"Game is unsolvable"<<endl;
		return 0;
	}stack<pair<int,int> >s;
	current=target;
	while(current!=start){
		s.push(prev[current]);
		current=toggle(current,prev[current].first,prev[current].second);
	}
	while(s.size()!=0){
		show(current,0);
		cout<<endl;
		cout<<"Press "<<s.top().first<<" "<<s.top().second<<endl;
		current=toggle(current,s.top().first,s.top().second);
		s.pop();
	}
	show(current,0);
}

