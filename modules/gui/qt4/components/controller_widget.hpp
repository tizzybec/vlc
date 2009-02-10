/*****************************************************************************
 * Controller_widget.cpp : Controller Widget for the controllers
 ****************************************************************************
 * Copyright (C) 2006-2008 the VideoLAN team
 * $Id$
 *
 * Authors: Jean-Baptiste Kempf <jb@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef _CONTROLLER_WIDGET_H_
#define _CONTROLLER_WIDGET_H_

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "qt4.hpp"

#include <QWidget>
#include <QFrame>
#include <QToolButton>

#define I_PLAY_TOOLTIP N_("Play\nIf the playlist is empty, open a media")

class QLabel;
class QSpinBox;
class QAbstractSlider;

/**
 * SPECIAL Widgets that are a bit more than just a ToolButton
 * and have an icon/behaviour that changes depending on the context:
 * - playButton
 * - A->B Button
 * - Teletext group buttons
 * - Sound Widget group
 **/
class PlayButton : public QToolButton
{
    Q_OBJECT
public:
    PlayButton( QWidget *parent ) : QToolButton( parent ) { }
private slots:
    void updateButton( bool );
};

class AtoB_Button : public QToolButton
{
    Q_OBJECT
public:
    AtoB_Button( QWidget *parent ) : QToolButton( parent ) { }
private slots:
    void setIcons( bool, bool );
};

class TeletextController : public QFrame
{
    Q_OBJECT
    friend class AbstractController;

public:
    TeletextController( QWidget *parent ) : QFrame( parent ) { }

private:
    QToolButton         *telexTransparent, *telexOn;
    QSpinBox            *telexPage;

private slots:
    void enableTeletextButtons( bool );
};

#define VOLUME_MAX 200
class VolumeClickHandler;

class SoundWidget : public QWidget
{
    Q_OBJECT

public:
    SoundWidget( QWidget *parent, intf_thread_t  *_p_i, bool,
                 bool b_special = false );

private:
    intf_thread_t       *p_intf;
    QLabel              *volMuteLabel;
    QAbstractSlider     *volumeSlider;
    bool                 b_my_volume;
    QMenu               *volumeMenu;
    virtual bool eventFilter( QObject *obj, QEvent *e );
protected slots:
    void updateVolume( int );
    void updateVolume( void );
    void showVolumeMenu( QPoint pos );
};

#endif
