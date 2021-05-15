// PiUEventHandleGetEvent 
 
int __fastcall PiUEventHandleGetEvent(int a1, _DWORD *a2, int a3, unsigned int a4, int a5)
{
  int v5; // r5
  int v6; // r4
  unsigned int v8; // r9
  unsigned int *v9; // r10
  unsigned int v10; // r7
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r2
  _DWORD *v14; // r6
  _DWORD *v15; // r9
  unsigned int v16; // r3
  _DWORD *v17; // r1
  unsigned int *v18; // r6
  unsigned int v19; // r8
  unsigned int v20; // r1
  unsigned int *v22; // r5
  unsigned int v23; // r6
  unsigned int v24; // r1

  v5 = *(_DWORD *)(a1 + 16);
  v6 = 0;
  if ( !v5 || !a2 || a4 <= 4 )
    return -1073741811;
  *a2 = 0;
  v8 = *(_DWORD *)(v5 + 8);
  v9 = a2 + 1;
  v10 = a4 - 4;
  v11 = KeAbPreAcquire(v8, 0, 0);
  v12 = KfRaiseIrql(1);
  do
    v13 = __ldrex((unsigned __int8 *)v8);
  while ( __strex(v13 & 0xFE, (unsigned __int8 *)v8) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
  {
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    *(_DWORD *)(v8 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v8 + 28) = v12;
    v14 = *(_DWORD **)(v5 + 64);
    if ( v14 != (_DWORD *)(v5 + 64) )
    {
      while ( v6 >= 0 )
      {
        v15 = v14;
        v6 = PiUEventCopyEventData(v9, v10, v14[4]);
        if ( v6 < 0 )
        {
          if ( *a2 )
            break;
          *(_DWORD *)(a5 + 4) = 0;
          v22 = *(unsigned int **)(v5 + 8);
          v23 = v22[7];
          v22[1] = 0;
          __dmb(0xBu);
          do
            v24 = __ldrex(v22);
          while ( !v24 && __strex(1u, v22) );
          if ( v24 )
            ExpReleaseFastMutexContended(v22, v24);
          KfLowerIrql((unsigned __int8)v23);
          KeAbPostRelease((unsigned int)v22);
          return v6;
        }
        v16 = *v9;
        if ( *v9 > v10 )
          v6 = -1073741789;
        else
          v9 = (unsigned int *)((char *)v9 + v16);
        v10 -= v16;
        v17 = v14;
        ++*a2;
        v14 = (_DWORD *)*v14;
        if ( *(_BYTE *)(v15[4] + 40) )
          PiUEventMovePendingEventToSynchronousQueue(v5, v17);
        else
          PiUEventDequeuePendingEventWorker(v5, v17);
        if ( v14 == (_DWORD *)(v5 + 64) )
          break;
      }
    }
    v18 = *(unsigned int **)(v5 + 8);
    v19 = v18[7];
    v18[1] = 0;
    __dmb(0xBu);
    do
      v20 = __ldrex(v18);
    while ( !v20 && __strex(1u, v18) );
    if ( v20 )
      ExpReleaseFastMutexContended(v18, v20);
    KfLowerIrql((unsigned __int8)v19);
    KeAbPostRelease((unsigned int)v18);
    if ( v6 == -1073741789 )
    {
      v6 = 0;
      PiUEventNotifyClientPendingEvent(v5);
    }
    *(_DWORD *)(a5 + 4) = a4 - v10;
    return v6;
  }
  return sub_7C16D0(v12);
}
