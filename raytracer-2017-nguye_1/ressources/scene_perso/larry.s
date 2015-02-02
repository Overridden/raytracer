;;; larry from super meat boy - dovan_n
eye
	position 0,0,0

plane
	position 0,0,-10
	rotation 0,0,0
	color 0xA7A7A7
	param 0
	color_annex 0xFF0000
	color_type 4
	texture ressources/img/mars.xpm

plane
	position 1000,0,0
	rotation 0,110,0
	color 0x005348
	param 0
	color_type 4
	texture ressources/img/sun.xpm

light
	position 0,0,0
	color 0xFF0000

light
	position 290,0,0
	color 0xFFFFFF

;;; larry
sphere
	position 150,0,-9
	color 0x94E5DB
	param 15

sphere
	position 147,0,-1
	color 0x94E5DB
	param 15

sphere
	position 144,0,7
	color 0x94E5DB
	param 15

sphere
	position 141,0,15
	color 0x94E5DB
	param 15

sphere
	position 135,0,23
	color 0x94E5DB
	param 15
	texture	ressources/img/lastru_g.xpm
	color_type 0

;;; yeux
sphere
	position 120,-8,25
	color 0x050505
	param 3

sphere
	position 120,8,25
	color 0x050505
	param 3

;;; lueur blanche yeux
sphere
	position 117,-8,25
	color 0xFFFFFF
	param 1

sphere
	position 117,8,25
	color 0xFFFFFF
	param 1

;;; bouche
sphere
	position 117,0,18
	color 0x050505
	param 4

;;; bg

cylinder
	position 100,-50,0
	rotation 0,0,0
	color 0x88ABA6
	param 1
	color_type 0
	texture ressources/img/moon.xpm

cylinder
	position 100,50,0
	rotation 0,0,0
	color 0x88ABA6
	param 1
	color_type 0
	texture ressources/img/moon.xpm
