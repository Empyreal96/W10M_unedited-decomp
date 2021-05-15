// CmpDereferenceKeyControlBlock 
 
unsigned int *__fastcall CmpDereferenceKeyControlBlock(unsigned int *result)
{
  unsigned int *v1; // r5
  unsigned int v2; // r4
  unsigned int v3; // r1
  unsigned int v4; // r2
  unsigned int v5; // r9
  _DWORD *v6; // r7
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned __int8 *v11; // r4
  int v12; // r0
  int v13; // r6
  unsigned int v14; // r2
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r2
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1
  unsigned int *v22; // r2
  unsigned int v23; // r1
  unsigned int v24; // r2
  int v25; // r3
  _DWORD *v26; // r4
  int v27; // r1
  unsigned int v28; // r0

  v1 = result;
  v2 = *result;
  __dmb(0xBu);
  if ( v2 <= 1 )
  {
LABEL_7:
    v5 = result[3];
    v6 = (_DWORD *)result[5];
    v7 = v6[461] + 12 * (((101027 * (v5 ^ (v5 >> 9))) ^ ((101027 * (v5 ^ (v5 >> 9))) >> 9)) & (v6[462] - 1));
    v8 = KeAbPreAcquire(v7, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v10 | 1, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v7, v8, v7);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    *(_DWORD *)(v7 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( !CmpReferenceHive((int)v6) )
      sub_7FEDCC();
    if ( (v1[1] & 0x100000) != 0 )
      v1[9] = CmpLockTableAdd((int)v1, 1);
    v11 = (unsigned __int8 *)(v1 + 7);
    v12 = KeAbPreAcquire((unsigned int)(v1 + 7), 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v11);
    while ( __strex(v14 | 1, v11) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v1 + 7, v12, (unsigned int)(v1 + 7));
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v1[8] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    CmpDereferenceKeyControlBlockWithLock(v1, 0);
    if ( v1[8] == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    {
      v1[8] = 0;
    }
    else
    {
      __dmb(0xBu);
      v22 = v1 + 8;
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 - 1, v22) );
      __dmb(0xBu);
    }
    __pld(v11);
    v15 = *(_DWORD *)v11;
    if ( (*(_DWORD *)v11 & 0xFFFFFFF0) > 0x10 )
      v16 = v15 - 16;
    else
      v16 = 0;
    if ( (v15 & 2) != 0 )
      goto LABEL_50;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v11);
    while ( v17 == v15 && __strex(v16, (unsigned int *)v11) );
    if ( v17 != v15 )
LABEL_50:
      ExfReleasePushLock(v1 + 7, v15);
    KeAbPostRelease((unsigned int)(v1 + 7));
    if ( (v1[1] & 0x100000) != 0 )
      CmpLockTableRemove((int)v1, v1[9]);
    if ( (v1[1] & 0x80000) != 0 )
      CmpFreeKeyControlBlock((unsigned int)v1);
    v24 = 3 * ((v6[462] - 1) & ((101027 * (v5 ^ (v5 >> 9))) ^ ((101027 * (v5 ^ (v5 >> 9))) >> 9)));
    v25 = v6[461];
    v26 = (_DWORD *)(v25 + 12 * ((v6[462] - 1) & ((101027 * (v5 ^ (v5 >> 9))) ^ ((101027 * (v5 ^ (v5 >> 9))) >> 9))));
    __pld(v26);
    v26[1] = 0;
    v27 = *(_DWORD *)(v25 + 4 * v24);
    if ( (v27 & 0xFFFFFFF0) <= 0x10 )
      v28 = 0;
    else
      v28 = v27 - 16;
    if ( (v27 & 2) != 0 )
      goto LABEL_55;
    __dmb(0xBu);
    do
      v18 = __ldrex(v26);
    while ( v18 == v27 && __strex(v28, v26) );
    if ( v18 != v27 )
LABEL_55:
      ExfReleasePushLock(v26, v27);
    result = (unsigned int *)KeAbPostRelease((unsigned int)v26);
    __dmb(0xBu);
    v19 = v6 + 830;
    do
    {
      v20 = __ldrex(v19);
      v21 = v20 - 1;
    }
    while ( __strex(v21, v19) );
    __dmb(0xBu);
    if ( !v21 )
      result = (unsigned int *)CmpDeleteHive(v6);
  }
  else
  {
    while ( 1 )
    {
      v3 = v2 - 1;
      __dmb(0xBu);
      do
        v4 = __ldrex(result);
      while ( v4 == v2 && __strex(v3, result) );
      v2 = v4;
      __dmb(0xBu);
      if ( v4 == v3 + 1 )
        break;
      if ( v4 <= 1 )
        goto LABEL_7;
    }
  }
  return result;
}
