// sub_515C60 
 
void __fastcall sub_515C60(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v14; // r8
  _DWORD *v15; // r9
  int v16; // r7
  unsigned int v17; // r5
  unsigned int v18; // r1
  int v19; // lr
  unsigned int v20; // r0
  unsigned int v21; // r3

  v16 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v17 = 328;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_63F990);
  }
  else
  {
    do
      v18 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
    while ( __strex(v18 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
    __dmb(0xBu);
    v17 = 0x148u;
    if ( v18 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F990);
    while ( 1 )
    {
      v19 = dword_63F990;
      if ( (dword_63F990 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_63F990 & 0x40000000) == 0 )
      {
        do
          v20 = __ldrex((unsigned int *)&dword_63F990);
        while ( v20 == v19 && __strex(v19 | 0x40000000, (unsigned int *)&dword_63F990) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v21 = *(_DWORD *)(v14 + 612);
  if ( v21 > 2 )
    *v15 = *(_DWORD *)(*(_DWORD *)v21 + 12);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiSystemPartition[v17], a14);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)&MiSystemPartition[v17] = 0;
  }
  KfLowerIrql(v16);
  JUMPOUT(0x4349B8);
}
