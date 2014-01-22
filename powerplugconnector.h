#include <functional>
#include <map>
#include <string>

class PowerPlugConnector {
	enum EPowerPlugSerialnumber {
    	ePowerPlugOne = 744102883,
    	ePowerPlugTwo = 424110073
    };

  	std::map< EPowerPlugSerialnumber, std::string > mPowerPlugsCollection;

  	public:
  		explicit PowerPlugConnector ();
  		void setupPowerPlugs ();
    	void turnPowerPlugOn (EPowerPlugSerialnumber id);
    	void turnPowerPlugOff (EPowerPlugSerialnumber id);
};