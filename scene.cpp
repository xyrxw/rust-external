#pragma once
#include "scene.hpp"
		  
void styles()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	{
		ImGuiStyle& style = ImGui::GetStyle();

	}

	ImGuiStyle* style = &ImGui::GetStyle();
	{
		style->WindowBorderSize = 1.0f;
		style->ChildBorderSize = 1.0f;

		style->FramePadding = ImVec2(4, 0);

		style->WindowTitleAlign = ImVec2(.5, .5);
	}
}
auto wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> bool
{
	return true;
}
auto init_ui() -> void  
{

	//ImGui::StyleColorsDark();
	styles();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImFontConfig font_config;
	font_config.OversampleH = 1; //or 2 is the same
	font_config.OversampleV = 1;
	font_config.PixelSnapH = 1;

	static const ImWchar ranges[] =
	{
		0x0020, 0x00FF, // Basic Latin + Latin Supplement
		0x0400, 0x044F, // Cyrillic
		0,
	};
	structure.c_font_defult = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 17.f);
	structure.c_font_icon = io.Fonts->AddFontFromMemoryTTF((void*)iconfont, sizeof(iconfont), 30, &font_config, ranges);
}

auto create_scene() -> void 
{
	// create cheat 
	cheat->create();
	
	// draw gui 
	gui->draw();	
}

void espThread()
{
	//if (vars.esp)
	gui->drawESPOverlay();
		
}

std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

void c_scene::create()
{
	Sleep(1000);
	GAPI::MakeWindow("Crown", "Crown", wnd_proc, init_ui, create_scene, espThread, &vars.g_open, &vars.g_menu_key);
}

