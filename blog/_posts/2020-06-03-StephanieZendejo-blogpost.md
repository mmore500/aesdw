---
layout: post
title: "Designing A Genome Class in C++"
date: 2020-07-26
author: Stephanie Zendejo
---

## Introduction to MABE :dna:
During the Summer of 2020, I had the pleasure of participating in the WAVES workshop and making contributions to MABE (Modular Agent-Based Evolution). **MABE is a tool for evolving and analyzing digital brains.** :exploding_head:  Users create and manage populations of evolving digital organisms which are then evaluated in worlds. The results of the evaluations dictate the generations of new populations by means of natural, artificial, and/or sexual selection.  

The purpose of MABE is twofold:
1. Support academic research into topics related to evolution

2. Provide insight into evolution and evolutionary processes  


## What are Digital Organisms? We just don't know. 
![WHAT ARE BIRDS](https://i.imgur.com/LUSV3Kn.jpg)  
I realized in order have a better understanding of the project, I needed a refresher in biology. The last time I had taken a biology course was nine years ago. The only thing I distinctly remembered was that _the mitochondria was the powerhouse of the cell_. I put myself through an evolutionary biology bootcamp. Once I had a good handle on terms and definitions, I worked on understanding how MABE works. 

![MABE Overview](https://raw.githubusercontent.com/wiki/Hintzelab/MABE/images/MABE_Overview.png)
- **Digital organisms** contain a brain which determine how the organisms interact in their environment (or world), and a genome, which provides a blueprint for the brain. A collection of organisms make up a population.

- **Archivist** is synonymous with a person who collects all data and decides what data to be stored.

- **Optimizer** is synonmyous with a person who decides which organisms in a population will produce the next generation of organisms.

- A **Group** in MABE is made up of a population of digital organisms, an optimizer, and archivist.

#### Mutations
Mutations can occur in genomes. If an organism progresses to the next generation, mutations applied to the genome introduces new genetic variation into the population. There are three basic mutations that can occur:
- **Overwrite:** changes the value of a single site in the genome
- **Insert:** inserts sites to the genome, changing the genome size and causing offsets
- **Remove:** removes sites from the genome, changing the genome size, and causing offsets





## Changelogging to the rescue!
### My Approach

## Lessons Learned

## Conclusion

## Acknowledgements
**Mentors:** Clifford Bohm, Jory Schossau, Jose Hernandez  
**Team Members:** Jamell Dacon, Tetiana Dadakova, Victoria Cao, Uma Sethuraman  
This work is supported through Active LENS: Learning Evolution and the Nature of Science using Evolution in Action (NSF IUSE #1432563). Any opinions, findings, and conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the National Science Foundation.
