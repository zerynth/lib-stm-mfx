"""
.. module:: mfx

**************
MFX Module
**************



"""

@native_c(
        "_c_start", 
        ["csrc/mfxstm32l152/mfxstm32l152.c", "csrc/mfx_ifc.c", "csrc/STM32756G_EVAL/stm32756g_eval.c", "csrc/STM32756G_EVAL/stm32756g_eval_io.c"], 
        ["USE_IOEXPANDER", "VHAL_ADC", "VHAL_I2C"], 
        ["-I.../csrc/mfxstm32l152", "-I.../csrc/STM32756G_EVAL"]
        )
def _c_start():
    pass

@native_c("_pin_write", [], [], [])
def _write_pin(pin, val):
    pass

@native_c("_pin_read", [], [], [])
def _read_pin(pin):
    pass

@native_c("_pin_mode", [], [], [])
def _pin_mode(pin, mode):
    pass

@native_c("_toggle_pin", [], [], [])
def _toggle_pin(pin):
    pass

class MFX():
    """
    
===============
 MFX class
===============

.. class:: MFX()

    Creates an intance of the MFX class.

    Example: ::
        
        from stm.mfx import MFX 
        
        ...
        
        port_expander = mfx.MFX()
        port_expander.pinMode(10,INPUT_PULLUP)
        
        state = port_expander.digitalRead(10)
        
        port_expander.pinMode(0,OUTPUT)
        port_expander.digitalWrite(0,HIGH)
        
        
    """
    def __init__(self):
        _c_start()
    
    def pinMode(self,pin,mode):
        """
    .. method:: pinMode(pin, mode)
        
        Select a mode for a pin.
        Valid *pin* values are from ``0`` to ``15`` included.
        Available modes are:
        
            * ``INPUT``
            * ``INPUT_PULLUP``
            * ``INPUT_PULLDOWN``
            * ``OUTPUT``
        
        
        """
        _pin_mode(pin, mode)
        pass
    
    def digitalRead(self,pin):
        """
    .. method:: digitalRead(pin)

        Returns the state of pin *pin*. The state can be ``0`` or ``1``.

        """
        _read_pin(pin)
        pass


    def digitalWrite(self,pin,val):
        """
    .. method:: digitalWrite(pin, val)

        Set pin *pin* to value *val*. Value can be ``0`` or ``1``.

        """
        _write_pin(pin, val)
        pass   

    def pinToggle(self, pin):
        """
    .. method:: pinToggle(pin)

        Toggle the value of the pin *pin*.

        """
        _toggle_pin(pin)
        pass   


