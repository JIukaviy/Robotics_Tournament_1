// TaskPool.h

#ifndef _TASKPOOL_h
#define _TASKPOOL_h

#include "Task.h"
#include "TaskQueue.h"

class TaskPool_t {
private:
	TaskQueue_t** TaskQueues;
	int QueueCount;
public:
	TaskPool_t(int queueCount = 10);

	void PushTask(Task_t* task, int queue) const;
	void PopTask(int queue) const;
	void DoTasks() const;
};

#endif

