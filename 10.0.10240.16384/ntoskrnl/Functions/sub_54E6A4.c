// sub_54E6A4 
 
void __fastcall sub_54E6A4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26)
{
  int v26; // r7
  int v27; // r8
  int v28; // r9
  unsigned int v29; // r1
  int v30; // r5
  unsigned int v31; // r0

  v28 = KfRaiseIrql(2);
  if ( (*(_DWORD *)(v26 + 1452) & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_63F7A8);
  }
  else
  {
    do
      v29 = __ldrex((unsigned __int8 *)&dword_63F7A8 + 3);
    while ( __strex(v29 | 0x80, (unsigned __int8 *)&dword_63F7A8 + 3) );
    __dmb(0xBu);
    if ( v29 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F7A8);
    while ( 1 )
    {
      v30 = dword_63F7A8;
      if ( (dword_63F7A8 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_63F7A8 & 0x40000000) == 0 )
      {
        do
          v31 = __ldrex((unsigned int *)&dword_63F7A8);
        while ( v31 == v30 && __strex(v30 | 0x40000000, (unsigned int *)&dword_63F7A8) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  dword_640508 += v27;
  if ( (*(_DWORD *)(v26 + 1452) & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F7A8, a26);
  }
  else
  {
    __dmb(0xBu);
    dword_63F7A8 = 0;
  }
  KfLowerIrql(v28);
  JUMPOUT(0x4E6D7A);
}
