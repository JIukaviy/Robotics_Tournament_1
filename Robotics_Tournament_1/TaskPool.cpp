// 
// 
// 

#include "TaskPool.h"


TaskPool_t::TaskPool_t(int queueCount) {
	TaskQueues = new TaskQueue_t*[queueCount];
}

void TaskPool_t::PushTask(Task_t* task, int queue) const {
	TaskQueues[queue]->PushTask(task);
}

void TaskPool_t::PopTask(int queue) const {
	TaskQueues[queue]->PopTask();
}

void TaskPool_t::DoTasks() const {
	for (int i = 0; i < QueueCount; i++) {
		TaskQueues[i]->DoTask();
	}
}
