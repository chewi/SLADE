#pragma once

#include "EntryPanel.h"

// Forward declarations
namespace slade::audio
{
class ModMusic;
}
namespace sf
{
class SoundBuffer;
class Sound;
class Music;
} // namespace sf
class wxMediaCtrl;

namespace slade
{
class AudioEntryPanel : public EntryPanel
{
public:
	AudioEntryPanel(wxWindow* parent, bool frame = true);
	~AudioEntryPanel();

	bool     saveEntry() override;
	wxString statusString() override;
	void     setAudioDuration(int duration);

protected:
	bool loadEntry(ArchiveEntry* entry) override;

private:
	enum AudioType
	{
		Invalid,
		Sound,
		Music,
		MIDI,
		Media,
		Mod,
		Emu,
		OPL,
	};

	wxString  prevfile_;
	AudioType audio_type_  = Invalid;
	int       num_tracks_  = 1;
	int       subsong_     = 0;
	int       song_length_ = 0;
	bool      opened_      = false;
	MemChunk  data_;

	wxBitmapButton* btn_play_      = nullptr;
	wxBitmapButton* btn_pause_     = nullptr;
	wxBitmapButton* btn_stop_      = nullptr;
	wxBitmapButton* btn_next_      = nullptr;
	wxBitmapButton* btn_prev_      = nullptr;
	wxSlider*       slider_seek_   = nullptr;
	wxSlider*       slider_volume_ = nullptr;
	wxTimer*        timer_seek_    = nullptr;
	wxMediaCtrl*    media_ctrl_    = nullptr;
	wxStaticText*   txt_title_     = nullptr;
	wxStaticText*   txt_track_     = nullptr;
	wxTextCtrl*     txt_info_      = nullptr;

	unique_ptr<sf::SoundBuffer> sound_buffer_;
	unique_ptr<sf::Sound>       sound_;
	unique_ptr<sf::Music>       music_;
	unique_ptr<audio::ModMusic> mod_;

	bool open(ArchiveEntry* entry);
	bool openAudio(MemChunk& audio, const wxString& filename);
	bool openMidi(MemChunk& data, const wxString& filename);
	bool openMod(MemChunk& data);
	bool openMedia(const wxString& filename);
	bool updateInfo() const;
	void startStream();
	void stopStream() const;
	void resetStream() const;

	// Events
	void onBtnPlay(wxCommandEvent& e);
	void onBtnPause(wxCommandEvent& e);
	void onBtnStop(wxCommandEvent& e);
	void onBtnPrev(wxCommandEvent& e);
	void onBtnNext(wxCommandEvent& e);
	void onTimer(wxTimerEvent& e);
	void onSliderSeekChanged(wxCommandEvent& e);
	void onSliderVolumeChanged(wxCommandEvent& e);
};
} // namespace slade
