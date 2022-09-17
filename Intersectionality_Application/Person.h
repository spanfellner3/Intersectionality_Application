#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <fstream>

class Person
{
public:
	std::string race;
	std::string gender;
	std::string sexualOrientation;
	std::string disability;
	std::string veteran;
	std::string parent;
	std::string comment;

	Person();
	Person(std::string traits);

	void addTraits(std::string traits);
	std::string getClosestConnections(Person me, std::vector<Person> people);
	std::string getConnection(Person person, Person me);
	bool contains(std::vector<int> connections, int value);
	int getStrongestConnection(std::vector<int> connections);
	std::vector<int> getConnections(Person me, std::vector<Person> people);
	std::string getTrait(std::string traits, std::string type);
	std::string getComment(std::string traits);
};

#endif