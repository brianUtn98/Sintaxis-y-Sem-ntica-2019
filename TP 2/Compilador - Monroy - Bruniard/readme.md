Pasos para compilar:
1. Abrir símbolo de sistema y ubicarse en la carpeta del proyecto.
2. Ejecutar /win_flex compilador.l
3. Ejecutar /win_bison -d compilador.y
4. Ejecutar /gcc -o compilador lex.yy.c compilador.tab.c
El paso 4 nos generará el archivo ejecutable de nuestro intérprete para lenguaje micro.

Pasos para ejecutar
1. Ejecutar el archivo compilador.exe.
2. Seleccionar modo de lectura.
3. En caso de elegir el modo por archivo, escribir como ruta pruebaN.mk, con N entre 1 y 7. (Siendo estas las pruebas propuestas por el grupo). También se pueden agregar nuevas pruebas creando archivos de texto manualmente en la carpeta del proyecto.

Para la ejecución estándar, se debe escribir linea por linea, presionando "Enter" cada vez.
