---
layout: default
title: Ffmpeg
lang-ref: chapter1.0
---
Output one image every second:

ffmpeg -i input.mp4 -vf fps=1 out%d.png


Output one image every minute:

ffmpeg -i test.mp4 -vf fps=1/60 thumb%04d.png


Output one image every 10 minutes:

ffmpeg -i test.mp4 -vf fps=1/600 thumb%04d.png
