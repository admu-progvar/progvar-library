# AdMU ProgVar Team Notebook
A collection of algorithms, data structures and other useful information for competitive programming. Used by everyone in the Ateneo de Manila University Programming Varsity.

---

### Prerequisites
LaTeX
- Install latex with `sudo apt install texlive-full` (warning: this could take up 5 Gb of space)
- Install `Pygments` with `pip3 install Pygments` or `pip install Pygments`

### How to contribute:
- Clone this repository using `git clone https://github.com/leloykun/admu-progvar-notebook.git`
- Create a new branch using `git checkout -b [add your 2-letter initials here]--[branch code]`. For example `git checkout -b fc--edit-readme`
- Add codes to the folder `/src` and edit `notebook.tex`
- Run `notebook/makefile.sh` to generate the notebook
- Submit a pull request
- Tag someone to review your code
- Merge your PR only after receiving at least 1 approval from a reviewer

### (sub)(sub)Section Syntax:
- <span style="color:red">Red</span>: copy-pasted / non-tested code
- <span style="color:black">Black</span>: no code yet
- To color a (sub)(sub)section, simple use `(sub)(sub)section(COLOR)`
    - For example, `subsectionBlack` gets you a black-colored subsection

### Todo
- Add layout.txt
- Add tests
- Automate testing and building docs with GitHub Actions
- Clean up Geometry section
- Add implementation of:
  - Dominator Tree
  - Fast Matrix Inverse in $F_2$
