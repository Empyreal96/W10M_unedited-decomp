// ObpInsertCallbackByAltitude 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ObpInsertCallbackByAltitude(int a1, int a2)
{
  int v4; // r8
  unsigned int v5; // r2
  unsigned __int8 *v6; // r4
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  _DWORD *v10; // r5
  _DWORD *v11; // r7
  _DWORD *v12; // t1
  int v13; // r9
  int v14; // r0
  bool v15; // zf
  int *v16; // r2 OVERLAPPED
  int v17; // r1 OVERLAPPED
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 310);
  v6 = (unsigned __int8 *)(a1 + 128);
  v7 = KeAbPreAcquire(a1 + 128, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( __strex(v9 | 1, v6) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v6, v7, (unsigned int)v6);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v12 = *(_DWORD **)(a1 + 136);
  v11 = (_DWORD *)(a1 + 136);
  v10 = v12;
  if ( v12 == v11 )
    goto LABEL_15;
  v13 = *(_DWORD *)(a2 + 16);
  while ( 1 )
  {
    v14 = RtlCompareAltitudes((unsigned __int16 *)(v10[4] + 8), (unsigned __int16 *)(v13 + 8));
    v15 = v14 == 0;
    if ( v14 <= 0 )
      break;
    v10 = (_DWORD *)*v10;
    if ( v10 == v11 )
    {
      v15 = v14 == 0;
      break;
    }
  }
  if ( v15 )
  {
    v4 = -1071906799;
  }
  else
  {
LABEL_15:
    v16 = (int *)v10[1];
    v17 = *v16;
    *(_QWORD *)a2 = *(_QWORD *)&v17;
    if ( *(int **)(v17 + 4) != v16 )
      __fastfail(3u);
    *(_DWORD *)(v17 + 4) = a2;
    *v16 = a2;
  }
  __pld(v6);
  v18 = *(_DWORD *)v6;
  v19 = *(_DWORD *)v6 - 16;
  if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
    v19 = 0;
  if ( (v18 & 2) != 0 )
    goto LABEL_25;
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)v6);
  while ( v20 == v18 && __strex(v19, (unsigned int *)v6) );
  if ( v20 != v18 )
LABEL_25:
    ExfReleasePushLock(v6, v18);
  v21 = KeAbPostRelease((unsigned int)v6);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x136) + 1;
  *(_WORD *)(v22 + 310) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 )
    KiCheckForKernelApcDelivery(v21);
  return v4;
}
