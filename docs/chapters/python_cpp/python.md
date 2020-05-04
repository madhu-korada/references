---
layout: default
title: Python
lang-ref: chapter1.0
---
## Ref links
<https://www.programiz.com/python-programming/file-operation>
## OS Library

Print current directory
```python
print(os.getcwd())
```

Change base directory
```python
os.chdir('C:\\Python33')
```

Making directory
```os.mkdir('/folder/name/')```

List directories
```python
os.listdir()
```
No of files inside a directory
```len(os.listdir('/folder/name/'))```

Remove a file
```
os.remove('old.txt')
```

Remove empty directory
```os.rmdir('/tmp/cats-v-dogs/')```

Remove the directory containing files
```python
import shutil
shutil.rmtree('/tmp/cats-v-dogs/')
```


## Glob
```python
import glob
all_images = glob.glob('images/directory/' + '*.jpg')
for image in all_images:
	# do the processing
```
