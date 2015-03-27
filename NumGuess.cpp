//GuessNumber.cpp
//用户将会猜测三个随机生成的数字
//作者：黄垚玮
#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
bool Asking(){                                         //判断是否需要玩游戏
	char answer;
	cout<<"需要玩游戏吗（Y/N）？";cin>>answer;
	if (answer=='Y')return true ; 
	 else  return false;
}
int main(){
  int numberone , numbertwo , numberthree ;             //numberone,numbertwo,numberthree:用户输入的猜测数字, 
  int i , k , m , n , random[3] , instant ;                  //i,k:循环中的数字 
                                                        //m,n:记录你完全猜测正确的数字个数和只是位置正确的数字个数  
                                                        //random[]:生成的三个随机数字数组
  int losenumber=0 , winnumber=0;                       //instant：用于产生不相同的随机数
  bool flag , asking;                                   //flag用于游戏的猜测循环，asking用于对是否玩游戏的判断
  asking=Asking();
  while (asking){
  srand(time(NULL));
  i=1;
  random[0]=rand()%10;
  while(i<3){                                           //产生随机数
	flag=true;
	instant=rand()%10;
	for(k=0;k<i;++k){
		if(random[k]==instant) {flag=false; break;}
	    }
	if(flag==true){random[i]=instant;++i;}            
	}
  
  cout<<"请输入你猜测的数字:"<<endl ;
  cin>>numberone>>numbertwo>>numberthree;                //输入猜测的数字                                                      
  for(i=0;i<6;++i){                                      //验证猜测数字是否正确 
	  n=0;
	  m=0;
      if(random[0]==numberone){++n;}
	  else{
		  if(random[0]==numbertwo||random[0]==numberthree) ++m;
	  }
	  if(random[1]==numbertwo){++n;}
	  else{
		  if(random[1]==numberone||random[1]==numberthree) ++m;
	  }
	  if(random[2]==numberthree){++n;}
	  else{
		  if(random[2]==numberone||random[2]==numbertwo) ++m;
	  }
	cout<<n<<'A'<<m<<'B'<<endl;                           //输出验证
	if(n==3){cout<<"恭喜，你猜对了";++winnumber;break;}  
	if(n!=3){
		cout<<"你错了，你还有 "<<6-i<<"次机会"<<endl;     
        cout<<"请输入你猜测的数字:"<<endl ;               //错误进行重新输入，再进入循环
		cin>>numberone>>numbertwo>>numberthree;
	}
  }
  if(n!=3){cout<<"很遗憾，你没有在规定次数内猜对。答案是"<<random[0]<<random[1]<<random[2]<<endl;++losenumber;}
  asking=Asking();                                        //判断是否继续进行游戏
  
  }
  cout<<"你一共玩了"<<winnumber+losenumber<<"局，赢了"<<winnumber<<"局，输了"<<losenumber<<"局";
  system("pause");
  return 0;
}