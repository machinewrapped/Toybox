#pragma once

#include <memory>
#include <iostream>

/* Base class for our tasks */
struct task_base {
	virtual ~task_base() {};
	virtual void process() = 0;
};

// Cannot change that! library!
struct library_task {};

struct some_library_task : public task_base, library_task {

	void process() override {
		std::cout << "Library Task" << std::endl;
	}
};

// some of our tasks.
struct print_task : task_base {
	void process() override {
		std::cout << "Print Task" << std::endl;
	}
};

struct special_task : task_base {
	void process() override {
		process(false);
	}

	int process(bool more_stuff) const {
		std::cout << "Special Task" << std::endl;
		return 1;
	}
};

struct some_task : task_base {
	void process() const {
		std::cout << "Some Task" << std::endl;
	}

	void stuff() {
		std::cout << "Some Task Stuff" << std::endl;
	}

private:
	void process() override {
		const_cast<some_task const*>(this)->process();
	}
};

// Container for all tasks, manages lifetime
struct task {
	template<typename T,
		typename = std::enable_if_t<std::is_base_of<task_base, T>::value> >
	task(T t) noexcept
		: self{ std::make_unique<T>(std::move(t)) }
	{}

	void process() {
		self->process();
	}

private:
	// the contained erased type
	std::unique_ptr<task_base> self;
};

