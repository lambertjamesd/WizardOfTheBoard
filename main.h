

#ifndef MAIN_H
#define MAIN_H

#ifdef _LANGUAGE_C

/* Definition of the external variable  */
extern NUContData	contdata[1]; /* Read data of the controller  */
extern u8 contPattern;		     /* The pattern of the connected controller  */

// Setting for the ingame FOV
extern float ingameFOV;

// Frame delta
extern OSTime time;
extern OSTime delta;
extern float deltaTimeSeconds;

#endif /* _LANGUAGE_C */
#endif /* MAIN_H */




