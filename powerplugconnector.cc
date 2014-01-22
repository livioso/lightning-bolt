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
		"0000111011101110111011101110111011101000111010001110111010001110111010"));

	mPowerPlugsCollection.insert(std::make_pair(ePowerPlugTwo, 
		"0000111011101110111011101110111011001000111010001110111010001110111010"));
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