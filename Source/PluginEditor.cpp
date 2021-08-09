/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultichannelGainPhaseAudioProcessorEditor::MultichannelGainPhaseAudioProcessorEditor (MultichannelGainPhaseAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    
    audioSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    audioSlider.setRange(0.0, 1.0);
    audioSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    audioSlider.setPopupDisplayEnabled(true, false, this);
    audioSlider.setTextValueSuffix ("Volume");
    audioSlider.setValue(1.0);
    
    addAndMakeVisible(&audioSlider);
    
}

MultichannelGainPhaseAudioProcessorEditor::~MultichannelGainPhaseAudioProcessorEditor()
{
}

//==============================================================================
void MultichannelGainPhaseAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Gain Phase", getLocalBounds(), juce::Justification::centred, 1);
}

void MultichannelGainPhaseAudioProcessorEditor::resized()
{
    // sets the position and size of the slider with arguments (x, y, width, height)
    audioSlider.setBounds (40, 30, 20, getHeight() - 60);
}
