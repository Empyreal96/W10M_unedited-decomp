// MmLinkJobProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MmLinkJobProcess(int a1, _DWORD *a2)
{
  int v3; // r10
  int v4; // r7
  unsigned int v5; // r9
  unsigned __int8 *v6; // r8
  int v7; // r0
  unsigned int v8; // r2
  _DWORD *v9; // r5
  _DWORD *v10; // r6
  int v11; // r10
  _DWORD *v12; // r0
  _DWORD *v13; // r3
  unsigned int *v14; // r2
  unsigned int v15; // r0
  _DWORD *v16; // r0
  _DWORD *v17; // r2
  int v18; // r6
  __int64 v19; // kr00_8
  unsigned int v20; // r1
  int result; // r0
  int v22; // r3
  int *v23; // r1
  int **v24; // r0
  int *v25; // r1
  __int64 v26; // kr08_8
  int *v27; // r5
  int *v28; // r1 OVERLAPPED
  _DWORD *v29; // r3
  unsigned int *v30; // r0
  unsigned int v31; // r1
  unsigned int v32; // r1
  int *v34; // [sp+8h] [bp-28h] BYREF
  int **v35; // [sp+Ch] [bp-24h]

  v35 = &v34;
  v34 = (int *)&v34;
  v3 = a1;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 310);
  v6 = (unsigned __int8 *)(a2 + 217);
  v7 = KeAbPreAcquire((unsigned int)(a2 + 217), 0, 0);
  do
    v8 = __ldrex(v6);
  while ( __strex(v8 | 1, v6) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7C216C(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( (a2[184] & 0x40) == 0 )
  {
    v9 = (_DWORD *)a2[218];
    v10 = a2 + 218;
    if ( v9 != a2 + 218 )
    {
      while ( 1 )
      {
        v11 = v9[2];
        v12 = (_DWORD *)ExAllocatePoolWithTag(1, 40, 1850960205);
        if ( !v12 )
          break;
        v12[8] = v11;
        v23 = v12 + 6;
        v12[4] = *(v9 - 2);
        v12[5] = *(v9 - 1);
        v24 = v35;
        *v23 = (int)&v34;
        v23[1] = (int)v24;
        if ( *v24 != (int *)&v34 )
          __fastfail(3u);
        *v24 = v23;
        v35 = (int **)v23;
        v9 = (_DWORD *)*v9;
        if ( v9 == v10 )
          goto LABEL_10;
      }
      v4 = -1073741670;
LABEL_10:
      v3 = a1;
    }
    while ( 1 )
    {
      v13 = (_DWORD *)a2[218];
      if ( v13 == v10 )
        break;
      MiRemoveSharedCommitNode(v13[2], a2, 1);
    }
    if ( v4 < 0 )
    {
      while ( 1 )
      {
        v25 = v34;
        if ( v34 == (int *)&v34 )
          break;
        v26 = *(_QWORD *)v34;
        if ( (int **)v34[1] != &v34 || *(int **)(v26 + 4) != v34 )
          __fastfail(3u);
        v34 = (int *)*v34;
        *(_DWORD *)(v26 + 4) = &v34;
        ExFreePoolWithTag((unsigned int)(v25 - 6));
      }
    }
    else if ( (a2[184] & 0x20) == 0 )
    {
      __dmb(0xBu);
      v14 = a2 + 184;
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x20, v14) );
      __dmb(0xBu);
    }
  }
  v16 = *(_DWORD **)(v3 + 28);
  v17 = a2 + 96;
  a2[96] = v3 + 24;
  a2[97] = v16;
  if ( *v16 != v3 + 24 )
    __fastfail(3u);
  *v16 = v17;
  *(_DWORD *)(v3 + 28) = v17;
  __dmb(0xBu);
  a2[72] = v3;
  while ( 1 )
  {
    v27 = v34;
    if ( v34 == (int *)&v34 )
      break;
    *(_QWORD *)&v28 = *(_QWORD *)v34;
    if ( (int **)v34[1] != &v34 || (int *)v28[1] != v34 )
      __fastfail(3u);
    v34 = v28;
    v28[1] = (int)&v34;
    if ( v4 >= 0 )
    {
      v18 = v27[2];
      if ( *((_QWORD *)v27 - 1) )
      {
        do
        {
          v4 = MiInsertSharedCommitNode(v18, a2, 1);
          if ( v4 < 0 )
            break;
          v19 = *((_QWORD *)v27 - 1) - 1i64;
          *((_QWORD *)v27 - 1) = v19;
        }
        while ( *(v27 - 1) | (unsigned int)v19 );
      }
    }
    ExFreePoolWithTag((unsigned int)(v27 - 6));
  }
  if ( v4 < 0 )
  {
    while ( 1 )
    {
      v29 = (_DWORD *)a2[218];
      if ( v29 == a2 + 218 )
        break;
      MiRemoveSharedCommitNode(v29[2], a2, 1);
    }
    __dmb(0xBu);
    v30 = a2 + 184;
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 & 0xFFFFFFDF, v30) );
    __dmb(0xBu);
    do
      v32 = __ldrex(v30);
    while ( __strex(v32 | 0x40, v30) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)v6);
  while ( __strex(v20 - 1, (unsigned int *)v6) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  result = KeAbPostRelease((unsigned int)v6);
  v22 = (__int16)(*(_WORD *)(v5 + 310) + 1);
  *(_WORD *)(v5 + 310) = v22;
  if ( !v22 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
