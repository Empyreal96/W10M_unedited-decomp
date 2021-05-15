// MiInsertSharedCommitNode 
 
int __fastcall MiInsertSharedCommitNode(_DWORD *a1, int a2, int a3)
{
  int v5; // r7
  _DWORD *v7; // r6
  unsigned int v8; // r8
  unsigned __int8 *v9; // r9
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  unsigned __int8 *v13; // r9
  int v14; // r0
  int v15; // r5
  unsigned int v16; // r2
  int v17; // r9
  int v18; // r5
  int v19; // r3
  _DWORD *v20; // r0
  _DWORD *v21; // lr
  int v22; // r9
  unsigned int *v23; // r4
  unsigned int v24; // r1
  int v25; // r0
  int v26; // r3
  unsigned int *v27; // r4
  unsigned int v28; // r1
  int v29; // r0
  int v30; // r3
  int v31; // r2
  unsigned int v32; // r4
  int v33; // r3
  int v34; // r0
  _DWORD *v35; // r4
  _DWORD *v36; // r0
  int v37; // r0
  unsigned int *v38; // r5
  unsigned int v39; // r6
  _DWORD *v40; // [sp+0h] [bp-68h]
  int v41; // [sp+4h] [bp-64h]
  _DWORD *v43; // [sp+14h] [bp-54h]
  char v44[12]; // [sp+20h] [bp-48h] BYREF
  int v45; // [sp+2Ch] [bp-3Ch]

  if ( !MiIncludeSharedCommit((int)a1) || (a1[7] & 0x20) != 0 )
    return 0;
  v5 = 0;
  if ( (a2 & 1) == 0 )
  {
    v40 = (_DWORD *)a2;
    if ( (*(_DWORD *)(a2 + 736) & 0x40) == 0 )
    {
      v7 = (_DWORD *)*a1;
      v45 = a2;
      v43 = v7;
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( (a3 & 1) == 0 )
      {
        --*(_WORD *)(v8 + 310);
        v9 = (unsigned __int8 *)(a2 + 868);
        v10 = KeAbPreAcquire(a2 + 868, 0, 0);
        v11 = v10;
        do
          v12 = __ldrex(v9);
        while ( __strex(v12 | 1, v9) );
        __dmb(0xBu);
        if ( (v12 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v9, v10, (unsigned int)v9);
        if ( v11 )
          *(_BYTE *)(v11 + 14) |= 1u;
      }
      if ( (a3 & 2) == 0 )
      {
        --*(_WORD *)(v8 + 310);
        v13 = (unsigned __int8 *)(v7 + 7);
        v14 = KeAbPreAcquire((unsigned int)(v7 + 7), 0, 0);
        v15 = v14;
        do
          v16 = __ldrex(v13);
        while ( __strex(v16 | 1, v13) );
        __dmb(0xBu);
        if ( (v16 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v7 + 7, v14, (unsigned int)(v7 + 7));
        if ( v15 )
          *(_BYTE *)(v15 + 14) |= 1u;
      }
      v17 = v7[12];
      v18 = 0;
      v41 = 0;
      if ( v17 )
      {
        while ( 1 )
        {
          v34 = MiSharedCommitCompare((int)v44, v17);
          if ( v34 <= 0 )
          {
            if ( v34 >= 0 )
            {
              ++*(_QWORD *)(v17 + 16);
              goto LABEL_29;
            }
            v19 = *(_DWORD *)v17;
            if ( !*(_DWORD *)v17 )
            {
              v18 = 0;
LABEL_26:
              v41 = v18;
              break;
            }
          }
          else
          {
            v19 = *(_DWORD *)(v17 + 4);
            if ( !v19 )
            {
              v18 = 1;
              goto LABEL_26;
            }
          }
          v17 = v19;
        }
      }
      v20 = (_DWORD *)ExAllocatePoolWithTag(1, 40, 1850960205);
      v21 = v20;
      if ( !v20 )
      {
        v5 = -1073741670;
        goto LABEL_29;
      }
      v20[3] = a2;
      v20[4] = 1;
      v20[5] = 0;
      if ( a2 )
      {
        v20[8] = a1;
        v35 = *(_DWORD **)(a2 + 876);
        v36 = v20 + 6;
        v21[6] = v40 + 218;
        v21[7] = v35;
        if ( (_DWORD *)*v35 != v40 + 218 )
          __fastfail(3u);
        *v35 = v36;
        v40[219] = v36;
        v37 = v7[3];
        v38 = v40 + 216;
        do
          v39 = __ldrex(v38);
        while ( __strex(v39 + v37, v38) );
        v18 = v41;
        v7 = v43;
      }
      else
      {
        v31 = v7[3];
        do
          v32 = __ldrex((unsigned int *)0x2F4);
        while ( __strex(v32 + v31, (unsigned int *)0x2F4) );
      }
      RtlAvlInsertNodeEx((int)(v7 + 12), v17, v18, v21);
      if ( v40
        && (v40[184] & 0x20) != 0
        && (v33 = v40[72], __dmb(0xBu), v5 = MiInsertSharedCommitNode(a1, v33 | 1, 3), v5 < 0) )
      {
        v22 = 1;
      }
      else
      {
LABEL_29:
        v22 = 0;
      }
      if ( (a3 & 2) == 0 )
      {
        v23 = v7 + 7;
        __dmb(0xBu);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 - 1, v23) );
        if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
          ExfTryToWakePushLock(v23);
        v25 = KeAbPostRelease((unsigned int)v23);
        v26 = (__int16)(*(_WORD *)(v8 + 310) + 1);
        *(_WORD *)(v8 + 310) = v26;
        if ( !v26 && *(_DWORD *)(v8 + 100) != v8 + 100 )
          KiCheckForKernelApcDelivery(v25);
      }
      if ( (a3 & 1) == 0 )
      {
        v27 = v40 + 217;
        __dmb(0xBu);
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 - 1, v27) );
        if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
          ExfTryToWakePushLock(v40 + 217);
        v29 = KeAbPostRelease((unsigned int)(v40 + 217));
        v30 = (__int16)(*(_WORD *)(v8 + 310) + 1);
        *(_WORD *)(v8 + 310) = v30;
        if ( !v30 && *(_DWORD *)(v8 + 100) != v8 + 100 )
          KiCheckForKernelApcDelivery(v29);
      }
      if ( v22 == 1 )
        MiRemoveSharedCommitNode(a1, v40, a3);
      return v5;
    }
    return 0;
  }
  return sub_802180();
}
