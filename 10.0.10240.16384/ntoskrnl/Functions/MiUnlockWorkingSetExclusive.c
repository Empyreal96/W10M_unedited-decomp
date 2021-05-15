// MiUnlockWorkingSetExclusive 
 
int __fastcall MiUnlockWorkingSetExclusive(int a1, int a2)
{
  int v5; // r2

  if ( (*(_BYTE *)(a1 + 115) & 0x10) != 0 )
    return sub_50E620();
  if ( (*(_BYTE *)(a1 + 115) & 0x20) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 68);
    *(_BYTE *)(a1 + 115) &= 0xDFu;
    MiReduceWs(a1, a2, v5);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  return KfLowerIrql(a2);
}
