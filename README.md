Pasos para correr el programa 

Es necesario tener instalados los drivers, poseer un atarjeta de nvidia, tener el sdk y el compilador nvcc

nvcc -O3 main.cu -o output
./output > image.ppm

Resultados 
Se realzian 3 casos para el programa sin modificaciones de rendimiento con diferentes parametros y después se repiten con el programa usando la gpu, se coloca lo encontrado abajo. Estos se realizaron seguidos, en la misma máquina sin cambiar características

el normal, sin modificaciones
520*800
5o samples 
20 depth 
0bolas
6.0686s

100 samples 
50 maxdepht
0 bolas 
48.1182s

20 samples 
20 maxdepht
14 bolas 
183.8940s

con grafica
520*800
5o samples 
20 depth 
0bolas
0.2803s

100 samples 
50 maxdepht
0 bolas 
0.6012s

20 samples 
20 maxdepht
14 bolas 
0.9330s


Explicación de algunas cosas importantes:
* Para el ambiente de desarrollo ayudado mediante dispositivos de procesamiento gráfico es de importancia resaltar el formato de los números, esto ya que las gŕaficas son fuertemente dependientes del tamaño de los datos. Esto significa que en esta fase del proyecto se pueden encontrar solamamente datos de tamaño menor o igual a presición simple
* Todos los smartpointes tienen que ser cambiados a punteros normales ya que la grafica no tiene el soporte de estos

* El programa se divide en el host (manejado por el procesador) y el service manejado por la gráfica. glonal y service son modificadores que representan pedazos de código escrito en kernel para la interpretación 
* El manejo del compilador nvcc para la parte de compilación de archivos mediante cmake se complicó debido a incompatibilidades con el ide y linux
* Al momento de compilar salen dos warnings:
    ptxas warning : Stack size for entry function '_Z12create_worldPP8hittableS1_PP6cameraiiP17curandStateXORWOW' cannot be statically determined
    ptxas warning : Stack size for entry function '_Z6renderP4vec3iiiPP6cameraPP8hittableP17curandStateXORWOW' cannot be statically determined
Estas se refieren a que no se puede determinar el tamaño que van a tener 2 secciones. al principio del main se escribe en comentarios que partes el usuario no debería modificar más allá de los límites 
* El gran cambio de código hace que los test queden obsoletos al 100%, además la herramienta valgrind pierde la posibilidad de trakear toda la memoria entonces genera errores 
* Se cuenta con la explicación base de https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/ quien explica cómo se realizan los pasos del proyecto orignal

