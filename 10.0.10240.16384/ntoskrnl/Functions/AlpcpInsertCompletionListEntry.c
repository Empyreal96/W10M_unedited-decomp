// AlpcpInsertCompletionListEntry 
 
int __fastcall AlpcpInsertCompletionListEntry(int a1, int a2)
{
  _DWORD *v2; // r6
  unsigned int v4; // r9
  int v5; // r10
  unsigned __int8 *v6; // r5
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  __int64 v10; // r4
  _DWORD *v11; // r3
  unsigned int v12; // r6
  unsigned __int64 v13; // kr08_8
  unsigned int *v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r3
  int v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // lr
  int v20; // r2
  unsigned int *v21; // r6
  unsigned int v22; // r1
  unsigned __int64 v23; // r2
  unsigned __int64 v24; // kr10_8
  unsigned __int64 v25; // kr18_8
  unsigned int *v26; // r4
  unsigned int v27; // r1
  unsigned int *v28; // r6
  unsigned int v29; // r1
  unsigned __int64 v30; // kr20_8
  unsigned int *v32; // r4
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r1
  unsigned int *v36; // r4
  unsigned int v37; // r1
  unsigned int *v38; // r2
  unsigned int v39; // r1
  _DWORD *v40; // [sp+0h] [bp-38h]
  int v42; // [sp+8h] [bp-30h]
  int v43; // [sp+Ch] [bp-2Ch]

  v2 = *(_DWORD **)(a1 + 212);
  v40 = v2;
  v4 = v2[12] >> 2;
  v42 = 0;
  v43 = v2[10];
  if ( !v4 )
    return 0;
  v5 = v2[10] + 128;
  while ( 1 )
  {
    v6 = (unsigned __int8 *)(*(_DWORD *)(a1 + 212) + 12);
    v7 = KeAbPreAcquire((unsigned int)v6, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(v6);
    while ( __strex(v9 | 1, v6) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v6, v7, (unsigned int)v6);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    LODWORD(v10) = *(_DWORD *)(v5 + 4);
    HIDWORD(v10) = *(_DWORD *)v5;
    __dmb(0xBu);
    if ( (HIDWORD(v10) & 0xFFFFFF) == 0xFFFFFF
      && (HIDWORD(v10) & 0xFF000000) == -16777216
      && (unsigned __int16)v10 == 0xFFFF )
    {
      break;
    }
    if ( (HIDWORD(v10) & 0xFFFFFFu) >= v4 || (v16 = (((_DWORD)v10 << 8) | HIBYTE(HIDWORD(v10))) & 0xFFFFFF, v16 >= v4) )
    {
      v28 = (unsigned int *)(*(_DWORD *)(a1 + 212) + 12);
      __dmb(0xBu);
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 - 1, v28) );
      if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
        ExfTryToWakePushLock(v28);
      KeAbPostRelease((unsigned int)v28);
      __dmb(0xBu);
      do
      {
        v30 = __ldrexd((unsigned __int64 *)v5);
        v23 = __PAIR64__(v30, HIDWORD(v30));
      }
      while ( __PAIR64__(v30, HIDWORD(v30)) == v10 && __strexd(__PAIR64__(v10, HIDWORD(v10)), (unsigned __int64 *)v5) );
      goto LABEL_54;
    }
    _rt_udiv64(v4, v16 + 1i64);
    v18 = v10 & 0xFFFF0000 | (unsigned __int16)(v17 >> 8);
    v19 = (HIDWORD(v10) ^ (v17 << 24)) & 0xFF000000 ^ HIDWORD(v10);
    v20 = (v18 << 8) | HIBYTE(v19);
    if ( ((v20 ^ v19) & 0xFFFFFF) == 0 )
    {
      v21 = (unsigned int *)(*(_DWORD *)(a1 + 212) + 12);
      __dmb(0xBu);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 - 1, v21) );
      if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
        ExfTryToWakePushLock(v21);
      KeAbPostRelease((unsigned int)v21);
      __dmb(0xBu);
      do
      {
        v24 = __ldrexd((unsigned __int64 *)v5);
        v23 = __PAIR64__(v24, HIDWORD(v24));
      }
      while ( __PAIR64__(v24, HIDWORD(v24)) == v10 && __strexd(__PAIR64__(v10, HIDWORD(v10)), (unsigned __int64 *)v5) );
LABEL_54:
      __dmb(0xBu);
      if ( v23 == v10 )
        return 0;
LABEL_55:
      v2 = v40;
      goto LABEL_56;
    }
    *(_DWORD *)(v2[11] + 4 * (v20 & 0xFFFFFF)) = a2;
    __dmb(0xBu);
    do
      v25 = __ldrexd((unsigned __int64 *)v5);
    while ( __PAIR64__(v25, HIDWORD(v25)) == v10 && __strexd(__PAIR64__(v18, v19), (unsigned __int64 *)v5) );
    __dmb(0xBu);
    if ( __PAIR64__(v25, HIDWORD(v25)) == v10 )
    {
      v36 = (unsigned int *)(*(_DWORD *)(a1 + 212) + 12);
      __dmb(0xBu);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 - 1, v36) );
      if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
        ExfTryToWakePushLock(v36);
      KeAbPostRelease((unsigned int)v36);
      __dmb(0xBu);
      v38 = (unsigned int *)(v43 + 256);
      do
        v39 = __ldrex(v38);
      while ( __strex(v39 + 1, v38) );
      __dmb(0xBu);
      return 1;
    }
    v26 = (unsigned int *)(*(_DWORD *)(a1 + 212) + 12);
    __dmb(0xBu);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 - 1, v26) );
    if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
      ExfTryToWakePushLock(v26);
    KeAbPostRelease((unsigned int)v26);
LABEL_56:
    if ( ++v42 >= v4 )
      return 0;
  }
  v11 = (_DWORD *)v2[11];
  v12 = v10 & 0xFFFF0000;
  *v11 = a2;
  __dmb(0xBu);
  do
    v13 = __ldrexd((unsigned __int64 *)v5);
  while ( __PAIR64__(v13, HIDWORD(v13)) == v10 && __strexd(__PAIR64__(v12, 0), (unsigned __int64 *)v5) );
  __dmb(0xBu);
  if ( __PAIR64__(v13, HIDWORD(v13)) != v10 )
  {
    v14 = (unsigned int *)(*(_DWORD *)(a1 + 212) + 12);
    __dmb(0xBu);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 - 1, v14) );
    if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
      ExfTryToWakePushLock(v14);
    KeAbPostRelease((unsigned int)v14);
    goto LABEL_55;
  }
  v32 = (unsigned int *)(*(_DWORD *)(a1 + 212) + 12);
  __dmb(0xBu);
  do
    v33 = __ldrex(v32);
  while ( __strex(v33 - 1, v32) );
  if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
    ExfTryToWakePushLock(v32);
  KeAbPostRelease((unsigned int)v32);
  __dmb(0xBu);
  v34 = (unsigned int *)(v43 + 256);
  do
    v35 = __ldrex(v34);
  while ( __strex(v35 + 1, v34) );
  __dmb(0xBu);
  if ( (v12 & 0xFFFF0000) == 0 )
    return 3;
  return 1;
}
