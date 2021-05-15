// KeInsertHeadQueue 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeInsertHeadQueue(int a1, _QWORD *a2)
{
  int v3; // r8
  unsigned __int8 v5; // r10
  unsigned int v6; // r9
  int v7; // r5
  BOOL v8; // r2
  unsigned int v9; // r2
  int v10; // r7
  _DWORD *v11; // r2 OVERLAPPED
  int v12; // r1 OVERLAPPED
  unsigned int v13; // r1

  v3 = a1 + 8;
  v5 = KfRaiseIrql(2);
  v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v7 = *(_DWORD *)(v6 + 1412);
  if ( (dword_682604 & 0x1000000) != 0 )
  {
    v8 = *(_BYTE *)(v7 + 132) == 2
      && *(_DWORD *)(v7 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    EtwTraceEnqueueWork(*(_DWORD *)(v6 + 1412), a2, v8);
  }
  do
    v9 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v9 | 0x80, (unsigned __int8 *)a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v9 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v9 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v9 | 0x80, (unsigned __int8 *)a1) );
  }
  v10 = *(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)(v3 + 4) == v3
    || *(_DWORD *)(a1 + 24) >= *(_DWORD *)(a1 + 28)
    || *(_DWORD *)(v7 + 152) == a1 && *(_BYTE *)(v7 + 395) == 15
    || !KiWakeQueueWaiter(v6 + 1408, a1, (int)a2) )
  {
    v11 = (_DWORD *)(a1 + 16);
    ++*(_DWORD *)(a1 + 4);
    v12 = *(_DWORD *)(a1 + 16);
    *a2 = *(_QWORD *)&v12;
    if ( *(_DWORD *)(v12 + 4) != a1 + 16 )
      __fastfail(3u);
    *(_DWORD *)(v12 + 4) = a2;
    *v11 = a2;
  }
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)a1);
  while ( __strex(v13 & 0xFFFFFF7F, (unsigned int *)a1) );
  KiExitDispatcher(v6 + 1408, 0, 1, 0, v5);
  return v10;
}
