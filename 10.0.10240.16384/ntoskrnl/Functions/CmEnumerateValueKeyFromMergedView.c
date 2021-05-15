// CmEnumerateValueKeyFromMergedView 
 
int __fastcall CmEnumerateValueKeyFromMergedView(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6, unsigned int a7, int *a8, unsigned int *a9)
{
  int v11; // r6
  int v12; // r4
  _DWORD *v14; // r10
  int v15; // r3
  _DWORD *v16; // r5
  _DWORD *v17; // r7
  int v18; // r3
  unsigned int *v19; // r9
  int v20; // r0
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r1
  unsigned int v24; // r8
  unsigned int v25; // r6
  int v26; // r3
  int v27; // r9
  int v28; // r6
  int v29; // r0
  int v30; // r8
  int v31; // r0
  void (__fastcall *v32)(int, int *); // r3
  int v33; // r0
  int v34; // r9
  unsigned int v35; // r2
  int v36; // r0
  unsigned int v38; // [sp+10h] [bp-68h]
  int v39; // [sp+14h] [bp-64h]
  int v41; // [sp+1Ch] [bp-5Ch] BYREF
  int v42; // [sp+20h] [bp-58h]
  int v43; // [sp+24h] [bp-54h] BYREF
  int v44; // [sp+28h] [bp-50h]
  int v45; // [sp+2Ch] [bp-4Ch] BYREF
  unsigned int *v46; // [sp+30h] [bp-48h]
  int v47; // [sp+34h] [bp-44h] BYREF
  int v48; // [sp+38h] [bp-40h] BYREF
  int v49; // [sp+3Ch] [bp-3Ch] BYREF
  int v50; // [sp+40h] [bp-38h]
  int v51; // [sp+44h] [bp-34h]
  int v52; // [sp+48h] [bp-30h]
  int v53; // [sp+4Ch] [bp-2Ch]
  __int16 v54; // [sp+50h] [bp-28h]
  int v55; // [sp+54h] [bp-24h]

  v11 = 0;
  v12 = 0;
  v47 = -1;
  v48 = -1;
  v44 = 0;
  v45 = -1;
  v49 = -1;
  v50 = a3;
  v41 = -1;
  v42 = 0;
  v43 = 0;
  v51 = 0;
  v52 = 0;
  v46 = 0;
  v14 = 0;
  v38 = 0;
  v39 = 0;
  if ( !a3 )
  {
    CmpLockRegistry();
    v11 = v43;
  }
  v15 = a1[7];
  if ( v15 || a1[8] )
  {
    v12 = CmpSearchAddTrans((int)a1, 0, 0, v15, a1[8], 0, &v43);
    if ( v12 < 0 )
    {
      if ( !a3 )
        goto LABEL_71;
      return v12;
    }
    v11 = v43;
  }
  v16 = (_DWORD *)a1[1];
  v17 = *(_DWORD **)(a2 + 4);
  if ( !v50 )
  {
    CmpLockTwoKcbsShared((unsigned int)v16, v17);
    v11 = v43;
  }
  if ( CmRmIsKCBDeleted((int)v16, v11) == 1 )
  {
    v18 = a1[6];
    goto LABEL_13;
  }
  if ( CmRmIsKCBDeleted((int)v17, v11) == 1 )
  {
    v18 = *(_DWORD *)(a2 + 24);
LABEL_13:
    if ( (v18 & 1) != 0 )
      v12 = -1073740763;
    else
      v12 = -1073741444;
    goto LABEL_69;
  }
  if ( !v11 )
    goto LABEL_25;
  if ( v16[38] == v11 )
  {
    v19 = v16 + 36;
    v46 = v16 + 36;
  }
  else
  {
    v19 = 0;
  }
  if ( v17[38] == v11 )
    v14 = v17 + 36;
  if ( !v19 )
  {
LABEL_25:
    v20 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v16[5] + 4))(v16[5], v16[6], &v47);
    v52 = v20;
    if ( !v20 )
    {
      v12 = -1073741670;
      goto LABEL_69;
    }
    v19 = (unsigned int *)(v20 + 36);
    v46 = (unsigned int *)(v20 + 36);
  }
  if ( v14 )
    goto LABEL_32;
  v21 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v17[5] + 4))(v17[5], v17[6], &v48);
  v22 = v21;
  v44 = v21;
  if ( v21 )
  {
    v14 = (_DWORD *)(v21 + 36);
LABEL_32:
    v23 = a4;
    v24 = 0;
    v25 = 0;
    while ( v25 < *v19 )
    {
      v26 = (*(int (__fastcall **)(_DWORD, unsigned int, int *))(v16[5] + 4))(v16[5], v19[1], &v45);
      v39 = v26;
      if ( !v26 )
      {
        v12 = -1073741670;
        goto LABEL_64;
      }
      v27 = *(_DWORD *)(v26 + 4 * v25);
      v28 = v16[5];
      v29 = (*(int (__fastcall **)(int, int, int *))(v28 + 4))(v28, v27, &v41);
      v30 = v29;
      if ( !v29 )
      {
        v12 = -1073741670;
LABEL_48:
        v34 = 0;
        goto LABEL_60;
      }
      v55 = v29 + 20;
      v54 = *(_WORD *)(v29 + 2);
      if ( CmpFindNameInList() && v53 == -1 )
      {
        if ( v38 == a4 )
        {
          v33 = (int)v16;
LABEL_57:
          v12 = CmpQueryKeyValueData(v33, v27, v30, a5, a6, a7, a8);
          if ( v30 )
            (*(void (__fastcall **)(int, int *))(v28 + 8))(v28, &v41);
          goto LABEL_59;
        }
        v24 = ++v38;
      }
      else
      {
        v24 = v38;
      }
      v31 = v16[5];
      v32 = *(void (__fastcall **)(int, int *))(v31 + 8);
      v25 = ++v51;
      v32(v31, &v41);
      if ( v39 )
      {
        (*(void (__fastcall **)(_DWORD, int *))(v16[5] + 8))(v16[5], &v45);
        v39 = 0;
      }
      v23 = a4;
      if ( v24 > a4 )
        goto LABEL_48;
      v19 = v46;
    }
    v35 = *v14 + v24;
    if ( v35 > v23 )
    {
      v36 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v17[5] + 4))(v17[5], v14[1], &v49);
      v34 = v36;
      v42 = v36;
      if ( !v36 )
      {
        v12 = -1073741670;
        goto LABEL_60;
      }
      v28 = v17[5];
      v27 = *(_DWORD *)(v36 + 4 * (a4 - v24));
      v30 = (*(int (__fastcall **)(int, int, int *))(v28 + 4))(v28, v27, &v41);
      if ( v30 )
      {
        v33 = (int)v17;
        goto LABEL_57;
      }
      v12 = -1073741670;
LABEL_59:
      v34 = v42;
      goto LABEL_60;
    }
    v12 = -2147483622;
    v34 = 0;
    if ( a9 )
      *a9 = v35;
LABEL_60:
    if ( v39 )
      (*(void (__fastcall **)(_DWORD, int *))(v16[5] + 8))(v16[5], &v45);
    if ( v34 )
      (*(void (__fastcall **)(_DWORD, int *))(v17[5] + 8))(v17[5], &v49);
LABEL_64:
    v22 = v44;
    goto LABEL_65;
  }
  v12 = -1073741670;
LABEL_65:
  if ( v52 )
    (*(void (__fastcall **)(_DWORD, int *))(v16[5] + 8))(v16[5], &v47);
  if ( v22 )
    (*(void (__fastcall **)(_DWORD, int *))(v17[5] + 8))(v17[5], &v48);
LABEL_69:
  if ( !v50 )
  {
    CmpUnlockTwoKcbs(v16, v17);
LABEL_71:
    CmpUnlockRegistry();
  }
  return v12;
}
