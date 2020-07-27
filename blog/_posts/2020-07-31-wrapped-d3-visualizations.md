---
layout: post
title: "Wrapped D3.js Visualizations"
date: 2020-07-31
author: Elizabeth Carney
---
<link rel="stylesheet" type="text/css" media="all" href="{{ site.baseurl }}/assets/elizabethcarney/wrapped-d3-visualizations-styles.css"/>

## Wrapping D3.js Visualizations
---
![Elizabeth Carney headshot]({{ site.baseurl }}/assets/elizabethcarney/wrapped-d3-visualizations-ec-headshot.jpg)  
{:style="width: 15%;"}{:class="headshot"}
  
_Hi! I'm Elizabeth Carney, a senior at Smith College studying Computer Science and East Asian Languages with a concentration in Translation Studies. I'm especially interested in data visualization, robotics, and machine translation. In my free time, I love tinkering in makerspaces :hammer_and_wrench:, doing nail art :nail_care:, and cooking :fried_egg:. To see some of my other projects, check out [my GitHub](https://github.com/elizabethcarney)!_  
{:class="next-to-headshot"}

**This summer I got to join the WAVES team to develop tools for the next version of [Avida-ED](https://avida-ed.msu.edu/).** It teaches students about evolution with visual, interactive experiments that run on Avida, a platform for digital evolution research. Avida creates digital organisms and lets them evolve based on various parameters like mutation rate; their survival is always dictated by natural selection, just like it is in the real world. Both softwares were created by the [Digital Evolution Lab](https://devolab.org/) at Michigan State University. 

As WAVES participants, our job was to develop new features for Avida-ED, or reinforce the tools that it uses. For my project, I focused on the development of a **mammoth** library that Avida is built on: [**Empirical**](https://github.com/devosoft/Empirical).

### Empirical and the Internet
[Empirical](https://github.com/devosoft/Empirical)—which was also built by the MSU devolab—is a C++ library for scientific software development. It especially facilitates building evolutionary computation tools, because you can easily create digital organisms and worlds for them to evolve in. [Here's an example](http://mmore500.com/dishtiny/53vgh/) of a web app built with Empirical that illustrates evolutionary computation in action!

[![digital evolution timelapse](http://img.youtube.com/vi/yOhryHORQxE/0.jpg)](https://www.youtube.com/watch?v=yOhryHORQxE)  
[**Click the image above** for an evolution timelapse!](#vid-timelapse)
{:id="vid-timelapse"}

As you can see, **creating a web app is an amazing way to share and showcase your work**. Lots of researchers want to publish their experiments and results online so that more people can access and understand them. Luckily, Empirical was built with the internet in mind! Experiments written in C++ can be compiled into _super-fast_ JavaScript using Empirical tools that work with [Emscripten](https://emscripten.org/docs/getting_started/Tutorial.html). On top of that, lots of web elements are wrapped in Empirical as well, like tables  :spiral_notepad:, animations :next_track_button:, buttons :white_check_mark:, text areas :pencil2:, canvases :art:, and more, which means that you can easily create web pages while coding in C++!

Data visualization is particularly important to researchers trying to share their results. Incorporating colors and graphics into a report catches the reader's eye and definitely helps them understand the content better. That's why (in my opinion) one of the coolest web tools in Empirical's collection is the **C++-wrapped version of D3.js**, a JavaScript data visualization library!

### What Does "Data-Driven Documents" Mean?
The "D3" in D3.js stands for **Data-Driven Documents**, meaning that **D3.js allows you to bind data to actual HTML document elements** (like circles or lines) instead of abstracting the data binding through some toolkit. Because of that, using the library is an exceptionally transparent process. As a bonus, all of the visualizations you create with D3.js are SVGs; that means they're scalable and won't get "fuzzy" because the graphics are based on equations instead of pixels.

![D3.js visualization examples]({{ site.baseurl }}/assets/elizabethcarney/wrapped-d3-visualizations-d3-examples.jpg)  
{:style="width: 80%;"}   
Here are some examples of the different visualizations you can create with D3.js!

One downside to D3.js is that _it doesn't come with any pre-packaged visualizations_ out of the box. Whether you want a line graph, histogram, scatterplot, or something entirely different—**you have to build it yourself** out of axes, circles, and other simple elements. There's a beauty to this system, though. The D3.js community is huge and very active, so there are **tons** of examples of building all types of visualizations online ([see this gallery to start!](https://www.d3-graph-gallery.com/index.html)). And, if you want, you can customize your graph endlessly until it's exactly how you want it.

Here's an example of how you could use D3.js to create a simple line graph: TODO

```js
// JavaScript code block to be filled in with lots of comments
var greeting = "wazzup";
```
< Add an image of the resulting line graph here >  TODO  
![D3.js line graph]({{ site.baseurl }}/assets/elizabethcarney/wrapped-d3-visualizations-d3-line-graph.jpg)  
{:style="width: 60%;"}    
Here's the resulting line graph!

D3.js had already been wrapped for Empirical a few years ago by [**Dr. Emily Dolson**](#check-out-people) at the devolab, but a new version came out since then and it needed to be **updated and revamped**. :star2:

### Wrapping a Library
:bellhop_bell: The number-one reason to wrap D3.js in C++ for Empirical was **convenience**. Many researchers want to be able to code data visualizations that integrate seamlessly into their C++-based experiments and web apps.   
:bangbang: And, if the original library goes through frequent changes, then having a wrapper can make it **easier to update** things on your end (you only have to change the code inside the wrapper).   
:zap: Moreover, using Emscripten to compile C++ into JavaScript results in **wicked-fast** (near-native!) code on the web side.   
:mag_right: However, it's important to note that we definitely wanted the wrapper to be **recognizable** to people who'd used D3 in JavaScript before. We needed to strike a balance between convenience in C++ and similarity to JavaScript.

**Basic D3-wrapper structure:** Each D3.js module (e.g. selection, transition, axis, scale, etc.) has its own header file in `Empirical/source/web/d3`. Some modules, like scales, contain a base class for shared methods as well as other classes that build off of it. **Each D3.js method has a wrapped equivalent**, though a method might be templated or have multiple versions in the C++ code because its corresponding D3.js method could take several different types of input or return several different types of output. 

Here's an example of how we want to be able to use the C++ version of D3.js to create the same simple line graph: TODO  

```c++
// C++ code block to be filled in with lots of comments
size_t my_num = 0;
```
In the process of wrapping D3.js for Empirical, we:
  - rewrote function calls to match the current version of D3.js
  - added functionality to make using the library from C++ even easier
  - wrote new functions to help us pass data between C++ and JS cleanly
  - generally cleaned up the code and increased readability

#### Wrapping Axis.h
Things I ran into while re-wrapping a D3 module. I'll probably have code blocks in here:

```c++
// another C++ code block to be filled in
size_t my_num_again = 0;
```

#### Web Testing
Blurb about how we wanted a good testing framework, used Emily's Karma/Mocha/Chai system, Alex built TestRunner, etc.

#### A Big Ol' Bug
Info about Widgets and D3 incompatibility here.

### How to Make a Visualization with the Wrapper
> Tip: Build something in JS with D3 first

Blurbs about building visualizations with the wrapper.

#### A Scatterplot
Info about the scatterplot I make, hopefully with link to working demo.

< Screenshot of output graph here >

How to use the pre-built scatterplot visualization:

```c++
// a third C++ code block to be filled in
size_t my_num_yet_again = 0;
```
Explanation here.

---

### Thank you!
I am so thankful to have been a part of the 2020 WAVES team! Thank you to [Dr. Charles Ofria](https://ofria.com/) and [Matthew Andres Moreno](https://mmore500.com/) for organizing such an educational and well-thought-out workshop. My summer was looking bleak, but WAVES turned that upside down; I got to code and learn alongside so many incredible collaborators and mentors. Every single person I met (be it virtually) was welcoming. It was a fantastic experience!

I especially want to thank the other three members of the d3-wrapper team: [**Oliver Baldwin Edwards**](#check-out-people), and my two wonderful mentors, [**Dr. Emily Dolson**](#check-out-people) and [**Alex Lalejini**](#check-out-people).

#### Check out these wonderful people: 
{:id="check-out-people"}

> **Oliver Baldwin Edwards** (collaborator), a senior at Amherst College studying Computer Science and Statistics. We worked on this wrapper project together, and he's an amazing programmer!  
[Github](https://github.com/Oliver-BE) | [Twitter](https://twitter.com/oliver_be2)

> **Dr. Emily Dolson** (mentor), an Assistant Professor in Computer Science at Michigan State University starting this fall with formal training in Computer Science, Evolutionary Biology, and Ecology. She creates mind-blowing web apps and visualizations for her research!  
[Github](https://github.com/EmilyDolson) | [Twitter](https://twitter.com/emilyldolson) | [Website](https://cse.msu.edu/~dolsonem/)

> **Alex Lalejini** (mentor), a fifth year PhD student working with Dr. Charles Ofria in Computer Science and Ecology, Evolutionary Biology, & Behavior at Michigan State University. He is a super welcoming researcher and a brilliant coder!  
[Github](https://github.com/amlalejini) | [Twitter](https://twitter.com/amlalejini) | [Website](https://lalejini.com/)

---

### Other resources to peruse:

- [My **wrapped d3 scatterplot** visualization demo!]()
- **Empirical** library [repo](https://github.com/devosoft/Empirical), [docs](https://empirical.readthedocs.io/en/latest/), [cookiecutter](https://github.com/devosoft/cookiecutter-empirical-project), and [example gallery](https://empirical.readthedocs.io/en/latest/BuiltWithEmpiricalGallery)
- Empirical's [**Web Tools** docs](https://empirical.readthedocs.io/en/latest/library/web/web.html)
- **Emscripten** [docs](https://emscripten.org/docs/getting_started/Tutorial.html) (compiles C and C++ into JavaScript to run on the web)
- **D3.js** [docs](https://github.com/d3/d3/wiki) and [Graph Gallery](https://www.d3-graph-gallery.com/index.html)
- [Javascript Testing on Travis CI with Karma and Mocha](https://devolab.org/javascript-testing-on-travis-ci-with-karma-and-mocha/) (by Emily Dolson) - this is how our **web testing** is set up!
- [The Curiously Recurring Template Pattern (CRTP)](https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/) - this is used in our wrapper's `selection.h`!
- [Salmon Run](http://avida-ed-mirror1.beacon-center.org/SalmonRun/game/), a fun game—or is it an evolutionary playground?
- If you'd like to take a look at some of my other projects, please [click here to go to **my GitHub**](https://github.com/elizabethcarney)!