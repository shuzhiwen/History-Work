#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PNUM  5 //进程的数量
#define TIMER 10 //定时器,最长CPU区间时间
#define SLICE 2 //轮转算法的时间片

typedef struct node {
   int pid; //进程号
   int priority; //进程优先级,1~3,数字越小优先级越高
   int arrival; //到达时间
   int burst; //CPU区间时间
   int rest; //剩余时间
   char state; //进程状态,'N'新建,'R'运行,'W'等待CPU(就绪),'T'终止
   struct node *next; //指向队列中下一个进程的PCB
} PCB;

int timenow = 0; //当前时刻,模拟时钟滴答
int gantt[TIMER*PNUM] = { 0 }; //用一个数组记录调度过程,每个时刻调度的进程号

PCB *job; //所有作业的序列,带头节点(为简化编程)
PCB *ready = NULL; //进程就绪队列,不带头节点
PCB *tail = NULL; //记录就绪队列的尾节点
PCB *run = NULL; //正在运行中的进程,不带头结点，任意时刻最多仅一个进程。
PCB *finish = NULL; //已经结束的程序,不带头结点，所有进程将按结束先后顺序移入该链表（栈式结构：新结束的结点总是加入链表头部，设计该链表仅为演示程序结果）。

void pushJob(PCB pcb[PNUM]) { //链接进程并放入job队列
  job = (PCB*)malloc(sizeof(PCB));
  job->next = pcb;
  for (int i = 0; i < PNUM - 1; i++) {
    pcb[i].next = pcb + i + 1;
  }
  tail = pcb + PNUM - 1;
}

void pushReady(PCB *job) { //遍历job，将符合条件的进程放入ready
  PCB *tmp = job->next;
  PCB *prev = job;

  while (tmp != NULL) {
    if (tmp->arrival == timenow) { //进程到达
      prev->next = tmp->next;
      tail->next = tmp;
      tail = tmp;
      tail->next = NULL;
      tail->state = 'W';
      if (ready == NULL) {
        ready = tail;
      }
    } else {
      prev = prev->next;
    }

    tmp = tmp->next;
  }
}

void FCFS(PCB pcb[PNUM]) {
  pushJob(pcb);
  while (job->next != NULL || ready != NULL || run != NULL) {
    if (run == NULL) {
      pushReady(job);
      if (ready != NULL) {
        run = ready;
        run->state = 'R';
        ready = ready->next;
      }
    } else {
      run->rest--;
      if (run->rest == 0) {
        run->state = 'T';
        run->next = finish;
        finish = run;
        run = NULL;
      }
    }

    timenow++;
  }
}

void RR(PCB pcb[PNUM]) {
  
}

void SJF(PCB pcb[PNUM]) {
  
}

void SRTF(PCB pcb[PNUM]) {
  
}

void Priority(PCB pcb[PNUM]) {
  
}

int main() {
  srand((unsigned)time(NULL));

  PCB *pcb = (PCB*)malloc(sizeof(PCB) * PNUM);
  for (int i = 0; i < PNUM; i++) {
    pcb[i].pid = rand() % 8000 + 1000;
    pcb[i].priority = rand() % 3 + 1;
    pcb[i].arrival = i + timenow;
    pcb[i].burst = rand() % TIMER + 1;
    pcb[i].rest = pcb[i].burst;
    pcb[i].state = 'N';
    pcb[i].next = NULL;
  }

  FCFS(pcb);
  RR(pcb);
  SJF(pcb);
  SRTF(pcb);
  Priority(pcb);
}

/*
void sort(PCB pcb[PNUM]) { //各个进程按到达时间先后排序
  for (int i = 0; i < PNUM; i++) {
    int select = i;
   
    for (int j = i; j < PNUM; j++) {
      if (pcb[j].arrival < pcb[select].arrival) {
        select = j;
      }
    }

    PCB tmp = pcb[select];
    pcb[select] = pcb[i];
    pcb[i] = tmp;
  }
}
*/