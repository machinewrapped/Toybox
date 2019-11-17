#include <vector>

/*
 * Alternative implementations.
 *
 * 1. Inheritance implementation uses a standard class hierarchy with virtual functions
 * 2. Concept Model implementastion adds a virtualising wrapper so that non-related types can be used as tasks 
 *    as long as they have a 'process()' method.
 */

#include "InheritanceImplementation.h"
 //#include "ConceptModelImplementation.h"

// our tasks. all tasks are processed inside run()
std::vector<task> tasks;

// add a new task into the vector
void push(task t) {
	tasks.emplace_back(std::move(t));
}

// Runs all the task and clear the vector
void run() {
	for (auto&& task : tasks) {
		task.process();
	}

	tasks.clear();
}

void do_stuff(bool condition) {
	some_task t;

	// do some stuff with task
	t.stuff();

	// maybe push the task
	if (condition) {
		push(std::move(t));
	}
}

int main() {

	do_stuff(true);
	do_stuff(false);

	// natural syntax for object construction! Yay!
	push(some_library_task{});
	push(special_task{});
	push(print_task{});

	run();
}