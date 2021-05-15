// CmpParseCacheAddSymbolicLink 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpParseCacheAddSymbolicLink(unsigned int *a1)
{
  unsigned int v2; // r7
  int *v4; // r6
  int v5; // r3
  int v6; // r5
  int v7; // r4
  int v8; // t1
  int v9; // r8
  int v10; // r8
  _WORD *v11; // r4
  unsigned int *v12; // r5
  unsigned int v13; // r3
  int v14; // r1
  int v15; // r6
  int v16; // r0
  int v17; // r5
  unsigned int v18; // r2
  int *v19; // r0
  unsigned int v20; // r3
  int v21; // r2
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r1
  int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r1 OVERLAPPED
  int **v32; // r2
  __int64 v33; // kr00_8
  int v34[2]; // [sp+0h] [bp-40h] BYREF
  int v35; // [sp+8h] [bp-38h] BYREF
  int v36; // [sp+10h] [bp-30h] BYREF
  _WORD *v37; // [sp+14h] [bp-2Ch]
  unsigned int *v38; // [sp+18h] [bp-28h]
  _DWORD v39[2]; // [sp+24h] [bp-1Ch] BYREF
  int v40; // [sp+2Ch] [bp-14h]

  v34[1] = (int)v34;
  v34[0] = (int)v34;
  v2 = ExAllocatePoolWithTag(1, 1542, 959728963);
  if ( !v2 )
    return sub_8194F8();
  v4 = &v36;
  v37 = (_WORD *)a1[10];
  v38 = a1;
  v36 = *((_DWORD *)v37 + 10);
  v5 = 0;
  v6 = 3;
  do
  {
    v8 = *v4++;
    v7 = v8;
    *(_WORD *)(v2 + 2 * v5) = 92;
    v9 = (unsigned __int16)(v5 + 1);
    if ( (*(_WORD *)(v8 + 106) & 0x20) != 0 )
    {
      CmpCopyCompressedName(
        (_WORD *)(v2 + 2 * v9),
        0x200u,
        *(_DWORD *)(v7 + 44) + 14,
        *(unsigned __int16 *)(*(_DWORD *)(v7 + 44) + 12));
      LOWORD(v5) = *(_WORD *)(*(_DWORD *)(v7 + 44) + 12) + v9;
    }
    else
    {
      memmove(v2, *(_DWORD *)(v7 + 44) + 14, *(unsigned __int16 *)(*(_DWORD *)(v7 + 44) + 12));
      v5 = v9 + (*(unsigned __int16 *)(*(_DWORD *)(v7 + 44) + 12) >> 1);
    }
    v5 = (unsigned __int16)v5;
    --v6;
  }
  while ( v6 );
  *(_WORD *)(v2 + 2 * (unsigned __int16)v5) = 0;
  v10 = (unsigned __int16)(2 * v5);
  v11 = (_WORD *)(v2 + 2 * ((unsigned int)(v10 - 1) >> 1));
  v12 = a1;
  do
  {
    while ( v2 < (unsigned int)v11 && *v11 != 92 )
      --v11;
    v37 = v11 + 1;
    LOWORD(v36) = 2 * ((int)(v2 + 2 * ((unsigned int)(v10 - 1) >> 1) - (_DWORD)v11) >> 1);
    v13 = v12[10];
    HIWORD(v36) = v10;
    if ( v13 )
      v14 = *(_DWORD *)(v13 + 24);
    else
      v14 = -1;
    v15 = CmpParseCacheAllocEntry(&v36, v14, (int)a1, &v35);
    if ( v15 < 0 )
      break;
    v25 = v39[0];
    v26 = v40 + 4;
    *(_DWORD *)(v40 + 4) = v39[0];
    *(_DWORD *)(v26 + 4) = v39;
    if ( *(_DWORD **)(v25 + 4) != v39 )
      __fastfail(3u);
    *(_DWORD *)(v25 + 4) = v26;
    v34[0] = v26;
    v12 = (unsigned int *)v12[10];
    --v11;
  }
  while ( v12 );
  v16 = KeAbPreAcquire((unsigned int)&CmpParseCacheLock, 0, 0);
  v17 = v16;
  do
    v18 = __ldrex((unsigned __int8 *)&CmpParseCacheLock);
  while ( __strex(v18 | 1, (unsigned __int8 *)&CmpParseCacheLock) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpParseCacheLock, v16, (unsigned int)&CmpParseCacheLock);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  if ( v15 < 0 )
  {
    __pld(&CmpParseCacheLock);
    v27 = CmpParseCacheLock;
    if ( (CmpParseCacheLock & 0xFFFFFFF0) <= 0x10 )
      v28 = 0;
    else
      v28 = CmpParseCacheLock - 16;
    if ( (CmpParseCacheLock & 2) != 0 )
      goto LABEL_51;
    __dmb(0xBu);
    do
      v29 = __ldrex((unsigned int *)&CmpParseCacheLock);
    while ( v29 == v27 && __strex(v28, (unsigned int *)&CmpParseCacheLock) );
    if ( v29 != v27 )
LABEL_51:
      ExfReleasePushLock(&CmpParseCacheLock, v27);
    KeAbPostRelease((unsigned int)&CmpParseCacheLock);
    while ( 1 )
    {
      v30 = v39[0];
      if ( (_DWORD *)v39[0] == v39 )
        break;
      *(_QWORD *)&v31 = *(_QWORD *)v39[0];
      if ( *(_DWORD **)(v39[0] + 4) != v39 || *(_DWORD *)(v31 + 4) != v39[0] )
        __fastfail(3u);
      v39[0] = v31;
      *(_DWORD *)(v31 + 4) = v39;
      ExFreePoolWithTag(v30 - 4);
    }
  }
  else
  {
    v19 = (int *)v34[0];
    if ( (int *)v34[0] != v34 )
    {
      do
      {
        v20 = 101027 * (v19[4] ^ ((unsigned int)v19[4] >> 9));
        v21 = CmpParseCacheTable + 4 * (((unsigned __int8)v20 ^ (unsigned __int8)(v20 >> 9)) & 0x1F);
        *(v19 - 1) = *(_DWORD *)(v21 + 4);
        *(_DWORD *)(v21 + 4) = v19 - 1;
        v19 = (int *)*v19;
      }
      while ( v19 != v34 );
      v19 = (int *)v34[0];
    }
    v32 = (int **)v19[1];
    v33 = *(_QWORD *)v32;
    if ( *v32 != v19 || *(int ***)HIDWORD(v33) != v32 )
      __fastfail(3u);
    v19[1] = HIDWORD(v33);
    *(_DWORD *)HIDWORD(v33) = v19;
    __pld(&CmpParseCacheLock);
    v22 = CmpParseCacheLock;
    if ( (CmpParseCacheLock & 0xFFFFFFF0) > 0x10 )
      v23 = CmpParseCacheLock - 16;
    else
      v23 = 0;
    if ( (CmpParseCacheLock & 2) != 0 )
      goto LABEL_39;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&CmpParseCacheLock);
    while ( v24 == v22 && __strex(v23, (unsigned int *)&CmpParseCacheLock) );
    if ( v24 != v22 )
LABEL_39:
      ExfReleasePushLock(&CmpParseCacheLock, v22);
    KeAbPostRelease((unsigned int)&CmpParseCacheLock);
    CmpReferenceKeyControlBlock(a1);
  }
  if ( v15 < 0 )
    ExFreePoolWithTag(v2);
  return v15;
}
