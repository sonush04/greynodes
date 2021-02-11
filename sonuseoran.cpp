// Name: Sonu Seoran
// Due date: 11/02/2021, 5:00 pm
// Email: sonush0409@gmail.com

#include<bits/stdc++.h>
using namespace std;

// required structure of a mower
struct mower{
    string name;
    string year;
    string warranty;
    int ticket;
};
// A comparision function according to the given information in assignment
bool comp(mower* m1, mower* m2){
    if(m1->warranty == "n" && m2->warranty == "y"){
        return true;
    }
    else if(m1->warranty == m2->warranty){
        return m2->year > m1->year;
    }
    else{
        return false;
    }
}
//user defined heap
class myHeap{
    public:
    mower* arr[10];
    int x;
    int t;
    
    myHeap(){
        x = 0;
        t = 0;
    }
    // to find the size of our queue
    int getSize(){
        return x;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    // for service , select the most prior mower repair and pop it out from our heap
    void pop(){
        if(x == 0){
            cout<<"Error:queue is empty"<<endl;
            return;
        }
        cout<<arr[0]->name<<endl;
        arr[0] = arr[x-1];
        x--;
        heapify(0);
        
    }
    // to arrange the queue in the given priority order
    void heapify(int i){
        int l = left(i); 
        int r = right(i); 
        int smallest = i; 
        if (l < x && comp(arr[i],arr[l])) 
            smallest = l; 
        if (r < x && comp(arr[smallest],arr[r])) 
            smallest = r; 
        if (smallest != i) 
        {   
            swap(arr[i], arr[smallest]); 
            heapify(smallest); 
        } 
    }
    // insert function to insert new mower repair in our user-defined heap
    void insert(string y, string n, string w){
         if(x >= 10){
             cout<<"Error:queue is full "<<y<<endl;
             return;
        }
        
        mower* m = new mower();
        m->name = n;
        m->year = y;
        m->warranty = w;
        m->ticket = t++;
        arr[x++] = m;
        int i = x-1;
        while( i!= 0 && comp(arr[parent(i)],arr[i])){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }
};

int main(){
    myHeap heap;
    while(1){
        string s;
        cin>>s;
        // when we reach at the end of file
        if(s == "end-of-file"){
            cout<<"There are "<<heap.getSize()<<" remaining repair orders in the queue."<<endl;
            break;
        }
        // service time
        else if(s == "service"){
            heap.pop();
        }
        // new mower repair order
        else{
            vector<string> v;
            string st = "";
            for(int i =0;i<s.length();i++){
                if(s[i] == '-'){
                    v.push_back(st);
                    st = "";
                }
                else{
                    st += s[i];
                }
            }
            v.push_back(st);
            if(v.size() != 3 || v[1].length() != 4 )
            	cout<<"wrong input"<<endl;
            if(v[2] != "y" || v[2] != "n")
            	cout<<"wrong input"<<endl;
            //put in out heap
            heap.insert(v[1],v[0], v[2]);
        }
    }
}
