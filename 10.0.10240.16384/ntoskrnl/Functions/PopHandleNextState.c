// PopHandleNextState 
 
int __fastcall PopHandleNextState(__int64 a1)
{
  int v1; // r5
  unsigned int *v2; // r6
  unsigned int v3; // r7
  int v4; // r2
  int v5; // r3
  char v6; // r3
  int v7; // r4
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r1

  v1 = HIDWORD(a1);
  v2 = (unsigned int *)a1;
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  while ( 1 )
  {
    v4 = *(_DWORD *)(a1 + 36);
    __dmb(0xBu);
    if ( v4 != *(_DWORD *)HIDWORD(a1) )
      break;
    __dmb(0xAu);
    __yield();
  }
  v5 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)HIDWORD(a1) = v5;
  switch ( v5 )
  {
    case 2:
      LODWORD(a1) = -27688;
      *(_BYTE *)(HIDWORD(a1) + 6) = 0;
      if ( (MEMORY[0xFFFF93D8] | MEMORY[0xFFFF95F0]) & 0xFFFFFFFC | MEMORY[0xFFFF93DC] | MEMORY[0xFFFF95F4] )
      {
        LODWORD(a1) = xHalTimerWatchdogStop();
        *(_BYTE *)(v1 + 6) = (int)a1 >= 0;
      }
      *(_DWORD *)(v1 + 16) = (unsigned int)KeGetPcr() & 0xFFFFF000;
      break;
    case 3:
      *(_BYTE *)(HIDWORD(a1) + 5) = KfRaiseIrql(15);
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v6 = 0;
      }
      else
      {
        __disable_irq();
        v6 = 1;
      }
      *(_BYTE *)(v1 + 4) = v6;
      LODWORD(a1) = KeSuspendClockTimer();
      break;
    case 5:
      if ( (PopSimulate & 0x800000) != 0 && *(_DWORD *)(a1 + 4) )
      {
        v7 = 0;
        PoResumeFromHibernate = 1;
      }
      else
      {
        if ( !*(_DWORD *)(v3 + 1428) && !*(_DWORD *)(a1 + 4) )
          KdPowerTransition(4);
        LODWORD(a1) = (*(int (__fastcall **)(_DWORD, unsigned int, unsigned int, unsigned int))(*v2 + 8))(
                        *(_DWORD *)(*v2 + 12),
                        v2[1],
                        v2[2],
                        v2[7]);
        v7 = a1;
        if ( !*(_DWORD *)(v3 + 1428) )
        {
          if ( !PoResumeFromHibernate )
            LODWORD(a1) = KdPowerTransition(1);
          if ( !*(_DWORD *)(v3 + 1428) )
          {
            LODWORD(a1) = ReadTimeStampCounter();
            *(_QWORD *)&dword_61F078 = a1;
          }
        }
      }
      *(_DWORD *)(v1 + 12) = v7;
      break;
    case 6:
      LODWORD(a1) = PopRestoreHiberContext(*(_DWORD **)(a1 + 12));
      break;
    case 7:
      __dsb(0xFu);
      __mcr(15, 0, 0, 8, 7, 0);
      __dsb(0xFu);
      __isb(0xFu);
      LODWORD(a1) = KiInvalidateCurrentCache();
      break;
    case 8:
      __mrc(15, 0, 13, 0, 3);
      break;
    case 9:
      v8 = *(_DWORD *)(a1 + 16);
      if ( *(_DWORD *)v8 )
        LODWORD(a1) = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))v8)(
                        *(_DWORD *)(a1 + 20),
                        *(_DWORD *)(v8 + 4),
                        *(unsigned __int8 *)(a1 + 24));
      break;
    case 11:
      KeResumeClockTimer();
      if ( *(_BYTE *)(v1 + 4) )
        __enable_irq();
      LODWORD(a1) = KfLowerIrql(*(unsigned __int8 *)(v1 + 5));
      break;
    case 12:
      LODWORD(a1) = PpmResetPerfEngineForProcessor(v3 + 1408);
      break;
    default:
      break;
  }
  __dmb(0xBu);
  v9 = v2 + 8;
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  return a1;
}
