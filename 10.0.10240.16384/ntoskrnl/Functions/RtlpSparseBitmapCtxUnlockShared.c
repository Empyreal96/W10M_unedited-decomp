// RtlpSparseBitmapCtxUnlockShared 
 
int __fastcall RtlpSparseBitmapCtxUnlockShared(int result, unsigned int *a2, unsigned __int8 a3)
{
  unsigned int v5; // r1
  unsigned int v6; // r2
  int vars4; // [sp+Ch] [bp+4h]

  if ( (*(_DWORD *)(result + 48) & 4) == 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(a2, vars4);
    }
    else
    {
      __dmb(0xBu);
      do
        v5 = __ldrex(a2);
      while ( __strex(v5 & 0xBFFFFFFF, a2) );
      __dmb(0xBu);
      do
        v6 = __ldrex(a2);
      while ( __strex(v6 - 1, a2) );
    }
    result = KfLowerIrql(a3);
  }
  return result;
}
