/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // make drive knob visible and with circle style
    addAndMakeVisible(driveKnob = new Slider("Drive"));
    driveKnob->setSliderStyle(Slider::Rotary);
    driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    // make range knob visible and with circle style
    addAndMakeVisible(rangeKnob = new Slider("Range"));
    rangeKnob->setSliderStyle(Slider::Rotary);
    rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    // make blend knob visible and with circle style
    addAndMakeVisible(blendKnob = new Slider("Blend"));
    blendKnob->setSliderStyle(Slider::Rotary);
    blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    // make volume knob visible and with circle style
    addAndMakeVisible(volumeKnob = new Slider("Volume"));
    volumeKnob->setSliderStyle(Slider::Rotary);
    volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    // attaching knobs to state
    driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
    rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
    blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
    volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);

    int firstWidth = ((getWidth() / 5) * 1) - (100 / 2);
    int secondWidth = ((getWidth() / 5) * 2) - (100 / 2);
    int thirdWidth = ((getWidth() / 5) * 3) - (100 / 2);
    int fourthWidth = ((getWidth() / 5) * 4) - (100 / 2);
    int height = (getHeight() / 2) + 45;


    g.drawText("Drive", firstWidth, height, 100, 20, juce::Justification::centred, false);
    g.drawText("Range", secondWidth, height, 100, 20, juce::Justification::centred, false);
    g.drawText("Blend", thirdWidth, height, 100, 20, juce::Justification::centred, false);
    g.drawText("Volume", fourthWidth, height, 100, 20, juce::Justification::centred, false);
}

void DistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    int firstWidth = ((getWidth() / 5) * 1) - (100 / 2);
    int secondWidth = ((getWidth() / 5) * 2) - (100 / 2);
    int thirdWidth = ((getWidth() / 5) * 3) - (100 / 2);
    int fourthWidth = ((getWidth() / 5) * 4) - (100 / 2);
    int height = (getHeight() / 2) - (100 / 2);

    driveKnob->setBounds(firstWidth, height, 100, 100);
    rangeKnob->setBounds(secondWidth, height, 100, 100);
    blendKnob->setBounds(thirdWidth, height, 100, 100);
    volumeKnob->setBounds(fourthWidth, height, 100, 100);
}
