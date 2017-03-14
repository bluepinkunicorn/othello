Work Distribution:
All work was done together. Usually we would plan the algorithm together, then one 
person would type while the other person helped dictate and error check. We first 
made an Othello that would play without returning errors. Then we implemented an 
algorithm to check if possible Moves were a corner or an edge piece. If they were, we 
automatically chose that move. We wrote and debugged this together as we did 
everything.

Making our AI tournament Worthy (and expansion on work distribution):
We tried implementing a WhiteCanMove function as part of the heuristic, but it ended 
up making our player worse so we got rid of the method.

This week we also created a heuristic method, assigning scores to each move 
depending on how many pieces we would take and the value of the spot we were 
moving onto.

Why our Strategy Will Work:
Our heuristic method will work because it considers the value of spots as well as a 
way to differentiate between relatively neutral moves by how many pieces we will 
take. While a minimax would make this even better, we made the first steps.