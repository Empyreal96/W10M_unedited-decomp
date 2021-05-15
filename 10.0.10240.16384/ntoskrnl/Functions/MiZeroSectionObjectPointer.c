// MiZeroSectionObjectPointer 
 
int __fastcall MiZeroSectionObjectPointer(int a1, _DWORD *a2, int a3)
{
  _DWORD *v4; // r8
  unsigned int *v5; // r4
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // lr
  int v12; // r1
  unsigned int v13; // r0
  int v15; // [sp+0h] [bp-28h]
  int v16; // [sp+4h] [bp-24h]
  int vars4; // [sp+2Ch] [bp+4h]

  if ( (a3 & 0x1000000) != 0 )
    v4 = (_DWORD *)(*(_DWORD *)(a1 + 20) + 8);
  else
    v4 = *(_DWORD **)(a1 + 20);
  KeAbPostRelease((unsigned int)v4);
  v5 = a2 + 9;
  v15 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a2 + 9);
  }
  else
  {
    v6 = (unsigned __int8 *)a2 + 39;
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a2 + 9);
    while ( 1 )
    {
      v8 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v8 & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex(v5);
        while ( v9 == v8 && __strex(v8 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v16 = a2[11];
  a2[11] = 0;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632E00);
  }
  else
  {
    do
      v10 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v10 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
    while ( 1 )
    {
      v11 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        v12 = dword_632E00 | 0x40000000;
        do
          v13 = __ldrex((unsigned int *)&dword_632E00);
        while ( v13 == v11 && __strex(v12, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *v4 = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_632E00 = 0;
  }
  a2[7] |= 0xC0000u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a2 + 9, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v15);
  return v16;
}
