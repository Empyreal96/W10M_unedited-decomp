// KiInitializeVfp 
 
int __spoils<R0,R2,R3,R12> KiInitializeVfp()
{
  int result; // r0
  int v1; // r4

  result = 0;
  __mcr(15, 0, __mrc(15, 0, 1, 0, 2) & 0x3F0FFFFF | 0xF00000, 1, 0, 2);
  __isb(0xFu);
  v1 = __mrc(15, 0, 1, 0, 2);
  if ( (v1 & 0xF00000) != 15728640 )
    sub_5194C8(0);
  __asm { VMRS            R2, FPSID }
  if ( (_R2 & 0x800000) != 0 )
    KeBugCheckEx(93, 5, _R2);
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xF0000000) < 0x10000000 )
    goto LABEL_23;
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xF00000u) < 0x100000 )
    goto LABEL_23;
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xF0000u) < 0x10000 )
    goto LABEL_23;
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xF00u) < 0x200 )
    goto LABEL_23;
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xF0u) < 0x20 )
  {
LABEL_23:
    __asm { VMRS            R2, MVFR0 }
    KeBugCheckEx(93, 6, _R2);
  }
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xFu) >= 2 )
    result = 16;
  _R3 = -805306368;
  __asm { VMSR            FPEXC, R3 }
  __isb(0xFu);
  __asm { VMRS            R3, FPEXC }
  if ( _R3 < 0 )
  {
    result |= 0x20u;
    if ( (_R3 & 0x10000000) != 0 )
      result |= 0x40u;
  }
  _R3 = 0x40000000;
  __asm { VMSR            FPEXC, R3 }
  __isb(0xFu);
  __asm { VMRS            R3, MVFR0 }
  if ( (_R3 & 0xFu) >= 2 )
  {
    __asm { VMRS            R3, MVFR1 }
    if ( (_R3 & 0xF0000u) >= 0x10000 )
    {
      __asm { VMRS            R3, MVFR1 }
      if ( (_R3 & 0xF000u) >= 0x1000 )
      {
        __asm { VMRS            R3, MVFR1 }
        if ( (_R3 & 0xF00u) >= 0x100 )
          result |= 0x80u;
      }
    }
  }
  __asm { VMRS            R3, MVFR1 }
  if ( (_R3 & 0xF0000000) >= 0x10000000 )
    MEMORY[0xFFFF928F] = 1;
  __mcr(15, 0, v1 & 0xFF0FFFFF, 1, 0, 2);
  __isb(0xFu);
  return result;
}
