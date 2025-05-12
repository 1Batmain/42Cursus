/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:47:32 by bduval            #+#    #+#             */
/*   Updated: 2025/05/11 09:35:18 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// Screen dimensions
# define WIN_WIDTH		1080
# define WIN_HEIGHT		720

//Objects types
# define CAMERA		0b00000001
# define LIGHT		0b00000010
# define AMB_LIGHT	0b00000100
# define SPHERE		0b00001000
# define PLANE		0b00010000
# define CYLINDER	0b00100000

//keycodes
# define BTN_CROSS			0xadd477e0
# define KEY_ESCAPE			0xff1b
# define KEY_UP				0xff52
# define KEY_DOWN			0xff54
# define KEY_LEFT			0xff51
# define KEY_RIGHT			0xff53
# define KEY_NP_PLUS		0xffab
# define KEY_NP_MINUS		0xffad

//Eroors messages
# define ERROR_ARGUMENTS	"\
You must provide only a scene description \
file with .br extension as argument\n"

//SETS
# define SPACES				" \t"
#endif
