---
layout: default
title: Numpy
lang-ref: chapter1.0
---


zero pad a 1D array
look here for ref <https://stackoverflow.com/questions/35751306/python-how-to-pad-numpy-array-with-zeros>
```python
input_data = np.array([19, 27, 18])
padded_input_data = np.zeros((5)) 
padded_input_data[:len(input_data)] = input_data

# output:  [19, 27, 18, 0, 0]
```



change data type of an array
```python
array = array.astype(np.float32) 
```



expand dimensions [ex:- (50) => (1,50)] 
```python
array = np.expand_dims(array, axis=0)
```




```python

```




```python

```