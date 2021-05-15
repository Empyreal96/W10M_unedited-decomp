// PsQueryStatisticsProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PsQueryStatisticsProcess(int a1, int a2)
{
  unsigned int v4; // r7
  unsigned int *v5; // r6
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r9 OVERLAPPED
  unsigned int v9; // r10 OVERLAPPED
  _DWORD *v10; // r6
  unsigned __int64 *v11; // lr
  unsigned int v12; // r0
  unsigned int v13; // r4
  unsigned __int64 v14; // kr08_8
  unsigned int v15; // r2
  int result; // r0
  __int16 v17; // r3
  int v18; // r1

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = (unsigned int *)(a1 + 720);
  v6 = KeAbPreAcquire(a1 + 720, 0, 0);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v7 )
    return sub_7C2D30(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *(_QWORD *)&v8 = *(_QWORD *)(a1 + 152);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a1 + 128);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 136);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a1 + 140);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 432);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 436);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 440);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a1 + 444);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a1 + 448);
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(a1 + 452);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(a1 + 456);
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(a1 + 460);
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a1 + 464);
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a1 + 468);
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(a1 + 472);
  *(_DWORD *)(a2 + 76) = *(_DWORD *)(a1 + 476);
  if ( *(_DWORD *)(a1 + 396) != a1 + 396 )
  {
    v10 = *(_DWORD **)(a1 + 396);
    do
    {
      v11 = (unsigned __int64 *)(v10 - 221);
      v8 += *(v10 - 132);
      v9 += *(v10 - 121);
      while ( 1 )
      {
        v12 = *(v10 - 220);
        v13 = *(_DWORD *)v11;
        do
          v14 = __ldrexd(v11);
        while ( __PAIR64__(v14, HIDWORD(v14)) == __PAIR64__(v13, v12) && __strexd(__PAIR64__(v12, v13), v11) );
        if ( __PAIR64__(v13, v12) == __PAIR64__(v14, HIDWORD(v14)) )
          break;
        __dmb(0xAu);
        __yield();
      }
      *(_QWORD *)(a2 + 16) += __PAIR64__(v12, v13);
      *(_QWORD *)(a2 + 24) += (unsigned int)*(v10 - 201);
      v10 = (_DWORD *)*v10;
    }
    while ( v10 != (_DWORD *)(a1 + 396) );
    v5 = (unsigned int *)(a1 + 720);
  }
  __dmb(0xBu);
  do
    v15 = __ldrex(v5);
  while ( v15 == 17 && __strex(0, v5) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(v5);
  result = KeAbPostRelease((unsigned int)v5);
  v17 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  v18 = KeMaximumIncrement;
  *(_QWORD *)a2 = (unsigned int)KeMaximumIncrement * (unsigned __int64)v8;
  *(_QWORD *)(a2 + 8) = (unsigned int)v18 * (unsigned __int64)v9;
  return result;
}
