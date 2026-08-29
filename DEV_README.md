# Dev README

---

## Git Rules

Main branch protection is enabled - you **cannot push directly to main**.

- All changes must go through a **Pull Request (PR)**.
- Every PR requires **at least one approval** from another team member before it can be merged.
- Do not develop directly on `main`.
- Use meaningful branch names.
- Use meaningful commit messages.
- All three team members must contribute throughout development.

Examples of good commit messages:

```text
Implement Observer attach and detach functionality
Add Composite child management
Implement Stage event responses
Add capacity alert behaviour
Create EventFlow Makefile
Add Doxygen comments to public operations
```

Avoid vague commit messages such as:

```text
stuff
changes
final
final2
fixed
```

---

## Project Requirements

This project is for COS 214 Practical 3 - EventFlow.

The required development environment is:

```text
Language: C++11
Build system: Makefile
Executable: eventflow
Documentation: Doxygen
Version control: Git and GitHub
```

The project must compile using:

```bash
make
```

The generated executable must be named:

```bash
eventflow
```

It can then be run using:

```bash
./eventflow
```

---

## Git Workflow

Before starting new work, first make sure your local `main` branch is up to date.

```bash
git checkout main
git pull
```

Create a new branch for the feature or task you are working on.

```bash
git checkout -b branch-name
```

Example branches:

```bash
git checkout -b observer-pattern
git checkout -b composite-pattern
git checkout -b event-rules
git checkout -b sequence-diagrams
git checkout -b doxygen
```

Do your work on that branch.

When you are ready to save your work:

```bash
git add .
git commit -m "Implement Observer notification system"
```

Push the branch to GitHub:

```bash
git push -u origin observer-pattern
```

Then create a Pull Request on GitHub from:

```text
observer-pattern -> main
```

Another team member must review and approve the Pull Request.

Once approved, the Pull Request can be merged into `main`.

---

## Starting New Work After a Merge

Before starting another feature, update your local copy of `main`.

```bash
git checkout main
git pull
```

Then create another branch:

```bash
git checkout -b new-feature-name
```

Do not continue using an old branch for unrelated work.

---

## Team Collaboration

All three team members must make meaningful contributions to the repository.

Each team member should:

* Make their own commits.
* Work on identifiable parts of the project.
* Commit regularly during development.
* Use meaningful commit messages.
* Review Pull Requests from other team members where appropriate.
* Understand the complete final system.

The repository history must show genuine development over time.

Do not wait until the end of the practical and upload the entire project in one commit.

---

## Branch Naming

Use short names that clearly describe the work being done.

Examples:

```text
observer-pattern
composite-pattern
event-control
event-rules
capacity-alert
doxygen
sequence-diagrams
makefile
```

For a specific fix:

```text
fix-observer-detach
fix-memory-leak
fix-composite-removal
```

---

## Pull Requests

Every change to `main` must go through a Pull Request.

A Pull Request should have a meaningful title.

Good examples:

```text
Implement Observer pattern
Add Composite event structure
Add event notification behaviour
Add Doxygen documentation
Implement runtime event reorganisation
```

Before approving a Pull Request, check that:

* The code compiles.
* Existing functionality still works.
* The changes belong to the stated feature.
* There are no obvious memory-management problems.
* The code follows the agreed design.
* The commit history is understandable.

---

## Required Repository Files

The final GitHub repository must contain at least:

```text
*.h
*.cpp
main.cpp
Makefile
README.md
DEV_README.md
Doxyfile
docs/
```

The `docs/` directory should contain the required diagrams, report material or exported copies used for the practical submission.

---

## README.md

The main `README.md` is separate from this development guide.

It must eventually contain:

* Event concept.
* Team member names.
* Instructions for building the project using `make`.
* Instructions for running `eventflow`.
* Doxygen instructions.
* Brief architecture overview.

Do not use `DEV_README.md` as a replacement for the required `README.md`.

---

## C++ Requirements

The project must use C++11.

The compiler configuration in the Makefile must therefore include:

```text
-std=c++11
```

Every polymorphic base class must have a virtual destructor.

For example:

```cpp
virtual ~EventComponent() {}
```

Ownership must be clearly defined so that all dynamically allocated objects are destroyed exactly once.

---

## Composite Pattern Requirements

The EventFlow system must contain a genuine Composite structure.

The common component interface must support sensible versions of:

```cpp
virtual void open() = 0;
virtual void close() = 0;
virtual void reportStatus() const = 0;
virtual int getCapacity() const = 0;
```

A Composite must be able to contain:

```text
Leaf objects
Other Composite objects
```

The final event must contain at least three levels of Composite nesting and at least five distinct concrete Leaf types.

---

## Observer Pattern Requirements

The Observer implementation must contain operations equivalent to:

```cpp
attach(Observer* observer)
detach(Observer* observer)
notify()
update(...)
```

The system must demonstrate observers being:

```text
attached
detached
notified
```

at runtime.

At least one Composite-level object must be able to receive a notification from above and notify interested observers below.

The notification must be capable of cascading through at least three runtime levels.

---

## Observer Policy

The team must decide whether Observer communication uses:

```text
Push
```

or:

```text
Pull
```

This choice must be used consistently in the implementation and diagrams.

The team must also clearly define:

* Whether Subjects own Observer objects.
* How duplicate registrations are handled.
* What happens when `detach()` is called for an Observer that is not registered.
* How dangling Observer pointers are prevented.
* What happens when an Observer changes registration.

These decisions must agree between the C++ code, UML class diagram and sequence diagrams.

---

## Runtime Behaviour

The final program must demonstrate:

```text
Composite construction
Observer registration
At least three different notices
At least one cascading notification
A registration change
A Composite traversal or query
A runtime reorganisation
Clean shutdown
```

At least six notice or order types must exist.

These should include:

```text
an operational notice
a capacity-related notice
a safety-related notice
```

Possible examples include:

```text
OPEN
CLOSE
SCHEDULE_CHANGE
CAPACITY_ALERT
WEATHER_ALERT
PAUSE
RESUME
EVACUATE
```

---

## Doxygen

Public classes and public operations must be documented using Doxygen.

Example:

```cpp
/**
 * @brief Registers an observer for future event notifications.
 *
 * This Subject stores a non-owning pointer. The observer must remain
 * alive while registered and must be detached before destruction.
 *
 * @param observer Observer to register. Must not be nullptr.
 */
virtual void attach(Observer* observer) = 0;
```

Use:

```text
@param
```

for parameters.

Use:

```text
@return
```

for non-void return values.

Ownership and lifetime expectations should also be documented where raw pointers cross an interface.

Generate the documentation using:

```bash
doxygen Doxyfile
```

---

## Sequence Diagrams

The project requires four substantial UML sequence diagrams.

They must correspond to real operations in the final implementation.

The four required scenarios are:

```text
SD1 - Building and registering part of the event

SD2 - Cascading event notification

SD3 - Conditional event response and Composite behaviour

SD4 - Signature event scenario
```

Across the sequence diagrams, use:

```text
loop
alt
opt
```

where required.

Sequence diagrams must use object-instance lifelines rather than only class names.

Example:

```text
mainZone : EventGroup
```

rather than:

```text
EventGroup
```

---

## Before Pushing Code

Before committing or pushing code, run:

```bash
make
```

Make sure the project compiles successfully.

Then run:

```bash
./eventflow
```

Make sure the required behaviour still works.

Only then commit and push your changes.

---

## Important

Always start new work with:

```bash
git checkout main
git pull
```

Then create a new branch.

Do not push directly to `main`.

Do not commit the entire practical only at the end.

Use GitHub throughout development so that the repository clearly shows the contributions of all three team members.
