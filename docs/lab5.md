# Lab 5 
Marcus Diaz
<!-- one sentence/phrase about what your tool does -->
calculate grade in class
<!-- collaborator if applicable -->

## Use case
For this calculator, I'll need to consider the grading system for the class, which includes different thresholds and letter grades. Additionally, I'll need to account for the influence of each badge earned on the final grade. The following information will be used:

## Design
Grading System:
D: 44
D+: 62
C-: 80
C: 98
C+: 116
B-: 134
B: 152
B+: 170
A-: 188
A: 206
Learning badges: Weight = 1, Varying complexity
Community badges: Complexity = 1, Weight varies based on learning badges earned
There are hard thresholds on learning badges, and community badges can make exceptions to these thresholds.

The order of application for community badges:

Make up for missing experience badges
Make up for missing review or practice badges to reach a total of 18 between these two types
Upgrade review to practice to meet a threshold
Give a step up (highest weight)
The goal is to calculate my final grade in the class based on this system and the badges I've earned.
<!-- write a bash line that shows how you would use your command with existing commands and pipes -->






## Reflection

1. How did this exercise impact your understanding of the unix philosophy?
 This exercise highlighted the power of Unix philosophy in breaking down complex tasks into modular, simple tools that can be combined effectively.

1. How did this planning exercise compare to your past experiences with planning out code? 
  Planning this exercise felt similar to planning out code, as I needed to understand the problem, break it into steps, and decide how to implement those steps.
2.  What is the most important thing you learned in this lab?
   The most crucial lesson from this lab is understanding how badges and their influence can impact my final grade in the class.
1. Would you recommend this lab activity be reused? (yes/no/or suggested changes are welcome)
2. I would recommend this lab activity, but with some improvements to provide clearer context and instructions, especially regarding the specific data and calculations involved.
