#include <functional>
#include <map>
#include <string>

// GPIO setup macros. Always use INP_GPIO
// before using OUT_GPIO or SET_GPIO_ALT

/*
	#define INP_GPIO(g) *(gpio + ((g)/10)) &= ~(7<<(((g)%10)*3))
	#define OUT_GPIO(g) *(gpio + ((g)/10)) |= (1<<(((g)%10)*3))
	#define SET_GPIO_ALT(g,a) *(gpio + (((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))

	#define GPIO_SET *(gpio + 7)
	#define GPIO_CLR *(gpio + 10)
*/

class PowerPlugConnector {

	private:

		struct GPIO {
			const unsigned int kPageSize = 4096;
			const unsigned int kBlockSize = 4096;
			const unsigned int kBCM2708PeriBase = 0x20000000;
			const unsigned int kGPIOControllerBase = kBCM2708PeriBase + 0x200000;
			volatile unsigned* gpio;
		} GPIO; 

		enum EPowerPlugSerialnumber {
			ePowerPlugOne = 744102883,
			ePowerPlugTwo = 424110073
		};

		/**	/dev/mem file descriptor assigned when
			setting up memory access and expected to
			be released during deconstruction phase */
		unsigned int mFileDescriptorMemory;

		/** Allocated memory for GPIO memory access */
		unsigned char* mGPIOMemory; 

		/** Corresponding mapped memory */
		unsigned char* mGPIOMemoryMapped; 

		/** Collection of <SerialNumber and corresponding bit sequences 
			to be sent to enable or disable the power plug device. 
			Note: As of now it looks like this will be the same for enable and disabling. */
		std::map< EPowerPlugSerialnumber, std::string > mPowerPlugsCollection;

	public:
			explicit PowerPlugConnector ();
			~PowerPlugConnector ();
			void setupMemoryAccess ();
			void tearDownMemoryAccess ();
			void setupPowerPlugs ();
			void turnPowerPlugOn (EPowerPlugSerialnumber id);
			void turnPowerPlugOff (EPowerPlugSerialnumber id);
};