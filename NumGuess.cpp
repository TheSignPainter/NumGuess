//GuessNumber.cpp
//�û�����²�����������ɵ�����
//���ߣ��ƈ���
#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
bool Asking(){                                         //�ж��Ƿ���Ҫ����Ϸ
	char answer;
	cout<<"��Ҫ����Ϸ��Y/N����";cin>>answer;
	if (answer=='Y')return true ; 
	 else  return false;
}
int main(){
  int numberone , numbertwo , numberthree ;             //numberone,numbertwo,numberthree:�û�����Ĳ²�����, 
  int i , k , m , n , random[3] , instant ;                  //i,k:ѭ���е����� 
                                                        //m,n:��¼����ȫ�²���ȷ�����ָ�����ֻ��λ����ȷ�����ָ���  
                                                        //random[]:���ɵ����������������
  int losenumber=0 , winnumber=0;                       //instant�����ڲ�������ͬ�������
  bool flag , asking;                                   //flag������Ϸ�Ĳ²�ѭ����asking���ڶ��Ƿ�����Ϸ���ж�
  asking=Asking();
  while (asking){
  srand(time(NULL));
  i=1;
  random[0]=rand()%10;
  while(i<3){                                           //���������
	flag=true;
	instant=rand()%10;
	for(k=0;k<i;++k){
		if(random[k]==instant) {flag=false; break;}
	    }
	if(flag==true){random[i]=instant;++i;}            
	}
  
  cout<<"��������²������:"<<endl ;
  cin>>numberone>>numbertwo>>numberthree;                //����²������                                                      
  for(i=0;i<6;++i){                                      //��֤�²������Ƿ���ȷ 
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
	cout<<n<<'A'<<m<<'B'<<endl;                           //�����֤
	if(n==3){cout<<"��ϲ����¶���";++winnumber;break;}  
	if(n!=3){
		cout<<"����ˣ��㻹�� "<<6-i<<"�λ���"<<endl;     
        cout<<"��������²������:"<<endl ;               //��������������룬�ٽ���ѭ��
		cin>>numberone>>numbertwo>>numberthree;
	}
  }
  if(n!=3){cout<<"���ź�����û���ڹ涨�����ڲ¶ԡ�����"<<random[0]<<random[1]<<random[2]<<endl;++losenumber;}
  asking=Asking();                                        //�ж��Ƿ����������Ϸ
  
  }
  cout<<"��һ������"<<winnumber+losenumber<<"�֣�Ӯ��"<<winnumber<<"�֣�����"<<losenumber<<"��";
  system("pause");
  return 0;
}