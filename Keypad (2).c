/*
 * Keypad.h
 *
 * Created: 8/3/2016 8:10:56 PM
 *  Author: Ahmad-Mustafa 
 */ 

#include "Keypad.h"

unsigned char keyPress(void)
{
	unsigned char col,row;	
	while(1)
	{
		//Higher 4 pits as output(columns) while Lower 4 pits as input (rows)
		KEYPAD_DDR = (0xF0);
		//KEYPAD_PORT |= 0xFF; //enable the internal pull up resistors for the first 4 pins in row pins.
		
		for(col=0;col<NC;col++) //loop for columns
		{			
			KEYPAD_PORT |= 0xFF; //enable the internal pull up resistors for the first 4 pins in row pins.
			KEYPAD_PORT &= (~(0b00010000<<col)); // clear the column which is the output pin in this trace 
			for(row=0;row<NR;row++) //loop for rows
			{
				if((KEYPAD_PIN & (1<<row)) == 0) //if the switch is press in this row 
				{
					_delay_ms(30);
					if((KEYPAD_PIN & (1<<row)) == 0) //if the switch is press in this row 
					{
						#if (NC == 3)   
							 unsigned char keypad_4x3[NR][NC] = {'1','2','3',
																 '4','5','6',
																'7','8','9',
																'*','0','#'};
							while((KEYPAD_PIN & (1<<row)) == 0);						
							return keypad_4x3[row][col];	
						
						#else 
						
							unsigned char keypad_4x4[NR][NC] = {'7','8','9','/',
																'4','5','6','*',
																'1','2','3','-',
																'C','0','=','+'};					
							while((KEYPAD_PIN & (1<<row)) == 0);						
							return keypad_4x4[row][col];	
						
						#endif								
					}
				 }
								 
			}
		}
		return 'D'; // any thing not in the 2-D arrays 
	}
}
