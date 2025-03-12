#ifndef REGISTERS_MAPPING_H

#define REGISTERS_MAPPING_H

#define ADDRESS_TYPE                uint32_t
#define PORT_TYPE                   volatile ADDRESS_TYPE *

#define GPIOB 	                    ((PORT_TYPE)0x40020400)

#define MODER(port)                 ((PORT_TYPE)((ADDRESS_TYPE)(port) + 0x00))
#define OTYPER(port)                ((PORT_TYPE)((ADDRESS_TYPE)(port) + 0x04))
#define OSPEEDR(port)               ((PORT_TYPE)((ADDRESS_TYPE)(port) + 0x08))
#define ODR(port)                   ((PORT_TYPE)((ADDRESS_TYPE)(port) + 0x14))
#define PUPDR(port)                 ((PORT_TYPE)((ADDRESS_TYPE)(port) + 0x0C))

#define RCC 		                ((PORT_TYPE)0x40023800)
#define RCC_AHB1ENR	                ((PORT_TYPE)((ADDRESS_TYPE)(RCC) + 0x30))

#define SET_BITS(port, mask)        do{*(port) |= (mask);}while(0)
#define CLEAR_BITS(port, mask)      do{*(port) &= ~(mask);}while(0)

#define SET_PIN(port, pin)          SET_BITS(port, (1 << pin))
#define RESET_PIN(port, pin)        CLEAR_BITS(port, (1 << pin))

#define READ_REGISTER(register)     (*(register))
#define READ_BITS(port, mask)       (READ_REGISTER(port) & (mask))

#endif // REGISTERS_MAPPING_H

