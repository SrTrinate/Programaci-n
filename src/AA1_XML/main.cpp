#include "../dep/inc/xml/rapidxml.hpp"
#include "../dep/inc/xml/rapidxml_utils.hpp"
#include "../dep/inc/xml/rapidxml_iterators.hpp"
#include "../dep/inc/xml/rapidxml_print.hpp"
#include <iostream>
#include <sstream>



int main()
{
	//Creación de un documento XML desde el fichero XML para poder leer su contenido
	rapidxml::xml_document<> doc;
	std::ifstream file("../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close(); 
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<>* pRoot = doc.first_node();

	// RECORREMOS ENEMIGO
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("enemy"); pNode; pNode = pNode->next_sibling())
	{
		std::cout << pNode->name() << ':' << '\n'; // IMPRIMIMOS NOMBRE TAG ENEMIGO

		for (rapidxml::xml_attribute<>* pAttr = pNode->first_attribute(); pAttr; pAttr = pAttr->next_attribute()) { // RECORREMOS ATRIBUTOS

			std::cout << '-' << pAttr->name() << '-' << pAttr->value() << '\n'; // IMPRIMIMOS NOMBRE I VALUE DE ATTTR

		};

		for (rapidxml::xml_node<>* pNodeStats = pNode->first_node(); pNodeStats; pNodeStats = pNodeStats->next_sibling()) // RECORREMOS LOS STATS
		{
			std::cout << pNodeStats->name() << ':' << pNodeStats->value() << '\n'; //IMPRIMIMOS STATS

			for (rapidxml::xml_attribute<>* pAttrStats = pNodeStats->first_attribute(); pAttrStats; pAttrStats = pAttrStats->next_attribute()) { // RECORREMOS ATRIBUTOS

				std::cout << '-' << pAttrStats->name() << '-' << pAttrStats->value() << '\n'; // IMPRIMIMOS NOMBRE I VALUE DE ATTTRSTATS

			};

			for (rapidxml::xml_node<>* pNodeWeapon = pNodeStats->first_node("weapon"); pNodeWeapon; pNodeWeapon = pNodeWeapon->next_sibling()) {

				std::cout << pNodeWeapon->name() << ':' << '\n'; // IMPRIME EL TAG WEAPON

				for (rapidxml::xml_attribute<>* pAttrStats = pNodeWeapon->first_attribute(); pAttrStats; pAttrStats = pAttrStats->next_attribute()) { // RECORREMOS ATRIBUTOS WEAPON

					std::cout << '-' << pAttrStats->name() << '-' << pAttrStats->value() << '\n'; // IMPRIMIMOS NOMBRE I VALUE DE WEAPON

				};
				for (rapidxml::xml_node<>* pNodeStatsWeapon = pNodeWeapon->first_node(); pNodeStatsWeapon; pNodeStatsWeapon = pNodeStatsWeapon->next_sibling()) // RECORREMOS LOS STATS
				{
					std::cout << pNodeStatsWeapon->name() << ':' << pNodeStatsWeapon->value() << '\n'; //NOMBRE DE TAG Y VALOR DE LA WEAPONSTATS

					for (rapidxml::xml_attribute<>* pAttrStatsWeapon = pNodeStatsWeapon->first_attribute(); pAttrStatsWeapon; pAttrStatsWeapon = pAttrStatsWeapon->next_attribute()) { // RECORREMOS ATRIBUTOS WEAPON

						std::cout << '-' << pAttrStatsWeapon->name() << '-' << pAttrStatsWeapon->value() << '\n'; // IMPRIMIMOS NOMBRE I VALUE DE WEAPON

					};
				}
			}

		};
		std::cout << '\n';
	}
}

