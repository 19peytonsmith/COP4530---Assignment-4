<div id="kl_assignments" class="">
<h3 class="">
<i class="icon-assignment" aria-hidden="true"></i>Assignment description</h3>
<p><strong>Educational Objectives:</strong></p>
<p><span>Understanding stacks and their applications&nbsp;</span></p>
<ul>
<li>Understand the stack Abstract Data Type (ADT) and its applications. Understand infix to post-fix conversion and post-fix expression evaluation.</li>
</ul>
<p><strong>Statement of Work:&nbsp;</strong></p>
<ul>
<li>Write and implement a generic stack container as an adapter class template.</li>
<li>Write and implement a program that converts infix expression to post-fix expression and implement a program that evaluates post-fix expression using the stack container you develop.</li>
<li>For this assignment you will write your own generic stack <strong>without using</strong> any of the predefined C++ Templates.&nbsp; I would suggest using your assignment #2 as a starting point.&nbsp;</li>
</ul>
<p><strong>Project Description:&nbsp;</strong></p>
<ul>
<li>A <strong>Stack</strong> is a type of data container/ data structure that implements the <strong>LAST-IN-FIRST-OUT (LIFO)</strong> strategy for inserting and recovering data. This is a very useful strategy, related to many types of natural programming tasks as we have discussed in class. Remember that in the generic programming paradigm, every data structure is supposed to provide encapsulation of the data collection, enabling the programmer to interact with the entire data structure in a meaningful way as a container of data. By freeing the programmer from having to know its implementation details and only exporting the interface of its efficient operations, a generic Stack provides separation of data access/manipulation from internal data representation. Programs that access the generic Stack only through the interface can be reused with any other Stack implementation. This results in modular programs with clear functionality and that are more manageable.</li>
</ul>
<p><strong>Goals:</strong></p>
<ol>
<li>Write your own generic Stack as an adapter class template&nbsp;</li>
<li>Write a program that parses infix arithmetic expressions to post-fix arithmetic expressions using a Stack</li>
<li>Write a program that evaluates post-fix arithmetic expressions using a Stack</li>
</ol>
<p><strong> Task1: Implement Stack adapter class template:&nbsp;</strong></p>
<ul>
<li>Stack MUST store elements internally using a proper C++ STL container (of course, you cannot use the C++ STL stack container).</li>
<li>Your Stack implementation MUST:&nbsp;
<ul>
<li>be able to store elements of an arbitrary type.</li>
<li>Every Stack instance MUST accept insertions as long as the system has enough free memory.</li>
</ul>
</li>
<li>Stack MUST implement the full interface specified below</li>
<li>You MUST provide the template and the implementation in two different files stack.h and stack.hpp, respectively. You must include stack.hpp into stack.h</li>
<li>Your stack implementation MUST be in the namespace cop4530.</li>
</ul>
<p>Interface:&nbsp; The following features of the Stack class must be implemented exactly as stated:&nbsp;</p>
<ul>
<li>
<strong>Stack():</strong> zero-argument constructor.</li>
<li>
<strong>~Stack ():</strong> destructor.</li>
<li>
<strong>Stack (const Stack&amp;):</strong> copy constructor.</li>
<li>
<strong>Stack(Stack &amp;&amp;):</strong> move constructor.</li>
<li>
<strong>Stack&amp; operator= (const Stack &amp;)</strong>: copy assignment operator=.</li>
<li>
<strong>Stack &amp; operator=(Stack &amp;&amp;)</strong>: move assignment operator=</li>
<li>
<strong>bool empty() const</strong>: returns true if the Stack contains no elements, and false otherwise.</li>
<li>
<strong>void clear()</strong>: delete all elements from the stack.</li>
<li>
<strong>void push(const T&amp; x):</strong> adds x to the Stack. copy version.</li>
<li>
<strong>void push(T &amp;&amp; x)</strong>: adds x to the Stack. move version.</li>
<li>
<strong>void pop()</strong>: removes and discards the most recently added element of the Stack.</li>
<li>
<strong>T&amp; top()</strong>: returns a reference to the most recently added element of the Stack (as a modifiable L-value).</li>
<li>
<strong>constT&amp; top()</strong> const: accessor that returns the most recently added element of the Stack (as a const reference)</li>
<li>
<strong>int size()</strong> const: returns the number of elements stored in the Stack.</li>
<li>
<strong>void print(std::ostream&amp; os, char ofc = ' ') const</strong>: print elements of Stack to ostream os. ofc is the separator between elements in the stack when they are printed out. Note that print() prints elements in the opposite order of the Stack (that is, the oldest element should be printed first).</li>
</ul>
<p>The interface of the Stack class must also include these non-member functions:&nbsp;</p>
<ul>
<li>
<strong>std::ostream&amp; operator&lt;&lt; (std::ostream&amp; os, const Stack&amp; a)</strong>: invokes the print() method to print the Stack a in the specified ostream</li>
<li>
<strong>bool operator== (const Stack&amp;, const Stack &amp;)</strong>: returns true if the two compared Stacks have the same elements, in the same order, and false otherwise</li>
<li>
<strong>bool operator!= (const Stack&amp;, const Stack &amp;)</strong>: opposite of operator==().</li>
<li>
<strong>bool operator&lt;= (const Stack&amp; a, const Stack &amp; b)</strong>: returns true if every element in <strong>Stack a</strong> is smaller than or equal to the corresponding element of <strong>Stack b,</strong> i.e., if repeatedly invoking <strong>top()</strong> and <strong>pop()</strong> on <strong>both a</strong> and <strong>b</strong>, we will generate a sequence of elements <strong>a<sub>i</sub></strong> from <strong>a</strong> and <strong>b<sub>i</sub></strong>&nbsp;from <strong>b</strong>, and for every <strong>i</strong>, <strong>a<sub>i</sub></strong> ≤ <strong>b<sub>i</sub></strong>, until a is empty. Note that <strong>Stack a</strong> and <strong>Stack b</strong> cannot be equal if they are not the same size.&nbsp;&nbsp;</li>
</ul>
<p><strong>Task 2:&nbsp; &nbsp;Analysis&nbsp;</strong></p>
<ul>
<li>Analyze the worst-case run-time complexity of the member function clear() of Stack.</li>
<li>Give the complexity in the form of Big-O. Your analysis can be informal; however, it must be clearly understandable by others. Note that the time complexity of the function clear() depends on the underlying adaptee class you use for the implementation of Stack.</li>
<li>Name the file containing the complexity analysis as "<strong><em>analysis.txt</em></strong>", in which, you should state the time complexity of clear() in the Big-O notation, your discussions on why it is so, in particular, you need to include the information on the underlying adaptee class you used in the implementation of the Stack.</li>
</ul>
<p><strong>Task 3: Convert Infix Notation to Postfix notation and evaluate ( if possible)&nbsp;</strong></p>
<ul>
<li>
<strong>The following are guidelines to be used in writing the infix-&gt;postfix routine</strong>
<ul>
<li>For the sake of this exercise, an arithmetic expression is a sequence of space-separated strings. Each string can represent an operand, an operator, or parentheses.</li>
<li>Operands: can be either a numerical value or a variable. A variable name only consists of alphanumerical letters and the underscore letter "_". A variable name starts with an alphabetical letter(upper or lower case). Numerical operands can be either integer or floating point values.</li>
<li>Examples of operands: "34", "5", "5.3", "a", "ab", "b1", and "a_1"</li>
<li>Operators are one of the characters '+', '-', '*', or '/'. As usual, '*' and '/' are regarded as having higher precedence than '+' or '-'. Note that all supported operators are binary, that is, they require two operands. There will be no unary operators.&nbsp;</li>
<li>Parentheses: '(' or ')' raise the precedence of the operand or operation within it.&nbsp;&nbsp;</li>
<li>Examples of infix notations:&nbsp;
<ul>
<li>( 5 + 3 ) * 12 - 7 is an infix arithmetic expression that evaluates to 89</li>
<li>5 + 3 * 12 - 7 is an infix arithmetic expression that evaluates to 34</li>
</ul>
</li>
<li>Examples of postfix notation:&nbsp;
<ul>
<li>a + b1 * c + ( dd * e + f ) * G in Infix notation becomes</li>
<li>a b1 c * + dd e * f + G * + in Postfix notation</li>
</ul>
</li>
</ul>
</li>
<li>The initial infix notation expression is evaluated from left to right as a series of space separated tokens ( each parenthesis, operand or operation is a token).&nbsp; &nbsp;I read everything in as strings and store them as strings. When I need to I convert the strings to integers and floats when needed.&nbsp; &nbsp; <em>Follow the rules below which are based upon Dijkstra's Shunting Yard Algorithm:</em>
<ol>
<li>When an operand is read in through the input, it is immediately output.&nbsp;</li>
<li>If an input symbol is '(', push it into stack.</li>
<li>If an input operator is '+', '-', '*', or '/', repeatedly print the top of the stack to the output and pop the stack until the stack is either (i) empty ; (ii) a '(' is at the top of the stack; or (iii) a lower-precedence operator is at the top of the stack. Then push the input operator into the stack.&nbsp;</li>
<li>If input operator is ')' and the last input processed was an operator, report an error. Otherwise, repeatedly print the top of the stack to the output and pop the stack until a '(' is at the top of the stack. Then pop the stack discarding the parenthesis. If the stack is emptied without a '(' being found, report error.</li>
<li>If end of input is reached and the last input processed was an operator or '(', report an error. Otherwise print the top of the stack to the output and pop the stack until the stack is empty. If an '(' is found in the stack during this process, report error.</li>
</ol>
</li>
</ul>
<p><strong>Evaluating Postfix Notations:&nbsp;</strong></p>
<ul>
<li>After converting a given expression in infix notation to post-fix notation, you will evaluate the resulting arithmetic expression IF all the operands are numeric (int, float, etc.) values. Otherwise, if the resulting post-fix expression contains characters, your output should be the same as the input ( just the post-fix expression itself).</li>
<li>Example post-fix notations:
<ul>
<li>5 3 + 12 * 7 -</li>
<li>5 3 12 * + 7 -</li>
<li>3 5 * c - 10 /</li>
</ul>
</li>
<li>What the previous output should be for each of the above:&nbsp;
<ul>
<li>89</li>
<li>34</li>
<li>3 5 * c - 10 /</li>
</ul>
</li>
<li>Algorithm to evaluate Post-fix Notations:
<ul>
<li>If the expression contains variables it cannot be evaluated.&nbsp;</li>
<li>To achieve this, you will have an operand stack, initially empty. Assume that the expression contains only numeric operands (no variable names).</li>
<li>Operands are pushed into the stack as they are ready from the input.</li>
<li>When an operator is read from the input, remove the two values on the top of the stack, apply the operator to them, and push the result onto the stack.</li>
<li>If an operator is read and the stack has fewer than two elements in it, report an error.</li>
<li>If end of input is reached and the stack has more than one operand left in it, report an error.</li>
<li>If end of input is reached and the stack has exactly one operand in it, print that as the final result, or 0 if the stack is empty.</li>
</ul>
</li>
<li>
<strong>Summary of Task 3:&nbsp;</strong>
<ul>
<li>Your program should expect as input from (possibly re-directed) stdin a series of space-separated strings.</li>
<li>If you read a1 (no space) this is the name of the variable a1 and not "a" followed by "1".</li>
<li>Similarly, if you read "bb 12", this is a variable "bb" followed by the number "12" and not "b" ,"b", "12" or "bb", "1" ,"2". The resulting post-fix expression should be printed to stdout.</li>
<li>Your program should evaluate the computed post-fix expressions that contain only numeric operands, using the above algorithm, and print the results to stdout.</li>
</ul>
</li>
</ul>
<p><strong>Restrictions:&nbsp;</strong></p>
<ul>
<li>The infix to post-fix conversion MUST be able to convert expressions containing both numbers and variable names.</li>
<li>Your program MUST be able to produce floating number evaluation (i.e., deal with floats correctly). For the sake of simplicity we will not mix integer and floating point expressions.&nbsp;</li>
<li>Your program MUST NOT attempt to evaluate post-fix expressions containing variable names. It should print the post-fix-converted result to stdout and MAY NOT throw an exception nor reach a run time error in that case.</li>
<li>Your program MUST check for mismatched parentheses (this should be taken care of if you infix to post-fix expression conversion is performed properly.</li>
<li>Your program MUST check invalid infix expressions and report errors. We consider the following types of infix expressions as invalid expressions:
<ul>
<li>1) an operator does not have the corresponding operands,</li>
<li>2) an operand does not have the corresponding operator; or ) mismatched parentheses.&nbsp;</li>
</ul>
</li>
</ul>
</div>
</div>
<p>Note that some checks can be performed in the expression conversion or post-fix evaluation. Your program MUST re-prompt the user for the next infix expression. Your program must be able to process several inputs before terminating (check the provided executable in2post.x to see the behavior of the program).</p>
<p><strong>Deliverable Requirements</strong></p>
<p>Your implementation should be contained in three files, which MUST be named</p>
<p>makefile, stack.h, stack.hpp and in2post.cpp.</p>
<p>Submit your implementation in a tar file including the three files (stack.h, stack.hpp, and in2post.cpp), the makefile you use, and the analysis.txt file for time complexity of the clear() function of Stack.</p>
<p>Your tar file should be named in this format, all lowercase: <em>lastname_firstname_p3.gz.tar </em></p>
<p>Example: My tar file would be: <em>gaitros_david_p3.gz.tar</em></p>
<p>Note that in addition to the provided test cases, we will also test your program/classes using additional test programs. Your program must be able to pass all such test cases to obtain a full score for the corresponding components.</p>
<p>This is an example of how to tar/zip your files if the command is executed in the directory where they are located:</p>
<p><em>tar -cvzf gaitros_david_p3.gz.tar stack.h stack.hpp in2post.cpp makefile analysis.txt</em></p>
<p>&nbsp;</p>
<p><a class="instructure_file_link" title="in2post-1" href="/courses/191038/files/15329933?wrap=1" target="_blank" data-canvas-previewable="false" data-api-endpoint="https://canvas.fsu.edu/api/v1/courses/170535/files/13593569" data-api-returntype="File">in2post-1</a>&nbsp;&nbsp;</p>
<p>Sample Output:&nbsp;</p>
<p>Gaitros:&gt;in2post<br>Enter in an expression<br>5 + 3 + 2 * ( 6 / 1 )&nbsp;<br>The InFix &nbsp; Notation is: 5 + 3 + 2 * ( 6 / 1 )&nbsp;<br>The PostFix Notation is: 5 3 + 2 6 1 / * +&nbsp;<br>&nbsp;Results are: 20<br>2 + 3 * ( 6 - 3 )&nbsp;<br>The InFix &nbsp; Notation is: 2 + 3 * ( 6 - 3 )&nbsp;<br>The PostFix Notation is: 2 3 6 3 - * +&nbsp;<br>&nbsp;Results are: 11<br>2 + 3 ( 6 - 3 )&nbsp;<br>The InFix &nbsp; Notation is: 2 + 3 ( 6 - 3 )&nbsp;<br>The PostFix Notation is: 2 3 6 3 - +&nbsp;<br>&nbsp;Results are: Error - Too few operands<br>( 5 + 3 ) * 12 - 7&nbsp;<br>The InFix &nbsp; Notation is: ( 5 + 3 ) * 12 - 7&nbsp;<br>The PostFix Notation is: 5 3 + 12 * 7 -&nbsp;<br>&nbsp;Results are: 89</p></div>

</div>
