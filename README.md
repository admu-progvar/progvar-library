# AdMU ProgVar Competitive Programming Library
A collection of algorithms, data structures and other useful information for competitive programming.
Used and maintained by members of the Ateneo de Manila University Programming Varsity.

![front page](https://user-images.githubusercontent.com/14250344/137528399-de98a987-df39-4241-baed-0f707f32e6e1.png)

This repo is a mixture of our previous team notebook, [Reykjavik University's open-source team notebook](https://github.com/SuprDewd/CompetitiveProgramming), and various code snippets from the web.

---

## Goals

### Long-term Goals:
- Develop this into a fully-fledged code library for competitive programming. Like [Atcoder's AC Library](https://github.com/atcoder/ac-library) but with more algorithms and data structures.
- Write wikis, documentation, and tutorials for each of the algorithms and data structures here.
- Make the team notebook easily customizable; maybe based on analytics on how often a team uses each code snippet.

### Short-term Goals
- Move the codes in `pvl/abridged` to `pvl` and add tests for each of them.
- Clean-up the team notebook.
- Add tutorials (even just as comments) on how to use each code snippet.
- Replace the headline image with something more catchy.

---

## How to Contribute

### Prerequisites
- Latex and extra plugins and fonts
```
// Warning: this could take up around 2 Gb of space
sudo apt install texlive-latex-base
sudo apt install texlive-latex-extra
sudo apt install texlive-fonts-extra

// or simply,

// Warning: this could take up around 5 Gb of space
sudo apt install texlive-full
```
- Pygments
```
pip3 install Pygments
// or
pip install Pygments
```
- Cmake, for testing
```
sudo apt install cmake
```

#### Pre-commit
We use [Pre-commit](https://pre-commit.com/) to make sure the codes are properly linted.
- Install Pre-commit using `pip3 install pre-commit`.
- Then run `pre-commit install` to setup the git hook scripts.

### Contribution Workflow:
1. Clone this repository using `git clone https://github.com/admu-progvar/progvar-library.git`
2. Create a new branch using `git checkout -b [add your 2-letter initials here]--[branch code]`. For example `git checkout -b fc--edit-readme`
3. Add codes to the folder `/pvl`
4. Add tests if necessary. See the section below for more details.
5. Add an abridged version of your codes to `/pvl/abridged`
6. Document your codes in `notebook.tex`
7. Run `notebook/makefile.sh` to generate the notebook
8. Submit a pull request
9. Tag someone to review your code
10. Merge your PR only after receiving at least 1 approval from a reviewer

### Tests
We use [GoogleTest](https://github.com/google/googletest) for writing tests for C++.
#### Adding tests
- Add tests in the `/tests` directory. Say, `hello_test.cc`.
- Add the following to `/tests/CMakeLists.txt`:
```
add_executable([Name of Test] /path/to/test/hello_test.cc)
target_link_libraries([Name of Test] gtest_main)
gtest_discover_tests([Name of Test])
```
#### Testing
- First, go to `/tests/`
```
cd tests
```
- Then build the tests
```
cmake -S . -B build && cmake --build build
```
- Go to `build/`
```
cd build
```
- And finally, run the tests
```
ctest
```

### (sub)(sub)Section Syntax:
- <span style="color:red">Red</span>: copy-pasted / non-tested code.
- <span style="color:black">Black</span>: either no code yet or we intentionally removed it from the default format of the team notebook.
- To color a (sub)(sub)section, simple use `(sub)(sub)section(COLOR)`
    - For example, `subsectionBlack` gets you a black-colored subsection

### Todo
- Add layout.txt
- Add more tests
- Add implementation of:
  - Dominator Tree
  - Fast Matrix Inverse in $F_2$
- Add benchmarking with [Google Benchmark](https://github.com/google/benchmark)

## Maintainers
### Lead Maintainer
- [Franz Louis Cesista](https://github.com/leloykun)
  - World Finalist on the [International Collegiate Programming Contest](https://icpc.global/)
  - Software Engineer @ [Expedock](https://www.expedock.com/)
  - BS Mathematics @ Ateneo de Manila
### Contributors
- Ateneo's Programming Varsity Alumni
- [Justin M. Tan](https://github.com/bullybutcher)
