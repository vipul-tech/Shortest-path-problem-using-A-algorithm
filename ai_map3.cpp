#include<bits/stdc++.h>
using namespace std;
string city_name;
int rear=-1,front=-1,c=0,flag=0;
int search_index(string s);
void ascend();
void Succesors();
void sort_route();
struct map{
	string name;
	struct map* E;
	struct map* W;
	struct map* N;
	struct map* S;
	struct map* NE;
	struct map* SE;
	struct map* SW;
	struct map* NW;
	int h=0;
	}null,city[100];
struct dist{
	int s,d,g,f;
	}r[50],open[50],close[50];
//loading the data of romania
void map_detail(){
	city[0].name="Eforie";
	city[0].h=161;
	city[0].NW=&city[1]; 
        city[0].N=0; city[0].E=0; city[0].W=0; city[0].S=0; city[0].SE=0; city[0].SW=0; city[0].NE=0;
	//*********************************************************************************************
	city[1].name="Hirsova";
        city[1].h=151;
        city[1].W=&city[2]; city[1].SE=&city[0];
        city[1].S=0; city[1].SW=0; city[1].NE=0; city[1].NW=0; city[1].N=0; city[1].E=0;
	//*********************************************************************************************
	city[2].name="Urziceni";
        city[2].h=80;
        city[2].NW=0; city[2].N=0; city[2].W=0; city[2].S=0; city[2].SE=0;
        city[2].E=&city[1];
        city[2].SW=&city[6];
        city[2].NE=&city[3];
	//*********************************************************************************************
	city[3].name="Vaslui";
        city[3].h=199;
        city[3].NW=&city[4]; city[3].SW=&city[2];
        city[3].N=0; city[3].E=0; city[3].W=0; city[3].S=0; city[3].SE=0; city[3].NE=0;
	//*********************************************************************************************
	city[4].name="Lasi";
        city[4].h=226;
        city[4].NW=&city[5]; city[4].SE=&city[3];
        city[4].N=0; city[4].E=0; city[4].W=0; city[4].S=0; city[4].SW=0; city[4].NE=0;
	//*********************************************************************************************
	city[5].name="Neamt";
        city[5].h=234;
        city[5].NW=0; city[5].N=0; city[5].E=0; city[5].W=0; city[5].S=0; city[5].SE=0; city[5].SW=0;
        city[5].NE=&city[4];
	//*********************************************************************************************
	city[6].name="Bucharest";
        city[6].h=0; city[6].N=0; city[6].E=0; city[6].S=0; city[6].SE=0;
        city[6].NW=&city[9]; city[6].W=&city[8]; city[6].SW=&city[7]; city[6].NE=&city[2];
	//*********************************************************************************************
	city[7].name="Giurgiu";
        city[7].h=77;
        city[7].NW=0; city[7].N=0; city[7].E=0; city[7].W=0; city[7].S=0; city[7].SE=0; city[7].SW=0;
        city[7].NE=&city[6];
	//*********************************************************************************************
	city[8].name="Pitesti";
        city[8].h=10;
        city[8].NW=&city[11]; city[8].SE=&city[6]; city[8].SW=&city[10];
	city[8].N=0; city[8].E=0; city[8].W=0; city[8].S=0; city[8].NE=0;
	//*********************************************************************************************
	city[9].name="Fagaras";
        city[9].h=176;
        city[9].NW=0; city[9].SW=0; city[9].NE=0; city[9].N=0; city[9].S=0; city[9].E=0;
        city[9].W=&city[12]; city[9].SE=&city[6];
	//*********************************************************************************************
	city[10].name="Craiova";
        city[10].h=160;
        city[10].N=&city[11]; city[10].W=&city[13]; city[10].NE=&city[8];
        city[10].E=0; city[10].S=0; city[10].SE=0; city[10].SW=0; city[10].NW=0;
	//*********************************************************************************************
	city[11].name="Rimnicu Vilcea";
        city[11].h=193;
        city[11].NW=&city[12]; city[11].S=&city[10]; city[11].SE=&city[8];
        city[11].N=0; city[11].SW=0; city[11].NE=0; city[11].E=0; city[11].W=0;
	//********************************************************************************************
	city[12].name="Sibiu";
        city[12].h=253;
        city[12].NW=&city[19]; city[12].E=&city[9]; city[12].W=&city[17]; city[12].SE=&city[11];
        city[12].N=0; city[12].SW=0; city[12].NE=0; city[12].S=0;
	//********************************************************************************************
	city[13].name="Dobreta";
        city[13].h=242;
        city[13].NW=0; city[13].W=0; city[13].S=0; city[13].SE=0; city[13].SW=0; city[13].NE=0;
        city[13].N=&city[14]; city[13].E=&city[10];
	//********************************************************************************************
	city[14].name="Mehadia";
        city[14].h=241;
        city[14].NW=0; city[14].SE=0; city[14].SW=0; city[14].NE=0; city[14].E=0; city[14].W=0;
        city[14].N=&city[15]; city[14].S=&city[13];
	//********************************************************************************************
	city[15].name="Lugoj";
        city[15].h=244;
        city[15].NW=&city[16];
        city[15].N=0; city[15].SE=0; city[15].SW=0; city[15].NE=0; city[15].E=0; city[15].W=0;
        city[15].S=&city[14];
	//********************************************************************************************
	city[16].name="Timisoara";
        city[16].h=329;
        city[16].NW=0; city[16].SW=0; city[16].NE=0; city[16].E=0; city[16].W=0; city[16].S=0;
        city[16].N=&city[17]; city[16].SE=&city[15];
	//*********************************************************************************************
	city[17].name="Arad";
        city[17].h=366;
        city[17].NW=0; city[17].SW=0; city[17].N=0; city[17].E=0; city[17].W=0;
        city[17].S=&city[16]; city[17].SE=&city[12]; city[17].NE=&city[18];
	//**********************************************************************************************
	city[18].name="Zerind";
        city[18].h=374;
        city[18].NW=0; city[18].N=0; city[18].E=0; city[18].W=0; city[18].S=0; city[18].SE=0;
        city[18].SW=&city[17]; city[18].NE=&city[19];
	//**********************************************************************************************
	city[19].name="Oradea";
        city[19].h=380;
        city[19].NW=0; city[19].N=0; city[19].E=0; city[19].W=0; city[19].S=0; city[19].NE=0;
        city[19].SE=&city[12]; city[19].SW=&city[18];
	//**********************************************************************************************
	r[0].s=0; r[0].d=1; r[0].g=86;
	r[1].s=1; r[1].d=2;r[1].g=98;
	r[2].s=1; r[2].d=0;r[2].g=86;
	r[3].s=2; r[3].d=1;r[3].g=98;
	r[4].s=2; r[4].d=6;r[4].g=85;
	r[5].s=2; r[5].d=3;r[5].g=142;
	r[6].s=3; r[6].d=4;r[6].g=92;
	r[7].s=3; r[7].d=2;r[0].g=142;
	r[8].s=4; r[8].d=5;r[8].g=87;
	r[9].s=4; r[9].d=3;r[9].g=92;
	r[10].s=5; r[10].d=4;r[10].g=87;
	r[11].s=6; r[11].d=9;r[11].g=211;
	r[12].s=6; r[12].d=8;r[12].g=101;
	r[13].s=6; r[13].d=7;r[13].g=90;
	r[14].s=6; r[14].d=2;r[14].g=85;
	r[15].s=7; r[15].d=6;r[15].g=90;
	r[16].s=8; r[16].d=11;r[16].g=97;
	r[17].s=8; r[17].d=6;r[17].g=101;
	r[18].s=8; r[18].d=10;r[18].g=138;
	r[19].s=9; r[19].d=12;r[19].g=99;
	r[20].s=9; r[20].d=6;r[20].g=211;
	r[21].s=10; r[21].d=11;r[21].g=146;
	r[22].s=10; r[22].d=13;r[22].g=120;
	r[23].s=10; r[23].d=8;r[23].g=138;
	r[24].s=11; r[24].d=12;r[24].g=80;
	r[25].s=11; r[25].d=10;r[25].g=145;
	r[26].s=11; r[26].d=8;r[26].g=97;
	r[27].s=12; r[27].d=19;r[27].g=151;
	r[28].s=12; r[28].d=9;r[28].g=99;
	r[29].s=12; r[29].d=17;r[29].g=140;
	r[30].s=12; r[30].d=11;r[30].g=80;
	r[31].s=13; r[31].d=14;r[31].g=75;
	r[32].s=13; r[32].d=10;r[32].g=120;
	r[33].s=14; r[33].d=15;r[33].g=70;
	r[34].s=14; r[34].d=13;r[34].g=75;
	r[35].s=15; r[35].d=16;r[35].g=111;
	r[36].s=15; r[36].d=14;r[36].g=70;
	r[37].s=16; r[37].d=17;r[37].g=118;
	r[38].s=16; r[38].d=15;r[38].g=111;
	r[39].s=17; r[39].d=16;r[39].g=118;
	r[40].s=17; r[40].d=12;r[40].g=140;
	r[41].s=17; r[41].d=18;r[41].g=75;
	r[42].s=18; r[42].d=17;r[42].g=75;
	r[43].s=18; r[43].d=19;r[43].g=71;
	r[44].s=19; r[44].d=12;r[44].g=151;
	r[45].s=19; r[45].d=18;r[45].g=71;
	//*********************************************************************************************
	
}
//Display route which we cover 
void display(){
      int count=0;
      cout<<endl<<endl;
      cout<<"THE SHORTEST ROUTE TO BUCHAREST IS AS SHOWN BELOW:"<<endl;
        for(int i=2;i<=c;i++){
                count++;
        if(i==2) 
           cout<<city[close[i].s].name;
        else
           cout<<"------>"<<city[close[i].s].name;
     }
	if(city_name=="Giurgiu"){ cout<<"------>Bucharest\n"; count++;}
	cout<<"\nTotal Steps required to find the shortest path: "<<count-1<<"\n\n";
     }
int gn=0;
void sort_route(){
	string s;
	int l,sel,k;
	//If Source Is Not In Map
	for(int i=0;i<20;i++){
		if(city[i].name==city_name){ l=i; flag=1;}
		}
	if(flag==0){
		cout<<"Source is Invalid\n";
		return;
		}
	string destination="Bucharest";
	//If Source name Is Same As Destination name
	if(city_name==destination){
		cout<<"We are already at the destination\n"; 
        	return;
		}
        front=0; rear=0;
	for(int i=0;i<46;i++){
        	if(r[i].s==l){
                	sel=i;
                    	break;
                   	}
		}	
		open[rear]=r[sel];
	 while(city[open[front].s].name!="Bucharest"){ 
                  ascend();
                  Succesors();
		}
	}	
void Succesors(){
       string s;
       int k,sel,l;
	   if(c==0) l=open[front].s;
	   else l=open[front].d;
            if(city[l].E!=0){
                   rear++;
                   s=city[l].E->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){;
                          if((r[i].s==l)&&(r[i].d==k)) sel=i;
                   	  }
		   r[sel].f=r[sel].g+city[k].h; 
                   open[rear]=r[sel];
                   }
           if(city[l].W!=0){
                   rear++;
                   s=city[l].W->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
           if(city[l].N!=0){
                   rear++;
                   s=city[l].N->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
           if(city[l].S!=0){
                   rear++;
                   s=city[l].S->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
            if(city[l].NE!=0){
                   rear++;
                   s=city[l].NE->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
              if(city[l].NW!=0){
                   rear++;
                   s=city[l].NW->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
            if(city[l].SE!=0){
                   rear++;
                   s=city[l].SE->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
            if(city[l].SW!=0){
                   rear++;
                   s=city[l].SW->name;
                   k=search_index(s);
                   for(int i=0;i<46;i++){
                   	if(r[i].s==l&&r[i].d==k) sel=i;
                   	}
		   r[sel].f=r[sel].g+city[k].h;
                   open[rear]=r[sel];
                   }
            c++;
            close[c]=open[front];
            front++;
   }
void ascend(){
	for(int i=front;i<=rear;i++){
        	for(int j=i+1;j<=rear;j++){
                	if(open[j].f<open[i].f){
                    		struct dist temp=open[j];
                    		open[j]=open[i];
                   		open[i]=temp;
                		}
            		}
        	}
     }
int search_index(string s){
	for(int i=0;i<20;i++){
		if(city[i].name==s) return i;
     	}
}
int main(){
       cout<<"enter the starting city name:";
       cin>>city_name;
       map_detail();
       sort_route();
       display();
       return 0;
}
