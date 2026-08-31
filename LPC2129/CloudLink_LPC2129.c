#include <LPC21xx.H>

/*
====================================================
       CloudLink LPC2129 - 4 Relay Controller

UART0:
P0.0 = TXD0
P0.1 = RXD0

ESP8266 TX  ---> LPC2129 P0.1 / RXD0
ESP8266 GND ---> LPC2129 GND

UART = 9600 baud

Commands from ESP8266:

R1ON
R1OFF

R2ON
R2OFF

R3ON
R3OFF

R4ON
R4OFF

Relay outputs are ACTIVE LOW:
LOW  = Relay ON
HIGH = Relay OFF
====================================================
*/


#define OUT1    16      /* P0.16 */
#define OUT2    17      /* P0.17 */
#define OUT3    18      /* P0.18 */
#define OUT4    19      /* P0.19 */


/*
----------------------------------------------------
 UART0 Initialization
----------------------------------------------------
*/
void UART0_Init(void)
{
    /* P0.0 = TXD0
       P0.1 = RXD0 */

    PINSEL0 &= ~0x0F;
    PINSEL0 |=  0x05;

    /* 8-bit data
       1 stop bit
       No parity
       DLAB = 1 */

    U0LCR = 0x83;

    /* 9600 baud for PCLK = 15 MHz */

    U0DLL = 97;
    U0DLM = 0;

    /* DLAB = 0 */

    U0LCR = 0x03;
}


/*
----------------------------------------------------
 Receive one character
----------------------------------------------------
*/
char UART0_GetChar(void)
{
    while (!(U0LSR & 0x01));

    return U0RBR;
}


/*
----------------------------------------------------
 Turn all relays OFF
 Active LOW:
 HIGH = OFF
----------------------------------------------------
*/
void All_Relays_OFF(void)
{
    IOSET0 =
          (1 << OUT1)
        | (1 << OUT2)
        | (1 << OUT3)
        | (1 << OUT4);
}


/*
----------------------------------------------------
 Main
----------------------------------------------------
*/
int main(void)
{
    char c;
    char command[6];
    unsigned int index = 0;


    /*
    Initialize UART
    */
    UART0_Init();


    /*
    Configure four relay pins as outputs
    */
    IODIR0 |=
          (1 << OUT1)
        | (1 << OUT2)
        | (1 << OUT3)
        | (1 << OUT4);


    /*
    Initially all relays OFF
    */
    All_Relays_OFF();


    while (1)
    {
        /*
        Receive character
        */
        c = UART0_GetChar();


        /*
        Check end of command
        */
        if (c == '\r' || c == '\n')
        {
            command[index] = '\0';


            /*
            ========================================
            RELAY 1
            ========================================
            */

            if (command[0] == 'R' &&
                command[1] == '1' &&
                command[2] == 'O' &&
                command[3] == 'N')
            {
                /* Relay 1 ON */
                IOCLR0 = (1 << OUT1);
            }

            else if (command[0] == 'R' &&
                     command[1] == '1' &&
                     command[2] == 'O' &&
                     command[3] == 'F')
            {
                /* Relay 1 OFF */
                IOSET0 = (1 << OUT1);
            }


            /*
            ========================================
            RELAY 2
            ========================================
            */

            else if (command[0] == 'R' &&
                     command[1] == '2' &&
                     command[2] == 'O' &&
                     command[3] == 'N')
            {
                /* Relay 2 ON */
                IOCLR0 = (1 << OUT2);
            }

            else if (command[0] == 'R' &&
                     command[1] == '2' &&
                     command[2] == 'O' &&
                     command[3] == 'F')
            {
                /* Relay 2 OFF */
                IOSET0 = (1 << OUT2);
            }


            /*
            ========================================
            RELAY 3
            ========================================
            */

            else if (command[0] == 'R' &&
                     command[1] == '3' &&
                     command[2] == 'O' &&
                     command[3] == 'N')
            {
                /* Relay 3 ON */
                IOCLR0 = (1 << OUT3);
            }

            else if (command[0] == 'R' &&
                     command[1] == '3' &&
                     command[2] == 'O' &&
                     command[3] == 'F')
            {
                /* Relay 3 OFF */
                IOSET0 = (1 << OUT3);
            }


            /*
            ========================================
            RELAY 4
            ========================================
            */

            else if (command[0] == 'R' &&
                     command[1] == '4' &&
                     command[2] == 'O' &&
                     command[3] == 'N')
            {
                /* Relay 4 ON */
                IOCLR0 = (1 << OUT4);
            }

            else if (command[0] == 'R' &&
                     command[1] == '4' &&
                     command[2] == 'O' &&
                     command[3] == 'F')
            {
                /* Relay 4 OFF */
                IOSET0 = (1 << OUT4);
            }


            /*
            Reset command buffer
            */
            index = 0;
        }

        else
        {
            /*
            Store received character
            */
            if (index < 5)
            {
                command[index++] = c;
            }
            else
            {
                /* Invalid/too-long command */
                index = 0;
            }
        }
    }

}
