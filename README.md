# Interview

This repository contains all the questions for the coding round which has been asked to me so far. I will keep this list up-to-date.

# Build

This repository uses Bazel Build System, so use following command to build particular target or run tests.

```bash
$ bazel run //algorithm/calculator/test:unit_tests
```

Change the bazel target to run various programs.

# Programs to Company to Interview Round mapping

| Program                | Underlying Algorithm/Data Structure | Interview Round | Company |
| ---------------------- | ----------------------------------- | --------------- | ------- |
| shared_ptr.cpp         | STL                                 | Round 1         | ArgoAI  |
| find_right_sibling.cpp | breadth_first_traversal, STL        | Round 4         | ArgoAI  |
| calculator.cpp         | stringstream                        | Round 5         | ArgoAI  |
| find_max_ride.cpp      | permutation combinations, STL       | Round 6         | ArgoAI  |
