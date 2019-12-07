import os
import shutil

# copy folders from a source directory hierarchy to a target directory
# if they contain any of the words or phrases in the 'keywords' list.
# relative paths are preserved

source = os.path.abspath('O:/Music/Prince/')
target = os.path.abspath('G:/Temp/')
keywords = ['1991', 'Purple']

for root, dirs, files in os.walk(source):
    newroot = root.replace(source, target)
    for folder in dirs:
        if any(word in folder for word in keywords):
            fullpath = os.path.join(root, folder)
            newpath = os.path.join(newroot, folder)
            print('Copying ' + fullpath + ' to ' + newpath)
            shutil.copytree(fullpath, newpath)

            
