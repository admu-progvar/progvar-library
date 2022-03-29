import os
from pathlib import PurePath, Path

MARGIN = 62
COMMENTS = ['"""', "'''", "/*", "*/"]


def generate_codes_and_docs(code_directory="../pvl/abridged"):
    for path, _, files in os.walk(code_directory):
        for f in files:
            if (
                f.endswith(".cpp")
                or f.endswith(".java")
                or f.endswith(".sh")
                or f.endswith(".py")
            ) and not f.endswith(".test.cpp"):
                p = os.path.join(path, f)
                path_tuple = PurePath(path).parts
                fout_code = os.path.join("_code", Path(*path_tuple[3:]), f)
                fout_docs = os.path.join(
                    "_docs", Path(*path_tuple[3:]), ".".join(f.split(".")[:-1]) + ".md"
                )
                print(fout_code, fout_docs)

                os.makedirs(os.path.dirname(fout_code), exist_ok=True)
                os.makedirs(os.path.dirname(fout_docs), exist_ok=True)

                dat = [line for line in open(p).read().splitlines()]
                docs = []

                with open(fout_code, "w") as out:
                    warning = False
                    error = False
                    last = False
                    is_doc_line = 0
                    for line in dat:
                        if line.strip() in COMMENTS:
                            is_doc_line = 1 - is_doc_line
                            continue
                        elif is_doc_line == 1:
                            docs.append(line.strip())
                            continue

                        last = False
                        s = line.lstrip(" ")
                        add = len(line) - len(s)
                        if add > 0:
                            s = " " + s
                            add -= 1
                        s = "-" * add + s
                        if len(s) > MARGIN:
                            print(s, file=out)
                            warning = True
                            last = True
                            if len(s) > MARGIN + 4:
                                error = True
                                print(len(s), MARGIN)
                                print(repr(s))
                        else:
                            if len(s) < MARGIN:
                                s += " "
                            print(s.ljust(MARGIN, "-"), file=out)

                with open(fout_docs, "w") as out:
                    # print(docs)
                    print(" ".join(docs), file=out)

                if last:
                    error = True
                if error:
                    print("ERROR: Code too wide: %s" % p)
                elif warning:
                    print("WARNING: Code (almost) too wide: %s" % p)


if __name__ == "__main__":
    print("Preprocesssing started")
    generate_codes_and_docs()
    print("Preprocesssing finished")
