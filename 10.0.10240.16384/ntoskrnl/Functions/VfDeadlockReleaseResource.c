// VfDeadlockReleaseResource 
 
_DWORD *__fastcall VfDeadlockReleaseResource(int a1, int a2, int a3, int a4)
{
  _DWORD *result; // r0
  int v8; // r3
  int v9; // r2
  _DWORD *v10; // r8
  _DWORD *v11; // r6
  unsigned int v12; // r0
  unsigned int v13; // r7
  int v14; // r3
  int v15; // r0
  int *v16; // r7
  int v17; // r3
  __int16 v18; // r2
  int v19; // r3
  int v20; // r2
  int v21; // r5
  _DWORD *v22; // r5
  _DWORD *v23; // r1
  int v24; // r3
  unsigned int v25; // r3
  unsigned int v26; // r3
  int v27; // r3
  int *v28; // r2
  int v29; // r3
  int *v30; // r2
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r2
  int v36; // r3
  _DWORD *v37; // r4
  int v38; // [sp+0h] [bp-78h]
  _DWORD *v39; // [sp+10h] [bp-68h] BYREF
  int v40; // [sp+14h] [bp-64h]
  int v41; // [sp+18h] [bp-60h]
  int v42; // [sp+1Ch] [bp-5Ch]
  unsigned int v43; // [sp+20h] [bp-58h]
  __int64 v44; // [sp+28h] [bp-50h] BYREF
  __int64 v45; // [sp+30h] [bp-48h] BYREF
  int v46[16]; // [sp+38h] [bp-40h] BYREF

  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = a3;
  result = (_DWORD *)ViDeadlockCanProceed(a1, a2);
  if ( !result )
    return result;
  result = (_DWORD *)ViIsThreadInsidePagingCodePaths();
  if ( result )
    return result;
  v8 = *(_DWORD *)(ViDeadlockGlobals + 16400);
  __dmb(0xBu);
  if ( v8 )
    return result;
  v9 = ViDeadlockChildrenCountMaximum;
  __dmb(0xBu);
  if ( *(_DWORD *)(ViDeadlockGlobals + 16604) > v9 )
    return result;
  v10 = 0;
  v11 = 0;
  v12 = RtlCaptureStackBackTrace(2u, 8u, (int)v46, 0);
  if ( !v12 )
  {
    v46[0] = a4;
    v12 = 1;
  }
  if ( v12 < 8 )
    v46[v12] = 0;
  v13 = ViRaiseIrqlToDpcLevel(v12);
  v43 = v13;
  ViDeadlockDetectionLock(1);
  KeQueryTickCount((int *)&v44);
  v14 = ViDeadlockDetectionEnabled;
  __dmb(0xBu);
  if ( v14 )
  {
    v15 = ViDeadlockSearchResource(a1, &v39);
    v16 = (int *)v15;
    if ( !v15 )
    {
LABEL_63:
      v13 = v43;
      goto LABEL_64;
    }
    v17 = *(_DWORD *)v15;
    if ( *(_DWORD *)v15 != a2 )
    {
      if ( v17 == 7 && (a2 == 6 || a2 == 5) )
      {
        *(_DWORD *)v15 = a2;
      }
      else
      {
        if ( v17 != 1 || a2 != 2 )
        {
          ViDeadlockPreprocessOptions(
            &dword_6187E4,
            "Releasing lock 0x%p using mismatched API for this lock type.",
            (const void *)0x1009);
          VfReportIssueWithOptions(196, 4105, a1, *v16, a2, &dword_6187E4);
LABEL_62:
          v31 = v46[1];
          v32 = v46[2];
          v33 = v46[3];
          v16[24] = v46[0];
          v16[25] = v31;
          v16[26] = v32;
          v16[27] = v33;
          v34 = v46[5];
          v35 = v46[6];
          v36 = v46[7];
          v16[28] = v46[4];
          v16[29] = v34;
          v16[30] = v35;
          v16[31] = v36;
          goto LABEL_63;
        }
        if ( *(unsigned __int16 *)(v15 + 6) > 1u )
          *(_WORD *)(v15 + 6) = 1;
      }
    }
    v18 = *(_WORD *)(v15 + 6);
    if ( v18 )
    {
      v11 = *(_DWORD **)(v15 + 12);
      if ( *v11 != v42 )
        v41 = 1;
      if ( *(_DWORD *)v15 == 5 || *(_DWORD *)v15 == 6 )
        v22 = (_DWORD *)v11[1];
      else
        v22 = (_DWORD *)v11[2];
      *(_WORD *)(v15 + 6) = v18 - 1;
      if ( v18 == 1 )
      {
        v23 = (_DWORD *)ViDeadlockGlobals;
        *(_DWORD *)(v15 + 12) = 0;
        ++v23[4114];
        if ( v22[7] == v15 )
        {
          v10 = v22;
          v26 = v22[9] & 0xFFFFFFFE;
        }
        else
        {
          ++v23[4112];
          if ( (ViDeadlockResourceTypeInfo[*(_DWORD *)v22[7]] & 4) == 0 )
          {
            v24 = ViDeadlockResourceTypeInfo[*(_DWORD *)v15];
            if ( (v24 & 4) == 0 )
            {
              DbgPrintEx(93, 0, (int)"Deadlock detection: Must release resources in reverse-order\n", v24);
              DbgPrintEx(
                93,
                0,
                (int)"Resource %p acquired before resource %p -- \nCurrent thread (%p) is trying to release %p first\n",
                a1);
              ViDeadlockPreprocessOptions(
                &dword_6187DC,
                "Releasing two locks in reverse order of their acquire.",
                4099,
                a1,
                *(_DWORD *)(v22[7] + 8),
                v11,
                a1);
              VfReportIssueWithOptions(196, 4099, a1, *(_DWORD *)(v22[7] + 8), (int)v11, &dword_6187DC);
              v23 = (_DWORD *)ViDeadlockGlobals;
            }
          }
          while ( (int *)v22[7] != v16 )
          {
            v22 = (_DWORD *)*v22;
            if ( !v22 )
              goto LABEL_44;
          }
          v10 = v22;
          v25 = v22[9] & 0xFFFFFFFE;
          v22[9] = v25;
          if ( (v25 & 4) == 0 )
            ++v23[4113];
          v26 = v22[9] | 4;
        }
        v22[9] = v26;
LABEL_44:
        if ( *v16 == 5 || *v16 == 6 )
        {
          v29 = v11[1];
          while ( v29 )
          {
            v30 = (int *)v11[1];
            if ( (v30[9] & 1) != 0 && (_DWORD *)v30[8] == v11 )
              break;
            v29 = *v30;
            v11[1] = *v30;
          }
        }
        else
        {
          v27 = v11[2];
          while ( v27 )
          {
            v28 = (int *)v11[2];
            if ( (v28[9] & 1) != 0 && (_DWORD *)v28[8] == v11 )
              break;
            v27 = *v28;
            v11[2] = *v28;
          }
        }
        if ( v10 )
        {
          v10[8] = 0;
          --v11[5];
          if ( v41 )
            v10[9] |= 4u;
          if ( !v11[5] )
          {
            v40 = 1;
            ViDeadlockRemoveThread(v11, 0);
          }
        }
      }
    }
    else
    {
      v19 = *(_DWORD *)(ViDeadlockGlobals + 16400);
      __dmb(0xBu);
      if ( !v19 )
      {
        v20 = ViDeadlockChildrenCountMaximum;
        __dmb(0xBu);
        if ( *(_DWORD *)(ViDeadlockGlobals + 16604) <= v20 )
        {
          v21 = v42;
          ViDeadlockSearchThread(v42);
          ViDeadlockPreprocessOptions(
            &dword_6187D8,
            "Releasing lock 0x%p that is not owned by the current thread.",
            (const void *)0x1007);
          v38 = ViDeadlockSearchThread(v21);
          VfReportIssueWithOptions(196, 4103, a1, (int)v16, v38, &dword_6187D8);
        }
      }
    }
    goto LABEL_62;
  }
LABEL_64:
  KeQueryTickCount((int *)&v45);
  if ( v45 - v44 > *(_QWORD *)(ViDeadlockGlobals + 8) )
    *(_QWORD *)(ViDeadlockGlobals + 8) = v45 - v44;
  ViDeadlockDetectionUnlock(1);
  ViLowerIrql(v13);
  result = v39;
  if ( v39 )
  {
    do
    {
      v37 = (_DWORD *)*result;
      ViDeadlockFree(result, 2);
      result = v37;
    }
    while ( v37 );
  }
  if ( v40 )
    result = (_DWORD *)ViDeadlockFree(v11, 3);
  return result;
}
