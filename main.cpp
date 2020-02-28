/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


//insert Example::main() into main() of user's repo.



/*
 1)
 */
struct Filter
{
    double frequency;
    int filterType;
    float dryWet;

    Filter() : frequency(4000.0), filterType(2), dryWet (1.0f) {}


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

    if(numberOfKnobs < 10) newKnob.spawnKnob(numberOfKnobs, knobLocation);
    std::cout << "You are trying to spawn too many knobs at once!\n\n";
}

void Filter::updateKnobPosition(FilterKnob knobToUpdate, double nextKnobPosition)
{
    int knobID = knobToUpdate.knobID;
    std::cout << "The knob to update is: " << knobID << ". The next knob position is: " << nextKnobPosition << "." << std::endl;
}
/*
 2)
 */
struct WavetableOscillator
{
    double frequency;
    int waveShape;
    float volumeLevel;

    WavetableOscillator() : frequency(4000.0), waveShape(2), volumeLevel(1.0f) {}

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

    int getNextFrequencyInSequence(float nextFrequency)
    {
        std::cout << "The next frequency is: " << nextFrequency << ".\n" << std::endl;
        return{};
    }
};

void WavetableOscillator::Wavetable::loadWavetable(int wavetableToLoad, float loadTimeOffset)
{
    if((currentWavetable != wavetableToLoad) && (loadTimeOffset > 0))
    {
        currentWavetable = wavetableToLoad;
        std::cout << "You just loaded wavetable: " << currentWavetable << ".\n" << std::endl;
    }
    else std::cout << "Unable to load wavetable!\n" << std::endl;
}
/*
 3)
 */
struct ADSREnvelope
{
    double attack = 2.0;
    double decay = 2.0;
    float sustain = 1.f;
    float release = 2.4f;
    bool isMidiControlEnabled = true;

    void playNote(); 
    void playNoteOnTrigger(ADSREnvelope myEnvelope);
};

void ADSREnvelope::playNoteOnTrigger(ADSREnvelope newEnvelope)
{
    newEnvelope.playNote();
}

void ADSREnvelope::playNote()
{
    std::cout << "Playing note! Your ADSR Values are:\nAttack: " << attack << "\nDecay: " << decay << "\nSustain: " << sustain << "\nRelease: " << release << ".\n" << std::endl;
}
/*
 4)
 */
struct Reverb
{
    int decayTime = 1;
    float roomSize = 3.5f;
    double inputVolume = 1.0;
    double outputVolume = 1.0;

    int setNextReverbSettings(Reverb newVerbSettings);
};

int Reverb::setNextReverbSettings(Reverb newVerbSettings)
{
    Reverb oldVerbSettings;
    if(newVerbSettings.decayTime == oldVerbSettings.decayTime)
    {
        decayTime = 0;
        std::cout << "Setting reverb decay time to: " << decayTime << ".\n" << std::endl;
    }
    else
    {
        newVerbSettings.decayTime = oldVerbSettings.decayTime;
        std::cout << "Setting reverb decay time to old verb settings: (" << newVerbSettings.decayTime << ").\n\n" << std::endl;
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

    Equalizer() : frequency(2000.19), equalizerQ(1.f), gain(0.5f), enableEQ(1) {}
    
    void disableEqualizer(Equalizer defaultEQ);
};

void Equalizer::disableEqualizer(Equalizer changeThisEQ)
{
    if(changeThisEQ.enableEQ == 1)
    {
        changeThisEQ.enableEQ = 0;
        std::cout << "Disabling EQ!\n" << std::endl;
    }
    else std::cout << "Cannot disable EQ... EQ is already disabled!\n" << std::endl;
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

    Delay() : bpmSync(false), feedback(50.f), delayRate(1), pingPong(false) {}

    void copySettingsToAllOfSameType(Delay);
};

void Delay::copySettingsToAllOfSameType(Delay settingsToCopy)
{
    Delay myDelay;

    myDelay.bpmSync = settingsToCopy.bpmSync;
    myDelay.feedback = settingsToCopy.feedback;
    myDelay.delayRate = settingsToCopy.delayRate;
    myDelay.pingPong = settingsToCopy.pingPong;

    std::cout << "Your new delay settings are: bpmSync = " << myDelay.bpmSync << ", feedback = " << myDelay.feedback << ", delayRate = " << myDelay.delayRate << ", pingPong = " << myDelay.pingPong << ".\n" << std::endl;
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

void Synthesizer::startSound()
{
    std::cout << "The Synthesizer has started  to produce sound.\n" << std::endl;
}
/*
 8)
 */
struct SimpleLooper
{
    float loopStartPoint = 0.f;
    float loopEndPoint = 10.f;
    bool shouldLoop = true;

    float createLoopPoint(float startPoint, float endPoint);
    void startLooping(float startPoint, float endPoint);
};

float SimpleLooper::createLoopPoint(float newStart, float newEnd)
{
    SimpleLooper myLoop;
    myLoop.startLooping(newStart, newEnd);
    return {};
}
void SimpleLooper::startLooping(float startPoint, float endPoint)
{
    float loopLength = endPoint - startPoint;
    std::cout << "Your new loop length is: " << loopLength << " seconds.\n" << std::endl;
}
/*
 9)
 */
struct Bank
{
    float totalMoney; // 100,000,000
    bool canLoanMoney;
    float yearlyInterestRate;

    Bank() : totalMoney(100000000.f), canLoanMoney(true), yearlyInterestRate(4.0f) {}
    
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

        float getValueOfAccount(PersonalAccount thisAccount)
        {
        std::cout << "The value of this account is: " << thisAccount.valueOfAccount << ".\n" << std::endl;
        return thisAccount.valueOfAccount;
        }
    };

    void payOffLoans(Bank chase, PersonalAccount newAccount);
};

void Bank::payOffLoans(Bank chase, PersonalAccount tristanAccount)
{
    if(tristanAccount.valueOfAccount > 1000.f)
    {
        chase.totalMoney += tristanAccount.valueOfAccount;
        tristanAccount.valueOfAccount = 0;
        std::cout << "\nThank you for your payment, but you STILL owe more! Current balance is: " << tristanAccount.valueOfAccount << ".\n" << std::endl;
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
    void openNewBrowserWindow(int totalNewWindows, float height, float width)
    {
        std::cout << "You want to open " << totalNewWindows << " windows. Their width will be: " << width << ", and their height will be: " << height << ".\n" << std::endl;
    }
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
void SearchEngine::SearchBar::clearSearchEngine()
{
    std::cout << "SearchEngine has been cleared!\n" << std::endl;
}

#include <iostream>
int main()
{ 
    
    Filter myFilter;
    Filter::FilterKnob myKnob;
    WavetableOscillator myWavetableOsc;
    WavetableOscillator::Wavetable myWavetable;
    Reverb myReverb;
    Reverb myOldReverb;
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
    myKnob.spawnKnob(10, 5.f);
    myWavetableOsc.getNextFrequencyInSequence(150.55f);
    myWavetable.loadWavetable(0, 1);
    myReverb.setNextReverbSettings(myOldReverb);
    myEqualizer.disableEqualizer(myEqualizer);
    myDelay.copySettingsToAllOfSameType(myDelay);
    mySynth.startSound();
    looper.startLooping(15.f, 20.f);
    myFilter.updateKnobPosition(myKnob, 5.3);
    localBank.payOffLoans(localBank, tristanAccount);
    tristanAccount.getValueOfAccount(tristanAccount);
    mySearchEngine.openNewBrowserWindow(5, 3.5f, 5.35f);
    mySearchBar.clearSearchEngine();
   // Example::main();
   // std::cout << "good to go!" << std::endl;
}
