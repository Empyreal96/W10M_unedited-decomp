// KeResumeThread 
 
int __fastcall KeResumeThread(int a1)
{
  int v2; // r8
  unsigned int v3; // r7
  unsigned __int8 *v4; // r6
  unsigned int v5; // r2
  int v6; // r5
  unsigned int v7; // r1

  v2 = KfRaiseIrql(2);
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v4 = (unsigned __int8 *)(a1 + 452);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v5 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)v4 & 0x80) != 0 );
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
  }
  v6 = *(char *)(a1 + 396);
  if ( *(_BYTE *)(a1 + 396) )
  {
    *(_BYTE *)(a1 + 396) = v6 - 1;
    if ( (_BYTE)v6 == 1 && (*(_DWORD *)(a1 + 80) & 0x2000) == 0 )
      KiResumeThread(a1, v3 + 1408, 0);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)v4);
  while ( __strex(v7 & 0xFFFFFF7F, (unsigned int *)v4) );
  KiExitDispatcher(v3 + 1408, 0, 1, 0, v2);
  return v6;
}
