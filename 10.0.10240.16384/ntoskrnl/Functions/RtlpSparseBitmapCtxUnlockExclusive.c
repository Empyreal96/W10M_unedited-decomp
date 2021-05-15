// RtlpSparseBitmapCtxUnlockExclusive 
 
int __fastcall RtlpSparseBitmapCtxUnlockExclusive(int result, _DWORD *a2, unsigned __int8 a3)
{
  int vars4; // [sp+Ch] [bp+4h]

  if ( (*(_DWORD *)(result + 48) & 4) == 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a2, vars4);
    }
    else
    {
      __dmb(0xBu);
      *a2 = 0;
    }
    result = KfLowerIrql(a3);
  }
  return result;
}
