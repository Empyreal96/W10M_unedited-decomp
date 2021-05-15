// MiManageSubsectionView 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiManageSubsectionView(int *a1, int a2, int a3)
{
  int v3; // r9
  unsigned int v7; // r4
  unsigned __int8 *v8; // r7
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r4
  _DWORD *v12; // r2 OVERLAPPED
  int v13; // r1 OVERLAPPED
  unsigned int v14; // r4
  unsigned int v15; // r1
  int result; // r0
  __int16 v17; // r3
  int v18; // r1 OVERLAPPED
  _DWORD *v19; // r2 OVERLAPPED

  v3 = *a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = (unsigned __int8 *)(v3 + 72);
  v9 = KeAbPreAcquire(v3 + 72, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3 + 72, v9, v3 + 72);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  switch ( a3 )
  {
    case 1:
      v12 = a1 + 13;
      v13 = a1[13];
      *(_QWORD *)a2 = *(_QWORD *)&v13;
      if ( *(int **)(v13 + 4) != a1 + 13 )
        sub_545A54();
      goto LABEL_9;
    case 2:
      *(_QWORD *)&v18 = *(_QWORD *)a2;
      if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v19 != a2 )
        __fastfail(3u);
      goto LABEL_18;
    case 3:
      v12 = (_DWORD *)(v3 + 4);
      v13 = *(_DWORD *)(v3 + 4);
      *(_QWORD *)a2 = *(_QWORD *)&v13;
      if ( *(_DWORD *)(v13 + 4) != v3 + 4 )
        __fastfail(3u);
LABEL_9:
      *(_DWORD *)(v13 + 4) = a2;
      *v12 = a2;
      goto LABEL_10;
    case 4:
      if ( (*(_DWORD *)(v3 + 28) & 0x400) != 0 )
        goto LABEL_10;
      *(_QWORD *)&v18 = *(_QWORD *)a2;
      if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v19 != a2 )
        __fastfail(3u);
LABEL_18:
      *v19 = v18;
      *(_DWORD *)(v18 + 4) = v19;
LABEL_10:
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)v8);
      while ( __strex(v15 - 1, (unsigned int *)v8) );
      if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
        ExfTryToWakePushLock(v3 + 72);
      result = KeAbPostRelease(v3 + 72);
      v17 = *(_WORD *)(v14 + 310) + 1;
      *(_WORD *)(v14 + 310) = v17;
      if ( !v17 && *(_DWORD *)(v14 + 100) != v14 + 100 )
        result = KiCheckForKernelApcDelivery(result);
      return result;
    default:
      goto LABEL_10;
  }
}
