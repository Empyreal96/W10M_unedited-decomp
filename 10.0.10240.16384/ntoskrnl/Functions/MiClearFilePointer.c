// MiClearFilePointer 
 
int __fastcall MiClearFilePointer(int result)
{
  int v1; // r6
  int v2; // r3
  unsigned int v3; // r8
  unsigned int v4; // r1
  int v5; // lr
  _DWORD *v6; // r3

  v1 = result;
  v2 = *(_DWORD *)(result + 28);
  if ( (v2 & 0x80000) == 0 )
  {
    *(_DWORD *)(result + 28) = v2 | 0x80000;
    v3 = *(_DWORD *)(result + 32) & 0xFFFFFFF8;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_53EAC8();
    }
    else
    {
      do
        v4 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
      while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
      __dmb(0xBu);
      if ( v4 >> 7 )
        result = ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
      while ( 1 )
      {
        v5 = dword_632E00;
        if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632E00 & 0x40000000) == 0 )
        {
          do
            result = __ldrex((unsigned int *)&dword_632E00);
          while ( result == v5 && __strex(v5 | 0x40000000, (unsigned int *)&dword_632E00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v6 = *(_DWORD **)(v3 + 20);
      if ( (*(_DWORD *)(v1 + 28) & 0x20) != 0 )
        v6[2] = 0;
      else
        *v6 = 0;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        result = ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      }
      else
      {
        __dmb(0xBu);
        dword_632E00 = 0;
      }
    }
  }
  return result;
}
