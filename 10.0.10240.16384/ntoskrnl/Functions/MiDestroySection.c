// MiDestroySection 
 
int __fastcall MiDestroySection(int a1, int a2)
{
  int vars4; // [sp+Ch] [bp+4h]

  *(_DWORD *)(a1 + 28) |= 9u;
  MiDrainControlAreaWrites(a1);
  MiClearFilePointer(a1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(a1 + 36), vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(a1 + 36) = 0;
  }
  KfLowerIrql(a2);
  return MiSegmentDelete(a1);
}
