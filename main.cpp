//#include<iostream>
//
//void programA(){
//    printf("programA�����ã�\n");
//
//}
//void programA2(){
//    printf("programA2�����ã�\n");
//
//}
//void programB(void(*callback)()){
//    printf("programB�����ã�\n");
//    callback();
//}
//
//
//int main(void){
//    programA();
//    programB(programA2);
//
//
//}


//ָ�뺯��
//#include<stdio.h>
//int* fun(int* x)    //����ָ��
//{
//    int* tmp = x;	  //ָ��tmpָ��x
//    return tmp;       //����tmpָ��ĵ�ַ
//}
//int main()
//{
//    int b = 2;
//    int* p = &b;   //pָ��b�ĵ�ַ
//    printf("%d",*fun(p));//���pָ��ĵ�ַ��ֵ
//    return 0;
//}

////����ָ��
//#include <iostream>
//#include <memory>
//using namespace std;
//class A {
//public:
//    int i;
//    A(int n):i(n) { };
//    ~A() { cout << i << " " << "destructed" << endl; }
//};
//int main() {
//    shared_ptr<A> sp1(new A(2)); //A(2)��sp1�йܣ�
//    shared_ptr<A> sp2(sp1);      //A(2)ͬʱ����sp2�й�
//    shared_ptr<A> sp3;
//    sp3 = sp2;   //A(2)ͬʱ����sp3�й�
//    cout<<sp1.use_count()<<endl; //���3
//    cout<<sp2.use_count()<<endl; //���3
//    cout<<sp3.use_count()<<endl; //���3
//    cout << sp1->i << "," << sp2->i <<"," << sp3->i << endl;
//    A * p = sp3.get();      // get�����йܵ�ָ�룬p ָ�� A(2)
//    cout << p->i << endl;   //��� 2
//    sp1.reset(new A(3));    // reset�����й��µ�ָ��, ��ʱsp1�й�A(3)
//    cout<<sp1.use_count()<<endl; //���1
//    cout<<sp2.use_count()<<endl; //���2
//    sp2.reset(new A(4));    // sp2�й�A(4)
//    cout << sp1->i << endl; //��� 3
//    sp3.reset(new A(5));    // sp3�й�A(5),A(2)�����йܣ���delete
//    cout << "end" << endl;
//    return 0;
//}
//
//

//�������
//#include<iostream>
//#include<string>
//using namespace std;
//
//class person{
//    public :
//        string name;
//        int age;
//        void hello(void){
//            cout<<"hello world"<<endl;
//        }
//        void hello1();
//        person(){
//            cout<<"���ǹ��캯����"<<endl;
//        }
//
//    protected:
//        string school="neu";
//
//};
//
//
//void person::hello1() {
//    cout<<"new hello world"<<endl;
//}
//
//
//�̳���
//class son: public  person{
//    public :
//
//        void printSon(){
//            cout<<"�����ҵĶ���"<<endl;
//            cout<<school<<endl;
//    }
//
//
//};
//
//
//
//int main(void){
//    person person1;
//    person1.name="yueshisheng";
//    person1.age=24;
//    cout<<person1.name<<" "<<person1.age<<endl;
//    person1.hello();
//    person1.hello1();
//    son son1;
//    son1.hello1();
//    son1.printSon();
//
//
//}
//#include <iostream>
//// �����ͷ�ļ�
//#include <pthread.h>
//
//using namespace std;
//
//#define NUM_THREADS 5
//
//// �̵߳����к���
//void say_hello(void)
//{
//    cout << "Hello Runoob��" << endl;
//
//}
//
//int main()
//{
//    // �����̵߳� id �������������ʹ������
//    pthread_t tids[NUM_THREADS];
//    for(int i = 0; i < NUM_THREADS; ++i)
//    {
//        //���������ǣ��������߳�id���̲߳��������õĺ���������ĺ�������
//        int ret = pthread_create(&tids[i], NULL, reinterpret_cast<void *(*)(void *)>(say_hello), NULL);
//        if (ret != 0)
//        {
//            cout << "pthread_create error: error_code=" << ret << endl;
//        }
//    }
//    //�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������
//    pthread_exit(NULL);
//}


//���߳�
#include<iostream>
#include<thread>
#include<mutex>
#include<memory>
#include<csignal>
#include<map>
#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<tuple>
#include<future>
#include<list>
#include<deque>
#include <algorithm>
#include<chrono>
#include<set>
#include <functional>
#include<Eigen/Dense>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;
mutex m;





class person{
    public :
        string *name;
        int age;


        void hello(void){
            cout<<"hello world"<<endl;
        }
        void hello1();
        person(string* name,int age){
            cout<<"���ǹ��캯����"<<endl;
            this->name=name;
            this->age=age;
        }
        person(person& p1){
           cout<<"�����������"<<endl;
           this->name=new string(*(p1.name));  //new�����������string��ֵ���������ָ��ָ������ַ�����new���ص���ָ��
           cout<<name<<endl;

        }

    person();



protected:
        string school="neu";
        virtual void hello2()=0;//���麯��

};



class yue12:public person{
    public:

    yue12();

    string addr;
    static string dream;

        void hello(void){
            cout<<"hello yue12"<<endl;

        }
        void hello2(){
            cout<<"���麯��"<<endl;
        }
        friend void test_friend();
        yue12(string s){
            this->addr="y";
        }
        yue12(yue12 & y){
            cout<<"�������"<<endl;
            this->addr=y.addr;
            cout<<addr<<endl;

        }

        void static testStatic(){
            cout<<"����static����"<<endl;




        }
        void testNoStatic(){
            cout<<"���Ƿ�static����"<<endl;
            testStatic();


        }


};


string yue12::dream="play";
//
void test_friend(){
    cout<<"������Ԫ����"<<endl;
    int b=1;
    static int a=1;
    a=a+3;
    b=b+3;
    cout<<"a="<<a<<"  b="<<b<<endl;
}

yue12::yue12() {

}


void person::hello1() {
    cout<<"new hello world"<<endl;
}

person::person() {}


void proc1(int i){
    m.lock();
    cout<<"proc1���ڸ�дi"<<endl;
    cout<<"ԭʼi��"<<i<<endl;
    cout<<"����i��"<<i+2<<endl;
    m.unlock();
}
void proc2(int i){
    m.lock();
    cout<<"proc2���ڸ�дi"<<endl;
    cout<<"ԭʼi��"<<i<<endl;
    cout<<"����i��"<<i+1<<endl;
    m.unlock();
}

void sign1(int num){
    cout<<"stop"<<endl;
    exit(num);

}


struct Book{
    string writer;
    int booknum;
    string location;
};



typedef struct Book1{
    string writer;
    int booknum;
    string location;
};




void datastruct(Book& book1){
    book1.writer="2023222";
    cout<<book1.writer<<endl;
}
void datastruct2(Book1 book2){
    cout<<book2.writer<<endl;
}

void datastruct(Book& book1);


thread_local int n=0;

void testThreadlocal(int x){
    n=n+x;
    cout<<"threadlocal����:"<<n<<endl;

}


int async1(){
    cout<<"�����첽��ʼ"<<this_thread::get_id()<<endl;
    this_thread::sleep_for(1s);
    cout<<"�첽�������"<<this_thread::get_id()<<endl;
    return 1;

}


void testptr(string * ptr){
    *ptr="yue2";

}
void testreference(string & s){
    s="reference";
}



void testCallback(void (*callback1)()){
    cout<<"���Իص�����"<<endl;
    callback1();

}
void callexam(){
    cout<<"���ص��ĺ���"<<endl;
}



void sum(int a,int b){
    cout<<"a+b="<<a+b<<endl;

}
void multy(int a,int b){
    cout<<"a*b="<<a*b<<endl;
}
double CalEucliDis(std::vector<Eigen::Vector3d> HvPathHistory,std::vector<Eigen::Vector3d> RvPathHistory,int i,int j){
    double EucliDis=sqrt(pow(HvPathHistory[i].y()-RvPathHistory[j].y(),2)+pow(HvPathHistory[i].x()-RvPathHistory[j].x(),2));
    return EucliDis;

}

double FrechetDisRVs(std::vector<Eigen::Vector3d> HvPathHistory,std::vector<Eigen::Vector3d> RvPathHistory){
     int HvPathHistoryLength=HvPathHistory.size();
     int RvPathHistoryLength=RvPathHistory.size();
     double FrechetDis[HvPathHistoryLength][RvPathHistoryLength];
     for(int i=0;i<HvPathHistoryLength;i++){
        for(int j=0;j<RvPathHistoryLength;j++){

            FrechetDis[i][j]=-1;

        }
    }
     FrechetDis[0][0]= CalEucliDis(HvPathHistory,RvPathHistory,0,0);
    for(int i=1;i<HvPathHistoryLength;i++){
        FrechetDis[i][0]=max(FrechetDis[i-1][0], CalEucliDis(HvPathHistory,RvPathHistory,i,0));
    }
     for(int j=1;j<RvPathHistoryLength;j++){
         FrechetDis[0][j]=max(FrechetDis[0][j-1], CalEucliDis(HvPathHistory,RvPathHistory,0,j));
     }
     for(int i=1;i<HvPathHistoryLength;i++){
         for(int j=1;j<RvPathHistoryLength;j++){
             double temp1=min(FrechetDis[i-1][j],min(FrechetDis[i-1][j-1],FrechetDis[i][j-1]));
             FrechetDis[i][j]=max(temp1, CalEucliDis(HvPathHistory,RvPathHistory,i,j));

         }

     }
    return FrechetDis[HvPathHistoryLength-1][RvPathHistoryLength-1];


}








int main(void){

    std::vector<Eigen::Vector3d> HvPathHistory;
    std::vector<Eigen::Vector3d> RvPathHistory;
    Eigen::Vector3d HvPoint1(-2.3172331932000816,0.07034168846439556,0);
    Eigen::Vector3d HvPoint2(92.17228486435488,-1.7957061034394373,0);
    Eigen::Vector3d HvPoint3(132.85317593999207,2.122506048704971,0);
    Eigen::Vector3d HvPoint4(140.47931287251413,9.021501978510068,0);
    Eigen::Vector3d HvPoint5(142.03995434613898,17.769519352645155,0);
    Eigen::Vector3d HvPoint6(139.4555159760639,63.13382341887337,0);
    Eigen::Vector3d HvPoint7(146.30033728620037,71.55025405762719,0);
    Eigen::Vector3d HvPoint8(156.52461497765034,73.85147979523755,0);
    Eigen::Vector3d HvPoint9(164.7770992377773,69.50162653194276,0);
    Eigen::Vector3d HvPoint10(190.1399042243138,41.4372407962219,0);
    Eigen::Vector3d RvPoint1(-44.539005434606224,4.68199069361435,0);
    Eigen::Vector3d RvPoint2(98.78000233415514,1.3826275171595686,0);
    Eigen::Vector3d RvPoint3(103.67595041682944,9.531445685308434,0);
    Eigen::Vector3d RvPoint4(105.98799339821562,20.27836722898065,0);
    Eigen::Vector3d RvPoint5(100.52841037278995,41.87213046685793,0);
    Eigen::Vector3d RvPoint6(92.95691597927362,53.1580248157261,0);
    Eigen::Vector3d RvPoint7( 83.23656303388998,55.69196527119494,0);
    Eigen::Vector3d RvPoint8(69.09211396425962,51.571402113884695,0);
    Eigen::Vector3d RvPoint9(44.56001874245703,50.34993975062389,0);
    Eigen::Vector3d RvPoint10(-57.11468796618283,51.139345356612466,0);
    HvPathHistory.push_back(HvPoint1);
    HvPathHistory.push_back(HvPoint2);
    HvPathHistory.push_back(HvPoint3);
    HvPathHistory.push_back(HvPoint4);
    HvPathHistory.push_back(HvPoint5);
    HvPathHistory.push_back(HvPoint6);
    HvPathHistory.push_back(HvPoint7);
    HvPathHistory.push_back(HvPoint8);
    HvPathHistory.push_back(HvPoint9);
    HvPathHistory.push_back(HvPoint10);
    RvPathHistory.push_back(RvPoint1);
    RvPathHistory.push_back(RvPoint2);
    RvPathHistory.push_back(RvPoint3);
    RvPathHistory.push_back(RvPoint4);
    RvPathHistory.push_back(RvPoint5);
    RvPathHistory.push_back(RvPoint6);
    RvPathHistory.push_back(RvPoint7);
    RvPathHistory.push_back(RvPoint8);
    RvPathHistory.push_back(RvPoint9);
    RvPathHistory.push_back(RvPoint10);



    double FrechetHvToRv= FrechetDisRVs(HvPathHistory,RvPathHistory);
    cout<<"Զ��2��Զ��3��fechet�ľ���Ϊ��"<<FrechetHvToRv<<endl;








    std::function<void()> f=std::bind(sum,2,2000);
    f();
    int a=2;
    int b=4;

    void (*ptr_func)(int,int);//����ָ��
    ptr_func =sum;
    (*ptr_func)(a,b);
    ptr_func(a,b);//��������ʽ������






    test_friend();
    test_friend();
    testCallback(callexam);








    cout<<yue12::dream<<endl;

    yue12 y_new;
    y_new.testNoStatic();



    auto t=system_clock::now();
    auto t1=system_clock::to_time_t(t);

    cout<<"����ʱ�䣺"<<ctime(&t1)<<endl;


    test_friend();

    string s1="yueshisheng123";
    string * s_ptr;
    s_ptr=&s1;
    cout<<"�޸�ָ���ֵ"<<*s_ptr<<endl;
    testptr(s_ptr);
    cout<<*s_ptr;

    cout<<s1<<endl;
    string & s3=s1;
    testreference(s3);
    cout<<s1<<endl;



//    thread th3=thread(testThreadlocal,10);
//    thread th4=thread(testThreadlocal,20);
//����Ϊasync���첽��defered��ͬ��
    future<int> result=async(launch::deferred,async1);
    int res=result.get();
    cout<<"����async"<<this_thread::get_id()<<endl;


    deque<int> de1{1,3,5,7};
    de1.insert(de1.begin()+1,2);
    for(deque<int>::iterator de_iter=de1.begin();de_iter!=de1.end();de_iter++){
        cout<<"����˫�˶��У�";
        cout<<*de_iter;
    }


    pair<string,int> p1=make_pair("����pair",214);
    cout<<p1.first<<" "<<p1.second<<endl;



    list<int> list1{2,2,1,23,1};
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);
    list1.push_back(4);
    list1.push_back(5);
    list1.unique();
    cout<<"list��Ԫ�أ�"<<list1.size()<<endl;



    list1.sort();
    cout<<"�������� "<<endl;
    bool flag=binary_search(list1.begin(), list1.end(), 3);
    cout<<"����"<<flag<<endl;

    for(list<int>::iterator list_iter=list1.begin();list_iter!=list1.end();list_iter++){
        cout<<*list_iter<<endl;
    }

     list<int>::iterator index2= std::find(list1.begin(), list1.end(), 3);
    cout<<"index="<<*(index2)<<endl;
    list1.pop_front();



     yue12  yue122("ys");
     yue12 yuei (yue122);//���
     yue12 shallow=yue122;//ǳ����






     Book1 book2;
     Book book1;
     Book& book3=book1;
     book1.writer="yueshisheng2023";
     book1.booknum=12;
     book1.location="beijing";

     book2.writer="yueshisheng2022";
     book2.booknum=28;
     book2.location="yingxian";


     datastruct2(book2);
     datastruct(book3);



   string  c1="yueshisheng1";
//   person per1(&c1,24);
//   person per2(per1);
   map<int,string> map1;

   vector<int> vec1{2,7,3,3,3,2,1};//Ԥ��ָ��
   vector<int> vec2(std::begin(vec1),std::begin(vec1)+2);
   cout<<"vect2Ϊ��"<<vec2.at(1)<<endl;
   vec2.emplace(std::begin(vec2)+1,2);
   cout<<"vect2Ϊ��"<<vec2.at(1)<<endl;
   vec1.push_back(1);
   vec1.push_back(2);
   make_heap(vec1.begin(),vec1.end(),less<int>());//Ĭ��С����
   cout<<"�ѵ�ֵ��"<<*vec1.begin()<<endl;




   vector<int>::iterator bevec=vec1.begin();
   for(bevec;bevec!=vec1.end();bevec++){
       cout<<"����vector�ĵ������� "<<*bevec<<endl;


   }
   cout<<"vector��Ԫ��"<<vec1.at(1)<<endl;






   map1.insert(pair<int,string>(1,"yueshisheng3"));
   map1.insert(pair<int,string>(2,"yueshisheng2"));
   map1.erase(2);
   cout<<"map�ļ�ֵ�ԣ�"<<map1.count(1)<<endl;
   map1[3]="yueshisheng3";  //���ַ�����
   cout<<"map��Ԫ��"<<map1.at(3)<<endl;





   map<int,string>::iterator index=map1.find(3);
   cout<<index->first<<" "<<index->second<<endl;

   map<int,string>::iterator  begin;
   map<int,string>::iterator end;
   begin=map1.begin();
   end=map1.end();
   while(begin!=end){
       cout<<begin->first<<" "<<begin->second<<endl;
       begin++;
   }
   vector<int>::iterator begin1=vec1.begin();
   vector<int>::iterator end1=vec1.end();
   while(begin1!=end1){
       cout<<*begin1.base()<<endl;
       begin1++;
   }


    //ջ�Ļ���ʹ��
    stack<string> stack1;
    stack1.push("yueshisheng210");
    stack1.push("yueshisheng211");
    cout<<"���ջ��Ԫ��"<<stack1.top()<<endl;




    //���еĻ���ʹ��
    queue<string> queue1;
    queue1.push("queue1");
    queue1.push("queue2");
    cout<<"���еĵ�һ��Ԫ��"<<queue1.front()<<'\n';

    //tuple�Ļ�����ʹ��
    tuple<int,string,int> tuple1(2023,"yue",1);
    cout<<"���tuple"<<get<2>(tuple1)<<endl;


    int i=2;
    int* unique1=&i;
    unique_ptr<int> uni(unique1);
    cout<<"����ָ��unique��"<<*uni<<endl;
    unique_ptr<int> uni2=move(uni);
    cout<<"����ָ��unique2��"<<*uni2<<endl;
    uni2.release();

    shared_ptr<int> shar1= make_shared<int>(i);
    shared_ptr<int> shar2(shar1);//������һ
    shared_ptr<int> shar3=shar1; //��ֵҲ��һ
    cout<<shar3.use_count()<<endl;
    cout<<"����ָ��:"<<shar2.use_count()<<endl;
    shared_ptr<int> shar4= move(shar2);//
    cout<<"����ָ��:"<<shar3.use_count()<<endl;

    thread ths[10];
    for(thread &th:ths){
        th=thread(proc1,i);
    }


    thread th1=thread(proc1, i);
    thread th2=thread(proc2, i);
    th1.join();//����th1�߳�ִ����
    th2.join();



    //ö��
    enum color {blue,red=5,green} c;
    c=green;
    cout<<"ö�٣�"<<c<<endl;



}



