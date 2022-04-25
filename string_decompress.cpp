#include <iostream>
#include <stack>
#include <string>
#include <chrono>
#include <functional>

void repeat(std::string &str, int num )
{
	std::string temp = str ;

    for(int i = 0; i < num-1; ++i)
		str += temp;
}

std::string decompress(std::string const &s)
{
	std::stack<std::string> st;

	for(int i = s.size()-1; i >= 0; --i)
	{
		if(s[i] >= '0' && s[i] <= '9') // if a num then find the whole num and repeat the top by num times
		{
			int j = i ;

			while(j >= 0 && s[j] >= '0' && s[j] <= '9')
				j--;

			j++; //integer starts from j position and ends at i

			int num = stoi(s.substr(j, i-j+1));

			i = j;

            if (! st.empty()) //handle this case if ends with number only ex: "2[abc]12"
                repeat(st.top(), num);
		}
		else if(s[i] == '[')  //if opening bracket concatanate all strings and push it in the stack
		{
			std::string temp;

			while(!st.empty() && st.top() != "]" )
			{
				temp += st.top();
				st.pop();
			}

			st.pop();
			st.push(temp);
		}
		else  //if char or closing bracket just push
			st.push(s.substr(i, 1));
	}

	std::string ans ;

	while(!st.empty()) // concatanate all residues in the stack  to form ans
	{
		ans += st.top();
		st.pop();
	}

	return ans;
}

void test(std::function<std::string(std::string const &)> func, std::initializer_list<std::string> stringList)
{
	for (auto const &str: stringList)
	{
		auto start = std::chrono::high_resolution_clock::now();
		std::string ret = func(str);
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << ret << ", Time taken(micro sec): " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
	}
}

int main()
{
	test(decompress, {"2[abc]13[cd]ef", "[abc]13[cd]ef", "[[abc]13[cd]ef]", "2[abc]4"});
	return 0;
}
