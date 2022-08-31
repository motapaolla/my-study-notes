# docker

### List all images that are locally stored with the Docker Engine

`$ docker image ls`

```

### Delete an image from the local image store

`$ docker image rm alpine:3.4`

### Print the last 100 lines of a container’s logs

`$ docker container logs --tail 100 web`

Delete all unused images

`$ docker image prune --all`

Remove TUDO:

`$ docker rmi -f $(docker images -a -q)`

Remove imagens intermediárias:

```
docker image rm -f $(docker images -f "dangling=true" -q)
```

Error response from daemon: conflict: unable to delete e89273b447b5 (cannot be forced) - image has dependent child images