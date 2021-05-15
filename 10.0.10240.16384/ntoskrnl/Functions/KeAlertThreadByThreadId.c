// KeAlertThreadByThreadId 
 
int __fastcall KeAlertThreadByThreadId(int a1)
{
  int v2; // r8
  unsigned int v3; // r5
  unsigned int *v4; // r6
  unsigned int v5; // r2
  int v6; // r7
  int v7; // r3
  int v8; // r0
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2

  v2 = KfRaiseIrql(2);
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v4 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v5 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( !v5 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v4 );
  }
  if ( (*(_DWORD *)(a1 + 80) & 8) != 0 )
  {
    v6 = 0;
  }
  else
  {
    v6 = 1;
    if ( *(_BYTE *)(a1 + 132) != 5
      || (v7 = *(_BYTE *)(a1 + 72) & 7, v7 == 4)
      || v7 == 3
      || *(_BYTE *)(a1 + 395) != 37
      || (v8 = KiSignalThread(v3 + 1408, a1, 257, 0), *(_BYTE *)(a1 + 72) |= 0x80u, !v8) )
    {
      __dmb(0xBu);
      v10 = (unsigned __int8 *)(a1 + 80);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 8, v10) );
      __dmb(0xBu);
    }
  }
  __dmb(0xBu);
  *v4 = 0;
  KiExitDispatcher(v3 + 1408, 0, 1, 2, v2);
  return v6;
}
