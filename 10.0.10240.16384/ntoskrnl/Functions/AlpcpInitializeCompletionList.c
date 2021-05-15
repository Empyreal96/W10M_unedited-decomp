// AlpcpInitializeCompletionList 
 
int __fastcall AlpcpInitializeCompletionList(int a1, int a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // r5
  int v6; // r6
  int v7; // r10
  _DWORD *v8; // r9
  _BYTE *v9; // r0
  int v10; // r4
  int v11; // r0
  int v12; // r6
  int v13; // r0
  _BYTE *v14; // r0
  _DWORD *v15; // r8
  unsigned int v16; // r2
  unsigned int v17; // r5
  unsigned int v18; // r4
  int v19; // r3
  int v20; // r1
  int v21; // r2
  __int64 v22; // kr08_8
  __int64 v23; // r2
  _DWORD *v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r3
  unsigned __int8 *v27; // r5
  int v28; // r0
  int v29; // r4
  unsigned int v30; // r2
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r4
  unsigned int *v35; // r5
  unsigned int v36; // r1
  int v37; // r0
  unsigned int v39; // [sp+Ch] [bp-34h]
  int v40; // [sp+10h] [bp-30h]
  int v41; // [sp+14h] [bp-2Ch]
  int v42; // [sp+18h] [bp-28h]
  int v43; // [sp+1Ch] [bp-24h]
  unsigned int v44; // [sp+20h] [bp-20h]

  v42 = a4;
  v5 = a3;
  v39 = a3;
  v6 = a2;
  v43 = a2;
  v7 = a1;
  v40 = 0;
  v41 = 0;
  v8 = 0;
  if ( (a2 & 0xFFF) != 0 || (a3 & 0xFFF) != 0 || a3 - 0x4000 > 0x3FFFC000 || (a5 & 0x57FFFFFF) != 0 || !a4 )
  {
    v10 = -1073741811;
    goto LABEL_36;
  }
  v9 = (_BYTE *)ExAllocatePoolWithTag(1, 88, 1850305601);
  v8 = v9;
  if ( v9 )
  {
    memset(v9, 0, 88);
    v8[3] = 0;
    v8[2] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v8[5] = v6;
    v8[6] = v6 + v5;
    if ( !AlpcpRegisterCompletionListDatabase(v8) )
    {
      v10 = -1073741800;
      goto LABEL_36;
    }
    v41 = 1;
    v11 = IoAllocateMdl(v6, v5, 0, 0, 0);
    v8[4] = v11;
    if ( v11 )
    {
      __mrc(15, 0, 13, 0, 3);
      MmProbeAndLockPages(v8[4]);
      v12 = 0;
      v40 = 1;
      v13 = v8[4];
      if ( (*(_WORD *)(v13 + 6) & 5) != 0 )
        v14 = *(_BYTE **)(v13 + 12);
      else
        v14 = (_BYTE *)MmMapLockedPagesSpecifyCache(v13, 0, 1, 0, 0, 0x40000000);
      v8[8] = v14;
      if ( !v14 )
        goto LABEL_15;
      memset(v14, 0, v5);
      v15 = (_DWORD *)v8[8];
      *v15 = -1163005939;
      v15[1] = -559038737;
      v15[162] = -559038737;
      v15[163] = -1163005939;
      v44 = (4 * (v5 >> 6) + 4095) & 0xFFFFF000;
      v16 = v5 - v44 - 4096;
      v17 = ((v16 >> 9) + 4095) & 0xFFFFF000;
      v18 = v16 - v17;
      v8[9] = v39;
      v8[10] = v15;
      v19 = v8[8] + 4096;
      v8[11] = v19;
      v8[12] = v44;
      v8[13] = v19 + v44;
      v8[14] = v17;
      v8[17] = (v16 >> 6) - (v17 >> 6);
      v8[15] = v19 + v44 + v17;
      v8[16] = v16 - v17;
      v8[19] = v42;
      v8[5] = v43;
      v8[6] = v43 + v39;
      v8[7] = v17 + v44 + v43 + 4096;
      v8[20] = a5;
      v8[21] = AlpcGetHeaderSize(a5);
      v15[2] = v39;
      v15[3] = 4096;
      v15[4] = v44;
      v15[5] = v44 + 4096;
      v15[6] = v17;
      v15[7] = v44 + 4096 + v17;
      v15[8] = v18;
      v20 = v15[33];
      v21 = v15[32];
      __dmb(0xBu);
      v15[32] = v21 | 0xFFFFFF;
      v15[33] = v20;
      v22 = *((_QWORD *)v15 + 16);
      __dmb(0xBu);
      v15[32] = v22 | 0xFF000000;
      v15[33] = HIDWORD(v22) | 0xFFFF;
      v23 = *((_QWORD *)v15 + 16);
      HIDWORD(v23) = WORD2(v23);
      __dmb(0xBu);
      *((_QWORD *)v15 + 16) = v23;
      v15[9] = v8[20];
      v15[10] = v8[21];
      v24 = (_DWORD *)v8[11];
      v25 = 0;
      if ( v24 > (_DWORD *)((char *)v24 + v8[12]) )
        v26 = 0;
      else
        v26 = (unsigned int)(v8[12] + 3) >> 2;
      if ( v26 )
      {
        do
        {
          *v24++ = -1;
          ++v25;
        }
        while ( v25 < v26 );
      }
      v27 = (unsigned __int8 *)(v7 + 208);
      v28 = KeAbPreAcquire(v7 + 208, 0, 0);
      v29 = v28;
      do
        v30 = __ldrex(v27);
      while ( __strex(v30 | 1, v27) );
      __dmb(0xBu);
      if ( (v30 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v7 + 208), v28, v7 + 208);
      if ( v29 )
        *(_BYTE *)(v29 + 14) |= 1u;
      v12 = 1;
      if ( *(_DWORD *)(v7 + 212) )
      {
        v10 = -1073740006;
        goto LABEL_37;
      }
      if ( (*(_DWORD *)(v7 + 244) & 0x40) != 0 )
      {
        v10 = -1073740032;
        goto LABEL_37;
      }
      if ( *(_DWORD *)(v7 + 16) )
      {
        v34 = AlpcpAllocateCompletionPacketLookaside(v44 >> 2);
        if ( !v34 )
        {
LABEL_15:
          v10 = -1073741670;
          goto LABEL_37;
        }
        AlpcpFreeCompletionPacketLookaside(*(unsigned int **)(v7 + 24), v31, v32, v33);
        *(_DWORD *)(v7 + 24) = v34;
      }
      *(_DWORD *)(v7 + 212) = v8;
      v8 = 0;
      *(_DWORD *)(v7 + 244) = *(_DWORD *)(v7 + 244) & 0xFFFFF7FF | 0x1C000;
      v10 = 0;
      goto LABEL_37;
    }
  }
  v10 = -1073741670;
LABEL_36:
  v12 = 0;
LABEL_37:
  if ( v12 )
  {
    v35 = (unsigned int *)(v7 + 208);
    __dmb(0xBu);
    do
      v36 = __ldrex(v35);
    while ( __strex(v36 - 1, v35) );
    if ( (v36 & 2) != 0 && (v36 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v7 + 208));
    KeAbPostRelease(v7 + 208);
  }
  if ( v8 )
  {
    if ( v40 )
      MmUnlockPages(v8[4]);
    v37 = v8[4];
    if ( v37 )
      IoFreeMdl(v37);
    if ( v41 )
      AlpcpUnregisterCompletionListDatabase(v8);
    ExFreePoolWithTag((unsigned int)v8);
  }
  return v10;
}
