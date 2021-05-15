// KiWriteBankedRegisters 
 
int __fastcall KiWriteBankedRegisters(int a1, int a2, int a3, int *a4)
{
  int result; // r0

  result = a1 - 16;
  switch ( result )
  {
    case 0:
    case 15:
      __asm { CPS.W           #0x1F; jumptable 0042006C cases 16,31 }
      a4 = 0;
      goto LABEL_6;
    case 2:
      __asm { CPS.W           #0x12; jumptable 0042006C case 18 }
      goto LABEL_6;
    case 3:
      goto LABEL_6;
    case 7:
      __asm { CPS.W           #0x17; jumptable 0042006C case 23 }
      goto LABEL_6;
    case 11:
      __asm { CPS.W           #0x1B; jumptable 0042006C case 27 }
LABEL_6:
      if ( a4 )
      {
        _R12 = *a4;
        __asm { MSR.W           SPSR_fc, R12 }
      }
      __asm { CPS.W           #0x13 }
      break;
    default:
      return result;
  }
  return result;
}
