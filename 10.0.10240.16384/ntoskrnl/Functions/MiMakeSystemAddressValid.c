// MiMakeSystemAddressValid 
 
int __fastcall MiMakeSystemAddressValid(unsigned int a1, int a2, int a3, int a4, char a5)
{
  int v7; // r7
  char v8; // r6
  int result; // r0
  int v10; // r6
  unsigned int *v11; // r5
  int v12; // r7
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  int v21; // [sp+8h] [bp-28h]

  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v21 = v7;
LABEL_2:
  v8 = a5;
  while ( 1 )
  {
    result = MiIsAddressValid(a1, 1);
    if ( result )
      return result;
    if ( a2 )
      return sub_543310();
    v10 = v8 & 1;
    v11 = (unsigned int *)(v7 + 492);
    if ( v10 )
    {
      MiUnlockWorkingSetExclusive(v7 + 492, a4);
    }
    else
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7 + 492);
      }
      else
      {
        __dmb(0xBu);
        do
          v16 = __ldrex(v11);
        while ( __strex(v16 & 0xBFFFFFFF, v11) );
        __dmb(0xBu);
        do
          v17 = __ldrex(v11);
        while ( __strex(v17 - 1, v11) );
      }
      KfLowerIrql(a4);
    }
    v12 = MmAccessFault(-2147483647, a1, 0, 0);
    if ( v12 < 0 )
    {
      MmFlushAllFilesystemPages(1);
      KeBugCheckEx(122, 1, v12);
    }
    if ( v10 )
    {
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11);
        v7 = v21;
        goto LABEL_2;
      }
      v13 = (unsigned __int8 *)v11 + 3;
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 | 0x80, v13) );
      __dmb(0xBu);
      if ( v14 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v11);
      while ( 1 )
      {
        v15 = *v11;
        v7 = v21;
        v8 = a5;
        if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v15 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v11);
          while ( v18 == v15 && __strex(v15 | 0x40000000, v11) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    else
    {
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v11);
        v7 = v21;
        goto LABEL_2;
      }
      v19 = *v11 & 0x7FFFFFFF;
      do
        v20 = __ldrex(v11);
      while ( v20 == v19 && __strex(v19 + 1, v11) );
      __dmb(0xBu);
      v7 = v21;
      v8 = a5;
      if ( v20 != v19 )
      {
        ExpWaitForSpinLockSharedAndAcquire(v11);
        goto LABEL_2;
      }
    }
  }
}
