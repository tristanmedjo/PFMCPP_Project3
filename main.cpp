/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate 1 or 2 instances of each of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.



/*
 1)
 */
struct Filter
{
    double frequency = 4000.0;
    int filterType = 2;
    float dryWet = 1.0f;

    struct FilterKnob
    {
        float knobPosition;
        bool knobOverride = false;
        int color = 1;

        void spawnKnob(int numberOfKnobs, float knobLocation);
    };

    void updateKnobPosition(FilterKnob knobOne, double nextKnobPosition);
};

void Filter::FilterKnob::spawnKnob(int numberOfKnobs, float knobLocation)
{
    FilterKnob newKnob;

    if(numberOfKnobs > 0)
    {
        newKnob.spawnKnob(numberOfKnobs, knobLocation);
    }
}
/*
 2)
 */
struct WavetableOscillator
{
    double frequency = 4000.0;
    int waveShape = 2;
    float volumeLevel = 1.0f;

    struct Wavetable
    {   
        int maxNumberOfWaveforms = 100;
        bool interpolationOn = true;
        int currentWavetable = 0;
        void loadWavetable(int wavetableToLoad, float loadTimeOffset);
    };

    int getNextFrequencyInSequence(float nextFrequency);
};

void WavetableOscillator::Wavetable::loadWavetable(int wavetableToLoad, float loadTimeOffset)
{
    if((currentWavetable != wavetableToLoad) && (loadTimeOffset > 0))
    {
        currentWavetable = wavetableToLoad;
    }
}
/*
 3)
 */
struct ADSREnvelope
{
    double attack  = 2.0;
    double decay = 2.0;
    float sustain = 1.f;
    float release =2.4f;
    bool isMidiControlEnabled = true;
    void playNote();
    void playNoteOnTrigger(ADSREnvelope myEnvelope);
};

void ADSREnvelope::playNoteOnTrigger(ADSREnvelope newEnvelope)
{
    newEnvelope.playNote();
}

void ADSREnvelope::playNote(){}
/*
 4)
 */
struct Reverb
{
    int decayTime;
    float roomSize;
    double inputVolume;
    double outputVolume;
    int setNextReverbSettings(Reverb newVerbSettings);
};

int Reverb::setNextReverbSettings(Reverb newVerbSettings)
{
    Reverb oldVerbSettings;
    if(newVerbSettings.decayTime == oldVerbSettings.decayTime)
    {
        decayTime = 1;
    }
    else
    {
        newVerbSettings.decayTime = oldVerbSettings.decayTime;
    }
    return {};
}

/*
 5)
 */
struct Equalizer
{
    double frequency = 2000.19;
    float equalizerQ = 1.f;
    float gain = 0.5f;
    int enableEQ = 1;
    
    void disableEqualizer(Equalizer defaultEQ);
};

void Equalizer::disableEqualizer(Equalizer changeThisEQ)
{
    if(changeThisEQ.enableEQ == 1)
    {
        changeThisEQ.enableEQ = 0;
    }
}
/*
 6)
 */
struct Delay
{
    bool bpmSync = false;
    float feedback = 50.f;
    int delayRate = 1;
    bool pingPong = false;

    void copySettingsToAllOfSameType(Delay defaultDelay, bool shouldOverride);
};

void Delay::copySettingsToAllOfSameType(Delay settingsToCopy, bool)
{
    Delay myDelay;

    myDelay.bpmSync = settingsToCopy.bpmSync;
    myDelay.feedback = settingsToCopy.feedback;
    myDelay.delayRate = settingsToCopy.delayRate;
    myDelay.pingPong = settingsToCopy.pingPong;
}
/*
 7)
 */
struct Synthesizer
{
    WavetableOscillator oscillator;
    Filter combFilter;
    ADSREnvelope defaultEnvelope;

    void playSound(Synthesizer mySynth, float durationLength, bool pitchGlideEnabled);
    void startSound();
};

void Synthesizer::playSound(Synthesizer, float, bool)
{
    startSound();
}

void Synthesizer::startSound(){}
/*
 8)
 */
struct SimpleLooper
{
    float loopStartPoint = 0.f;
    float loopEndPoint = 10.f;
    bool shouldLoop = true;

    //SimpleLooper(int audioClipList); this was the original member function, but I am not sure how to call it below. I know we need to specify the type, but since there is no type, how would this work? I am adding a new function for now. ALSO, this function was causing problems with declaring a type, comment down below
    float createLoopPoint(float startPoint, float endPoint);
    void startLooping(float startPoint, float endPoint);
};

float SimpleLooper::createLoopPoint(float newStart, float newEnd)
{
    SimpleLooper myLoop; // When I had SimpleLooper(int audioClipList) above, it was causing "no matching constructor for initialization of myLoop"
    myLoop.startLooping(newStart, newEnd);
    return {};
}
void SimpleLooper::startLooping(float startPoint, float endPoint){
    startPoint = loopStartPoint;
    endPoint = loopEndPoint;
}
/*
 9)
 */
struct Bank
{
    float totalMoney = 100000000.f; // 100,000,000
    bool canLoanMoney = true;
    float yearlyInterestRate = 4.0f;
    
    struct PersonalAccount
    {
        float valueOfAccount = 50000.f;
        bool owesMoney = true;
        int totalAssetsHeld = 15;

        int getLastDepositAmount(PersonalAccount myAccount, float lastDepositTime);
    };

    void payOffLoans(Bank chase, PersonalAccount newAccount);
};

void Bank::payOffLoans(Bank chase, PersonalAccount tristanAccount)
{
    if(tristanAccount.valueOfAccount > 1000.f)
    {
        chase.totalMoney += tristanAccount.valueOfAccount;
        tristanAccount.valueOfAccount = 0;
    }
    else
    {
        chase.yearlyInterestRate += 0.1f;
    }
}
/*
 10)
 */
struct SearchEngine
{
    int totalSearches = 50;
    int totalAdsBlocked = 100;
    bool accountLoggedIn = false;

    struct SearchBar
    {
        float widthOfSearchBar = 100.f;
        float heightOfSearchBar = 5.f;
        bool searchEnabled = true;

        char showBookmarks(int totalBookmarks);
        void show();
        void clearSearchEngine();
    };
    SearchEngine(char recentlySearchedAddress);
};

char SearchEngine::SearchBar::showBookmarks(int totalBookmarks)
{
    SearchBar mySearchBar;

    if(totalBookmarks == 0)
    {
        clearSearchEngine();
    }
    else
    {
        mySearchBar.show();
    }
    return {};
}
void SearchEngine::SearchBar::show(){}
void SearchEngine::SearchBar::clearSearchEngine(){}

#include <iostream>
int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl;
}
