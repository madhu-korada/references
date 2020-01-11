### Docker Basic Commands

##### show all the containers (running and exited)

``` $ docker ps -a ```

##### show all the running containers

``` $ docker ps ```  

##### create a container from an image

``` $ docker run -it -d <image name> ```
  
- **With volumes and gpus**

``` $ docker run -it -d --gpus all -v "home/madhu/folder:/folder" --name madhu <image name> ```

- **With Display**

``` $ docker run -it -d --gpus all --net=host --env="DISPLAY" -v="$HOME/.Xauthority:/root/.Xauthority:rw" -v "/home/madhu/:/madhu" --name madhu <image name> ```

##### access the running container

``` $ docker exec -it <container id> bash ```

##### stop a running container

``` $ docker stop <container id> ```

##### kill the container by stopping its execution immediately

``` $ docker kill <container id> ```

##### create a new image of an edited container on the local system

``` $ docker commit <conatainer id> <username/imagename> ```
  
  --> give author name and message

``` $ docker commit -a "Madhu Korada" -m "put message here" <conatainer id> <username/imagename> ```

login to the docker hub repository

``` $ docker login ```

push an image to the docker hub repository

``` $ docker push <username/image name> ```

show all the images

``` $ docker images ```

delete a stopped container

``` $ docker rm <container id> ```

delete an image from local storage

``` $ docker rmi <image-id> ```

build an image from a specified docker file

``` $ docker build <path to docker file> ```

export the image into a tar file

``` $ docker save -o madhu_deep_learning_image.tar <image-id> ```

load the tar file into other machine

``` $ docker load -i <path to image tar file> ```

Change docker image name

``` $ docker tag old_name:docker_tag new_name:docker_tag  ```
