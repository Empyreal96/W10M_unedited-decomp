// sub_53E5B8 
 
void __fastcall sub_53E5B8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int *a10, int **a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
  _DWORD *v18; // r5
  int v19; // r8
  unsigned int *v20; // r4
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r1

  v20 = v18 + 9;
  while ( 1 )
  {
    a6 = 8;
    LOWORD(a8) = 263;
    BYTE2(a8) = 4;
    a9 = 0;
    a11 = &a10;
    a10 = (int *)&a10;
    a5 = v18[11];
    v18[11] = &a5;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v18 + 9, a18);
    }
    else
    {
      __dmb(0xBu);
      *v20 = 0;
    }
    KfLowerIrql(v19);
    KeWaitForGate((int)&a8, 18);
    v19 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v18 + 9);
    }
    else
    {
      v21 = (unsigned __int8 *)v18 + 39;
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x80, v21) );
      __dmb(0xBu);
      if ( v22 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v18 + 9);
      while ( 1 )
      {
        v23 = *v20;
        if ( (*v20 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v23 & 0x40000000) == 0 )
        {
          do
            v24 = __ldrex(v20);
          while ( v24 == v23 && __strex(v23 | 0x40000000, v20) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    if ( !v18[10] )
      JUMPOUT(0x4A6AEE);
  }
}
