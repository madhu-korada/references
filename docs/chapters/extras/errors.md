---
layout: default
title: Errors
lang-ref: chapter1.0
---
## Installation errors

## Errors in general




### Keras:

* AttributeError: module 'keras.backend' has no attribute 'image_dim_ordering' 
	(problem occurs if keras version is > 2.2.4)

	```$ pip install keras==2.2.4```

### OpenCV in anaconda:

* ImportError: libGL.so.1: cannot open shared object file: No such file or directory

	```$ sudo apt install libgl1-mesa-glx```



### jekyll

in `require': cannot load such file -- jekyll-twitter-plugin (LoadError)

	gem install jekyll-twitter-plugin will solve the problem


