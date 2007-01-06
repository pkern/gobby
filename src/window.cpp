/* gobby - A GTKmm driven libobby client
 * Copyright (C) 2005 0x539 dev group
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtkmm/main.h>
#include "createdialog.hpp"
#include "joindialog.hpp"
#include "window.hpp"

Gobby::Window::Window()
 : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{
	m_header.session_create_event().connect(
		sigc::mem_fun(*this, &Window::on_session_create) );
	m_header.session_join_event().connect(
		sigc::mem_fun(*this, &Window::on_session_join) );
	m_header.session_quit_event().connect(
		sigc::mem_fun(*this, &Window::on_session_quit) );
	m_header.quit_event().connect(
		sigc::mem_fun(*this, &Window::on_quit) );

	m_frame_chat.set_shadow_type(Gtk::SHADOW_IN);
	m_frame_list.set_shadow_type(Gtk::SHADOW_IN);
	m_frame_text.set_shadow_type(Gtk::SHADOW_IN);

	m_frame_chat.add(m_chat);
	m_frame_list.add(m_userlist);
	m_frame_text.add(m_folder);

	m_subpaned.pack1(m_frame_text, true, false);
	m_subpaned.pack2(m_frame_list, true, false);

	m_mainpaned.set_border_width(10);
	m_mainpaned.pack1(m_subpaned, true, false);
	m_mainpaned.pack2(m_frame_chat, true, false);

	m_mainbox.pack_start(m_header, Gtk::PACK_SHRINK);
	m_mainbox.pack_start(m_mainpaned, Gtk::PACK_EXPAND_WIDGET);

	add(m_mainbox);

	set_title("Gobby");
	set_default_size(640, 480);
}

Gobby::Window::~Window()
{
}

void Gobby::Window::on_session_create()
{
	CreateDialog dlg(*this);
	if(dlg.run() == Gtk::RESPONSE_OK)
	{
	}
}

void Gobby::Window::on_session_join()
{
	JoinDialog dlg(*this);
	if(dlg.run() == Gtk::RESPONSE_OK)
	{
	}
}

void Gobby::Window::on_session_quit()
{
}

void Gobby::Window::on_quit()
{
	Gtk::Main::quit();
}

