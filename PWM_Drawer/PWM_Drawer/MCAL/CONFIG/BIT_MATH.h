/*
 * BIT_MATH.h
 *
 * Created: 5/5/2023 9:20:37 AM
 *  Author: NewVision
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT) REG |= (1 << BIT)		// Set value of bit to logic(1)
#define CLR_BIT(REG, BIT) REG &= ~(1 << BIT)	// Set value of bit to logic(0)
#define TGL_BIT(REG, BIT) REG ^= (1 << BIT)		// Toggle value of bit (NOT)
#define GET_BIT(REG, BIT) ((REG>>BIT) & 0x01)	// Read value of needed bit

#endif /* BIT_MATH_H_ */