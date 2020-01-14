### Docker Basic Commands

##### Show all the containers (running and exited)

``` $ docker ps -a ```

##### Show all the running containers

``` $ docker ps ```  

##### Create a container from an image

``` $ docker run -it -d <image name> ```
  
###### With volumes and gpus

``` $ docker run -it -d --gpus all -v "home/madhu/folder:/folder" --name madhu <image name> ```

###### With Display and Port 

``` $ docker run -it -d --gpus all -p 8080:8080 --net=host --env="DISPLAY" -v="$HOME/.Xauthority:/root/.Xauthority:rw" -v "/home/madhu/:/madhu" --name madhu <image name> ```

##### Access the running container

``` $ docker exec -it <container id> bash ```

##### Stop a running container

``` $ docker stop <container id> ```

##### Kill the container by stopping its execution immediately

``` $ docker kill <container id> ```

##### Create a new image of an edited container on the local system

``` $ docker commit <conatainer id> <username/imagename> ```
  
##### Give author name and message

``` $ docker commit -a "Madhu Korada" -m "put message here" <conatainer id> <username/imagename> ```

##### Login to the docker hub repository

``` $ docker login ```

##### Push an image to the docker hub repository

``` $ docker push <username/image name> ```

##### Show all the images

``` $ docker images ```

##### Delete a stopped container

``` $ docker rm <container id> ```

##### Delete an image from local storage

``` $ docker rmi <image-id> ```

##### Build an image from a specified docker file

``` $ docker build <path to docker file> ```

##### Export the image into a tar file

``` $ docker save -o madhu_deep_learning_image.tar <image-id> ```

##### Load the tar file into other machine

``` $ docker load -i <path to image tar file> ```

##### Change docker image name

``` $ docker tag old_name:docker_tag new_name:docker_tag  ```
