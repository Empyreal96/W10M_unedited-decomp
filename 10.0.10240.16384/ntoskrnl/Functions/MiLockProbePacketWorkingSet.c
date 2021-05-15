// MiLockProbePacketWorkingSet 
 
int __fastcall MiLockProbePacketWorkingSet(int result, int a2, int a3)
{
  int v3; // r4
  unsigned int *v4; // r5
  char v5; // r7
  unsigned int v6; // r1

  v3 = result;
  v4 = *(unsigned int **)(result + 48);
  if ( v4 == (unsigned int *)MmBadPointer )
  {
    *(_BYTE *)(result + 44) = 17;
  }
  else if ( *(_BYTE *)(result + 32) == 1 )
  {
    result = sub_5455AC(result, a2, a3, KfRaiseIrql);
  }
  else
  {
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v4);
    }
    else
    {
      result = *v4 & 0x7FFFFFFF;
      do
        v6 = __ldrex(v4);
      while ( v6 == result && __strex(result + 1, v4) );
      __dmb(0xBu);
      if ( v6 != result )
        result = ExpWaitForSpinLockSharedAndAcquire(v4);
    }
    *(_BYTE *)(v3 + 44) = v5;
  }
  return result;
}
