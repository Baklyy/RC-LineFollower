#ifndef APP_AUTO_AUTO_INTERFACE_H_
#define APP_AUTO_AUTO_INTERFACE_H_

#define AUTO_u16_STANDERED_RPM		30

#define AUTO_f32_COLLISION_DIST		20.0

#define AUTO_u8_MAX_VIEW_SIZE		60
//
#define AUTO_u8_GO_RIGHT 	1
#define AUTO_u8_GO_LEFT		0

#define AUTO_u8_AVOIDANCE_RPM	10
//
#define AUTO_u8RIGHT 180
#define AUTO_u8LEFT 0
#define AUTO_u8Center 90
#define AUTO_u16_SLOW_RPM		25



//
void AUTO_voidReCenter();

void AUTO_voidInit();

void AUTO_voidStart();

void AUTO_voidGoToClearSide(u8 AUTO_u8_Clear_Side);

void AUTO_voidAvoidObstacle();
//

void AUTO_voidIr0();
void AUTO_voidIr1();
void tim0isr();

void AUTO_voidIRen(u8 Copy_u8EXTINo);
void AUTO_voidIRdis(u8 Copy_u8EXTINo);

#endif /* APP_AUTO_AUTO_INTERFACE_H_ */
