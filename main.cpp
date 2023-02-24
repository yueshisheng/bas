//#include<iostream>
//
//void programA(){
//    printf("programA被调用！\n");
//
//}
//void programA2(){
//    printf("programA2被调用！\n");
//
//}
//void programB(void(*callback)()){
//    printf("programB被调用！\n");
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


//指针函数
//#include<stdio.h>
//int* fun(int* x)    //传入指针
//{
//    int* tmp = x;	  //指针tmp指向x
//    return tmp;       //返回tmp指向的地址
//}
//int main()
//{
//    int b = 2;
//    int* p = &b;   //p指向b的地址
//    printf("%d",*fun(p));//输出p指向的地址的值
//    return 0;
//}

////智能指针
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
//    shared_ptr<A> sp1(new A(2)); //A(2)由sp1托管，
//    shared_ptr<A> sp2(sp1);      //A(2)同时交由sp2托管
//    shared_ptr<A> sp3;
//    sp3 = sp2;   //A(2)同时交由sp3托管
//    cout<<sp1.use_count()<<endl; //输出3
//    cout<<sp2.use_count()<<endl; //输出3
//    cout<<sp3.use_count()<<endl; //输出3
//    cout << sp1->i << "," << sp2->i <<"," << sp3->i << endl;
//    A * p = sp3.get();      // get返回托管的指针，p 指向 A(2)
//    cout << p->i << endl;   //输出 2
//    sp1.reset(new A(3));    // reset导致托管新的指针, 此时sp1托管A(3)
//    cout<<sp1.use_count()<<endl; //输出1
//    cout<<sp2.use_count()<<endl; //输出2
//    sp2.reset(new A(4));    // sp2托管A(4)
//    cout << sp1->i << endl; //输出 3
//    sp3.reset(new A(5));    // sp3托管A(5),A(2)无人托管，被delete
//    cout << "end" << endl;
//    return 0;
//}
//
//

//面向对象
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
//            cout<<"这是构造函数！"<<endl;
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
//继承类
//class son: public  person{
//    public :
//
//        void printSon(){
//            cout<<"这是我的儿子"<<endl;
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
//// 必须的头文件
//#include <pthread.h>
//
//using namespace std;
//
//#define NUM_THREADS 5
//
//// 线程的运行函数
//void say_hello(void)
//{
//    cout << "Hello Runoob！" << endl;
//
//}
//
//int main()
//{
//    // 定义线程的 id 变量，多个变量使用数组
//    pthread_t tids[NUM_THREADS];
//    for(int i = 0; i < NUM_THREADS; ++i)
//    {
//        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
//        int ret = pthread_create(&tids[i], NULL, reinterpret_cast<void *(*)(void *)>(say_hello), NULL);
//        if (ret != 0)
//        {
//            cout << "pthread_create error: error_code=" << ret << endl;
//        }
//    }
//    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
//    pthread_exit(NULL);
//}


//多线程
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
            cout<<"这是构造函数！"<<endl;
            this->name=name;
            this->age=age;
        }
        person(person& p1){
           cout<<"这是深拷贝函数"<<endl;
           this->name=new string(*(p1.name));  //new的括号里边是string的值，代表这个指针指向这个字符串，new返回的是指针
           cout<<name<<endl;

        }

    person();



protected:
        string school="neu";
        virtual void hello2()=0;//纯虚函数

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
            cout<<"纯虚函数"<<endl;
        }
        friend void test_friend();
        yue12(string s){
            this->addr="y";
        }
        yue12(yue12 & y){
            cout<<"深拷贝函数"<<endl;
            this->addr=y.addr;
            cout<<addr<<endl;

        }

        void static testStatic(){
            cout<<"这是static函数"<<endl;




        }
        void testNoStatic(){
            cout<<"这是非static函数"<<endl;
            testStatic();


        }


};


string yue12::dream="play";
//
void test_friend(){
    cout<<"测试友元函数"<<endl;
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
    cout<<"proc1正在改写i"<<endl;
    cout<<"原始i："<<i<<endl;
    cout<<"现在i："<<i+2<<endl;
    m.unlock();
}
void proc2(int i){
    m.lock();
    cout<<"proc2正在改写i"<<endl;
    cout<<"原始i："<<i<<endl;
    cout<<"现在i："<<i+1<<endl;
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
    cout<<"threadlocal测试:"<<n<<endl;

}


int async1(){
    cout<<"测试异步开始"<<this_thread::get_id()<<endl;
    this_thread::sleep_for(1s);
    cout<<"异步任务结束"<<this_thread::get_id()<<endl;
    return 1;

}


void testptr(string * ptr){
    *ptr="yue2";

}
void testreference(string & s){
    s="reference";
}



void testCallback(void (*callback1)()){
    cout<<"测试回调函数"<<endl;
    callback1();

}
void callexam(){
    cout<<"被回调的函数"<<endl;
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
    cout<<"远车2和远车3的fechet的距离为："<<FrechetHvToRv<<endl;








    std::function<void()> f=std::bind(sum,2,2000);
    f();
    int a=2;
    int b=4;

    void (*ptr_func)(int,int);//函数指针
    ptr_func =sum;
    (*ptr_func)(a,b);
    ptr_func(a,b);//这两种形式都可以






    test_friend();
    test_friend();
    testCallback(callexam);








    cout<<yue12::dream<<endl;

    yue12 y_new;
    y_new.testNoStatic();



    auto t=system_clock::now();
    auto t1=system_clock::to_time_t(t);

    cout<<"现在时间："<<ctime(&t1)<<endl;


    test_friend();

    string s1="yueshisheng123";
    string * s_ptr;
    s_ptr=&s1;
    cout<<"修改指针的值"<<*s_ptr<<endl;
    testptr(s_ptr);
    cout<<*s_ptr;

    cout<<s1<<endl;
    string & s3=s1;
    testreference(s3);
    cout<<s1<<endl;



//    thread th3=thread(testThreadlocal,10);
//    thread th4=thread(testThreadlocal,20);
//参数为async是异步，defered是同步
    future<int> result=async(launch::deferred,async1);
    int res=result.get();
    cout<<"测试async"<<this_thread::get_id()<<endl;


    deque<int> de1{1,3,5,7};
    de1.insert(de1.begin()+1,2);
    for(deque<int>::iterator de_iter=de1.begin();de_iter!=de1.end();de_iter++){
        cout<<"测试双端队列：";
        cout<<*de_iter;
    }


    pair<string,int> p1=make_pair("测试pair",214);
    cout<<p1.first<<" "<<p1.second<<endl;



    list<int> list1{2,2,1,23,1};
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);
    list1.push_back(4);
    list1.push_back(5);
    list1.unique();
    cout<<"list的元素："<<list1.size()<<endl;



    list1.sort();
    cout<<"测试排序： "<<endl;
    bool flag=binary_search(list1.begin(), list1.end(), 3);
    cout<<"二分"<<flag<<endl;

    for(list<int>::iterator list_iter=list1.begin();list_iter!=list1.end();list_iter++){
        cout<<*list_iter<<endl;
    }

     list<int>::iterator index2= std::find(list1.begin(), list1.end(), 3);
    cout<<"index="<<*(index2)<<endl;
    list1.pop_front();



     yue12  yue122("ys");
     yue12 yuei (yue122);//深拷贝
     yue12 shallow=yue122;//浅拷贝






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

   vector<int> vec1{2,7,3,3,3,2,1};//预先指定
   vector<int> vec2(std::begin(vec1),std::begin(vec1)+2);
   cout<<"vect2为："<<vec2.at(1)<<endl;
   vec2.emplace(std::begin(vec2)+1,2);
   cout<<"vect2为："<<vec2.at(1)<<endl;
   vec1.push_back(1);
   vec1.push_back(2);
   make_heap(vec1.begin(),vec1.end(),less<int>());//默认小根堆
   cout<<"堆的值："<<*vec1.begin()<<endl;




   vector<int>::iterator bevec=vec1.begin();
   for(bevec;bevec!=vec1.end();bevec++){
       cout<<"测试vector的迭代器： "<<*bevec<<endl;


   }
   cout<<"vector的元素"<<vec1.at(1)<<endl;






   map1.insert(pair<int,string>(1,"yueshisheng3"));
   map1.insert(pair<int,string>(2,"yueshisheng2"));
   map1.erase(2);
   cout<<"map的键值对："<<map1.count(1)<<endl;
   map1[3]="yueshisheng3";  //这种方法简单
   cout<<"map的元素"<<map1.at(3)<<endl;





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


    //栈的基本使用
    stack<string> stack1;
    stack1.push("yueshisheng210");
    stack1.push("yueshisheng211");
    cout<<"输出栈顶元素"<<stack1.top()<<endl;




    //队列的基本使用
    queue<string> queue1;
    queue1.push("queue1");
    queue1.push("queue2");
    cout<<"队列的第一个元素"<<queue1.front()<<'\n';

    //tuple的基本的使用
    tuple<int,string,int> tuple1(2023,"yue",1);
    cout<<"输出tuple"<<get<2>(tuple1)<<endl;


    int i=2;
    int* unique1=&i;
    unique_ptr<int> uni(unique1);
    cout<<"智能指针unique："<<*uni<<endl;
    unique_ptr<int> uni2=move(uni);
    cout<<"智能指针unique2："<<*uni2<<endl;
    uni2.release();

    shared_ptr<int> shar1= make_shared<int>(i);
    shared_ptr<int> shar2(shar1);//拷贝加一
    shared_ptr<int> shar3=shar1; //赋值也加一
    cout<<shar3.use_count()<<endl;
    cout<<"智能指针:"<<shar2.use_count()<<endl;
    shared_ptr<int> shar4= move(shar2);//
    cout<<"智能指针:"<<shar3.use_count()<<endl;

    thread ths[10];
    for(thread &th:ths){
        th=thread(proc1,i);
    }


    thread th1=thread(proc1, i);
    thread th2=thread(proc2, i);
    th1.join();//等于th1线程执行完
    th2.join();



    //枚举
    enum color {blue,red=5,green} c;
    c=green;
    cout<<"枚举："<<c<<endl;



}



