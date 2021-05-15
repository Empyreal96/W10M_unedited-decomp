// MiQueueControlAreaDelete 
 
int __fastcall MiQueueControlAreaDelete(_DWORD *a1)
{
  int v2; // r9
  unsigned int v3; // r5
  unsigned int v4; // r1
  int v5; // r7
  unsigned int v6; // r0
  int vars4; // [sp+24h] [bp+4h]

  *a1 = 0;
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v3 = 192;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v4 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    v3 = 0xC0u;
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
  *a1 = dword_63FA90;
  dword_63FA90 = (int)a1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v3], vars4);
  }
  else
  {
    __dmb(0xBu);
    MiState[v3] = 0;
  }
  KfLowerIrql(v2);
  return KeSetEvent((int)&unk_63FA80, 0, 0);
}
