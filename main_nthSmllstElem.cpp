#include<bits/stdc++.h>
#include<time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> ar;

int qsortR(int l , int r, int sze, int n);
int getRandPartition(int l, int r, int len);
int partition(int l, int r, int len);
void printArray(int sze);

int main(){
	int sze, n;
	cin>>sze;
	ar.resize(sze);

	for(int i=0;i<sze;i++){
		cin>>ar[i];
	}

	while(1){
		cout<<"Enter the nth place: ";
		cin>>n;
		if(n==-1){
			break;
		}
		if(n>sze){
			cout<<"Entered n is not in range; Invalid!"<<endl;
		}
		else{
			// auto start, end;

			duration<double> elapsed; 
			time_t end_time;

			////////////////////////////////////////////////
			//time for inbuild nth_element()
			auto start=system_clock::now();
			nth_element(ar.begin(),ar.begin()+n-1,ar.end());

			auto end =system_clock::now();
			elapsed=end-start;
			end_time = std::chrono::system_clock::to_time_t(end);
			cout<<"Time with inbuild nth_element(): "<<(elapsed).count()*1000000<<endl;
			/////////////////////////////////////////////


			////////////////////////////////////////////////
			//time for custom nth_element()
			start=system_clock::now();
			int res;
			res=qsortR(0, sze-1, sze, n);
			end = system_clock::now();
			elapsed=end-start;
			end_time = std::chrono::system_clock::to_time_t(end);
			cout<<"Nth smallest is:"<<res<<endl;
			cout<<"Time w/o inbuild nth_element(): "<<(elapsed).count()*1000000<<endl;
			/////////////////////////////////////////////
		}
	}
	

	return 0;
	
}

int qsortR(int l, int r, int len, int n){
	while(l<=r){
		int pivot=getRandPartition(l,r,len);

		// cout<<"pivot: "<<pivot<<endl;
		if(n-1==pivot){
			cout<<"Found; ";
			return ar[pivot];
		}
		if(n-1<pivot){
			r=pivot-1;
		}
		else{
			l=pivot+1;
		}
	}
	return -1;//won't reach this statement; necessary to compile
}

int getRandPartition(int l, int r, int len){
	int random=1;
	int diff=r-l;

	if(l!=r){
		random=rand()%diff;
		random+=l;
		swap(ar[l], ar[random]);  
		return partition(l,r,len);
	}
	else{
		return l;
	}
	return -1;//won't reach this statement; necessary to compile
}


int partition(int l, int r, int len){
	int valAtPivot=ar[l], less=l+1, more=r, temp1=0, temp2=0;
	int swapElem=1;

	// cout<<"valAtPivot: "<<valAtPivot<<endl;

	while(less<=more){
		while(less<=more && ar[more]>valAtPivot){
			more--;
		}
		while(less<=more && ar[less]<=valAtPivot){
			less++;
		}

		if(less<more){
			swap(ar[less], ar[more]);
		}

	}
	ar[l]=ar[more];
	ar[more]=valAtPivot;

	// cout<<"array after a partition:"<<endl;
	// printArray(len);
	return more;

}

void printArray(int sze){
	for(int i=0;i<sze;i++){
		cout<<ar[i]<<endl;
	}
}