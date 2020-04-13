/*******************************************************************************
  SYS PORTS Static Functions for PORTS System Service

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.c

  Summary:
    PIO function implementations for the PIO PLIB.

  Description:
    The PIO PLIB provides a simple interface to manage peripheral
    input-output controller.

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

#include "plib_pio.h"

/* Array to store callback objects of each configured interrupt */
PIO_PIN_CALLBACK_OBJ portPinCbObj[3];

/* Array to store number of interrupts in each PORT Channel + previous interrupt count */
uint8_t portNumCb[7 + 1] = { 0, 0, 0, 3, 3, 3, 3, 3, };

/******************************************************************************
  Function:
    PIO_Initialize ( void )

  Summary:
    Initialize the PIO library.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_Initialize ( void )
{


 /* Port C Peripheral function GPIO configuration */
	PIOC_REGS->PIO_MSKR = 0xe0000000L;
	PIOC_REGS->PIO_CFGR = 0x0;
	
 /* Port C Pin 29 configuration */
	PIOC_REGS->PIO_MSKR = 0x20000000;
	PIOC_REGS->PIO_CFGR = (PIOC_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x3003200;
	
 /* Port C Pin 30 configuration */
	PIOC_REGS->PIO_MSKR = 0x40000000;
	PIOC_REGS->PIO_CFGR = (PIOC_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x3003200;
	
 /* Port C Pin 31 configuration */
	PIOC_REGS->PIO_MSKR = 0x80000000L;
	PIOC_REGS->PIO_CFGR = (PIOC_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x3003200;
	

    /* Clear the ISR register */ 
	(uint32_t)PIOC_REGS->PIO_ISR;
 /* Port D Peripheral function A configuration */
	PIOD_REGS->PIO_MSKR = 0xffffffffL;
	PIOD_REGS->PIO_CFGR = 0x1;
	

 /* Port E Peripheral function A configuration */
	PIOE_REGS->PIO_MSKR = 0xff;
	PIOE_REGS->PIO_CFGR = 0x1;
	

 /* Port F Peripheral function A configuration */
	PIOF_REGS->PIO_MSKR = 0x600087ff;
	PIOF_REGS->PIO_CFGR = 0x1;
	
 /* Port F Pin 2 configuration */
	PIOF_REGS->PIO_MSKR = 0x4;
	PIOF_REGS->PIO_CFGR = (PIOF_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x20000;
	

 /* Port G Peripheral function A configuration */
	PIOG_REGS->PIO_MSKR = 0xffffff;
	PIOG_REGS->PIO_CFGR = 0x1;
	
 /* Port G Pin 0 configuration */
	PIOG_REGS->PIO_MSKR = 0x1;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 1 configuration */
	PIOG_REGS->PIO_MSKR = 0x2;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 2 configuration */
	PIOG_REGS->PIO_MSKR = 0x4;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 3 configuration */
	PIOG_REGS->PIO_MSKR = 0x8;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 4 configuration */
	PIOG_REGS->PIO_MSKR = 0x10;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 5 configuration */
	PIOG_REGS->PIO_MSKR = 0x20;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 6 configuration */
	PIOG_REGS->PIO_MSKR = 0x40;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 7 configuration */
	PIOG_REGS->PIO_MSKR = 0x80;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 8 configuration */
	PIOG_REGS->PIO_MSKR = 0x100;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 9 configuration */
	PIOG_REGS->PIO_MSKR = 0x200;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 10 configuration */
	PIOG_REGS->PIO_MSKR = 0x400;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 11 configuration */
	PIOG_REGS->PIO_MSKR = 0x800;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 12 configuration */
	PIOG_REGS->PIO_MSKR = 0x1000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 13 configuration */
	PIOG_REGS->PIO_MSKR = 0x2000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 14 configuration */
	PIOG_REGS->PIO_MSKR = 0x4000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 15 configuration */
	PIOG_REGS->PIO_MSKR = 0x8000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 16 configuration */
	PIOG_REGS->PIO_MSKR = 0x10000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 17 configuration */
	PIOG_REGS->PIO_MSKR = 0x20000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 18 configuration */
	PIOG_REGS->PIO_MSKR = 0x40000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 19 configuration */
	PIOG_REGS->PIO_MSKR = 0x80000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 20 configuration */
	PIOG_REGS->PIO_MSKR = 0x100000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 21 configuration */
	PIOG_REGS->PIO_MSKR = 0x200000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 22 configuration */
	PIOG_REGS->PIO_MSKR = 0x400000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	
 /* Port G Pin 23 configuration */
	PIOG_REGS->PIO_MSKR = 0x800000;
	PIOG_REGS->PIO_CFGR = (PIOG_REGS->PIO_CFGR & (PIO_CFGR_FUNC_Msk)) | 0x10000;
	


    uint32_t i;
    /* Initialize Interrupt Pin data structures */
    portPinCbObj[0 + 0].pin = PIO_PIN_PC29;
    
    portPinCbObj[0 + 1].pin = PIO_PIN_PC30;
    
    portPinCbObj[0 + 2].pin = PIO_PIN_PC31;
    
    for(i=0; i<3; i++)
    {
        portPinCbObj[i].callback = NULL;
    }

}

// *****************************************************************************
// *****************************************************************************
// Section: PIO APIs which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint32_t PIO_PortRead ( PIO_PORT port )

  Summary:
    Read all the I/O lines of the selected port.

  Description:
    This function reads the live data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.

    This function reads the value regardless of pin configuration, whether it is
    set as as an input, driven by the PIO Controller, or driven by a peripheral.

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t PIO_PortRead(PIO_PORT port)
{
    return ((pio_group_registers_t*)port)->PIO_PDSR;
}

// *****************************************************************************
/* Function:
    void PIO_PortWrite (PIO_PORT port, uint32_t mask, uint32_t value);

  Summary:
    Write the value on the masked I/O lines of the selected port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value)
{
    ((pio_group_registers_t*)port)->PIO_MSKR = mask;
    ((pio_group_registers_t*)port)->PIO_ODSR = value;
}

// *****************************************************************************
/* Function:
    uint32_t PIO_PortLatchRead ( PIO_PORT port )

  Summary:
    Read the latched value on all the I/O lines of the selected port.

  Remarks:
    See plib_pio.h for more details.
*/
uint32_t PIO_PortLatchRead(PIO_PORT port)
{
    return ((pio_group_registers_t*)port)->PIO_ODSR;
}

// *****************************************************************************
/* Function:
    void PIO_PortSet ( PIO_PORT port, uint32_t mask )

  Summary:
    Set the selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortSet(PIO_PORT port, uint32_t mask)
{
    ((pio_group_registers_t*)port)->PIO_SODR = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortClear ( PIO_PORT port, uint32_t mask )

  Summary:
    Clear the selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortClear(PIO_PORT port, uint32_t mask)
{
    ((pio_group_registers_t*)port)->PIO_CODR = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortToggle ( PIO_PORT port, uint32_t mask )

  Summary:
    Toggles the selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortToggle(PIO_PORT port, uint32_t mask)
{
    /* Write into Clr and Set registers */
    ((pio_group_registers_t*)port)->PIO_MSKR = mask;
    ((pio_group_registers_t*)port)->PIO_ODSR ^= mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortInputEnable ( PIO_PORT port, uint32_t mask )

  Summary:
    Enables selected IO pins of a port as input.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortInputEnable(PIO_PORT port, uint32_t mask)
{
    ((pio_group_registers_t*)port)->PIO_MSKR = mask;
    ((pio_group_registers_t*)port)->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);	
}

// *****************************************************************************
/* Function:
    void PIO_PortOutputEnable ( PIO_PORT port, uint32_t mask )

  Summary:
    Enables selected IO pins of a port as output(s).

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask)
{
    ((pio_group_registers_t*)port)->PIO_MSKR = mask;
    ((pio_group_registers_t*)port)->PIO_CFGR |= (1 << PIO_CFGR_DIR_Pos);
}
// *****************************************************************************
/* Function:
    void PIO_PortInterruptEnable(PIO_PORT port, uint32_t mask)

  Summary:
    Enables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortInterruptEnable(PIO_PORT port, uint32_t mask)
{
    ((pio_group_registers_t*)port)->PIO_IER = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortInterruptDisable(PIO_PORT port, uint32_t mask)

  Summary:
    Disables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortInterruptDisable(PIO_PORT port, uint32_t mask)
{
    ((pio_group_registers_t*)port)->PIO_IDR = mask;
}

// *****************************************************************************
// *****************************************************************************
// Section: PIO APIs which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    bool PIO_PinInterruptCallbackRegister(
        PIO_PIN pin,
        const PIO_PIN_CALLBACK callback,
        uintptr_t context
    );

  Summary:
    Allows application to register callback for every pin.

  Remarks:
    See plib_pio.h for more details.
*/
bool PIO_PinInterruptCallbackRegister(
    PIO_PIN pin,
    const PIO_PIN_CALLBACK callback,
    uintptr_t context
)
{
    uint8_t i;
    uint8_t portIndex;

    portIndex = pin >> 5;

    for(i = portNumCb[portIndex]; i < portNumCb[portIndex +1]; i++)
    {
        if (portPinCbObj[i].pin == pin)
        {
            portPinCbObj[i].callback = callback;
            portPinCbObj[i].context  = context;
            return true;
        }
    }
    return false;
}

// *****************************************************************************
// *****************************************************************************
// Section: Interrupt Service Routine (ISR) Implementation(s)
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIOC_InterruptHandler (void)

  Summary:
    Interrupt handler for PORTC.

  Description:
    This function defines the Interrupt service routine for PORTC.
    This is the function which by default gets into Interrupt Vector Table.

  Remarks:
    User should not call this function.
*/
void PIOC_InterruptHandler(void)
{
    uint32_t status;
    uint8_t j;

    status  = PIOC_REGS->PIO_ISR;
    status &= PIOC_REGS->PIO_IMR;
	
	for( j = 0; j < 3; j++ )
	{
		if((status & ( 1 << (portPinCbObj[j].pin & 0x1F) ) ) && (portPinCbObj[j].callback != NULL))
		{
			portPinCbObj[j].callback ( portPinCbObj[j].pin, portPinCbObj[j].context );
		}
	}   
}

/*******************************************************************************
 End of File
*/