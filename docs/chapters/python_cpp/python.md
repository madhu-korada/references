---
layout: default
title: Python
lang-ref: chapter1.0
---
#### Glob
```python
import glob
all_images = glob.glob('images/directory/' + '*.jpg')
for image in all_images:
	# do the processing
```
