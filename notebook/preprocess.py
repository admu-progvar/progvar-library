import os
import hashlib
import re
from pathlib import PurePath, Path

TO_HASH = False
MARGIN = 100 - 40 - 8 + 7 - 1 + (0 if TO_HASH else 4)

counter = 0

COMMENTS = ["\"\"\"", "\'\'\'", "/*", "*/"]

def mkhash(line):
    global counter
    # conc = ""
    for i in line:
        # conc += re.sub('\s*', '', i) + "\n"
        counter += 1;
        hash = str(hex(counter))[2:]
        while len(hash) < 3:
            hash = "0" + hash
        yield hash
        # yield hashlib.md5(conc).hexdigest()[:2]

for path, dirs, files in os.walk('../pvl/abridged'):
    path_start = len(PurePath(path).parts)
    for f in files:
        if (f.endswith(".cpp") or f.endswith('.java') or
            f.endswith('.sh') or f.endswith('.py')) and not f.endswith(".test.cpp"):

            p = os.path.join(path, f)
            path_tuple = PurePath(path).parts
            fout_code = os.path.join("_code", Path(*path_tuple[path_start:]), f)
            fout_docs = os.path.join("_docs", Path(*path_tuple[path_start:]), '.'.join(f.split('.')[:-1]) + '.md')
            print(fout_code, fout_docs)

            try:
                os.makedirs(os.path.dirname(fout_code))
            except:
                pass

            try:
                os.makedirs(os.path.dirname(fout_docs))
            except:
                pass

            dat = [line for line in open(p).read().splitlines()]
            docs = []

            with open(fout_code, 'w') as out:
                warning = False
                error = False
                last = False
                is_doc_line = 0
                for line, hash in zip(dat, mkhash(dat)):
                    if line.strip() in COMMENTS:
                        is_doc_line = 1 - is_doc_line;
                        continue
                    elif is_doc_line == 1:
                        docs.append(line.strip())
                        continue

                    if not TO_HASH:
                        hash = ""

                    last = False
                    s = line.lstrip(' ')
                    add = len(line) - len(s)
                    if add > 0:
                        s = ' ' + s
                        add -= 1
                    s = '-'*add + s
                    if(len(s) > MARGIN):
                        print(s, file=out)
                        warning = True
                        last = True
                        if len(s) > MARGIN+4:
                            error = True
                            print(len(s), MARGIN)
                            print(repr(s))
                    else:
                        if len(s) < MARGIN:
                            s += ' '
                        print(s.ljust(MARGIN, '-') + hash, file=out)

            with open(fout_docs, 'w') as out:
                #print(docs)
                print(" ".join(docs), file=out)

            if last:
                error = True
            if error:
                print('ERROR: Code too wide: %s' % p)
            elif warning:
                print('WARNING: Code (almost) too wide: %s' % p)
