#include "powerplugconnector.h"
#include <iostream>
#include <utility>

PowerPlugConnector::PowerPlugConnector ()
{
	setupPowerPlugs();

	turnPowerPlugOn(ePowerPlugOne);
	turnPowerPlugOn(ePowerPlugTwo);
}

// make sure that one is not virtual 
// as it's called from within the constructor
void PowerPlugConnector::setupPowerPlugs ()
{
	mPowerPlugsCollection.insert(std::make_pair(ePowerPlugOne, 
		std::string("00001110111011101110111011101110111") + 
					"01000111010001110111010001110111010" +
					"00100010001000111011101110111010011"));

	mPowerPlugsCollection.insert(std::make_pair(ePowerPlugTwo, 
		std::string("00001110111011101110111011101110111") + 
					"01000111010001110111010001110111010" +
					"00100010001000111011101110111010000"));
}

void PowerPlugConnector::turnPowerPlugOn (EPowerPlugSerialnumber id)
{
	auto finding = mPowerPlugsCollection.find(id);

	if(mPowerPlugsCollection.end() != finding) {
		std::cout << "Turning power plug with ID " << finding->first << 
			" on with corresponding bit sequence " << finding->second << std::endl; 
	}
}

void PowerPlugConnector::turnPowerPlugOff (EPowerPlugSerialnumber id)
{
	auto finding = mPowerPlugsCollection.find(id);

	if(mPowerPlugsCollection.end() != finding) {
		std::cout << "Turning power plug with ID " << finding->first << 
			" off with corresponding bit sequence " << finding->second << std::endl; 
	}
}