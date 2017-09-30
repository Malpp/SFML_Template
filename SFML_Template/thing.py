import fnmatch
import os

matches = []
for root, dirnames, filenames in os.walk('SFML-2.4.2'):
    for i in filenames:
        print '<ProjectItem ReplaceParameters="false" TargetFileName="{0}">{1}</ProjectItem>'.format(i, (root + "\\" + i).replace("\\","\\\\"))
