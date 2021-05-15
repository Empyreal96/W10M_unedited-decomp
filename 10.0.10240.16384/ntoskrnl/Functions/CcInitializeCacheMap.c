// CcInitializeCacheMap 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcInitializeCacheMap(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r10
  _BYTE *v7; // r9
  unsigned int v8; // r3
  int *v9; // r1
  __int64 v10; // r4
  int v11; // r6
  int v12; // r7
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r5
  int v17; // r7
  int v18; // r2
  _BYTE *v19; // r0
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r0
  int v25; // r7
  __int64 v26; // r0
  _BYTE *v27; // r4
  int result; // r0
  int v29; // r2
  unsigned int v30; // r2
  int v31; // r3
  int v32; // r3
  int v33; // r0
  int v34; // r6
  int v35; // r0
  int v36; // r1
  int v37; // r2
  int v38; // r7
  int v39; // r0
  int v40; // r5
  int v41; // r0
  int v42; // r10
  unsigned int v43; // r0
  int *v44; // r0
  int v45; // r2
  int v46; // r5
  int v47; // r0
  int v48; // r3
  int v49; // r3
  _QWORD *v50; // r2
  __int64 v51; // r0
  __int64 v52; // r0
  int v53; // r3
  _DWORD *v54; // r3
  int v55; // r1
  int v56; // r0
  int v57; // r0
  int v58; // r5
  int v59; // r0
  int v60; // r3
  int v61; // r0
  _DWORD *v62; // r2
  __int64 v63; // r0
  void **v64; // r0
  unsigned int v65; // r3
  unsigned int v66; // r3
  int v67; // [sp+8h] [bp-60h]
  int v68; // [sp+Ch] [bp-5Ch]
  int v69; // [sp+10h] [bp-58h]
  int v70; // [sp+14h] [bp-54h]
  int v71; // [sp+18h] [bp-50h]
  int v72; // [sp+1Ch] [bp-4Ch]
  _DWORD *v73; // [sp+20h] [bp-48h]
  int v74; // [sp+24h] [bp-44h]
  __int64 v77; // [sp+30h] [bp-38h] BYREF
  int v78; // [sp+38h] [bp-30h]
  int v79; // [sp+3Ch] [bp-2Ch]
  int v80; // [sp+40h] [bp-28h]
  int v81; // [sp+44h] [bp-24h]

  v69 = 0;
  v70 = 0;
  v72 = 0;
  v5 = 0;
  v67 = 0;
  v7 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_QWORD *)a2;
  v11 = *(_DWORD *)(a2 + 8);
  v12 = *(_DWORD *)(a2 + 12);
  v9 = (int *)(a2 + 16);
  v77 = v10;
  v78 = v11;
  v79 = v12;
  HIDWORD(v10) = v9[1];
  v73 = (_DWORD *)v8;
  v13 = *(_DWORD *)(v8 + 116);
  v80 = *v9;
  v81 = HIDWORD(v10);
  v14 = v77;
  v68 = 0;
  v74 = v13;
  if ( !v77 )
    v14 = 1;
  if ( (v73[19] & 0x400) == 0 )
    v5 = 1;
  if ( *(_BYTE *)(a1 + 39) )
  {
    v71 = (__PAIR64__(HIDWORD(v77), v14) + 0xFFFFF) >> 32;
    HIDWORD(v77) = v71;
    v15 = (v14 + 0xFFFFF) & 0xFFF00000;
  }
  else
  {
    v71 = (__PAIR64__(HIDWORD(v77), v14) + 0x3FFFF) >> 32;
    HIDWORD(v77) = v71;
    v15 = (v14 + 0x3FFFF) & 0xFFFC0000;
  }
  v17 = v81;
  v18 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  LODWORD(v77) = v15;
  if ( !v18 )
  {
    v19 = (_BYTE *)ExAllocatePoolWithTag(512, 376, 1666409283);
    v7 = v19;
    if ( !v19 )
      RtlRaiseStatus(-1073741670);
    memset(v19, 0, 376);
    *(_WORD *)v7 = 767;
    v20 = v78;
    *((_WORD *)v7 + 1) = 376;
    *((_DWORD *)v7 + 17) = a1;
    *((_DWORD *)v7 + 2) = v20;
    v21 = v79;
    *((_DWORD *)v7 + 9) = v17;
    *((_DWORD *)v7 + 11) = v17;
    *((_DWORD *)v7 + 3) = v21;
    v22 = v80;
    *((_DWORD *)v7 + 8) = v80;
    *((_DWORD *)v7 + 10) = v22;
    *((_DWORD *)v7 + 90) = *(_DWORD *)(v74 + 408);
    v68 = CcInitializeVolumeCacheMap(a1, (int **)v7 + 89);
    if ( v68 < 0 )
      RtlRaiseStatus(-1073741670);
    *((_DWORD *)v7 + 45) = 1;
    *((_DWORD *)v7 + 46) = 0;
    *((_DWORD *)v7 + 47) = 0;
    v7[192] = 1;
    v7[193] = 0;
    v7[194] = 4;
    *((_DWORD *)v7 + 49) = 0;
    *((_DWORD *)v7 + 50) = v7 + 200;
    *((_DWORD *)v7 + 51) = v7 + 200;
    *((_DWORD *)v7 + 18) = 0;
    if ( a3 )
      *((_DWORD *)v7 + 24) |= 4u;
    if ( (*(_DWORD *)(a1 + 44) & 0x20) != 0 )
      *((_DWORD *)v7 + 24) |= 0x40u;
    if ( v5 )
      *((_DWORD *)v7 + 24) |= 0x200000u;
    *((_DWORD *)v7 + 4) = v7 + 16;
    *((_DWORD *)v7 + 5) = v7 + 16;
    v23 = a4;
    *((_QWORD *)v7 + 17) = *(_QWORD *)(&a5 - 1);
    *((_DWORD *)v7 + 36) = v7 + 144;
    *((_DWORD *)v7 + 37) = v7 + 144;
  }
  v24 = KeAcquireQueuedSpinLock(5);
  v25 = v24;
  if ( !*(_DWORD *)(a1 + 24) )
  {
    LODWORD(v26) = &CcCleanSharedCacheMapList;
    v27 = *(_BYTE **)(*(_DWORD *)(a1 + 20) + 4);
    if ( v27 )
    {
      if ( (*(_DWORD *)(a1 + 44) & 0x20) == 0 )
        *((_DWORD *)v27 + 24) &= 0xFFFFFFBF;
      v48 = *((_DWORD *)v27 + 24);
      if ( (v48 & 0x200000) != 0 && !v5 )
        *((_DWORD *)v27 + 24) = v48 & 0xFFDFFFFF;
      v49 = *(_DWORD *)(v74 + 408);
      if ( v49 )
        *((_DWORD *)v27 + 90) = v49;
    }
    else
    {
      if ( !v7 )
        return sub_53C764(&CcCleanSharedCacheMapList);
      HIDWORD(v26) = dword_63260C;
      v27 = v7;
      v29 = (int)(v7 + 88);
      *((_QWORD *)v7 + 11) = v26;
      v7 = 0;
      if ( *(_UNKNOWN **)HIDWORD(v26) != &CcCleanSharedCacheMapList )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v26) = v29;
      v72 = 1;
      dword_63260C = v29;
      *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4) = v27;
      ObfReferenceObjectWithTag(a1);
    }
    if ( KdDebuggerEnabled && !KdDebuggerNotPresent && (*((_DWORD *)v27 + 24) & 0x80000) != 0 )
    {
      DbgPrint("CC: Reusing shared cache map that is already marked for deletion!\n");
      __debugbreak();
    }
    if ( (*(_DWORD *)(a1 + 44) & 0x100000) != 0 )
      *((_DWORD *)v27 + 24) = (*((_DWORD *)v27 + 24) | 0x1000) & 0xFFDFFFFF;
    v30 = *((_DWORD *)v27 + 24) & 0xFFFFFFEF;
    v31 = *((_DWORD *)v27 + 16);
    *((_DWORD *)v27 + 24) = v30;
    if ( !v31 && (v30 & 0x100) == 0 )
    {
      ++*((_DWORD *)v27 + 1);
      *((_DWORD *)v27 + 24) = v30 | 0x100;
      v32 = *((_DWORD *)v27 + 28);
      if ( v32 )
      {
        *(_BYTE *)v32 = 0;
        *(_BYTE *)(v32 + 1) = 0;
        *(_BYTE *)(v32 + 2) = 4;
        *(_DWORD *)(v32 + 4) = 0;
        v54 = (_DWORD *)(v32 + 8);
        *v54 = v54;
        v54[1] = v54;
      }
      KeReleaseQueuedSpinLock(5, v25);
      v33 = *((_DWORD *)v27 + 27);
      v34 = 0;
      v69 = 1;
      v70 = 1;
      if ( v33 )
      {
        v55 = v71;
        if ( __SPAIR64__(v71, v15) > *((_QWORD *)v27 + 3) )
        {
          v56 = MmExtendSection(v33, &v77, 1);
          if ( v56 < 0 )
          {
            v38 = FsRtlNormalizeNtstatus(v56, -1073741588);
            goto LABEL_101;
          }
          v55 = HIDWORD(v77);
          v15 = v77;
        }
        v38 = CcExtendVacbArray(v27, v55, __SPAIR64__(v55, v15));
        v68 = v38;
        if ( v38 >= 0 )
        {
LABEL_38:
          v25 = KeAcquireQueuedSpinLock(5);
          v39 = *((_DWORD *)v27 + 28);
          *((_DWORD *)v27 + 24) &= 0xFFFFFEFF;
          if ( v39 )
            KeSetEvent(v39, 0, 0);
          KeReleaseQueuedSpinLock(5, v25);
          v70 = 0;
          goto LABEL_41;
        }
      }
      else
      {
        v35 = MmCreateCacheManagerSection(v27 + 108, &v77);
        *((_DWORD *)v27 + 25) = v35;
        if ( v35 < 0 )
        {
          *((_DWORD *)v27 + 27) = 0;
          v38 = FsRtlNormalizeNtstatus(v35, -1073741590);
        }
        else
        {
          ObDeleteCapturedInsertInfo(*((_DWORD *)v27 + 27));
          if ( (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 6) & 1) == 0 && !*(_DWORD *)(a1 + 16) )
          {
            MmDisableModifiedWriteOfSection(*(_DWORD *)(a1 + 20), v36, v37, 0);
            v47 = KeAcquireQueuedSpinLock(5);
            *((_DWORD *)v27 + 24) |= 0x200u;
            KeReleaseQueuedSpinLock(5, v47);
          }
          v38 = CcCreateVacbArray(v27, v36, v77, HIDWORD(v77));
          v68 = v38;
          if ( v38 >= 0 )
            goto LABEL_38;
        }
      }
LABEL_101:
      v58 = KeAcquireQueuedSpinLock(5);
      if ( v70 )
      {
        v59 = *((_DWORD *)v27 + 28);
        if ( v59 )
          KeSetEvent(v59, 0, 0);
        *((_DWORD *)v27 + 24) &= 0xFFFFFEFF;
      }
      v60 = *((_DWORD *)v27 + 1) - 1;
      *((_DWORD *)v27 + 1) = v60;
      if ( v60 || (*((_DWORD *)v27 + 24) & 0x20) != 0 || *((_DWORD *)v27 + 19) )
      {
        result = KeReleaseQueuedSpinLock(5, v58);
        v42 = 0;
      }
      else
      {
        result = CcDeleteSharedCacheMap(v27, v58, 0, 0);
        v42 = 0;
      }
      goto LABEL_56;
    }
    if ( (v30 & 0x100) != 0 )
    {
      if ( !*((_DWORD *)v27 + 28) )
      {
        v57 = ExAllocatePoolWithTag(512, 16, 1984258883);
        *((_DWORD *)v27 + 28) = v57;
        if ( !v57 )
        {
          KeReleaseQueuedSpinLock(5, v25);
          v34 = 0;
LABEL_99:
          v68 = -1073741670;
          if ( !v69 )
          {
            v42 = 0;
LABEL_50:
            if ( !v34 )
              v25 = KeAcquireQueuedSpinLock(5);
            if ( !v72 && !*((_DWORD *)v27 + 19) && *((_DWORD *)v27 + 1) )
            {
              if ( (*((_DWORD *)v27 + 24) & 0x3000000) != 0 )
              {
                v62 = v27 + 80;
                v63 = *((_QWORD *)v27 + 10);
                if ( *(_BYTE **)(v63 + 4) != v27 + 80 || *(_DWORD **)HIDWORD(v63) != v62 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v63) = v63;
                *(_DWORD *)(v63 + 4) = HIDWORD(v63);
                v64 = (void **)dword_632604;
                *v62 = &CcCleanSharedCacheMapWithLogHandleList;
                *((_DWORD *)v27 + 21) = v64;
                if ( *v64 != &CcCleanSharedCacheMapWithLogHandleList )
                  __fastfail(3u);
                *v64 = v62;
                dword_632604 = (int)(v27 + 80);
              }
              v50 = v27 + 88;
              v51 = *((_QWORD *)v27 + 11);
              if ( *(_BYTE **)(v51 + 4) != v27 + 88 || *(_QWORD **)HIDWORD(v51) != v50 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v51) = v51;
              *(_DWORD *)(v51 + 4) = HIDWORD(v51);
              LODWORD(v52) = &CcCleanSharedCacheMapList;
              HIDWORD(v52) = dword_63260C;
              *v50 = v52;
              if ( *(_UNKNOWN **)HIDWORD(v52) != &CcCleanSharedCacheMapList )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v52) = v50;
              dword_63260C = (int)(v27 + 88);
            }
            v46 = *((_DWORD *)v27 + 44);
            if ( v46 )
            {
              do
              {
                v65 = v46 & 0xFFFFFFFE;
                v46 = *(_DWORD *)(v46 & 0xFFFFFFFE);
                KeSetEvent(v65 + 4, 0, 0);
              }
              while ( v46 );
              v42 = v67;
            }
            *((_DWORD *)v27 + 44) = 0;
            *((_DWORD *)v27 + 24) &= 0xFFFEFFFF;
LABEL_55:
            result = KeReleaseQueuedSpinLock(5, v25);
            v38 = v68;
LABEL_56:
            if ( v7 )
              result = ExFreePoolWithTag(v7, 1666409283);
            if ( v42 )
              result = ExFreePoolWithTag(v42, 1666212675);
            if ( v38 < 0 )
              RtlRaiseStatus(v38);
            return result;
          }
          v38 = -1073741670;
          goto LABEL_101;
        }
        *(_BYTE *)v57 = 0;
        *(_BYTE *)(v57 + 1) = 0;
        *(_DWORD *)(v57 + 4) = 0;
        *(_BYTE *)(v57 + 2) = 4;
        *(_DWORD *)(v57 + 8) = v57 + 8;
        *(_DWORD *)(v57 + 12) = v57 + 8;
      }
      ++*((_DWORD *)v27 + 1);
      KeReleaseQueuedSpinLock(5, v25);
      v69 = 1;
      v34 = 0;
      KeWaitForSingleObject(*((_DWORD *)v27 + 28), 0, 0, 0, 0);
      v61 = *((_DWORD *)v27 + 25);
      if ( v61 < 0 )
      {
        v38 = FsRtlNormalizeNtstatus(v61, -1073741590);
        goto LABEL_101;
      }
    }
    else
    {
      ++*((_DWORD *)v27 + 1);
      KeReleaseQueuedSpinLock(5, v25);
      v34 = 0;
      v69 = 1;
    }
LABEL_41:
    if ( v7 )
    {
      ExFreePoolWithTag(v7, 1666409283);
      v7 = 0;
    }
    v40 = (int)(v27 + 248);
    if ( *((_WORD *)v27 + 124) )
      goto LABEL_81;
    while ( 1 )
    {
      v34 = 1;
      v41 = KeAcquireQueuedSpinLock(5);
      v25 = v41;
      if ( *(_DWORD *)(a1 + 24) )
        break;
      if ( !*(_WORD *)v40 )
      {
        v42 = v67;
        goto LABEL_47;
      }
      v53 = v67;
      if ( v67 )
      {
        v42 = 0;
        v67 = 0;
        v40 = v53;
LABEL_47:
        memset((_BYTE *)v40, 0, 104);
        *(_DWORD *)(v40 + 4) = 4095;
        *(_DWORD *)(v40 + 8) = a1;
        *(_WORD *)v40 = 766;
        v43 = (v73[240] >> 12) & 7;
        if ( (*(_DWORD *)(v73[84] + 192) & 0x100000) != 0 && v43 >= 2 )
          v43 = 2;
        *(_DWORD *)v40 ^= (*(_DWORD *)v40 ^ (v43 << 18)) & 0x1C0000;
        *(_DWORD *)(v40 + 80) = 0;
        v44 = (int *)*((_DWORD *)v27 + 37);
        v45 = v40 + 92;
        *(_DWORD *)(v40 + 92) = v27 + 144;
        *(_DWORD *)(v40 + 96) = v44;
        if ( (_BYTE *)*v44 != v27 + 144 )
          __fastfail(3u);
        *v44 = v45;
        *((_DWORD *)v27 + 37) = v45;
        *(_DWORD *)(a1 + 24) = v40;
        goto LABEL_50;
      }
      KeReleaseQueuedSpinLock(5, v41);
      v34 = 0;
LABEL_81:
      v67 = ExAllocatePoolWithTag(512, 104, 1666212675);
      if ( !v67 )
        goto LABEL_99;
    }
    v66 = *((_DWORD *)v27 + 1);
    if ( v66 <= 1 )
      KeBugCheckEx(52, 1935, -1073740768);
    v42 = v67;
    *((_DWORD *)v27 + 1) = v66 - 1;
    goto LABEL_55;
  }
  result = KeReleaseQueuedSpinLock(5, v24);
  if ( v7 )
    result = ExFreePoolWithTag(v7, 1666409283);
  return result;
}
