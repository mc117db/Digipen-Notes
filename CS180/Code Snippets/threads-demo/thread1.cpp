#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <thread>
#include <pthread.h>
#include <ctime>
#include <unistd.h>



using namespace std;

int global_data = 10;
char buff[100] = "Hello World";

void *runThread1(void *threadparam)	//thread 1
{
   long tid;
   tid = (long)threadparam;   
   int count=0;
   while(count++<tid)
   {
		std::cout<<" thread1 "<<endl;
		sleep(2);	
	}
   pthread_exit(NULL);
}

void *runThread2(void *threadparam)  //thread 2
{
   long tid;
   tid = (long)threadparam;   
   int count=0;
   while(count++<tid)
   {
		std::cout<<"\t thread2 "<<endl;
		sleep(3);	
	}
   pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
   pthread_t threads[2];
   int rc1 = pthread_create(&threads[0], NULL, runThread1, (void *)5);
   int rc2 = pthread_create(&threads[1], NULL, runThread2, (void *)10);
   
   //cout<< rc1<<" "<<rc2<<" "<<threads[0]<<" "<<threads[1]<<endl;
   
   int count=0;
   /* Last thing that main() should do */      
   while(count++<3)
   {
	cout<<"\n\t\t main_thread \n"<<endl;
	sleep(1);
	}
   pthread_exit(NULL);
   
}
