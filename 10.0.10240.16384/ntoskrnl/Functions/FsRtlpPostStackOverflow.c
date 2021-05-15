// FsRtlpPostStackOverflow 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlpPostStackOverflow(int a1, int a2, int a3, int a4)
{
  int *v8; // r5 OVERLAPPED
  unsigned __int8 *v9; // r4
  unsigned __int8 v10; // r9
  unsigned int v11; // r8
  int v12; // r6
  BOOL v13; // r2
  unsigned int v14; // r2
  int **v15; // r1
  unsigned int v16; // r1

  v8 = (int *)ExAllocatePoolWithTag(512, 28);
  if ( !v8 )
  {
    if ( !a4 )
      RtlRaiseStatus(-1073741670);
    KeWaitForSingleObject((unsigned int)&StackOverflowFallbackSerialEvent, 0, 0, 0, 0);
    v8 = &StackOverflowFallback;
  }
  v8[5] = a1;
  v8[6] = a2;
  *(_QWORD *)(v8 + 3) = *(_QWORD *)&v8;
  v8[2] = (int)FsRtlStackOverflowRead;
  v9 = (unsigned __int8 *)&FsRtlWorkerQueues + 40 * a4;
  *v8 = 0;
  v10 = KfRaiseIrql(2);
  v11 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v12 = *(_DWORD *)(v11 + 1412);
  if ( (dword_682604 & 0x1000000) != 0 )
  {
    v13 = *(_BYTE *)(v12 + 132) == 2
       && *(_DWORD *)(v12 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    EtwTraceEnqueueWork(*(_DWORD *)(v11 + 1412), v8, v13);
  }
  do
    v14 = __ldrex(v9);
  while ( __strex(v14 | 0x80, v9) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v14 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)v9 & 0x80) != 0 );
    do
      v14 = __ldrex(v9);
    while ( __strex(v14 | 0x80, v9) );
  }
  if ( *((unsigned __int8 **)v9 + 3) == v9 + 8
    || *((_DWORD *)v9 + 6) >= *((_DWORD *)v9 + 7)
    || *(unsigned __int8 **)(v12 + 152) == v9 && *(_BYTE *)(v12 + 395) == 15
    || !KiWakeQueueWaiter(v11 + 1408, (int)v9, (int)v8) )
  {
    ++*((_DWORD *)v9 + 1);
    v15 = (int **)*((_DWORD *)v9 + 5);
    *v8 = (int)(v9 + 16);
    v8[1] = (int)v15;
    if ( *v15 != (int *)(v9 + 16) )
      __fastfail(3u);
    *v15 = v8;
    *((_DWORD *)v9 + 5) = v8;
  }
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v9);
  while ( __strex(v16 & 0xFFFFFF7F, (unsigned int *)v9) );
  return KiExitDispatcher(v11 + 1408, 0, 1, 0, v10);
}
