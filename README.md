# SOcket

## Compiling the system

```bash
$ make all
```

## Excecuting the system

After creating both executable files ```server``` and ```client```, the system can be excecuted.

```bash
$ ./server
```
And in a different terminal, run:

```bash
$ ./client <HOST> <PORT>
```
`HOST` and `PORT` can be modified in the code but should be `0.0.0.0` and `8080` respectively.  

## Testing

The user can run the implemented static tests by using the following commands:

```make pvs-studio-test```

```make cpp-check-test```

Note that pvs-studio and cpp-check do need to be installed. 

## Easter Eggs

The group could only find the one that appears when using the comand `strings`. There a cow can be seen saying "Esto es un Easter egg".
