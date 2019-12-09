import os
import shutil

# copy folders from a source directory hierarchy to a target directory
# if they contain any of the words or phrases in the 'keywords' list.
# relative paths are preserved

source = os.path.abspath('O:/Music/Prince/')
target = os.path.abspath('G:/Temp/')
keywords = ['1991', 'Purple']

def UpdateFiles(oldpath, newpath):
    for file in os.listdir(oldpath):
        oldfile = os.path.join(oldpath, file)
        if os.path.isfile(oldfile):
            newfile = os.path.join(newpath, file)
            if not os.path.exists(newfile):
                print('Copying ' + oldfile + ' to ' + newfile)
                shutil.copy2(oldfile, newfile)

for root, dirs, files in os.walk(source):
    newroot = root.replace(source, target)
    for folder in dirs:
        if any(word in folder for word in keywords):
            fullpath = os.path.join(root, folder)
            newpath = os.path.join(newroot, folder)
            if not os.path.exists(newpath):
                print('Copying ' + fullpath + ' to ' + newpath)
                shutil.copytree(fullpath, newpath, dirs_exist_ok = True)
            else:
                UpdateFiles(fullpath, newpath)

