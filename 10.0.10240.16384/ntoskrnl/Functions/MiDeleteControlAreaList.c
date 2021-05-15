// MiDeleteControlAreaList 
 
int __fastcall MiDeleteControlAreaList(int a1)
{
  int v2; // r10
  _DWORD *v3; // r6
  unsigned int v4; // r1
  int v5; // r6
  unsigned int v6; // r0
  int result; // r0
  int vars4; // [sp+24h] [bp+4h]

  while ( 1 )
  {
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
    }
    else
    {
      do
        v4 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
      while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
      __dmb(0xBu);
      if ( v4 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
      while ( 1 )
      {
        v5 = dword_632D80;
        if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632D80 & 0x40000000) == 0 )
        {
          do
            v6 = __ldrex((unsigned int *)&dword_632D80);
          while ( v6 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&dword_632D80) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v3 = *(_DWORD **)(a1 + 912);
    if ( v3 )
      *(_DWORD *)(a1 + 912) = *v3;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
    }
    else
    {
      __dmb(0xBu);
      dword_632D80 = 0;
    }
    result = KfLowerIrql(v2);
    if ( !v3 )
      break;
    MiDeleteControlArea(v3);
  }
  return result;
}
