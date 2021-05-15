// MiCleanSection 
 
int __fastcall MiCleanSection(_DWORD *a1, int a2, int a3)
{
  unsigned int *v5; // r5
  int v6; // r1
  int v7; // r2
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v13; // [sp+10h] [bp-48h]
  int v15; // [sp+18h] [bp-40h] BYREF
  int v16[2]; // [sp+20h] [bp-38h] BYREF
  int v17; // [sp+28h] [bp-30h]
  char v18; // [sp+2Ch] [bp-2Ch]
  char v19; // [sp+2Dh] [bp-2Bh]
  char v20; // [sp+2Eh] [bp-2Ah]
  int v21; // [sp+30h] [bp-28h]
  int var24[10]; // [sp+34h] [bp-24h] BYREF
  int vars4; // [sp+5Ch] [bp+4h]

  while ( 1 )
  {
    if ( (a1[7] & 0x20) != 0 )
      goto LABEL_31;
    v17 = 0;
    v16[1] = 4;
    v18 = 7;
    v19 = 1;
    v20 = 4;
    v21 = 0;
    var24[1] = (int)var24;
    var24[0] = (int)var24;
    v5 = a1 + 9;
    v16[0] = a1[11];
    a1[11] = v16;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    KfLowerIrql(a2);
    v13 = MiFlushSectionInternal(0, 0, a1 + 20, 0, 0, 0x80000000, &v15);
    a2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      v8 = (unsigned __int8 *)a1 + 39;
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 | 0x80, v8) );
      __dmb(0xBu);
      if ( v9 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(a1 + 9);
      while ( 1 )
      {
        v10 = *v5;
        if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v10 & 0x40000000) == 0 )
        {
          do
            v11 = __ldrex(v5);
          while ( v11 == v10 && __strex(v10 | 0x40000000, v5) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    MiRemoveWakeListEntry(a1, v16);
    if ( !v17 )
      break;
    if ( a1[5] != 1 || a1[3] )
    {
      v7 = 1;
      goto LABEL_23;
    }
  }
  if ( v13 >= 0 )
  {
LABEL_31:
    a1[5] = 0;
    MiDestroySection(a1, a2);
    return 1;
  }
  v7 = 2;
LABEL_23:
  --a1[5];
  if ( a3 )
    a1[7] |= 0x40000u;
  if ( v7 == 2 )
    MiInsertUnusedSegment(a1, v6);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9, vars4);
  }
  else
  {
    __dmb(0xBu);
    a1[9] = 0;
  }
  KfLowerIrql(a2);
  return 0;
}
