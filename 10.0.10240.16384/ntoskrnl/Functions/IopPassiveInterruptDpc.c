// IopPassiveInterruptDpc 
 
int __fastcall IopPassiveInterruptDpc(int a1, int a2)
{
  _DWORD *v2; // r6
  unsigned __int8 v3; // r8
  unsigned int v4; // r7
  int v5; // r5
  unsigned int v7; // r2
  unsigned int v8; // r1
  void **v9; // r1

  v2 = (_DWORD *)(a2 + 44);
  v3 = KfRaiseIrql(2);
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v5 = *(_DWORD *)(v4 + 1412);
  if ( (dword_682604 & 0x1000000) != 0 )
    return sub_55530C();
  do
    v7 = __ldrex((unsigned __int8 *)&PassiveInterruptRealtimeWorkQueue);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)&PassiveInterruptRealtimeWorkQueue) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v7 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (PassiveInterruptRealtimeWorkQueue & 0x80) != 0 );
    do
      v7 = __ldrex((unsigned __int8 *)&PassiveInterruptRealtimeWorkQueue);
    while ( __strex(v7 | 0x80, (unsigned __int8 *)&PassiveInterruptRealtimeWorkQueue) );
  }
  if ( (_UNKNOWN *)dword_630CAC == &unk_630CA8
    || (unsigned int)dword_630CB8 >= unk_630CBC
    || *(int **)(v5 + 152) == &PassiveInterruptRealtimeWorkQueue && *(_BYTE *)(v5 + 395) == 15
    || !KiWakeQueueWaiter(v4 + 1408, (int)&PassiveInterruptRealtimeWorkQueue, (int)v2) )
  {
    ++dword_630CA4;
    v9 = (void **)dword_630CB4;
    *v2 = &unk_630CB0;
    v2[1] = v9;
    if ( *v9 != &unk_630CB0 )
      __fastfail(3u);
    *v9 = v2;
    dword_630CB4 = (int)v2;
  }
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PassiveInterruptRealtimeWorkQueue);
  while ( __strex(v8 & 0xFFFFFF7F, (unsigned int *)&PassiveInterruptRealtimeWorkQueue) );
  return KiExitDispatcher(v4 + 1408, 0, 1, 0, v3);
}
