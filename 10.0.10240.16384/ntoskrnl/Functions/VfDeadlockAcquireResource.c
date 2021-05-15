// VfDeadlockAcquireResource 
 
_DWORD *__fastcall VfDeadlockAcquireResource(_DWORD *result, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r4
  int v8; // r10
  int v9; // r3
  int v10; // r1
  int v11; // r7
  int v12; // r6
  unsigned int v13; // r0
  int v14; // r3
  _DWORD *v15; // r5
  int v16; // r6
  __int64 v17; // kr00_8
  int v18; // r2
  __int64 v19; // kr08_8
  _DWORD *v20; // r4
  int v21; // r5
  int v22; // r3
  int v23; // r4
  int v24; // r3
  __int16 v25; // r3
  unsigned __int16 v26; // r3
  _DWORD *v27; // r9
  int v28; // r1
  _DWORD *v29; // r6
  _DWORD *v30; // r9
  int v31; // r3
  int v32; // r3
  int v33; // r1
  int v34; // r3
  char v35; // r2
  _DWORD *v36; // r1
  int v37; // r0
  int v38; // r0
  _DWORD *v39; // r1
  unsigned __int16 v40; // r3
  int v41; // r3
  _DWORD *v42; // r3
  _DWORD *v43; // r4
  int v44; // r0
  int v45; // r1
  int v46; // r2
  int v47; // r3
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r1
  int v52; // r2
  int v53; // r3
  int v54; // r1
  int v55; // r2
  int v56; // r3
  unsigned int *v57; // r5
  int v58; // r1
  int v59; // r2
  int v60; // r3
  int v61; // r1
  int v62; // r2
  int v63; // r3
  int v64; // [sp+8h] [bp-78h]
  _DWORD *v65; // [sp+Ch] [bp-74h] BYREF
  int v66; // [sp+10h] [bp-70h]
  _DWORD *v67; // [sp+14h] [bp-6Ch]
  _DWORD *v68; // [sp+18h] [bp-68h]
  int v69; // [sp+1Ch] [bp-64h]
  int v70; // [sp+20h] [bp-60h]
  _DWORD *v71; // [sp+24h] [bp-5Ch] BYREF
  unsigned int v72; // [sp+28h] [bp-58h]
  unsigned int v73; // [sp+2Ch] [bp-54h]
  __int64 v74; // [sp+30h] [bp-50h] BYREF
  __int64 v75; // [sp+38h] [bp-48h] BYREF
  unsigned int v76; // [sp+40h] [bp-40h] BYREF
  int v77; // [sp+44h] [bp-3Ch]
  int v78; // [sp+48h] [bp-38h]
  int v79; // [sp+4Ch] [bp-34h]
  unsigned int v80; // [sp+50h] [bp-30h]
  int v81; // [sp+54h] [bp-2Ch]
  int v82; // [sp+58h] [bp-28h]
  int v83; // [sp+5Ch] [bp-24h]

  v66 = a4;
  v5 = 0;
  v73 = a5;
  v8 = (int)result;
  v70 = 0;
  v71 = 0;
  v65 = 0;
  if ( a2 == 8 && (!VfWin32kDllBase || VfWin32kDllBase > a5 || VfWin32kSizeOfImage + VfWin32kDllBase <= a5) )
    return result;
  result = (_DWORD *)ViDeadlockCanProceed(result, a2);
  if ( !result )
    return result;
  result = (_DWORD *)ViIsThreadInsidePagingCodePaths();
  if ( result )
    return result;
  v9 = *(_DWORD *)(ViDeadlockGlobals + 16400);
  __dmb(0xBu);
  if ( v9 )
    return result;
  v10 = ViDeadlockChildrenCountMaximum;
  __dmb(0xBu);
  if ( *(_DWORD *)(ViDeadlockGlobals + 16604) > v10 )
    return result;
  v67 = 0;
  v11 = 0;
  v12 = ViDeadlockResourceTypeInfo[a2];
  v69 = ViDeadlockAllocate(3);
  v68 = (_DWORD *)ViDeadlockAllocate(2);
  v64 = ViDeadlockAllocate(1);
  v13 = RtlCaptureStackBackTrace(2u, 8u, (int)&v76, 0);
  if ( !v13 )
  {
    v76 = a5;
    v13 = 1;
  }
  if ( v13 < 8 )
    *(&v76 + v13) = 0;
  v72 = ViRaiseIrqlToDpcLevel(v13);
  ViDeadlockDetectionLock(1);
  KeQueryTickCount((int *)&v74);
  v14 = ViDeadlockDetectionEnabled;
  __dmb(0xBu);
  if ( !v14 )
    goto LABEL_20;
  v67 = v68;
  v68 = 0;
  if ( !v67 )
    goto LABEL_20;
  v11 = ViDeadlockSearchThread(a3);
  if ( !v11 )
  {
    v11 = ViDeadlockAddThread(a3, v69);
    v69 = 0;
    if ( !v11 )
    {
LABEL_20:
      v15 = (_DWORD *)v64;
LABEL_21:
      v16 = 0;
      goto LABEL_22;
    }
    v5 = 1;
  }
  if ( a2 == 8 )
  {
    *(_BYTE *)(v11 + 28) = 1;
    goto LABEL_20;
  }
  v21 = ViDeadlockSearchResource(v8, &v65);
  if ( v21 )
  {
LABEL_44:
    v22 = *(_DWORD *)v21;
    if ( *(_DWORD *)v21 != a2 )
    {
      if ( (a2 != 3 && a2 != 4 || v22 != 3 && v22 != 4) && (v22 != 7 || a2 != 6 && a2 != 5) )
      {
        ViDeadlockPreprocessOptions(
          &dword_6187EC,
          "Acquiring lock 0x%p using mismatched API for this lock type.",
          (const void *)0x1008);
        VfReportIssueWithOptions(196, 4104, v8, *(_DWORD *)v21, a2, &dword_6187EC);
        goto LABEL_20;
      }
      *(_DWORD *)v21 = a2;
    }
    if ( a2 == 5 || a2 == 6 )
      v23 = *(_DWORD *)(v11 + 4);
    else
      v23 = *(_DWORD *)(v11 + 8);
    v24 = *(_DWORD *)(v21 + 12);
    if ( v24 && v24 != v11 )
      *(_WORD *)(v21 + 6) = 0;
    v25 = *(_WORD *)(v21 + 6);
    *(_DWORD *)(v21 + 12) = v11;
    v26 = v25 + 1;
    *(_WORD *)(v21 + 6) = v26;
    if ( v23 )
    {
      if ( v26 > 1u )
      {
        if ( (v12 & 1) == 0 )
        {
          ViDeadlockPreprocessOptions(
            &dword_6187E0,
            "Lock 0x%p doesn't support recursive acquire.",
            (const void *)0x1000);
          VfReportIssueWithOptions(196, 4096, v8, v21, v11, &dword_6187E0);
        }
        goto LABEL_20;
      }
      v27 = *(_DWORD **)(v23 + 4);
      v28 = v66;
      while ( v27 != (_DWORD *)(v23 + 4) )
      {
        v29 = v27 - 3;
        v27 = (_DWORD *)*v27;
        if ( ViDeadlockSimilarNode(v8, v28, v29) )
        {
          ViDeadlockCheckDuplicatesAmongChildren(v23, v29, &v65);
          goto LABEL_89;
        }
      }
      if ( *(_WORD *)(v21 + 4) && !v28 && ViDeadlockAnalyze(v8, v23, 1, 0, v73) )
        goto LABEL_20;
LABEL_80:
      v29 = v67;
      v67[8] = 0;
      v29[9] = 0;
      v29[11] = 0;
      v29[19] = 0;
      v67 = 0;
      v32 = v29[9];
      v29[10] = 0;
      v32 &= 0xFFFFFFFE;
      v29[9] = v32;
      v33 = v32 & 7;
      v34 = ViDeadlockGlobals;
      *v29 = v23;
      v29[7] = v21;
      v35 = v66;
      v29[9] = v33 | (8 * *(_DWORD *)(v34 + 16420));
      v36 = v29 + 3;
      v29[1] = v29 + 1;
      v29[2] = v29 + 1;
      v29[3] = v29 + 3;
      v29[4] = v29 + 3;
      v29[9] ^= ((unsigned __int8)v29[9] ^ (unsigned __int8)(2 * v35)) & 2;
      if ( !v70 )
      {
        v37 = *(_DWORD *)(v23 + 4);
        *v36 = v37;
        v29[4] = v23 + 4;
        if ( *(_DWORD *)(v37 + 4) != v23 + 4 )
          __fastfail(3u);
        *(_DWORD *)(v37 + 4) = v36;
        *(_DWORD *)(v23 + 4) = v36;
        ViDeadlockUpdateChildrenCount(v23, 1);
      }
      v38 = *(_DWORD *)(v21 + 16);
      v39 = v29 + 5;
      v29[5] = v38;
      v29[6] = v21 + 16;
      if ( *(_DWORD *)(v38 + 4) != v21 + 16 )
        __fastfail(3u);
      *(_DWORD *)(v38 + 4) = v39;
      *(_DWORD *)(v21 + 16) = v39;
      v40 = *(_DWORD *)(v21 + 4) + 1;
      *(_WORD *)(v21 + 4) = v40;
      if ( v40 > 0xFFF0u )
        ViDeadlockState |= 0x20u;
    }
    else
    {
      v30 = *(_DWORD **)(v21 + 16);
      do
      {
        if ( v30 == (_DWORD *)(v21 + 16) )
        {
          v70 = 1;
          goto LABEL_80;
        }
        v29 = v30 - 5;
        v31 = *(v30 - 5);
        v30 = (_DWORD *)*v30;
      }
      while ( v31 || !ViDeadlockSimilarNode(v8, v66, v29) );
      ViDeadlockCheckDuplicatesAmongRoots(v29, &v65);
    }
LABEL_89:
    if ( v29 )
    {
      v41 = v29[9];
      v29[8] = v11;
      v29[9] = v41 | 1;
      if ( a2 == 5 || a2 == 6 )
        *(_DWORD *)(v11 + 4) = v29;
      else
        *(_DWORD *)(v11 + 8) = v29;
      ++*(_DWORD *)(v11 + 20);
      v42 = (_DWORD *)*v29;
      if ( *v29 )
      {
        v43 = v42 + 11;
        v44 = v42[11];
        v45 = v42[12];
        v46 = v42[13];
        v47 = v42[14];
        v43 += 4;
        v29[19] = v44;
        v29[20] = v45;
        v29[21] = v46;
        v29[22] = v47;
        v48 = v43[1];
        v49 = v43[2];
        v50 = v43[3];
        v29[23] = *v43;
        v29[24] = v48;
        v29[25] = v49;
        v29[26] = v50;
      }
      v51 = v77;
      v52 = v78;
      v53 = v79;
      v29[11] = v76;
      v29[12] = v51;
      v29[13] = v52;
      v29[14] = v53;
      v54 = v81;
      v55 = v82;
      v56 = v83;
      v29[15] = v80;
      v29[16] = v54;
      v29[17] = v55;
      v29[18] = v56;
      v57 = (unsigned int *)(v29[7] + 64);
      v58 = v77;
      v59 = v78;
      v60 = v79;
      *v57 = v76;
      v57[1] = v58;
      v57[2] = v59;
      v57[3] = v60;
      v57 += 4;
      v61 = v81;
      v62 = v82;
      v63 = v83;
      *v57 = v80;
      v57[1] = v61;
      v57[2] = v62;
      v57[3] = v63;
    }
    goto LABEL_20;
  }
  v15 = (_DWORD *)v64;
  if ( ViDeadlockAddResource(v8, a2, v64, &v76, &v71, &v65) )
  {
    v64 = 0;
    v21 = ViDeadlockSearchResource(v8, &v65);
    goto LABEL_44;
  }
  if ( !v5 )
    goto LABEL_21;
  v16 = 1;
  ViDeadlockRemoveThread(v11, 0);
LABEL_22:
  KeQueryTickCount((int *)&v75);
  v17 = v75 - v74;
  v18 = ViDeadlockGlobals;
  v19 = *(_QWORD *)ViDeadlockGlobals;
  if ( (int)((unsigned __int64)(v75 - v74) >> 32) >= *(_DWORD *)(ViDeadlockGlobals + 4)
    && ((int)((unsigned __int64)(v75 - v74) >> 32) > SHIDWORD(v19) || (unsigned int)v17 > (unsigned int)v19) )
  {
    *(_DWORD *)ViDeadlockGlobals = v17;
    *(_DWORD *)(v18 + 4) = HIDWORD(v17);
  }
  ViDeadlockDetectionUnlock(1);
  ViLowerIrql(v72);
  result = v65;
  if ( v65 )
  {
    do
    {
      v20 = (_DWORD *)*result;
      ((void (*)(void))ViDeadlockFree)();
      result = v20;
    }
    while ( v20 );
  }
  if ( v71 )
    result = (_DWORD *)ExFreeToNPagedLookasideList((int)&ViDeadlockResourceLookaside, v71);
  if ( v16 )
    result = (_DWORD *)ViDeadlockFree(v11, 3);
  if ( v67 )
    result = (_DWORD *)ViDeadlockFree(v67, 2);
  if ( v15 )
    result = (_DWORD *)ExFreeToNPagedLookasideList((int)&ViDeadlockResourceLookaside, v15);
  if ( v68 )
    result = (_DWORD *)ViDeadlockFree(v68, 2);
  if ( v69 )
    result = (_DWORD *)ViDeadlockFree(v69, 3);
  return result;
}
