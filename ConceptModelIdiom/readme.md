Examination of the Concept Model idiom described at https://gracicot.github.io/conceptmodel/2017/09/13/concept-model-part1.html

Two implementations of the same system, include one or the other to compare:

1. Inheritance implementation uses a standard class hierarchy with virtual functions
2. Concept Model implementastion adds a virtualising wrapper so that non-related types can be used as tasks 
   as long as they have a 'process()' method.

As can be seen, several of the advantages claimed for the Concept Model idiom are artefacts of implementation, not
inherently related to the Concept Model idiom.

Claim 1: "First, it enable polymorphism with a natural syntax. It looks uniform, and also has a lighter syntax."

Conclusion: An identical syntax can be achieved using standard polymorphism

Claim 2: "Second, it avoid heap allocation. Yes indeed, even if we pass around our object inside a unique pointer internally...
    In this example, t is pushed into the list conditionally. If we don’t need heap allocation and polymorphism, 
    we can decide at runtime to not use it."
    
Conclusion:
    Both implementations have an identical number of heap allocations at exactly the same points (the make_unique call in task's constructor).
    Similarly, the compiler will bypass the vtable when calling a method on a concrete object, so the virtualisation overhead is avoided 
    in both implementations when not used.

The only claimed benefit of the Concept Model that stands up to scrutiny is that it provides duck-typing - any object with
a 'process' method taking no arguments  can be used as a task without modification.  This is definitely a useful tool in some
situations, e.g. a scheduler which allows tasks from a variety of unrelated systems to be executed on a common schedule is an
excellent use of the technique.

In other circumstances, inheritance is a natural fit for the system being modelled and there is no practical advantage to using 
Concept Model instead of the more readily available methods for runtime polymorphism built in to the C++ language.

