// sub_546594 
 
void __fastcall sub_546594(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
  _DWORD *v18; // r4
  char v19; // r5
  int v20; // r6
  int v21; // r7
  int v22; // r8
  unsigned int *v23; // r10
  unsigned int v24; // r1
  unsigned int v25; // r2
  int v26; // r3
  unsigned __int8 *v27; // r3
  unsigned int v28; // r0

  v18[7] = a4 | 4;
  v18[5] = 1;
  v23 = v18 + 9;
  if ( (*(_DWORD *)(v21 + 4) & v22) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v18 + 9, a18);
  }
  else
  {
    __dmb(0xBu);
    *v23 = 0;
  }
  KfLowerIrql(v20);
  MiPurgeImageSection(v18);
  KfRaiseIrql(2);
  if ( (*(_DWORD *)(v21 + 4) & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v18 + 9);
  }
  else
  {
    v27 = (unsigned __int8 *)v18 + 39;
    do
      v24 = __ldrex(v27);
    while ( __strex(v24 | 0x80, v27) );
    __dmb(0xBu);
    if ( v24 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v18 + 9);
    while ( 1 )
    {
      v28 = *v23;
      if ( (*v23 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v28 & 0x40000000) == 0 )
      {
        do
          v24 = __ldrex(v23);
        while ( v24 == v28 && __strex(v28 | 0x40000000, v23) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v25 = v18[7] & 0xFFFFFFFB;
  v26 = v18[5];
  v18[7] = v25;
  v18[5] = --v26;
  if ( !v26 && !v18[3] )
  {
    if ( v18[4] )
    {
      if ( (v19 & 1) == 0 )
        MiInsertUnusedSegment(v18, v24);
    }
    else
    {
      v18[7] = v25 | 1;
      MiClearFilePointer((int)v18);
    }
  }
  JUMPOUT(0x4C09F8);
}
