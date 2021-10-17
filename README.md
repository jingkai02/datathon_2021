# Major Explorer Project

## Project Description 
The Major Explorer project aims to support undergraduate students from University of Wisconsin-Madison with choosing majors. 

Major requirements are scraped from [UW Guide](https://guide.wisc.edu/), where information about all academic programs can be found. Our **Major Explore** program compares overlapping classes between majors and generates optimized class selections to aid students in exploring classes, double major planning and major changing. 

This project focuses on Data Science major and some relevant majors like Mathematics in Data & Risk Analysis and Actuarial Science. Users are able to choose their current major and additional major they are considering. Monte Carlo Simulation is applied for decision making and a table with classes with least amount of credits needed to fulfill both requirement is generated in the user interface. 

This could help in deciding whether or not to pursue a major as well as aid in degree planning. 

## How to use this program
1) Download the files from the repository
2) Open up the `Interface.ipynb` file in Jupyter Notebook and "Restart and Run All"
3) You can now interact with the program and choose your current major + double major choice.


## What We Did:
1. Scraped class requirement datasets from UW Guide<br/>
      i) [Data Science](https://guide.wisc.edu/undergraduate/letters-science/statistics/data-science-bs/#requirementstext) <br/>
      ii) [Mathematics (Data and Risk Analysis)](https://guide.wisc.edu/undergraduate/letters-science/mathematics/mathematics-ba/mathematics-mathematics-data-risk-analysis-ba/)) <br/>
      iii) [Actuarial Science](https://guide.wisc.edu/undergraduate/business/risk-insurance/business-actuarial-science-bba/#requirementstext) <br/>
2. Used Monte Carlo simulation to find best combination of classes to take in current major:
      i) Based on class combination criteria for each major, generate random sets of classes for student
      ii) Weight each class by how many criteria in the second major it overlaps with
      iii) Sort class weights in ascending order and iteratively assign overlapping classes to second major, then calculate num of remaining classes needed
      iv) Over all iterations, find the class combination resulting in least num of remaining classes
3. Incorporated intuitive GUI and allowed users to choose primary major and second major from drop-down menu provided

- Output: Num of additional classes needed, optimal classes to take in current major

 
## Why We Care:
1. As the world and subjects gets more integrated, over 1 in 5 students have double majors in their first bachelor's degree. At the same time, around 1 in 3 students enter college as "undecided", and this rate is even higher for underrepresented students, such as first-generation students. Also, around 50% - 75% of students change their majors in college.
2. Higher education is important, but with a variety of options provided, it could be overwhelming for college students to distinguish between majors and classes.
3. If there is a more integrated system where people can access the feasibility of completing a major, it would make the selection of major and higher education in general much less overwhelming.
4. For incoming students exploring majors, this project establishes areas of theory studies and possible real-life applications.
5. Overlapping coursesis are visually shown for more thoughtful decision making.
6. This project assesses chaging majors in a realistic way, taking time considerations (in terms of credits) for graduation into account.
7. Therefore, this project has real-world impact for a considerable proportion of undergraduate students. These include students who are considering double majoring, students who are considering major changes, and students who are just simply exploring possibilities. After assessing the amount of overlap between their majors and other majors, they will be able to make more informed plans for their future. We wanted to create a platform where people could assess their availability by the classes needed, the overlapse of those classes, the prerequisites to take those credits (so it is a realisitic representation of what is needed). In the future, more can be added to this project, such as the grade distribution for these classes, and the rate my professor rate for the usual professors of those classes, to benefit students.
8. Higher education is stressful, but there will always be people there to help, and we want to be a part of that.
