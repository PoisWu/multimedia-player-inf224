# multimedia-player-inf224

This repo implements a multimedia player backend in C++ and frontend in Java
Swing following the instruction from these websites. 
[1](https://perso.telecom-paristech.fr/elc/cpp/TP-C++.html)[2](https://perso.telecom-paristech.fr/elc/swing/TP-Swing.html) 


## Requirement
- [mpv](https://mpv.io/)

## Launch backend
```
sh make -f ./cpp/Makefile make -f ./cpp/Makefile run 
```

## Launch Java swing frondend
```
sh make -f ./swing/Makefile 
```

## Usage
There are some files in `./cpp/media/` that can illustrate the function of the
application. One can search the following files in the search bar in the
frondend interface. The integration of mpv into frondend has not been done yet.
- film1.mp4 
- imag1.jpg 
- imag2.jpg

PS. The manuel, `./manual.pdf` of C++ backend is autogenrated by Doxygen. 


