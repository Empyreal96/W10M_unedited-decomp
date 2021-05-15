// FsRtlReleaseEofLock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlReleaseEofLock(int a1)
{
  int v2; // r1
  int v3; // r6
  int *v4; // r8
  int v5; // r5
  int v6; // r7
  unsigned int v7; // r2
  int v8; // r3
  bool v9; // zf
  int v10; // r3
  unsigned int v11; // r5 OVERLAPPED
  unsigned int v12; // r6 OVERLAPPED
  int v13; // r1
  unsigned int *v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r1
  int result; // r0
  int *i; // r4
  unsigned int *v19; // r4
  unsigned int v20; // r5
  unsigned int v21; // r1
  int *v22; // r7
  __int64 v23; // kr00_8
  __int64 v24; // kr08_8
  int *v25; // lr
  int v26; // r3
  int *v27; // r2
  int v28; // r3
  __int64 v29; // kr10_8
  int **v30; // lr
  int v31; // [sp+8h] [bp-30h] BYREF
  int *v32; // [sp+10h] [bp-28h] BYREF
  int **v33; // [sp+14h] [bp-24h]

  v2 = *(_DWORD *)(a1 + 12);
  v32 = (int *)&v32;
  v33 = &v32;
  v3 = *(_DWORD *)(v2 + 40);
  v4 = 0;
  v5 = KeAbPreAcquire(v3, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended(v3, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v3 + 28) = v6;
  v8 = (unsigned __int16)(*(_WORD *)(a1 + 22) - 1);
  *(_WORD *)(a1 + 22) = v8;
  v9 = v8 == 0;
  v10 = *(_DWORD *)(a1 + 12);
  if ( v9 )
  {
    *(_QWORD *)&v11 = *(_QWORD *)(v10 + 32);
    if ( *(_BYTE *)(a1 + 20) )
    {
      PsBoostThreadIoEx(*(_DWORD *)a1, 1, 0);
      *(_BYTE *)(a1 + 20) = 0;
    }
    v13 = *(_DWORD *)(a1 + 4);
    if ( v13 == a1 + 4 )
      goto LABEL_12;
    do
    {
      v22 = (int *)v13;
      v23 = *(_QWORD *)(v13 + 24);
      v13 = *(_DWORD *)v13;
      if ( v23 >= 0 && v23 <= __SPAIR64__(v12, v11) )
      {
        v29 = *(_QWORD *)v22;
        if ( *(int **)(*v22 + 4) != v22 || *(int **)HIDWORD(v29) != v22 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v29) = v29;
        *(_DWORD *)(v29 + 4) = HIDWORD(v29);
        v30 = v33;
        *v22 = (int)&v32;
        v22[1] = (int)v30;
        if ( *v30 != (int *)&v32 )
          __fastfail(3u);
        *v30 = v22;
        v33 = (int **)v22;
      }
      else if ( !v4 )
      {
        v24 = *(_QWORD *)v22;
        if ( *(int **)(*v22 + 4) != v22 || *(int **)HIDWORD(v24) != v22 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v24) = v24;
        *(_DWORD *)(v24 + 4) = HIDWORD(v24);
        v25 = v32;
        *v22 = (int)v32;
        v22[1] = (int)&v32;
        if ( (int **)v25[1] != &v32 )
          __fastfail(3u);
        v25[1] = (int)v22;
        v32 = v22;
        v4 = v22;
      }
    }
    while ( v13 != a1 + 4 );
    if ( !v4 )
    {
LABEL_12:
      *(_DWORD *)a1 = 0;
      *(_WORD *)(a1 + 22) = 0;
      *(_DWORD *)(a1 + 16) = 0;
    }
    else
    {
      v26 = v4[8];
      *(_WORD *)(a1 + 22) = 1;
      *(_DWORD *)a1 = v26;
      *(_DWORD *)(a1 + 16) = v4[9];
    }
    v14 = *(unsigned int **)(*(_DWORD *)(a1 + 12) + 40);
    v15 = v14[7];
    v14[1] = 0;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( !v16 && __strex(1u, v14) );
    if ( v16 )
      ExpReleaseFastMutexContended(v14, v16, 1);
    KfLowerIrql((unsigned __int8)v15);
    result = KeAbPostRelease(v14);
    for ( i = v32; i != (int *)&v32; result = KeSetEventBoostPriorityEx(v27 + 2, 0, &v31, 0, 0) )
    {
      v27 = i;
      v28 = i[9];
      i = (int *)*i;
      v31 = v28;
    }
  }
  else
  {
    v19 = *(unsigned int **)(v10 + 40);
    v20 = v19[7];
    v19[1] = 0;
    __dmb(0xBu);
    do
      v21 = __ldrex(v19);
    while ( !v21 && __strex(1u, v19) );
    if ( v21 )
    {
      result = sub_51E7C0();
    }
    else
    {
      KfLowerIrql((unsigned __int8)v20);
      result = KeAbPostRelease(v19);
    }
  }
  return result;
}
