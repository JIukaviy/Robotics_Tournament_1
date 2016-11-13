// 
// 
// 

#include "TaskQueue.h"

TaskQueue_t::TaskNode_t::TaskNode_t(Task_t* task, TaskNode_t* prevTask) {
	{
		Task = task;
		if (prevTask) {
			prevTask->Next = this;
		}
	}
}

TaskQueue_t::TaskNode_t::~TaskNode_t() {
	if (Task) {
		delete Task;
	}
}

TaskQueue_t::TaskQueue_t() {
	front_node = nullptr;
	back_node = nullptr;
}

void TaskQueue_t::PushTask(Task_t* task) {
	TaskNode_t* new_node = new TaskNode_t(task, back_node);
	if (!back_node) {
		front_node = back_node = new_node;
	}
}

void TaskQueue_t::PopTask() {
	if (front_node) {
		TaskNode_t* t = front_node->Next;
		delete front_node;
		front_node = t;
		if (!t->Next) {
			back_node = front_node;
		}
	}
}

void TaskQueue_t::InitFrontTask() const {
	if (front_node) {
		front_node->Task->Init();
	}
}

void TaskQueue_t::DoTask() {
	if (front_node) {
		if (front_node->Task->DoWork()) {
			PopTask();
			InitFrontTask();
		}
	}
}
