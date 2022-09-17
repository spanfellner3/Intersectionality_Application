#include "Person.h"

std::string name;
std::string race;
std::string gender;
std::string sexualOrientation;
std::string disability;
std::string veteran;
std::string parent;
std::string comment;

Person::Person() {}
Person::Person(std::string traits)
{
	addTraits(traits);
}

void Person::addTraits(std::string traits)
{
	traits += " ";
	race = getTrait(traits, "race:");
	gender = getTrait(traits, "gender:");
	sexualOrientation = getTrait(traits, "sexualOrientation:");
	disability = getTrait(traits, "disability:");
	veteran = getTrait(traits, "veteran:");
	parent = getTrait(traits, "parent:");
	comment = getComment(traits);
}

std::string Person::getClosestConnections(Person me, std::vector<Person> people)
{
	std::string connections_string = "";

	std::vector<int> connections = getConnections(me, people);
	int strongestConnection = getStrongestConnection(connections);

	for (int i = strongestConnection; i >= 0; i--)
	{
		if (contains(connections, i))
		{
			connections_string += "      -----------------------------------------------------------------<br>\n";
			connections_string += "      Intersectionality strength: " + std::to_string(i) + "<br>\n";
			connections_string += "      -----------------------------------------------------------------<br>\n";

			for (int j = 0; j < connections.size(); j++)
			{
				if (connections[j] == i)
					connections_string += getConnection(people[j], me);
			}
		}
	}
	return connections_string;
}

std::string Person::getConnection(Person person, Person me)
{
	std::string connection = "";

	if (person.race.compare("") != 0)
		connection += "      ";
	if (person.race.compare(me.race) == 0 && me.race != "")
		connection += "***";
	if (person.race.compare("") != 0)
		connection += "Race: " + person.race + "<br>\n";

	if (person.gender.compare("") != 0)
		connection += "      ";
	if (person.gender.compare(me.gender) == 0 && me.gender != "")
		connection += "***";
	if (person.gender.compare("") != 0)
		connection += "Gender: " + person.gender + "<br>\n";
	
	if(person.sexualOrientation.compare("") != 0)
		connection += "      ";
	if (person.sexualOrientation.compare(me.sexualOrientation) == 0 && me.sexualOrientation != "")
		connection += "***";
	if (person.sexualOrientation.compare("") != 0)
		connection += "Sexual Orientation: " + person.sexualOrientation + "<br>\n";

	if(person.disability.compare("") != 0)
		connection += "      ";
	if (person.disability.compare(me.disability) == 0 && me.disability != "")
		connection += "***";
	if (person.disability.compare("") != 0)
		connection += "Disability: " + person.disability + "<br>\n";

	if(person.veteran.compare("") != 0)
		connection += "      ";
	if (person.veteran.compare(me.veteran) == 0 && me.veteran != "")
		connection += "***";
	if (person.veteran.compare("") != 0)
		connection += "Veteran: " + person.veteran + "<br>\n";

	if(person.parent.compare("") != 0)
		connection += "      ";
	if (person.parent.compare(me.parent) == 0 && me.parent != "")
		connection += "***";
	if (person.parent.compare("") != 0)
		connection += "Parent: " + person.parent + "<br>\n";

	connection += "      Comment: " + person.comment + "<br>\n";
	connection += "      <br>\n";

	return connection;
}

bool Person::contains(std::vector<int> connections, int value)
{
	for (int i = 0; i < connections.size(); i++)
		if (connections[i] == value)
			return true;
	return false;
}

int Person::getStrongestConnection(std::vector<int> connections)
{
	int strongestConnection = 0;
	for (int i = 0; i < connections.size(); i++)
		if (connections[i] > strongestConnection)
			strongestConnection = connections[i];
	return strongestConnection;
}

std::vector<int> Person::getConnections(Person me, std::vector<Person> people)
{
	std::vector<int> connections;

	for (int i = 0; i < people.size(); i++)
	{
		int numConnections = 0;

		if (me.race.compare(people[i].race) == 0 && me.race != "")
			numConnections++;

		if (me.gender.compare(people[i].gender) == 0 && me.gender != "")
			numConnections++;

		if (me.sexualOrientation.compare(people[i].sexualOrientation) == 0 && me.sexualOrientation != "")
			numConnections++;

		if (me.disability.compare(people[i].disability) == 0 && me.disability != "")
			numConnections++;

		if (me.veteran.compare(people[i].veteran) == 0 && me.veteran != "")
			numConnections++;

		if (me.parent.compare(people[i].parent) == 0 && me.parent != "")
			numConnections++;

		connections.push_back(numConnections);

	}

	return connections;
}

std::string Person::getTrait(std::string traits, std::string type)
{
	std::string trait = "";
	std::string SPACE = " ";

	size_t traitIndex = traits.find(type);

	if (traitIndex == -1)
		return "";

	char character = traits[traitIndex];
	for (size_t i = traitIndex + (size_t)type.size(); !isspace(character); i++)
	{
		character = traits[i];
		trait.push_back(character);
	}

	return trait;
}

std::string Person::getComment(std::string traits)
{
	std::string comment = "";
	std::string SPACE = " ";

	int traitIndex = traits.find("comment:");

	if (traitIndex == -1)
		return "";

	char character = traits[traitIndex];
	for (int i = traitIndex + 8; i < traits.size(); i++)
	{
		character = traits[i];
		comment.push_back(character);
	}

	return comment;
}

