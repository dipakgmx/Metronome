# Metronome

A Qt based Metronome

## Necessary QT Plugins
```
sudo apt-get install qtmultimedia5-dev
sudo apt-get install libqt5multimedia5-plugins
```

## Installation

Run the following in the extracted folder:
```
cmake -H. -Bbuild
cmake --build build -- -j3
```
The generated executable could be found in the `build` folder.
