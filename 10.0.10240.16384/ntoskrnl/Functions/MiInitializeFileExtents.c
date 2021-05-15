// MiInitializeFileExtents 
 
int __fastcall MiInitializeFileExtents(int *a1, int a2, int a3, int a4)
{
  int v4; // r6
  unsigned int *v6; // r4
  int v7; // r6
  int *v8; // r9
  int v9; // r7
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v20[9]; // [sp+4h] [bp-24h] BYREF
  int vars4; // [sp+2Ch] [bp+4h]

  v20[0] = a3;
  v20[1] = a4;
  v4 = a2;
  if ( a1[1] )
    return 0;
  v6 = (unsigned int *)(*a1 + 36);
  while ( 1 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v4);
    v7 = MiAllocateFileExtents(a1, v20);
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v6);
    }
    else
    {
      v10 = (unsigned __int8 *)v6 + 3;
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 0x80, v10) );
      __dmb(0xBu);
      if ( v11 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v6);
      while ( 1 )
      {
        v12 = *v6;
        if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v12 & 0x40000000) == 0 )
        {
          do
            v13 = __ldrex(v6);
          while ( v13 == v12 && __strex(v12 | 0x40000000, v6) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v7 < 0 )
      break;
    v8 = (int *)v20[0];
    v7 = MiEnableFileExtents(a1, a2, v20[0]);
    if ( v7 >= 0 )
      break;
    v9 = *v8;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(a2);
    if ( v9 )
      MiReleaseFileExtentWaiters(v9);
    MiDeleteFileExtents((int)v8, 0, 0, 6);
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v6);
    }
    else
    {
      v15 = (unsigned __int8 *)v6 + 3;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v6);
      while ( 1 )
      {
        v17 = *v6;
        if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v6);
          while ( v18 == v17 && __strex(v17 | 0x40000000, v6) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( v7 != -1073741791 )
      break;
    v4 = a2;
    if ( a1[1] )
      return 0;
  }
  return v7;
}
