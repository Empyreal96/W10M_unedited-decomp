// MiUnlockProbePacketWorkingSet 
 
int __fastcall MiUnlockProbePacketWorkingSet(int result)
{
  unsigned int *v1; // r5
  int v2; // r4
  unsigned int v3; // r1
  unsigned int v4; // r2

  v1 = *(unsigned int **)(result + 48);
  if ( v1 != (unsigned int *)MmBadPointer )
  {
    if ( *(_BYTE *)(result + 32) == 1 )
    {
      result = sub_5454B0();
    }
    else
    {
      v2 = *(unsigned __int8 *)(result + 44);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(*(_DWORD *)(result + 48));
      }
      else
      {
        __dmb(0xBu);
        do
          v3 = __ldrex(v1);
        while ( __strex(v3 & 0xBFFFFFFF, v1) );
        __dmb(0xBu);
        do
          v4 = __ldrex(v1);
        while ( __strex(v4 - 1, v1) );
      }
      result = KfLowerIrql(v2);
    }
  }
  return result;
}
