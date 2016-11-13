// TaskQueue.h

#ifndef _TASKQUEUE_h
#define _TASKQUEUE_h

#include "Task.h"

class TaskQueue_t {
private:
	struct TaskNode_t {
		Task_t* Task;
		TaskNode_t* Next;

		TaskNode_t(Task_t* task, TaskNode_t* prevTask);
		~TaskNode_t();
	};
	
	TaskNode_t* front_node;
	TaskNode_t* back_node;
public:
	TaskQueue_t();

	void PushTask(Task_t* task);
	void PopTask(); 
	void InitFrontTask() const;
	void DoTask();
};

#endif

