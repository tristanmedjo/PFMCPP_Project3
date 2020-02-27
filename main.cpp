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
    double frequency;
    int filterType;
    float dryWet;

    Filter()
    {
        frequency = 4000.0;
        filterType = 2;
        dryWet = 1.0f;
    }

    struct FilterKnob
    {
        float knobPosition;
        bool knobOverride;
        int knobID;

        FilterKnob()
        {
            knobPosition = 1.0f;
            knobOverride = false;
            knobID = 1;
        }

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

void Filter::updateKnobPosition(FilterKnob knobToUpdate, double nextKnobPosition)
{
    int knobID = knobToUpdate.knobID;
    std::cout << "\nThe knob to update is: " << knobID << ". The next knob position is: " << nextKnobPosition << "." << std::endl;
}
/*
 2)
 */
struct WavetableOscillator
{
    double frequency;
    int waveShape;
    float volumeLevel;

    WavetableOscillator()
    {
        frequency = 4000.0;
        waveShape = 2;
        volumeLevel = 1.0f;
    }

    struct Wavetable
    {   
        int maxNumberOfWaveforms;
        bool interpolationOn;
        int currentWavetable;

        Wavetable()
        {
            maxNumberOfWaveforms = 100;
            interpolationOn = true;
            currentWavetable = 0;
        }

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
    double attack;
    double decay;
    float sustain;
    float release;
    bool isMidiControlEnabled;

    ADSREnvelope()
    {
        attack = 2.0;
        decay = 2.0;
        sustain = 1.f;
        release =2.4f;
        isMidiControlEnabled = true;
    }

    void playNote(); 
    void playNoteOnTrigger(ADSREnvelope myEnvelope);
};

void ADSREnvelope::playNoteOnTrigger(ADSREnvelope newEnvelope)
{
    newEnvelope.playNote();
}

void ADSREnvelope::playNote()
{
    std::cout << "Playing note! Your ADSR Values are:\nAttack: " << attack << "\nDecay: " << decay << "\nSustain: " << sustain << "\nRelease " << release << std::endl;
}
/*
 4)
 */
struct Reverb
{
    int decayTime;
    float roomSize;
    double inputVolume;
    double outputVolume;

    Reverb()
    {
        decayTime = 1;
        roomSize = 3.5f;
        inputVolume = 1.0;
        outputVolume = 1.0;
    }
    
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
    double frequency;
    float equalizerQ;
    float gain;
    int enableEQ;

    Equalizer()
    {
        frequency = 2000.19;
        equalizerQ = 1.f;
        gain = 0.5f;
        enableEQ = 1;
    }
    
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
    bool bpmSync;
    float feedback;
    int delayRate;
    bool pingPong;

    Delay()
    {
        bpmSync = false;
        feedback = 50.f;
        delayRate = 1;
        pingPong = false;
    }

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
    ADSREnvelope defaultEnvelope; // I dont need to do any constructor here, since the UDT's I'm referencing already have constructors... correct?

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
    float loopStartPoint;
    float loopEndPoint;
    bool shouldLoop;

    SimpleLooper()
    {
        loopStartPoint = 0.f;
        loopEndPoint = 10.f;
        shouldLoop = true;
    }

    float createLoopPoint(float startPoint, float endPoint);
    void startLooping(float startPoint, float endPoint);
};

float SimpleLooper::createLoopPoint(float newStart, float newEnd)
{
    SimpleLooper myLoop;
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
    float totalMoney; // 100,000,000
    bool canLoanMoney;
    float yearlyInterestRate;

    Bank()
    {
        totalMoney = 100000000.f; 
        canLoanMoney = true;
        yearlyInterestRate = 4.0f;
    }
    
    struct PersonalAccount
    {
        float valueOfAccount;
        bool owesMoney;
        int totalAssetsHeld;

        PersonalAccount()
        {
            valueOfAccount = 50000.f;
            owesMoney = true;
            totalAssetsHeld = 15;
        }

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
        std::cout << "\nThank you for your payment, but you STILL owe more! Current balance is: " << tristanAccount.valueOfAccount << "." << std::endl;
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
    int totalSearches;
    int totalAdsBlocked;
    bool accountLoggedIn;

    SearchEngine()
    {
        totalSearches = 50;
        totalAdsBlocked = 100;
        accountLoggedIn = false;
    }

    struct SearchBar
    {
        float widthOfSearchBar;
        float heightOfSearchBar;
        bool searchEnabled;

        SearchBar()
        {
            widthOfSearchBar = 100.f;
            heightOfSearchBar = 5.f;
            searchEnabled = true;
        }

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
    
    Filter myFilter;
    Filter::FilterKnob myKnob;
    WavetableOscillator myWavetableOsc;
    WavetableOscillator::Wavetable myWavetable;
    Reverb myReverb;
    Equalizer myEqualizer;
    Delay myDelay;
    Synthesizer mySynth;
    SimpleLooper looper;
    SearchEngine mySearchEngine;
    SearchEngine::SearchBar mySearchBar;
    Bank localBank;
    Bank::PersonalAccount tristanAccount;
    ADSREnvelope myEnvelope;
   
    myEnvelope.playNote(); 
    myFilter.updateKnobPosition(myKnob, 5.3);
    localBank.payOffLoans(localBank, tristanAccount);

   // Example::main();
   // std::cout << "good to go!" << std::endl;
}
