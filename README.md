# Windows Internals Playground 

Este repositorio contiene una colección de **códigos de prueba escritos en C**, diseñados para explorar y experimentar con la **Windows API** y **NTAPI**. La idea es entender el comportamiento interno del sistema operativo, aprender técnicas avanzadas y documentar comportamientos curiosos o útiles.

##  Estructura del repositorio

- `WinAPI/`: Pruebas relacionadas con funciones de la Windows API (como manejo de archivos, procesos, memoria, threads, etc).
- `NTAPI/`: Snippets que hacen uso directo de funciones internas (no documentadas oficialmente) expuestas por `ntdll.dll`.
- `Utils/`: Funciones auxiliares y herramientas de soporte para los ejemplos.

##  ¿Qué tipo de cosas encontrarás aquí?

- Manejo de archivos y directorios con `CreateFileW`, `ReadFile`, `WriteFile`, etc.
- Manipulación de memoria con `HeapAlloc`, `VirtualAlloc`, `NtAllocateVirtualMemory`, etc.
- Creación y manejo de procesos e hilos (incluyendo técnicas de ejecución remota).
- Interacción con objetos del kernel usando `Nt*` syscalls.
- Experimentación con estructuras internas como `PEB`, `TEB`, `EPROCESS`, etc.
- Técnicas ofensivas / defensivas (seguridad, detección de hooks, análisis de procesos).

##  Requisitos

- Windows 10/11 (preferiblemente versión 64 bits).
- [Visual Studio](https://visualstudio.microsoft.com/) con soporte para C/C++.
- Conocimientos básicos/intermedios de programación en C.
- Familiaridad con Windows Internals y herramientas como x64dbg, Process Hacker, WinDbg, etc. (opcional, pero recomendado).

##  Advertencia

> Este repositorio es **educativo y experimental**. Algunos códigos pueden interactuar directamente con componentes sensibles del sistema operativo. Ejecútalos bajo tu propia responsabilidad y siempre en entornos de prueba (máquinas virtuales).

##  Objetivo

Aprender haciendo. Explorar cómo funciona Windows "por dentro", sin miedo a romper cosas. Si algo falla... se aprende más 😉

##  Contacto / Feedback

¿Encontraste un bug o tienes ideas para nuevos experimentos? Siéntete libre de abrir un issue o enviarme un mensaje.

---

**Happy Hacking! 👾**
