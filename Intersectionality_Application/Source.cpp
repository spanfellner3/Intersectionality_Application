#include "Person.h"

int main() {

	std::vector<Person> people;

	std::string me_str;
	std::cout << "Please enter information to sort by: ";
	std::getline(std::cin, me_str);
	std::cout << std::endl;

	Person me = Person(me_str);

	Person person1 = Person("race:black gender:male sexualOrientation:gay parent:yes comment:very friendly staff");
	Person person2 = Person("race:black gender:male comment:felt very welcome");
	Person person3 = Person("race:asian gender:female sexualOrientation:gay parent:yes comment:some offensive comments made here and there");
	Person person4 = Person("race:black gender:female sexualOrientation:striaght comment:never had a bad experience");

	people.push_back(person1);
	people.push_back(person2);
	people.push_back(person3);
	people.push_back(person4);

	std::string connections = me.getClosestConnections(me, people);

	std::ofstream file;
	file.open("intersectionality_results.html");
	file << "<!DOCTYPE html>\n  <html lang=\"en\">\n    <title>Intersectionality Results</title>\n    <body>\n";
	file << connections;
	file << "    </body>\n  </html";

	return 0;
}


