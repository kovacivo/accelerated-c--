// program draws a picture from strings by surrounding it with asterisks - a.k.a frame around it

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// frame the strings putting them into vector which will be written later
std::vector<std::string> frame_picture(const std::vector<std::string>& vec)
{

	// find out the longest string
	std::string::size_type len = 0;
	// for(std::vector<std::string>::size_type i = 0; i != vec.size(); i++)
	for(std::vector<std::string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
		len = std::max(len,(*iter).size());

	// output vector
	std::vector<std::string> framed_pic;

	// put the top line
	framed_pic.push_back(std::string(len+4, '*'));

	// for(std::vector<std::string>::size_type i = 0; i != vec.size(); i++)
	for(std::vector<std::string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		framed_pic.push_back("* " + (*iter) + std::string(len - (*iter).size(),' ') + " *");
	}

	// put the bottom line
	framed_pic.push_back(std::string(len+4, '*'));

	return framed_pic;
}

std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom)
{
	// concatenates the two vector into one copying the lines from both into a new one, putting the top as the first one
	std::vector<std::string> concatenated_vector;

	// take the first one
	for (std::vector<std::string>::const_iterator iter = top.begin(); iter != top.end(); iter++)
		concatenated_vector.push_back(*iter);
	
	// take the second one
	for (std::vector<std::string>::const_iterator iter = bottom.begin(); iter != bottom.end(); iter++)
		concatenated_vector.push_back(*iter);

	return concatenated_vector;
}


std::vector<std::string> hcat(std::vector<std::string>& left, std::vector<std::string>& right)
{
	// horizontal concatenation
	std::vector<std::string>::iterator it1 = left.begin();
	std::vector<std::string>::iterator it2 = right.begin();

	std::vector<std::string> hvec;
	while ((it1 != left.end()) || (it2 != right.end())) // this is a problem - gives me the segfault errors
	// while ((it1 != content.end()) && (it2 != content2.end()))
	{
		// if the first vector has fewer lines
		if (it1 == left.end()) {
			//tmp_string = *it2;
			hvec.push_back(*it2);
			it2++;
		// if the second vector has fewer lines
		} else
			if (it2 == right.end()) {
				// tmp_string = (*it1);
				hvec.push_back(*it1);
				it1++;
			} else {
				// tmp_string = std::string((*it1) + " " + (*it2));			
				hvec.push_back(std::string((*it1) + " " + (*it2)));			
				it1++; it2++;
			}
		// std::cout << tmp_string << std::endl;
		// it1++; it2++;
	}
	return hvec;
}





int main()
{
	// acquire a strings from users
	std::cout << "Input the content to be framed." << std::endl;
	
	std::vector<std::string> content;
	std::string input_str;

	// put the strings into the vector reading the whole line of input
	while(getline(std::cin, input_str))
		content.push_back(input_str);

	// frame the content
	std::vector<std::string> frame = frame_picture(content);

	// output the ready framed picture
	std::cout << "Showing the framed content." << std::endl;
	for(std::vector<std::string>::size_type i = 0; i != frame.size(); i++)
		std::cout << frame[i] << std::endl;

	std::vector<std::string> content2;
	content2.push_back("333"); 
	content2.push_back("000"); 
	content2.push_back("dalsi obsah"); 

	const char* args[] = {"01 01 01", "02 02 02", "03 03 03", "04 04 04"};
	std::vector<std::string> content3(args, args+4);
	
	// concatenate two vectors
	std::vector<std::string> frame2 = vcat(content, content2);
	// frame the content
	frame = frame_picture(frame2);

	// output the ready framed concatenated picture
	std::cout << "Showing the framed content concatenated with some other content - vertical." << std::endl;
	for(std::vector<std::string>::size_type i = 0; i != frame.size(); i++)
		std::cout << frame[i] << std::endl;

	// concatenate two vectors
	// frame2 = vcat(content, content3);
	// frame the content
	// frame = frame_picture(frame2);

	// output the ready framed concatenated picture std::cout << "Showing the framed content concatenated with some other content." << std::endl;
	// for(std::vector<std::string>::size_type i = 0; i != frame.size(); i++)
	//		std::cout << frame[i] << std::endl;


	// horizontal concatenation
	std::cout << "Showing the framed content concatenated with some other content - horizontal." << std::endl;
	std::vector<std::string> hvec;
	hvec = hcat(content, content2);
	
	// frame it
	frame = frame_picture(hvec);

	// output the ready framed concatenated picture std::cout << "Showing the framed content concatenated with some other content." << std::endl;
	for(std::vector<std::string>::size_type i = 0; i != frame.size(); i++)
		std::cout << frame[i] << std::endl;

	return 0;

}
