---
layout: default
title: Tensorflow
lang-ref: chapter1.0
---
# Tensorflow 2.x

## To use slim in TF 2 

```pip install git+https://github.com/adrianc-a/tf-slim.git@remove_contrib```
```python
import tf_slim as slim
```
## Convert whole project to tf 2.x

```tf_upgrade_v2 --intree my_project/ --outtree my_project-tf2/ --reportfile my_project-tf2/report_tf2_conversion.txt ```

## Disable eager execution and disable TF 2 behaviour

```tf.compat.v1.disable_eager_execution()```
```tf.compat.v1.disable_v2_behavior()```

# Tutorial to build an Image Classifer in Tensorflow 2.0

Tensorflow uses Keras API to further remove the complexity of Tensorflow 1. 

In this post we will see how to build a basic image classifier, how to train the classifier with custom data and few other approches to improve the classifier.

```python

```


Define the callback class and create an instance of callback. 
```python
class myCallback(tf.keras.callbacks.Callback):
  def on_epoch_end(self, epoch, logs={}):
    if(logs.get('accuracy')>0.6):
      print("\nReached 60% accuracy so cancelling training!")
      self.model.stop_training = True
```

To define optimizer, loss, metrics and callbacks.
```python
model.compile(optimizer = tf.optimizers.Adam(),
              loss = 'sparse_categorical_crossentropy',
              metrics=['accuracy'],
              callbacks=[callbacks])
```

```python
training_steps = training_images_no/batch_size_training
validating_steps = validating_images_no/batch_size_validating

history = model.fit(
      train_generator,
      steps_per_epoch=training_steps,
      epochs=100,
      validation_data=validation_generator,
      validation_steps=validating_steps,
      verbose=2)
```


```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator
# All images will be rescaled by 1./255
train_datagen = ImageDataGenerator(rescale=1./255)
test_datagen = ImageDataGenerator(rescale=1./255)
```
Using data agumentation
```python

train_datagen = ImageDataGenerator(
      rescale=1./255,
      rotation_range=40,
      width_shift_range=0.2,
      height_shift_range=0.2,
      shear_range=0.2,
      zoom_range=0.2,
      horizontal_flip=True,
      fill_mode='nearest')

test_datagen = ImageDataGenerator(rescale=1./255)
```
```python
# Flow training images in batches of 20 using train_datagen generator
train_generator = train_datagen.flow_from_directory(
        train_dir,  # This is the source directory for training images
        target_size=(150, 150),  # All images will be resized to 150x150
        batch_size=20,
        # Since we use binary_crossentropy loss, we need binary labels
        class_mode='binary')

# Flow validation images in batches of 20 using test_datagen generator
validation_generator = test_datagen.flow_from_directory(
        validation_dir,
        target_size=(150, 150),
        batch_size=20,
        class_mode='binary')
```

Plotting Training and validation accuracies and losses using **matplotlib**.
```python
import matplotlib.pyplot as plt
acc = history.history['accuracy']
val_acc = history.history['val_accuracy']
loss = history.history['loss']
val_loss = history.history['val_loss']

epochs = range(len(acc))

plt.plot(epochs, acc, 'bo', label='Training accuracy')
plt.plot(epochs, val_acc, 'b', label='Validation accuracy')
plt.title('Training and validation accuracy')

plt.figure()

plt.plot(epochs, loss, 'bo', label='Training Loss')
plt.plot(epochs, val_loss, 'b', label='Validation Loss')
plt.title('Training and validation loss')
plt.legend()

plt.show()
```

```python

```




## Tensorflow in Practice Specialization 

### TF 2 resource links

* Awesome Tensorflow 2 : Tensorflow 2.x resources such as tutorials, blogs, code and videos. Recommended level:heartheartheartheart!![link](https://github.com/Amin-Tgz/awesome-tensorflow-2)


* TensorFlow 2.0 + Keras Overview for Deep Learning Researchers : by the father of Keras: Twitter ’s super-liked TF 2.0 + Keras crash course. Need to look over the wall.[colab_link](https://colab.research.google.com/drive/1UCJt8EYjlzCs1H1d1X0iDGYJsHKwu-NO#scrollTo=88ExjKfCo7aP)










# Tensorflow 1.x


## TFlite

### convert a model to tflite (tf 1.15)
```python 

model_loc = 'models/model/'
meta_name = 'my_model0.meta'
pb_dir = model_loc + 'pb'

tflite_filename = 'models/static_rnn_lstm.tflite'

with tf.compat.v1.Session() as sess:

    new_saver = tf.compat.v1.train.import_meta_graph(model_loc + meta_name)
    new_saver.restore(sess, tf.train.latest_checkpoint(model_loc))
    
    graph = tf.compat.v1.get_default_graph()

    # get the input and output tensors using tensor names
    input_tensor = graph.get_tensor_by_name('bacth_in:0')
    output_tensor = graph.get_tensor_by_name('last_fc/Sigmoid:0')

    converter = tf.compat.v1.lite.TFLiteConverter.from_session(
    sess, [input_tensor], [output_tensor])
    
    # ## Flag to enable MLIR converter (Generally TOCO converter is used)
    # converter.experimental_new_converter = True

    # ## Enable the quantizer
    # converter.experimental_new_quantizer = True

    # ## Allow the custom ops (if you wrote custom ops)
    # converter.allow_custom_ops = True
    # converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS,
    #                                    tf.lite.OpsSet.SELECT_TF_OPS]

    tflite_model = converter.convert()
    print('Model converted successfully!')
    open(tflite_filename, "wb").write(tflite_model)

```

### To do Inference using tflite models
```python
# Load TFLite model and allocate tensors.
interpreter = tf.lite.Interpreter(model_path=tflite_filename)#"madhu_lstm_test1.tflite")
interpreter.allocate_tensors()

# Get input and output tensors.
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# print(input_details)
# print(output_details)
# get the shape of input tensor (example = 1,30,4) 
input_shape = input_details[0]['shape']

# generate random data for input
input_data = np.random.rand(input_shape[0],input_shape[1],input_shape[2])
input_data = input_data.astype(np.float32)

interpreter.set_tensor(input_details[0]['index'], input_data)
interpreter.invoke()

# The function `get_tensor()` returns a copy of the tensor data.
# Use `tensor()` in order to get a pointer to the tensor.
output_data = interpreter.get_tensor(output_details[0]['index'])
print("output : ", output_data)
```

