#pragma once

#include "EntryPanel.h"

namespace slade
{
class DefaultEntryPanel : public EntryPanel
{
public:
	DefaultEntryPanel(wxWindow* parent, bool frame = true);
	~DefaultEntryPanel() = default;

	bool loadEntries(vector<ArchiveEntry*>& entries);
	bool saveEntry() override;

protected:
	bool loadEntry(ArchiveEntry* entry) override;

private:
	vector<ArchiveEntry*> entries_;

	wxStaticText* label_type_  = nullptr;
	wxStaticText* label_size_  = nullptr;
	wxStaticText* label_index_ = nullptr;

	// Actions
	wxStaticBox* frame_actions_          = nullptr;
	wxButton*    btn_gfx_convert_        = nullptr;
	wxButton*    btn_gfx_modify_offsets_ = nullptr;
	wxButton*    btn_texture_edit_       = nullptr;

	// Events
	void onBtnGfxModifyOffsets(wxCommandEvent& e);
};
} // namespace slade
