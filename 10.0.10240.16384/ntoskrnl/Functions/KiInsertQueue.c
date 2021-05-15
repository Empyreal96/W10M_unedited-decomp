// KiInsertQueue 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiInsertQueue(int a1, int a2, int a3, char a4)
{
  int v6; // r9
  unsigned int v9; // r0
  int v10; // r6
  BOOL v11; // r2
  unsigned int v12; // r2
  int v13; // r7
  int *v14; // r2 OVERLAPPED
  int v15; // r1 OVERLAPPED
  int *v16; // r1
  int v17; // r1
  unsigned int v19; // [sp+8h] [bp-28h]
  unsigned __int8 v20; // [sp+Ch] [bp-24h]

  v6 = a1 + 8;
  v20 = KfRaiseIrql(2);
  v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v10 = *(_DWORD *)(v9 + 1412);
  v19 = v9;
  if ( (dword_682604 & 0x1000000) != 0 )
  {
    v11 = *(_BYTE *)(v10 + 132) == 2
       && *(_DWORD *)(v10 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    EtwTraceEnqueueWork(v10, a2, v11);
    v9 = v19;
  }
  if ( a3 && (*(_BYTE *)(a1 + 1) & 2) != 0 )
    a3 = 0;
  do
    v12 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v12 | 0x80, (unsigned __int8 *)a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v12 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v12 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v12 | 0x80, (unsigned __int8 *)a1) );
  }
  v13 = *(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)(v6 + 4) == v6
    || *(_DWORD *)(a1 + 24) >= *(_DWORD *)(a1 + 28)
    || *(_DWORD *)(v10 + 152) == a1 && *(_BYTE *)(v10 + 395) == 15
    || !KiWakeQueueWaiter(v9 + 1408, a1, a2) )
  {
    v14 = (int *)(a1 + 16);
    ++*(_DWORD *)(a1 + 4);
    if ( (a4 & 2) != 0 )
    {
      v15 = *v14;
      *(_QWORD *)a2 = *(_QWORD *)(&v14 - 1);
      if ( *(int **)(v15 + 4) != v14 )
        __fastfail(3u);
      *(_DWORD *)(v15 + 4) = a2;
      *v14 = a2;
    }
    else
    {
      v16 = *(int **)(a1 + 20);
      *(_DWORD *)a2 = v14;
      *(_DWORD *)(a2 + 4) = v16;
      if ( (int *)*v16 != v14 )
        __fastfail(3u);
      *v16 = a2;
      *(_DWORD *)(a1 + 20) = a2;
    }
  }
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)a1);
  while ( __strex(v17 & 0xFFFFFF7F, (unsigned int *)a1) );
  if ( (a4 & 1) != 0 )
    v17 = 1;
  if ( (a4 & 1) == 0 )
    v17 = 0;
  KiExitDispatcher(v19 + 1408, v17, 1, a3, v20);
  return v13;
}
