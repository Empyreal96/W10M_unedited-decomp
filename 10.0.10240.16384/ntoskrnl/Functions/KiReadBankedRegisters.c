// KiReadBankedRegisters 
 
int __fastcall KiReadBankedRegisters(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, int a5)
{
  int v5; // lr
  int result; // r0

  result = a1 - 16;
  switch ( result )
  {
    case 0:
    case 15:
      __asm { CPS.W           #0x1F; jumptable 0042001C cases 16,31 }
      a4 = 0;
      goto LABEL_6;
    case 2:
      __asm { CPS.W           #0x12; jumptable 0042001C case 18 }
      goto LABEL_6;
    case 3:
      goto LABEL_6;
    case 7:
      __asm { CPS.W           #0x17; jumptable 0042001C case 23 }
      goto LABEL_6;
    case 11:
      __asm { CPS.W           #0x1B; jumptable 0042001C case 27 }
LABEL_6:
      if ( a2 )
        *a2 = &a5;
      if ( a3 )
        *a3 = v5;
      if ( a4 )
        *a4 = __get_CPSR();
      __asm { CPS.W           #0x13 }
      break;
    default:
      return result;
  }
  return result;
}
