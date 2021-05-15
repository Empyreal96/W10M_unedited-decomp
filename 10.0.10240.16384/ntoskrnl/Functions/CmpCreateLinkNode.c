// CmpCreateLinkNode 
 
int CmpCreateLinkNode(int a1, int a2, int a3, ...)
{
  int v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r0
  int v9; // r5
  __int64 v10; // kr00_8
  __int16 v12; // r3
  int *v13; // r10
  int v14; // r7
  int v15; // r0
  __int16 v16; // r3
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r0
  int v20; // r4
  int v21; // r0
  int v22; // r5
  __int64 v23; // r1
  unsigned int v24; // r2
  unsigned int v26; // r7
  int v27; // r0
  int v28; // r4
  unsigned __int64 v29; // r2
  unsigned int *v30; // r4
  unsigned int v31; // r1
  int v32; // r5
  _DWORD *v33; // r4
  int v34; // r0
  int v35; // [sp+38h] [bp-98h] BYREF
  int v36; // [sp+3Ch] [bp-94h] BYREF
  __int64 v37; // [sp+40h] [bp-90h] BYREF
  int v38; // [sp+48h] [bp-88h] BYREF
  int v39; // [sp+4Ch] [bp-84h] BYREF
  int v40; // [sp+50h] [bp-80h]
  int v41; // [sp+54h] [bp-7Ch]
  int v42; // [sp+58h] [bp-78h] BYREF
  int var70[29]; // [sp+60h] [bp-70h] BYREF
  int varg_r3; // [sp+E4h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+E4h] [bp+14h]
  int v46; // [sp+E8h] [bp+18h]
  int v47; // [sp+ECh] [bp+1Ch]
  int v48; // [sp+F0h] [bp+20h]
  int v49; // [sp+F4h] [bp+24h]
  int v50; // [sp+F8h] [bp+28h]
  int v51; // [sp+FCh] [bp+2Ch]
  int v52; // [sp+100h] [bp+30h]
  int v53; // [sp+104h] [bp+34h]
  int *v54; // [sp+108h] [bp+38h]
  va_list va1; // [sp+10Ch] [bp+3Ch] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v46 = va_arg(va1, _DWORD);
  v47 = va_arg(va1, _DWORD);
  v48 = va_arg(va1, _DWORD);
  v49 = va_arg(va1, _DWORD);
  v50 = va_arg(va1, _DWORD);
  v51 = va_arg(va1, _DWORD);
  v52 = va_arg(va1, _DWORD);
  v53 = va_arg(va1, _DWORD);
  v54 = va_arg(va1, int *);
  v39 = -1;
  v40 = a3;
  v38 = -1;
  v36 = -1;
  v42 = v52;
  if ( (void *)a1 == CmpMasterHive )
  {
    if ( v53 )
      return -1073741811;
    v5 = *(_DWORD *)(a1 + 1872);
    v41 = 0;
    ExAcquireResourceSharedLite(v5, 1);
    ExAcquireResourceExclusiveLite(*(_DWORD *)(*(_DWORD *)(v49 + 36) + 1872), 1, v6, *(_DWORD *)(v49 + 36));
    v7 = *(_DWORD *)(v52 + 4);
    if ( (v7 & 0x80) != 0 )
    {
      v14 = -1073741790;
    }
    else if ( (v7 & 0x20000) != 0 )
    {
      v14 = -1073741772;
    }
    else
    {
      v8 = CmpNameSize((int *)varg_r3a);
      v9 = HvAllocateCell(a1, v8 + 76, 0, 0, 0);
      if ( v9 == -1 )
        goto LABEL_53;
      v10 = *(_QWORD *)(v49 + 32);
      if ( (_DWORD)v10 == -1 )
      {
        v13 = v54;
        v14 = CmpDoCreateChild(HIDWORD(v10), a2, 0, v40, (int *)varg_r3a, (char)v47, v49, v50, v52, 12, &v35, v54, 0);
        if ( v14 < 0 )
        {
LABEL_48:
          HvFreeCell(a1, v9);
          goto LABEL_26;
        }
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v49 + 36) + 32) + 36) = v35;
        v26 = *(_DWORD *)(*(_DWORD *)(v49 + 36) + 1868);
        LODWORD(v37) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v27 = KeAbPreAcquire(v26, 0, 0);
        v28 = v27;
        do
          LODWORD(v29) = __ldrex((unsigned __int8 *)v26);
        while ( __strex(v29 & 0xFE, (unsigned __int8 *)v26) );
        __dmb(0xBu);
        if ( (v29 & 1) == 0 )
          ExpAcquireFastMutexContended(v26, v27);
        if ( v28 )
          *(_BYTE *)(v28 + 14) |= 1u;
        HIDWORD(v29) = v37;
        *(_DWORD *)(v26 + 4) = v37;
        HvMarkBaseBlockDirty(*(_DWORD *)(v49 + 36), v29);
        v14 = HvCheckAndUpdateHiveBackupTimeStamp(*(_DWORD *)(v49 + 36));
        v30 = *(unsigned int **)(*(_DWORD *)(v49 + 36) + 1868);
        v30[1] = 0;
        __dmb(0xBu);
        do
          v31 = __ldrex(v30);
        while ( !v31 && __strex(1u, v30) );
        if ( v31 )
          ExpReleaseFastMutexContended(v30, v31);
        KeAbPostRelease((unsigned int)v30);
LABEL_12:
        if ( v14 >= 0 )
        {
          if ( !HvpMarkCellDirty(*(_DWORD *)(v49 + 36), v35, 0, 0) )
          {
            HvFreeCell(a1, v9);
            v14 = -1073741443;
LABEL_56:
            v32 = *v13;
            *(_WORD *)(*(_DWORD *)(*v13 + 4) + 4) = *(_DWORD *)(*(_DWORD *)(*v13 + 4) + 4) | 0x20;
            v33 = *(_DWORD **)(v32 + 4);
            v34 = v33[5];
            v33[1] |= 0x20000u;
            CmpRemoveKeyHash(v34, v33 + 3);
            v33[4] = -1;
            *(_DWORD *)(*(_DWORD *)(v32 + 4) + 24) = -1;
            DelistKeyBodyFromKCB(v32, 1);
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v32 + 4) + 20) + 92) |= 0x40u;
            CmpDereferenceKeyControlBlockWithLock(*(_DWORD *)(v32 + 4), 0);
            CmpUnlockAndLockKcbs(v50, *(_DWORD *)(v32 + 4), 0, 0);
            *(_DWORD *)(v32 + 4) = 0;
            *(_WORD *)(v32 + 24) |= 4u;
            ObDereferenceObjectDeferDelete(*v13);
            goto LABEL_26;
          }
          v15 = (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(v49 + 36) + 4))(
                  *(_DWORD *)(v49 + 36),
                  v35,
                  &v36);
          if ( v15 )
          {
            v16 = *(_WORD *)(v15 + 2);
            *(_DWORD *)(v15 + 16) = v9;
            *(_WORD *)(v15 + 2) = v16 | 0xC;
            (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(v49 + 36) + 8))(*(_DWORD *)(v49 + 36), &v36);
            v17 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v9, &v38);
            v18 = v17;
            if ( v17 )
            {
              *(_WORD *)v17 = 27500;
              *(_DWORD *)(v17 + 16) = a2;
              *(_WORD *)(v17 + 2) = 10;
              v19 = CmpCopyName(v17 + 76, (int *)varg_r3a);
              *(_WORD *)(v18 + 72) = v19;
              if ( v19 < (unsigned __int16)varg_r3 )
                *(_WORD *)(v18 + 2) |= 0x20u;
              KeQuerySystemTime(&v37);
              *(_QWORD *)(v18 + 4) = v37;
              *(_DWORD *)(v18 + 28) = -1;
              *(_DWORD *)(v18 + 32) = -1;
              *(_DWORD *)(v18 + 20) = 0;
              *(_DWORD *)(v18 + 24) = 0;
              *(_QWORD *)(v18 + 36) = 0xFFFFFFFF00000000ui64;
              *(_WORD *)(v18 + 74) = 0;
              *(_DWORD *)(v18 + 32) = *(_DWORD *)(v49 + 36);
              *(_DWORD *)(v18 + 28) = v35;
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v38);
              v20 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v39);
              v21 = a1;
              if ( !v20 )
                goto LABEL_55;
              if ( CmpAddSubKeyEx(a1, a2, v9, 0) )
              {
                v22 = *v13;
                CmpCleanUpSubKeyInfo(*(_DWORD *)(*(_DWORD *)(*v13 + 4) + 40));
                KeQuerySystemTime(&v37);
                v23 = v37;
                *(_QWORD *)(v20 + 4) = v37;
                *(_QWORD *)(*(_DWORD *)(*(_DWORD *)(v22 + 4) + 40) + 88) = v23;
                if ( *(unsigned __int16 *)(v20 + 52) < (unsigned int)(unsigned __int16)varg_r3 )
                {
                  *(_WORD *)(v20 + 52) = varg_r3;
                  *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v22 + 4) + 40) + 96) = varg_r3;
                }
                v24 = *(_DWORD *)(v49 + 4);
                if ( *(_DWORD *)(v20 + 56) < v24 )
                  *(_DWORD *)(v20 + 56) = v24;
                (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v39);
                if ( v41 )
                  HvResetDirtyData(*(_DWORD *)(v49 + 36));
                goto LABEL_26;
              }
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v39);
            }
          }
          v21 = a1;
LABEL_55:
          HvFreeCell(v21, v9);
          v14 = -1073741670;
          goto LABEL_56;
        }
        goto LABEL_48;
      }
      v35 = *(_DWORD *)(v49 + 32);
      if ( !*(_DWORD *)(HIDWORD(v10) + 44) )
        v41 = 1;
      if ( ((int (*)(void))HvpMarkCellDirty)() )
      {
        if ( (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(v49 + 36) + 4))(*(_DWORD *)(v49 + 36), v35, &v36) )
        {
          v12 = *(_WORD *)(HIDWORD(v10) + 2);
          *(_DWORD *)(HIDWORD(v10) + 16) = v9;
          *(_WORD *)(HIDWORD(v10) + 2) = v12 | 0xC;
          (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(v49 + 36) + 8))(*(_DWORD *)(v49 + 36), &v36);
          memmove((int)var70, v49, 0x50u);
          var70[0] &= 0xFFFFFFFE;
          v13 = v54;
          LODWORD(v37) = *(_DWORD *)(v49 + 36);
          v14 = CmpDoOpen(
                  &v37,
                  v10,
                  v40,
                  (char)v47,
                  v48,
                  var70,
                  2,
                  v50,
                  v51,
                  &v42,
                  (int *)varg_r3a,
                  *(_DWORD *)(v49 + 44),
                  0,
                  v54,
                  0,
                  0,
                  0);
          goto LABEL_12;
        }
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v38);
        HvFreeCell(a1, v9);
LABEL_53:
        v14 = -1073741670;
        goto LABEL_26;
      }
      HvFreeCell(a1, v9);
      v14 = -1073741443;
    }
LABEL_26:
    ExReleaseResourceLite(*(_DWORD *)(*(_DWORD *)(v49 + 36) + 1872));
    ExReleaseResourceLite(*(_DWORD *)(a1 + 1872));
    return v14;
  }
  return sub_7D281C();
}
