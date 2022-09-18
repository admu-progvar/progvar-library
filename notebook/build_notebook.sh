while getopts n: flag
do
    case "${flag}" in
        n) teamname=${OPTARG};;
    esac
done

rm -rf *.{aux,log,toc,fls,fdb_latexmk} _code/ _docs/
python3 preprocess.py
python3 build_tex.py

pdflatex -shell-escape -jobname="notebook-trunc" "\def\ICPCCONFIG{1} \def\TEAMNAME{$teamname} \input{notebook.tex}"
pdflatex -shell-escape -jobname="notebook-trunc" "\def\ICPCCONFIG{1} \def\TEAMNAME{$teamname} \input{notebook.tex}"

pdflatex -shell-escape "\def\ICPCCONFIG{1} \def\TEAMNAME{$teamname} \input{notebook.tex}"
pdflatex -shell-escape "\def\ICPCCONFIG{1} \def\TEAMNAME{$teamname} \input{notebook.tex}"

rm -rf *.{aux,log,toc,fls,fdb_latexmk} _minted-notebook*
