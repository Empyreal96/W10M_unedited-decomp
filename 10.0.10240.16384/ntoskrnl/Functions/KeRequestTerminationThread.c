// KeRequestTerminationThread 
 
int __fastcall KeRequestTerminationThread(int result)
{
  int v1; // r4
  unsigned __int8 *v2; // r3
  unsigned int v3; // r1
  int v4; // r7
  int v5; // r8
  unsigned int *v6; // r6
  unsigned int v7; // r2
  unsigned int v8; // r5

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned __int8 *)(result + 81);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x40, v2) );
  __dmb(0xBu);
  if ( !((unsigned __int8)(v3 & 0x40) >> 6) )
  {
    v4 = 0;
    v5 = KfRaiseIrql(2);
    v6 = (unsigned int *)(v1 + 44);
    while ( 1 )
    {
      do
        v7 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( !v7 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v6 );
    }
    v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( (*(_DWORD *)(v1 + 76) & 0x4000) != 0 )
    {
      v4 = 1;
      if ( !*(_BYTE *)(v1 + 446) )
      {
        *(_BYTE *)(v1 + 446) = 1;
        KiInsertQueueApc(v1 + 400);
        KiSignalThreadForApc(v8 + 1408, v1 + 400, v5);
      }
    }
    __dmb(0xBu);
    *v6 = 0;
    result = KiExitDispatcher(v8 + 1408, 0, 1, 0, v5);
    if ( v4 )
    {
      KeAlertThread(v1, 0);
      result = KeForceResumeThread(v1);
    }
  }
  return result;
}
