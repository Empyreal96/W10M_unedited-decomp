// MiQueuePageFileExtension 
 
int __fastcall MiQueuePageFileExtension(int a1, char a2)
{
  int v2; // r8
  char v3; // r6
  int v5; // r7
  unsigned int v6; // r5
  unsigned int v7; // r1
  int v8; // r6
  unsigned int v9; // r0
  __int64 v10; // r0
  int v11; // r2
  int v12; // r3
  int vars4; // [sp+34h] [bp+4h]

  v2 = *(_DWORD *)(a1 + 12);
  v3 = a2;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v6 = 192;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v7 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    v6 = 0xC0u;
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v8 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex((unsigned int *)&dword_632D80);
        while ( v9 == v8 && __strex(v8 | 0x40000000, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v3 = a2;
  }
  HIDWORD(v10) = v2 + 800;
  LODWORD(v10) = *(_DWORD *)(v2 + 800);
  v11 = a1 + 4;
  *(_QWORD *)(a1 + 4) = v10;
  if ( *(_DWORD *)(v10 + 4) != v2 + 800 )
    __fastfail(3u);
  *(_DWORD *)(v10 + 4) = v11;
  *(_DWORD *)HIDWORD(v10) = v11;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v6], vars4);
  }
  else
  {
    __dmb(0xBu);
    MiState[v6] = 0;
  }
  KfLowerIrql(v5);
  return KeReleaseSemaphoreEx(v2 + 780, 0, 1, v12, v3);
}
