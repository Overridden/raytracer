eye
	position -10,0,0

plane
	position 10, 10, 21
	rotation 180, 0, 0
	color 0x848484

plane
	position -10, -10, -7
	color 0xEDFFFA

#cylindre du fond
	
cylinder
	position 45, 13, 0
	param 3
	color 0x0000FF

cylinder
	position 45, -10, 0
	param 3
	color 0x0000FF

#cylinder de  devant

cylinder
	position 12, 11, 0
	param 3
	color 0x0000FF

cylinder
	position 13, -10, 0
	param 3
	color 0x0000FF

#sphere du milieu

sphere
	position 25,1,-5
	color 0xFF6BF5
	param 2

#sphere de gauche
	
sphere
	position 25, -9, 8
	color 0xFF0000
	param 2

#sphere de droite
	
sphere
	position 25, 11, 0
	color 0xFF0000
	param 2

#lumiere
	
light
	position -20,-60,20
	color :0x0000FF

light
	position -20,52,20
	color 0x0000FF
