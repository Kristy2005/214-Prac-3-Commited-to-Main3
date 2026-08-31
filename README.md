# 214-Prac-3-Commited-to-Main3
# EventFlow - Summer Music Festival

## Event Concept

EventFlow models an 18+ outdoor Summer Music Festival with multiple event areas and services, including stages, entrance and stage gates, bars, food vendors, security teams and medical teams. The system uses the Composite and Observer design patterns so that festival components can be grouped, managed and notified of changing event conditions such as weather alerts, capacity alerts, pauses, resumptions and evacuations.

## Team Members

- Kristy - Student Number: u24702341
- Thabo - Student Number: u24742512
- Lindo - Student Number: u24891968

## Architecture Overview

The project combines the Composite and Observer design patterns.

### Composite Pattern

`EventComponent` is the common component interface used by the festival structure.

`EventGroup` is the Composite and can contain both other `EventGroup` objects and concrete event units.

Concrete event units include:

- `Stage`
- `EntranceGate`
- `StageGate`
- `Bar`
- `FoodVendor`
- `SecurityTeam`
- `MedicalTeam`

This allows the festival to be represented as a tree structure with several levels of nesting.

### Observer Pattern

`Subject` manages registered observers and provides `attach()`, `detach()` and `notify()` behaviour.

`Observer` defines the `update()` operation used by objects that receive notices.

`EventControl` acts as the central event control subject.

`EventGroup` can act as both an Observer and a Subject. This allows a notice to be received from a higher level and then passed down to registered observers below it.

The project uses a push-style Observer implementation where a `Notice` object is sent directly to observers.

## Building the Project

The project requires a C++11 compatible compiler and `make`.

From the project directory, run:

```bash
make
```

This builds the executable:

```text
eventflow
```

## Running the Project

After building the project, run:

```bash
./eventflow
```

## Cleaning the Project

To remove generated object files and the executable, run:

```bash
make clean
```

## Doxygen Documentation

Doxygen is used to generate documentation for the public classes and operations.

Make sure Doxygen is installed, then run:

```bash
doxygen Doxyfile
```

After generation, open the generated HTML documentation from the output directory configured in the `Doxyfile`.

If the default HTML output directory is being used, open:

```text
html/index.html
```

## GitHub Workflow

The repository is private for submission.

During development, the team used separate branches and pull requests to integrate work into `main`. Team members reviewed each other's changes before merging, which helped keep `main` as the most recent approved version of the project and reduced merge conflicts.

All three team members contributed commits and pull requests throughout development.

## Development Requirements

- Language: C++11
- Build system: Makefile
- Executable: `eventflow`
- Documentation: Doxygen
- Version control: Git and GitHub
