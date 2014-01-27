#include "powerplugconnector.h"
#include <iostream>
#include <utility>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>

PowerPlugConnector::PowerPlugConnector ()
	:	mFileDescriptorMemory(0),
		mGPIOMemory(NULL),
		mGPIOMemoryMapped(NULL)
{
	setupPowerPlugs();
	turnPowerPlugOn(ePowerPlugOne);
	turnPowerPlugOn(ePowerPlugTwo);
}

PowerPlugConnector::~PowerPlugConnector ()
{
	tearDownMemoryAccess();
}

void PowerPlugConnector::setupMemoryAccess ()
{
	const unsigned int kBytesToBeAllocated =
		GPIO.kBlockSize + (GPIO.kPageSize - 1); 

	mFileDescriptorMemory = open("/dev/mem", O_RDWR|O_SYNC);
	mGPIOMemory = (unsigned char*) malloc(kBytesToBeAllocated);

	if(0 == mFileDescriptorMemory || NULL == mGPIOMemory)
	{
		std::cout << "Memory setup failed. Can not do anything." << std::endl;
		exit(-1);
	}

	// make sure pointer is on boundary -> no offset
	ptrdiff_t kMemoryBoundryOffsetToPageSize = 
		(intptr_t) mGPIOMemory % GPIO.kPageSize;
	if(0 != kMemoryBoundryOffsetToPageSize)
	{
		mGPIOMemory += GPIO.kPageSize - kMemoryBoundryOffsetToPageSize;
	}

	// map the memory now
	mGPIOMemoryMapped = (unsigned char*) mmap(
		(caddr_t) mGPIOMemory,
		GPIO.kBlockSize,
		PROT_READ|PROT_WRITE,
		MAP_SHARED|MAP_FIXED,
		mFileDescriptorMemory,
		GPIO.kGPIOControllerBase);

}

void PowerPlugConnector::tearDownMemoryAccess ()
{
	close(mFileDescriptorMemory);
	mFileDescriptorMemory = 0; 

	free(mGPIOMemory);
	mGPIOMemory = NULL;
}

// make sure that one is not virtual 
// as it's called from within the constructor
void PowerPlugConnector::setupPowerPlugs ()
{
	mPowerPlugsCollection.insert(std::make_pair(ePowerPlugOne,
		"0000111011101110111011101110111011101000111010001110111010001110111010"));

	mPowerPlugsCollection.insert(std::make_pair(ePowerPlugTwo, 
		"0000111011101110111011101110111011001000111010001110111010001010111010"));
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