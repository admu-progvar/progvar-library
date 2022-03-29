import os

for path, dirs, files in os.walk('./structure'):
  for f in files:
    if not f.endswith('.md'): continue

    p = os.path.join(path, f)
    fout_tex = os.path.join("tex", '.'.join(f.split('.')[:-1]) + '.tex')
    print(fout_tex)

    try:
      os.makedirs(os.path.dirname(fout_tex), exist_ok=True)
      print("Created file", fout_tex)
    except:
      print("Couldn't create file", fout_tex)
      pass

    dat = [line for line in open(p).read().splitlines()]

    with open(fout_tex, 'w') as out:
      print("\\section{{{}}}".format(dat[0]), file=out)
      for line in dat[1:]:
        num_spaces = len(line) - len(line.lstrip()) + 2
        subs = num_spaces//2
        line = line.lstrip()[2:]
        blocks = line.split('|')

        if "comment" in blocks: continue

        if (line.endswith(".cpp") or line.endswith('.java') or
            line.endswith('.sh') or line.endswith('.py')):

          fdocs = os.path.join("_docs", f[:-3], '.'.join(blocks[-1].split('.')[:-1]) + '.md')
          with open(fdocs, 'r') as fdocs_:
            for doc_line in fdocs_.readlines():
              if len(doc_line.strip()) == 0: continue
              print(" "*num_spaces + doc_line, end="", file=out)

          print(" "*num_spaces + "\\code{{{}/{}}}".format(f[:-3], blocks[-1]), file=out)
        else:
          if "black" in blocks:
            print(" "*num_spaces + "\\" + "sub" * subs + "sectionBlack{{{}}}".format(blocks[-1]), file=out)
          elif "red" in blocks:
            print(" "*num_spaces + "\\" + "sub" * subs + "sectionRed{{{}}}".format(blocks[-1]), file=out)
          else:
            print(" "*num_spaces + "\\" + "sub" * subs + "section{{{}}}".format(blocks[-1]), file=out)
