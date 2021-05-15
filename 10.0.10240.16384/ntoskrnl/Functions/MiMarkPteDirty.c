// MiMarkPteDirty 
 
unsigned int *__fastcall MiMarkPteDirty(unsigned int *result)
{
  unsigned int *v1; // r5
  unsigned int v2; // r3
  int v3; // r10
  unsigned int v4; // r1
  int v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r4
  int v8; // r6
  unsigned int v9; // r0
  int v10; // r0
  int v11; // [sp+0h] [bp-20h]

  v1 = result;
  v2 = *result;
  if ( (*result & 0x10) == 0 || (v2 & 0x200) != 0 && (v2 & 0x80) != 0 )
  {
    v3 = 0;
    v11 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = (unsigned int *)sub_520CB8();
    }
    else
    {
      do
        v4 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
      while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
      __dmb(0xBu);
      if ( v4 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
      while ( 1 )
      {
        v5 = dword_634E00;
        if ( (dword_634E00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_634E00 & 0x40000000) == 0 )
        {
          do
            v9 = __ldrex((unsigned int *)&dword_634E00);
          while ( v9 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&dword_634E00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v6 = *v1;
      v7 = *v1;
      if ( (*v1 & 2) != 0 )
      {
        if ( (v6 & 0x10) == 0 )
        {
          v7 = v6 | 0x10;
          v3 = 1;
        }
        if ( (v7 & 0x200) != 0 && (v7 & 0x80) != 0 )
        {
          v7 = v7 & 0xFFFFFDFF | 0x10;
          v3 = 1;
        }
        if ( v3 == 1 )
        {
          if ( (unsigned int)(v1 + 0x10000000) > 0x3FFFFF )
          {
            *v1 = v7;
          }
          else
          {
            v8 = 0;
            __dmb(0xBu);
            *v1 = v7;
            if ( (v6 & 2) == 0 && (v7 & 2) != 0 )
              v8 = 1;
            if ( (unsigned int)(v1 + 267649024) <= 0xFFF )
            {
              v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v10, v10 + 4 * ((unsigned __int16)v1 & 0xFFF), v7);
            }
            if ( v8 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
      }
      result = (unsigned int *)MiUnlockWorkingSetExclusive(&dword_634E00, v11);
    }
  }
  return result;
}
