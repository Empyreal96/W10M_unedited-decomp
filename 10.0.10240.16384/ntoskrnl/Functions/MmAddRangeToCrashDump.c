// MmAddRangeToCrashDump 
 
int __fastcall MmAddRangeToCrashDump(int (__fastcall **a1)(_DWORD, unsigned int, int, int), unsigned int a2, int a3)
{
  int v4; // r1
  unsigned int v5; // r5
  char *v6; // r2
  int v7; // r0
  int v8; // r9
  unsigned int v9; // r2
  int v10; // r6
  unsigned int v11; // r4
  unsigned int v12; // r5
  int v13; // r4
  unsigned int v14; // r0
  unsigned int v15; // r1
  unsigned int v17; // [sp+8h] [bp-48h]
  char v19[16]; // [sp+10h] [bp-40h] BYREF
  unsigned int v20; // [sp+20h] [bp-30h]
  unsigned int v21; // [sp+24h] [bp-2Ch]
  int v22; // [sp+28h] [bp-28h]

  v22 = 0;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v4 == PsInitialSystemProcess
    && *(int (**)())((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x39C) != KeBalanceSetManager )
  {
    v22 = 1;
  }
  v5 = a3 + a2 - 1;
  v6 = v19;
  v7 = 2;
  v20 = a2;
  v21 = v5;
  do
  {
    a2 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
    v5 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
    *(_DWORD *)v6 = a2;
    *((_DWORD *)v6 + 1) = v5;
    v6 += 8;
    --v7;
  }
  while ( v7 );
  v17 = v5;
  v8 = 17;
  if ( (KiBugCheckActive & 3) == 0 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( dword_63437C != v9 )
    {
      v8 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
      }
      else
      {
        v10 = dword_6342C0 & 0x7FFFFFFF;
        v11 = (dword_6342C0 & 0x7FFFFFFF) + 1;
        do
          v12 = __ldrex((unsigned int *)&dword_6342C0);
        while ( v12 == v10 && __strex(v11, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
        if ( v12 != v10 )
          ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
        v5 = v17;
      }
    }
  }
  v13 = MiAddRangeToCrashDump(a1, (_DWORD *)a2, v5, (int)v19, 1);
  if ( v8 != 17 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v14 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v15 - 1, (unsigned int *)&dword_6342C0) );
    }
    KfLowerIrql(v8);
  }
  return v13;
}
