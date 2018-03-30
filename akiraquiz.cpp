//============================================================================
// Name        : BPokhrel3.cpp
// Author      : Baivab Pokhrel
// Version     :
// Copyright   : Your copyright notice
// Description : Akira's Animal Quiz
//============================================================================

#include <iostream>
#include <string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
 using namespace std;

 bool check_equal(string,string);//to check input and our shuffled word is same or not
 string underscore_add(string,int);//to add underscores to our word
 string underscore_lose(string,string);//to lose underscores from our word



 int main()
{
	srand (time(NULL));
    vector<string> wordlist;//to store our first input i.e list if animals
    vector<string> wordlist1;//vector to pick random words from the above vector and remove that element so that we don't get repeated words.
    string input_word;//string to all the inputs
    string content;//string that gets one line
    string input_answer;//string that stores the word guessed
    string word1="";//string that stored words a array that are to be shuffled
    string print_word;//string that is to be shown after been shuffled
    string input_add="";//string to store our list of animals to vectors.
    int winsum=0,losesum=0;//integer to keep track of won or lost round
    int underscores=0;//integer to keep track of number of underscores needed in a string
    int rand1,rand2;//random number to get random word from the list of animals
    int check2=0;//to check if we won or lost round and change the word only if we won

    cout<<"Enter at least five animal names, e.g., cat, dog, etc..."<<endl;
    do{

     input_word="";//emptying the string to add all the inputs
     wordlist.clear();//emptying the vector in case if there were less than 5 inputs it has to come back here

    do//loop to keep track when there is empty line and continue it till we get empty line
    	{
    	cout<<">";
    	getline(cin,content);
    	input_word=input_word+content+" ";//to ad all the inputs into one line
    	}
    while(!content.empty());//criteria of loop where we stop when we get empty line


    for(int i=0;i<=input_word.length();i++)//loop to take the words stored above and keep them in a vector
    {
    	input_add=input_add+input_word[i];
        if(isspace(input_word[i]))//check if there is space and make a new index of vector if there is space
        {

            if(input_add!=" ")//do this only when out input is empty which we do at the end
            {
            	input_add=input_add.erase(input_add.length()-1,1);//once the words till the first space are stored that space is erased till we reach the next letter

            	wordlist.push_back(input_add);//adding all the string to a vector

            }
           input_add="";//making it empty for our if statement to work

        }


    }
    if(wordlist.size()<5)//display this message if our input has less than 5 inputs
            	cout<<"Enter at least five animal names, e.g., cat, dog, etc..."<<endl;


    }while(wordlist.size()<5);//criteria of while loop to see if there are at least 5 animals entered
    for(int p=0;p<wordlist.size();p++)//loop displaying all the animals in a serial order
        {
        	cout<<p+1<<": "<<wordlist[p]<<endl;
        }




    for(int m=0;;m++)//infinite loop that runs over our whole program which is stopped if our input is equal to quit using break statement
    {
    	wordlist1.clear();//making our vector wordlist1 empty as all the elements of wordlist are stored in this vector to make non repetitive words as a secret word
    	for(int n=0; n<wordlist.size();n++)//assigning all the list of animals which was in wordlist to wordlist1
    	{
    		wordlist1.push_back(wordlist[n]);
    	}
     int check1=1;//integer to check if there is difference in number of words needed and entered
     if(check2==0)// this loop runs only if this is equal to zero which are changed follows according to its need
      {
	        rand1=rand()%3+1;//first random number to get 1 or 2 or 3 words out of our list


            for(int j=0;j<rand1;j++)
            {

            	rand2=rand()%wordlist1.size();//second random to get the random index of vectors wordlist which was given all the lists of animal
                word1=word1+wordlist1[rand2];//adding that word to a empty string to get a complete secret string
                wordlist1.erase(wordlist1.begin()+rand2);//erasing that index to the vector to avoid repetition of words in our secret word,
                //as we already have our original vector wordlist with all our animals erasing this will not further affect out program because its just a template of that vector.


             }

            random_shuffle(word1.begin(),word1.end());//shuffling the words after getting all the required from from the vector


            }

            print_word = underscore_add(word1,underscores);//adding underscores to our shuffled word, which has 0 underscores as underscore is assigned to be 0 at first unless it is further changed



            cout<<"What are "<<rand1<<" animals in "<<'"'<< print_word<<'"' <<" ?"<<endl;//requesting our user for a input after showing them shuffled word

            getline(cin,input_answer);//getting the user guessed word


            for(int k=0;k<input_answer.length();k++)//taking that input and removing space from it making it easier to check if its equal with our secret word
                        {

                        	if(isspace(input_answer[k]))//using isspace() function to remove function
                        	{

                        		input_answer=input_answer.erase(k,1);//erasing that element if its a space

                                check1++;//to count how many space are there in the input as number of words is just 1 greater than number of spaces

                        	}
                        }


            if(input_answer=="?")//this is the case when user inputs '?' we display the list of all elements in a vector
                        {
                        	for(int r=0;r<wordlist.size();r++)//for loop, loops until all the elements of the vector wordlist are displayed
                        	{
                        		cout<<r+1<<" : "<<wordlist[r]<<endl;
                        	}

                             check2++;//increasing check by 1 because we don't want the word to be changed in this case, making check greater than 1 it word it will not go through first if statement
                        	continue;//using this statement because we don't any further steps to occur after this condition
                        }
            if(input_answer=="quit")//this is he case when input is equal to'quit', we simply break and go out of the loop
                       		{
                       			cout<<"Bye..."	<<endl;
                       			break;//to get out of the loop as its the only way to do so

                       		}
            if(check1!=rand1)//checking if user input is same as our random number of words used to make the secret word
            {
            	cout<<"Your number of input is incorrect. Enter again:"<<endl;//displaying error message
                check2++;//adding 1 to check 2 as we don't want to change the word for this time to
        	    continue;//this statement because we don't to go through other steps if this happens
            }




            if(!check_equal(word1,input_answer))//this is the case where the word is not equal to the user input
            {
                losesum++;//increasing losesum by 1 so we can check for two consecutive case
                winsum=0;//making winsum 0 because we wan the condition for consecutive case
                check2++;//adding check2 with 1 as we don't want to change our secret word
                cout<<"Nope!"<<endl;//displaying message to say user input is wrong
                if(losesum==2)//this is the case when user is consecutively wrong for two times
                            	{
                            	cout<<"Missed two consecutive times, challenge goes down!\n"<<endl;//displaying error message
                            	print_word=underscore_lose(word1,print_word);//using our function to decrease underscores from our randomly shuffled word
                            	if(underscores!=0)
                            	{underscores--;}//decreasing number underscores as it should be decreased in this case
                                losesum=0;//re assigning losesum to be 0 to make our condition work successfully for next time
                            	}
             }
            else if(check_equal(word1,input_answer))//this is the case where the word is equal to the user input
            {
            	winsum++;//increasing winsum by 1 so we can check for two consecutive case
            	losesum=0;//making losesum 0 because we wan the condition for consecutive case
                check2=0;//making check 2 equal to ) as we wan to change our secret word for this case
            	cout<<"Yes!"<<endl;//displaying the yes message
            	if(winsum==2)//this is the case when user is consecutively correct for two times
            	            {

            		            underscores++;//increasing underscores to increase the level of the game
            	            	cout<<"Succeeded two consecutive times, challenge goes up!\n"<<endl;
            	            	print_word=underscore_add(word1,underscores);//using this function to increase the number of underscores in out randomly shuffled word.

            	            	winsum=0;//making winsum 0 after one round to make it work fine for next round
            	            }


            	word1="";//making word1 empty to reassign word1 with new randomly shuffle word
            }




    }
}


bool check_equal(string str1, string str2)//function to check two strings equal
{
    if(str1.length() != str2.length())
        return false;
    for(int i = 0; i < str1.length();i++)
    {
        bool found = false;
        int j = 0;
        while(!found && j < str2.length())
        {
            if(str1[i] == str2[j])
            {
                found = true;
                str2[j] = 0;
            }
            j++;
        }
        if(!found)
            return false;
    }
    return true;
}
string underscore_add(string word,int times)//function to add underscores
{
	srand(time(NULL));
	int a=word.length();//initializing integer a with word length of string word
	if(a>times)//if word length is greater than times of underscores
	{


	for(int i=0;i<times;i++)//loop to add underscores required number of times
	{
		a--;
		word[a]='_';//replacing that element of the word with underscore


	}
	}
	else if(a<=times)//if word length is less than required number of underscores replace all the letters with underscore
	{
		for(int i=0;i<a;i++)
		{
			word[i]='_';
		}
	}