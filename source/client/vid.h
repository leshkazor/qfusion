/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// vid.h -- video driver defs

#ifndef __VID_H__
#define __VID_H__

typedef struct
{
	unsigned width, height;             // coordinates from main game
} viddef_t;

extern viddef_t	viddef;             // global video state

// Video module initialisation etc
void	VID_Init( void );
void	VID_Shutdown( void );
void	VID_CheckChanges( void );
void	VID_Restart( qboolean verbose, qboolean soundRestart );
// The sound module may require the handle when using directsound
void	*VID_GetWindowHandle( void );
void	VID_FlashWindow( int count );
qboolean VID_GetDisplaySize( int *width, int *height );
qboolean VID_GetModeInfo( int *width, int *height, qboolean *wideScreen, int mode );
void	VID_AppActivate( qboolean active, qboolean destroy );
qboolean VID_RefreshActive( void );
int		VID_GetWindowWidth( void );
int		VID_GetWindowHeight( void );
float	VID_GetPixelRatio( void );

#endif
