SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

name=$1
if [[ $name == "init" ]]; then
    pip3 install -r $SCRIPT_DIR/requirements.txt
    pip3 install -r $SCRIPT_DIR/requirements.devtools.txt
    pre-commit install
    cat $SCRIPT_DIR/requirements.system.txt | xargs sudo apt install;
elif [[ $name == "test" ]]; then
    cd $SCRIPT_DIR/tests
    cmake -S $SCRIPT_DIR/tests -B $SCRIPT_DIR/tests/build && cmake --build $SCRIPT_DIR/tests/build
    cd $SCRIPT_DIR/tests/build
    ctest;
elif [[ $name == "build-notebook" ]]; then
    cd $SCRIPT_DIR/notebook
    bash build_notebook.sh;
else
    echo "Command $name not found" >&2
    exit 1
fi
