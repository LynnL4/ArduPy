// options to control how MicroPython is built
#define MICROPY_HW_BOARD_NAME               "Ardupy"
#define MICROPY_HW_MCU_NAME                 "seeed"
#define MICROPY_PY_SYS_PLATFORM             "Atmel SAMD51"
#define ARDUPY_FULL_BUILD                   (0)
#define MICROPY_USE_INTERNAL_PRINTF         (1)
#define MICROPY_EMIT_THUMB                  (0)
#define MICROPY_EMIT_INLINE_THUMB           (0)
#define MICROPY_PY_COLLECTIONS_ORDEREDDICT  (0)

// #define CIRCUITPY_INTERNAL_NVM_SIZE 256 

// #define BOARD_FLASH_SIZE (0x00040000 - 0x2000 - 0x010000 - CIRCUITPY_INTERNAL_NVM_SIZE)

#define DEFAULT_I2C_BUS_SCL                 (&pin_SCL)
#define DEFAULT_I2C_BUS_SDA                 (&pin_SDA)

#define DEFAULT_SPI_BUS_SCK                 (&pin_SCK)
#define DEFAULT_SPI_BUS_MOSI                (&pin_MOSI)
#define DEFAULT_SPI_BUS_MISO                (&pin_MISO)

#define DEFAULT_UART_BUS_RX                 (&pin_RX)
#define DEFAULT_UART_BUS_TX                 (&pin_TX)

// USB is always used internally so skip the pin objects for it. 
#define IGNORE_PIN_PA24     1   
#define IGNORE_PIN_PA25     1 


// We have inlined IRQ functions for efficiency (they are generally
// 1 machine instruction).
//
// Note on IRQ state: you should not need to know the specific
// value of the state variable, but rather just pass the return
// value from disable_irq back to enable_irq.  If you really need
// to know the machine-specific values, see irq.h.

// static inline void samd21_enable_irq(uint32_t state) {
//     __DMB();
//     __set_PRIMASK(state);
// }

// static inline uint32_t samd21_disable_irq(void) {
//     uint32_t state = __get_PRIMASK();
//     __disable_irq();
//     __DMB();
//     return state;
// }

// #define MICROPY_BEGIN_ATOMIC_SECTION()     samd21_disable_irq()
// #define MICROPY_END_ATOMIC_SECTION(state)  samd21_enable_irq(state)
