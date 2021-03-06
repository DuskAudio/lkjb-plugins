/*
==============================================================================

  This file was auto-generated by the Introjucer!

  It contains the basic startup code for a Juce application.

==============================================================================
*/

#ifndef __PLUGINEDITOR_H_8FBA87C0__
#define __PLUGINEDITOR_H_8FBA87C0__

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//#include "LkjbLookAndFeels.h"
#include "GuiLookAndFeel.h"

class ModalCallback;

//==============================================================================
/**
*/
class LuftikusAudioProcessorEditor  : public AudioProcessorEditor,
	                                  public Slider::Listener,
									  public ComboBox::Listener,
									  public Timer,
									  public Button::Listener,
									  public TooltipClient
{
public:

	LuftikusAudioProcessorEditor (LuftikusAudioProcessor* ownerFilter, LuftikusAudioProcessor::GUIType type);
	~LuftikusAudioProcessorEditor();

  //==============================================================================
  // This is just a standard Juce paint method...
	void resized();
	void paint (Graphics& g);

	void timerCallback();

	void sliderValueChanged (Slider* slider);
	void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
	void buttonClicked (Button* button);

	void mouseDown(const MouseEvent& e);

	String getTooltip();
	void modalReturn(int returnValue);

private:


	class ModalCallback : public ModalComponentManager::Callback
	{
	public:
		ModalCallback(LuftikusAudioProcessorEditor* parent_)
			: parent(parent_)
		{
		}

		void modalStateFinished(int returnValue)
		{
			if (parent != nullptr)
				parent->modalReturn(returnValue);
		}
	private:
		LuftikusAudioProcessorEditor* parent;
	};

	void initGui();
	void resizedGui();

	void paintGui(Graphics& g);

	void updateSliders();

	void updateSlidersGui();

	void timerCallbackGui();

	void updateTooltipState();

	LuftikusAudioProcessor* Proc;

	const LuftikusAudioProcessor::GUIType guiType;

	GuiSlider guiSliders[EqDsp::kNumTypes];

	Label labels[EqDsp::kNumTypes];
	ComboBox type;

	ToggleButton mastering;
	ToggleButton analog;
	ToggleButton keepGain;

	ToggleButton types[EqDsp::kNumHighSelves];

	GuiSlider guiMasterVol;

	Label masterVolLabel;

	Image background;
	GuiLookAndFeel guiLookAndFeel;

	ScopedPointer<TooltipWindow> tooltips;

	ModalCallback* modalCallback;
	ScopedPointer<PopupMenu> showTooltips;

	JUCE_DECLARE_NON_COPYABLE(LuftikusAudioProcessorEditor)
};



#endif  // __PLUGINEDITOR_H_8FBA87C0__
