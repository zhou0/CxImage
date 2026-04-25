import sys

def fix_braces(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    # We want to fix Draw and Draw2HBITMAP
    # Draw starts at line 822 (originally)
    # Draw2HBITMAP starts at line 1145 (originally)

    new_lines = []
    for line in lines:
        if '^I' in line:
            line = line.replace('^I', '\t')
        new_lines.append(line)

    with open(filename, 'w') as f:
        f.writelines(new_lines)

fix_braces('CxImage/ximawnd.cpp')
