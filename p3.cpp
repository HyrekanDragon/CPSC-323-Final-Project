/*PART III*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Part 3
	//Beginning Part 3 get original p2 file and make new p3 cpp file.
  ifstream infile("finalp2.txt");
  ofstream offile("finalp3.cpp");
  string line = "";//matching temporary line
  while (infile >> line)//goes through entire txt file until done.
  {
	  if (line == "program")//beginning line
	  {
		  line = "#include <iostream>";//required to run
		  offile << line;//to put in the new cpp file.
		  
		  while (line != ";")//check to end at the semicolon originally in the file.
			  {
				  infile >> line;
				  if (line == ";") //skips it and hits the next line of code.
				  {
					  offile << endl;
					  break;
				  }
			  }
	  }
	  
    else if (line == "var")//var can become using namespace std.
	  {
		  line = "using namespace std;";
		  offile << line << endl;
	  }
	  
    else if (line == "integer")//integer can become int.
	  {
		  line = "int";
		  offile << line;
	  }
    
  	else if (line == "begin")//begin can be int main() {
	  {
		  line = "int main()";
		  offile << line << endl << "{" << endl;
	  }
  	
    else if (line == "show")//show works like cout.
	  {
		  line = "cout";
	  	offile << line;
  		infile >> line;
		  if (line == "(") //syntax changes to preserve it.
		  {
			  line = "<<"; // carrots to lead into it.
			  offile << line;
			  while (line != ")")//preserve everything originally in the parenthesis.
			  {
				  infile >> line;
				  if (line == ")") //there is left parenthesis, so this can go.
				  {
					  line == " ";
					  break;
				  }
				offile << line;
			  }
      }
     }
      
	  else if (line == "end")//end can become the right brace.
	  {
		  line = "}";
		  offile << line << endl;
	  }

	  else if (line == ";")//tricky but every semicolon ends with a new line of code; easier readability.
		  offile << line << endl;

	  else //other that continues on regardless.
		  offile << line;
   }
}
