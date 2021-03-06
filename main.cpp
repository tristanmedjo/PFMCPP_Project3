/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
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
    double transitionToNextFrequency(Filter, double, double);
};

double Filter::transitionToNextFrequency(Filter thisFilter, double targetFrequency, double incrementAmount)
{
    std::cout << "\nThe starting frequency before transitioning is: " << thisFilter.frequency << "." << std::endl;

    while(targetFrequency <= thisFilter.frequency || thisFilter.frequency <= targetFrequency)
    {
        std::cout << "Transitioning... frequency is: " << thisFilter.frequency << std::endl;

        if(thisFilter.frequency < targetFrequency && targetFrequency - thisFilter.frequency > incrementAmount)
        {
            thisFilter.frequency += incrementAmount;
        }
        else if(thisFilter.frequency > targetFrequency && targetFrequency - thisFilter.frequency < incrementAmount)
        {
            thisFilter.frequency -= incrementAmount;
        }
        else
        {
            double remainder = targetFrequency - thisFilter.frequency;
            thisFilter.frequency += remainder; // making sure we hit that final increment without exceeding target
            
            std::cout << "Frequency transition completed. Current frequency is: " << thisFilter.frequency << ".\n" << std::endl;
            return thisFilter.frequency;
        }  
    }
    
    return thisFilter.frequency;
}

void Filter::FilterKnob::spawnKnob(int numberOfKnobs, float knobLocation)
{
    FilterKnob newKnob;

    if(numberOfKnobs < 10) newKnob.spawnKnob(numberOfKnobs, knobLocation);
    std::cout << "You are trying to spawn too many knobs at once!\n\n";
}

void Filter::updateKnobPosition(FilterKnob knobToUpdate, double nextKnobPosition)
{
    int knobID = knobToUpdate.knobID;
    std::cout << "The knob to update is: " << knobID << ". The next knob position is: " << nextKnobPosition << ".\n" << std::endl;
    std::cout << "Your filter frequency is:" << frequency << std::endl;
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
                    
        int cycleToTargetWavetable(WavetableOscillator::Wavetable table, int targetTable);   
        void loadWavetable(int wavetableToLoad, float loadTimeOffset);
    };

    int getNextFrequencyInSequence(float nextFrequency)
    {
        std::cout << "The next frequency is: " << nextFrequency << ".\n" << std::endl;

        std::cout << "Waveshape is: " << waveShape << ". Volume Level is: " << volumeLevel << ".\n" << std::endl;
        return{};
    }

    float fadeOutVolume(WavetableOscillator osc, float incrementAmount)
    {
        for(float i = osc.volumeLevel; i >= 0; i -= incrementAmount)
        {
            osc.volumeLevel -= incrementAmount;
            std::cout << "Current oscillator volume is: " << osc.volumeLevel << "." << std::endl;
            if(osc.volumeLevel <= 0)
            {
                std::cout << "Finished fading out!\n" << std::endl;
                return osc.volumeLevel;
            }
        }
        
        return osc.volumeLevel;
    }
};

int WavetableOscillator::Wavetable::cycleToTargetWavetable(WavetableOscillator::Wavetable table, int targetTable)
{
    std::cout << "Cycling through wavetables!" << std::endl;
    while(table.currentWavetable != targetTable)
    {
        table.currentWavetable += 1;
        if(table.currentWavetable >= targetTable)
        {
            std::cout << "Completed cycling! Final wavetable is: " << table.currentWavetable << ".\n" << std::endl;
            return table.currentWavetable;
        }
        std::cout << "Current wavetable is: " << table.currentWavetable << "." << std::endl;
    }
   
    return table.currentWavetable;
}

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
    double dryWet = 1.0;

    int setNextReverbSettings(Reverb newVerbSettings);
    double setNextDryWet(Reverb targetVerb, double nextDryWetValue)
    {
        double epsilon = 0.0001;

        std::cout << "\nAdjusting reverb dryWet!" << std::endl;
        double incrementPolarity;

        if(targetVerb.dryWet < nextDryWetValue) incrementPolarity = 0.1;
        else incrementPolarity = -0.1;

        if(nextDryWetValue > 1) 
        {
            std::cout << "dryWet cannot be higher than 1.0!" << std::endl;
            return dryWet;
        }

        for(double instancedDryWet = targetVerb.dryWet; std::abs(instancedDryWet - nextDryWetValue) > epsilon; instancedDryWet += incrementPolarity)
        {
            std::cout << "Current dryWet is: " << instancedDryWet << "." << std::endl;

            if(instancedDryWet <= nextDryWetValue)
            {
                std::cout << "Finished! New dryWet is: " << instancedDryWet << ".\n" << std::endl;
                return dryWet;
            }
        }
        return dryWet;
    }
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
        std::cout << "EQ Settings: Frequency: " << frequency << ". EqualizerQ: " << equalizerQ << ". Gain: " << gain << ". EnableEQ: " << enableEQ << ".\n" << std::endl;
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
    float playOneLoopCycle(SimpleLooper, float EndPoint, float incrementAmount)
    {
        float epsilon = 0.0001f;

        float playhead = 0.f;
        std::cout << "Starting one loop cycle. Playhead is currently at: " << playhead << "." << std::endl;

        while(playhead <= EndPoint)
        {
            playhead += incrementAmount;
            std::cout << "Playhead location: " << playhead << "." << std::endl;

            if(std::abs(playhead - loopEndPoint) < epsilon)
            {
                std::cout << "You have reached the end of the loop!" << std::endl;
                return playhead;
            }
        }
        return playhead;
    }
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
    std::cout << "SimpleLooper Values: loopStartPoint: " << loopStartPoint << ". loopEndPoint: " << loopEndPoint << ". shouldLoop: " << shouldLoop << ".\n" << std::endl;
}
/*
 9)
 */
struct Bank
{
    float totalMoney; // 100,000,000
    bool canLoanMoney;
    float yearlyInterestRate;

    Bank() : totalMoney(100.f), canLoanMoney(true), yearlyInterestRate(4.0f) {}
    
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
    float makeDepositOverTime(Bank targetBank, float depositAmount, int howManyDeposits)
    {
        float newTotal = targetBank.totalMoney + depositAmount;
        int currentDeposit = 0;
        for(float i = targetBank.totalMoney; i <= newTotal; i = i + (depositAmount / howManyDeposits))
        {
            float epsilon = 0.0001f;
            
            if(std::abs(i - targetBank.totalMoney) < epsilon)
            std::cout << "\nYour account value BEFORE the deposit is: " << targetBank.totalMoney << "." << std::endl;
           
            else std::cout << "Account value after deposit " << currentDeposit << " is " << i << "." << std::endl;
            
            currentDeposit += 1;

            if(std::abs(i - newTotal) < epsilon)
            {
                std::cout << "Deposit completed!\n" << std::endl;
                return targetBank.totalMoney;
            }
        }
        
        return targetBank.totalMoney;
    }
};

void Bank::payOffLoans(Bank chase, PersonalAccount tristanAccount)
{
    if(tristanAccount.valueOfAccount > 1000.f)
    {
        chase.totalMoney += tristanAccount.valueOfAccount;
        tristanAccount.valueOfAccount = 0;
        std::cout << "\nThank you for your payment, but you STILL owe more! Current balance is: " << tristanAccount.valueOfAccount << ".\n" << std::endl;

        std::cout << "Bank values: totalMoney: " << totalMoney << ". canLoanMoney: " << canLoanMoney << ". yearlyInterestRate: " << yearlyInterestRate << ".\n";
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
void SearchEngine::SearchBar::show()
{
    std::cout << "SearchEngine and SearchBar Values: widthOfSearchBar: " << widthOfSearchBar << ". heightOfSearchBar: " <<heightOfSearchBar << ". searchEnabled: " << searchEnabled << ". widthOfSearchBar: " << widthOfSearchBar << "heightOfSearchBar: " << heightOfSearchBar << ". searchEnabled: " << searchEnabled << ".\n" << std::endl; 
}
void SearchEngine::SearchBar::clearSearchEngine()
{
    std::cout << "SearchEngine has been cleared!\n" << std::endl;
}

#include <iostream>
int main()
{ 
    Example::main();

    Filter myFilter; 
    //Filter::FilterKnob myKnob;
    WavetableOscillator myWavetableOsc;
    WavetableOscillator::Wavetable myWavetable;
    Reverb myReverb;
    //Reverb myOldReverb;
    //Equalizer myEqualizer;
    //Delay myDelay;
    //Synthesizer mySynth;
    SimpleLooper looper;
    //SearchEngine mySearchEngine;
    //SearchEngine::SearchBar mySearchBar;
    Bank localBank;
    //Bank::PersonalAccount tristanAccount;
    //ADSREnvelope myEnvelope;
   /*
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
*/
    myFilter.transitionToNextFrequency(myFilter, 5000, 150);
    myWavetableOsc.fadeOutVolume(myWavetableOsc, 0.05f);
    myWavetable.cycleToTargetWavetable(myWavetable, 8);
    looper.playOneLoopCycle(looper, 10.f, 1.f);
    localBank.makeDepositOverTime(localBank, 100, 5);
    myReverb.setNextDryWet(myReverb, .6);

    std::cout << "good to go!" << std::endl;
}
