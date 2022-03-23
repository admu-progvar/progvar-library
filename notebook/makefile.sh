while getopts t: flag
do
    case "${flag}" in
        t) teamname=${OPTARG};;
    esac
done

rm -f *.{aux,log,toc,fls,fdb_latexmk}
python3 preprocess.py
python3 build_tex.py

pdflatex -shell-escape -jobname="notebook-trunc" "\def\ICPCCONFIG{1} \def\team{$teamname} \input{notebook.tex}"
pdflatex -shell-escape -jobname="notebook-trunc" "\def\ICPCCONFIG{1} \def\team{$teamname} \input{notebook.tex}"

pdflatex -shell-escape "\def\ICPCCONFIG{1} \def\team{$teamname} \input{notebook.tex}"
pdflatex -shell-escape "\def\ICPCCONFIG{1} \def\team{$teamname} \input{notebook.tex}"

rm -f *.{aux,log,toc,fls,fdb_latexmk}
#rm -rf _code/
#rm -rf _docs/
rm -rf _minted-notebook*
