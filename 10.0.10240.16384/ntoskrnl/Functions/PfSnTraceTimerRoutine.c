// PfSnTraceTimerRoutine 
 
unsigned int *__fastcall PfSnTraceTimerRoutine(int a1, unsigned int *a2)
{
  signed int v3; // r1
  unsigned int *result; // r0
  unsigned int *v5; // r2
  int v6; // r2
  unsigned int *v7; // r6
  unsigned int v8; // r2
  unsigned int *v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int *v18; // [sp+10h] [bp-18h] BYREF

  if ( !a2[72] )
  {
    v3 = a2[62];
    if ( v3 > (int)a2[64] )
      v3 = a2[64];
    if ( (int)a2[60] > v3 )
      return (unsigned int *)sub_5237CC();
    a2[a2[61] + 50] = v3 - a2[60];
    a2[60] = v3;
    if ( PfSnTraceGetLogEntry(a2, 1, &v18) >= 0 )
    {
      v5 = v18;
      *v18 &= 7u;
      v5[1] = 0;
      *v5 = *v5 & 0xFFFFFFF8 | 4;
      v6 = a2[61] + 1;
      a2[61] = v6;
      if ( v6 >= dword_637274 )
      {
        __dmb(0xBu);
        v16 = a2 + 72;
        do
          v17 = __ldrex(v16);
        while ( !v17 && __strex(4u, v16) );
        __dmb(0xBu);
        if ( !v17 )
          ExQueueWorkItem(a2 + 68, 1);
      }
      else
      {
        v7 = a2 + 48;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(a2 + 48);
        }
        else
        {
          do
            v8 = __ldrex(v7);
          while ( __strex(1u, v7) );
          __dmb(0xBu);
          if ( v8 )
            KxWaitForSpinLockAndAcquire(a2 + 48);
        }
        if ( !a2[72] )
        {
          v9 = a2 + 67;
          __pld(a2 + 67);
          v10 = a2[67] & 0xFFFFFFFE;
          v11 = v10 + 2;
          do
            v12 = __ldrex(v9);
          while ( v12 == v10 && __strex(v11, v9) );
          __dmb(0xBu);
          if ( v12 == v10 || ExfAcquireRundownProtection(v9, v12, v11) )
            KiSetTimerEx(a2 + 26, a2 + 40, a2[38], a2[39], 0, 0, a2 + 40);
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(a2 + 48);
        }
        else
        {
          __dmb(0xBu);
          *v7 = 0;
        }
      }
    }
  }
  result = a2 + 67;
  __pld(a2 + 67);
  v13 = a2[67] & 0xFFFFFFFE;
  __dmb(0xBu);
  v14 = v13 - 2;
  do
    v15 = __ldrex(result);
  while ( v15 == v13 && __strex(v14, result) );
  if ( v15 != v13 )
    result = (unsigned int *)ExfReleaseRundownProtection(result, v15, v14);
  return result;
}
