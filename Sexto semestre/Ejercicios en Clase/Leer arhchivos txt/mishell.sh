#!/bin/csh
#!/bin/bash

echo 'Hola Mundo'
./conversion $1
@ a = $? + 0
echo $a
if($a == 0) then
    echo 'no hubo errores'
else
    echo 'hubo errores'
endif