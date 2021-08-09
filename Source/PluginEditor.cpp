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
    setSize (400, 200);
    
    gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    gainSlider.setRange(0.0, 1.0);
    gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    gainSlider.setTextValueSuffix ("Volume");
    gainSlider.setValue(1.0);
    
    phaseButton.setToggleState(false, 0);
    
    addAndMakeVisible(&gainSlider);
    addAndMakeVisible(&phaseButton);
    
    // add the listener to the slider
    gainSlider.addListener(this);
    phaseButton.addListener(this);
    
    
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
    g.drawFittedText ("Gain & Phase", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void MultichannelGainPhaseAudioProcessorEditor::resized()
{
    // sets the position and size of the slider with arguments (x, y, width, height)
    gainSlider.setBounds (40, 30, 20, getHeight() - 60);
    phaseButton.setBounds(38, getHeight() - 25, 30, 20);
}

//==============================================================================
void MultichannelGainPhaseAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if(slider == &gainSlider)
    {
        audioProcessor.rawVolume = gainSlider.getValue();
    }
}

void MultichannelGainPhaseAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if(button == &phaseButton)
    {
        if(!button->getToggleState())
            audioProcessor.phase = 1;
        else audioProcessor.phase = -1;
    }}

void MultichannelGainPhaseAudioProcessorEditor::buttonStateChanged(juce::Button* button)
{
}
