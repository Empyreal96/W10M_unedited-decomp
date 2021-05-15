// KeInsertQueueApc 
 
int __fastcall KeInsertQueueApc(int a1, int a2, int a3, int a4)
{
  int v4; // r10
  int v6; // r9
  unsigned int v7; // r7
  unsigned int *v8; // r8
  unsigned int v9; // r5
  int v10; // r4

  v4 = *(_DWORD *)(a1 + 8);
  v6 = KfRaiseIrql(2);
  v7 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v8 = (unsigned int *)(v4 + 44);
  while ( 1 )
  {
    do
      v9 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( !v9 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v8 );
  }
  if ( (*(_DWORD *)(v4 + 76) & 0x4000) == 0 || *(_BYTE *)(a1 + 46) )
  {
    v10 = 0;
  }
  else
  {
    *(_BYTE *)(a1 + 46) = 1;
    *(_DWORD *)(a1 + 36) = a2;
    *(_DWORD *)(a1 + 40) = a3;
    KiInsertQueueApc(a1);
    KiSignalThreadForApc(v7 + 1408, a1, v6);
    v10 = 1;
  }
  __dmb(0xBu);
  *v8 = 0;
  KiExitDispatcher(v7 + 1408, 0, 1, a4, v6);
  return v10;
}
