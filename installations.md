
### Anaconda:

* prevent Conda from activating the base environment by default
	
	```$ conda config --set auto_activate_base false```

### Tensorflow:

* if cuda is latest and the tensorflow is built with previous cuda version, then install cudatoolkit locally in conda
		
	```$ conda install cudatoolkit        (we can use cudatoolkit=x.y also)```
	```$ conda install cudnn ```

    or try this also 
	
	```$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cuda/extras/CUPTI/lib64```
      
	
* Numpy version < 1.17 for tensorflow 1.14
	
	```$ pip install numpy==1.16```

### TensorRT:

##### Two ways - using debfile, using zip file

* Download the tar file from nvidia website
* Using zip file, installation has been done in server. 

	```$ tar xzvf <zip_file_name>```

	```$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<eg:/home/TensorRT-3.0.4/lib>```

	* Optional 
	
	```$ cd TensorRT-3.0.4/python```

	```$ sudo pip2 install tensorrt-3.0.4-cp27-cp27mu-linux_x86_64.whl```

    if that throws error use, 

	```$ sudo env PATH=$PATH pip install tensorrt-3.0.4-cp27-cp27mu-linux_x86_64.whl```
			
	```$ which tensorrt```

    (optional) validate tensorrt installation using 

	```$ cd TensorRT-3.0.4/uff```

	```$ sudo pip2 install uff-0.2.0-py2.py3-none-any.whl```

    (optional) validate uff installation using 
	```$ which convert-to-uff```
 
 Use "/home/TensorRT-3.0.4/lib" in target link libraries and "/home/TensorRT-3.0.4/include" in include directory in CMakelists.
 if the directory of installation is inside a certain user, copy the TensorRT folder to usr/local/ 

### VS Code:

* With Snap:- ```sudo snap install --classic code```

* To use cmake:- Install cmake and cmake-tools from vs code extensions.

