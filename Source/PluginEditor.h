/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MultichannelGainPhaseAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                   private juce::Slider::Listener,
                                                   private juce::Button::Listener
{
public:
    MultichannelGainPhaseAudioProcessorEditor (MultichannelGainPhaseAudioProcessor&);
    ~MultichannelGainPhaseAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MultichannelGainPhaseAudioProcessor& audioProcessor;
    
    juce::Slider gainSlider;
    juce::ToggleButton phaseButton;

    void sliderValueChanged(juce::Slider* slider) override;
    void buttonClicked(juce::Button* button) override;
    void buttonStateChanged(juce::Button* button) override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultichannelGainPhaseAudioProcessorEditor)
};
