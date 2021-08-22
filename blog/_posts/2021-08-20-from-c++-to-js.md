---
layout: post
title: "The Fast & Furious Data Visualizations"
date: August 20, 2021
author: David E. Ackley
---

#### August 20, 2021 David E. Ackley

The main data visualizations tools from the D3 wrapper that was created by ...
This project is a part of Empirical, a header-only C++ library equipped with tools for developing experimental software.


## A brief history lesson on Javascript
invented by Brendan Eich
simply for dynamic web pages


### The bias against JavaScript


### ECMAScript versions over the years


## Running on undefined
### nonsensical duck typing + prototype classes
### making pit stops for runtime errors
### lanes on the web assembly bridge
imports and exports
type mismatch

## Turbocharging the Javascript Engine
With the release of WebAssembly, web developers gain the ability to have 
low level control over near-native execution of client side code. (near native execution)

### compiling to wasm
opens the door for many opportunities
Stack based virtual machines
binaryen, llvm, 

### Chrome V8 and SpiderMonkey
dev tools to look at wasm
recording performance

## Emscripten supplied couplers
Emscripten comes with a variety of ways to connect C++ and JavaScript code.

### who's driving?
consider where the control flow of your application lives and where to bridge
control flow, data flow, shared memory, multithreading

### JS at the wheel
better access to web apis and other front end tools

### C++ at the wheel
javascript macros
emscripten bind classes and override with javascript
eventual support through emscripten val and wasm api thing

## Accelerating your data driven documents

### d3 wrapper chassis
Mainly built using emscripten JavaScript macros.

### D4 summer 2021 models
#### the D4 histogram
#### the D4 scatterplot

## Coming full circle

## Acknowledgements