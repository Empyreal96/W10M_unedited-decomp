// CmpFindSubKeyByNumberFromMergedView 
 
int __fastcall CmpFindSubKeyByNumberFromMergedView(int a1, int a2, unsigned int a3, int a4, _DWORD *a5, int *a6, unsigned int **a7, unsigned int *a8)
{
  unsigned int v8; // lr
  int v9; // r4
  int v10; // r6
  unsigned int *v11; // r5
  unsigned int *v12; // r7
  unsigned int v13; // r9
  int v14; // r10
  int v15; // r8
  int *v16; // r1
  int v17; // r2
  int v18; // r10
  int v19; // r3
  int v20; // r3
  int *v21; // r1
  int v22; // r2
  int v23; // r8
  int v24; // r3
  int v25; // r6
  int v26; // r0
  int v27; // r8
  int v28; // r0
  unsigned int v29; // r2
  int v33; // [sp+18h] [bp-60h]
  int v34; // [sp+1Ch] [bp-5Ch]
  int v36; // [sp+24h] [bp-54h]
  int v37; // [sp+28h] [bp-50h]
  unsigned int *v38; // [sp+2Ch] [bp-4Ch] BYREF
  unsigned int *v39; // [sp+30h] [bp-48h] BYREF
  int v40; // [sp+34h] [bp-44h]
  int v41; // [sp+38h] [bp-40h] BYREF
  int v42; // [sp+3Ch] [bp-3Ch] BYREF
  unsigned int v43; // [sp+40h] [bp-38h]
  int v44; // [sp+44h] [bp-34h] BYREF
  unsigned int v45; // [sp+48h] [bp-30h]
  int v46; // [sp+4Ch] [bp-2Ch] BYREF
  int v47; // [sp+50h] [bp-28h]
  int v48; // [sp+54h] [bp-24h]

  v48 = a4;
  v45 = 0;
  v43 = 0;
  v46 = -1;
  v47 = 0;
  v40 = 0;
  v8 = a3;
  v36 = 0;
  *a5 = 0;
  v37 = 0;
  v9 = -1073741670;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  *a6 = -1;
  v33 = 0;
  v34 = -1;
  v13 = 0;
  v44 = -1;
  v14 = -1;
  v41 = -1;
  v42 = -1;
  v15 = -1;
  v38 = 0;
  v39 = 0;
  if ( !a2 )
  {
    v40 = 1;
    v41 = -1;
    v34 = -1;
  }
  while ( 1 )
  {
    if ( v10 && v13 >= v8 )
    {
LABEL_81:
      v9 = -2147483622;
      goto LABEL_83;
    }
    if ( v11 )
    {
      CmpDelayDerefKeyControlBlock(v11);
      v11 = 0;
      v38 = 0;
    }
    if ( v12 )
    {
      CmpDelayDerefKeyControlBlock(v12);
      v12 = 0;
      v39 = 0;
    }
    if ( !v47 && v14 == -1 )
    {
      if ( v48 )
        v16 = (int *)&v38;
      else
        v16 = 0;
      if ( v48 )
        v17 = a2;
      else
        v17 = 0;
      v18 = a1;
      v19 = a1;
      if ( !v48 )
        v19 = 0;
      v9 = CmpFindSubKeyByNumberEx(*(_DWORD *)(a1 + 20), *(_DWORD *)(a1 + 24), v45, &v42, v19, v17, v48, (int)v16);
      v11 = v38;
      if ( v9 < 0 )
        goto LABEL_84;
      v14 = v42;
      if ( v42 == -1 )
        v47 = 1;
    }
    v20 = v40;
    if ( !v40 && v15 == -1 )
    {
      if ( v48 )
        v21 = (int *)&v39;
      else
        v21 = 0;
      if ( v48 )
        v22 = a1;
      else
        v22 = 0;
      v23 = a2;
      v24 = a2;
      if ( !v48 )
        v24 = 0;
      v9 = CmpFindSubKeyByNumberEx(*(_DWORD *)(a2 + 20), *(_DWORD *)(a2 + 24), v43, &v41, v24, v22, v48, (int)v21);
      v12 = v39;
      if ( v9 < 0 )
        goto LABEL_52;
      v15 = v41;
      v34 = v41;
      if ( v41 == -1 )
      {
        v20 = 1;
        v40 = 1;
      }
      else
      {
        v20 = v40;
      }
    }
    if ( v47 )
    {
      if ( v20 )
        goto LABEL_81;
      v25 = 2;
    }
    else
    {
      v25 = v20 != 0;
    }
    if ( v15 != -1 )
    {
      v37 = (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(a2 + 20) + 4))(*(_DWORD *)(a2 + 20), v15, &v44);
      if ( !v37 )
      {
LABEL_82:
        v10 = v33;
        goto LABEL_83;
      }
    }
    if ( v14 == -1 )
    {
      v26 = v36;
    }
    else
    {
      v26 = (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(a1 + 20) + 4))(*(_DWORD *)(a1 + 20), v14, &v46);
      v36 = v26;
      if ( !v26 )
        goto LABEL_82;
    }
    v27 = 0;
    if ( !v25 )
      break;
    if ( v25 != 1 )
    {
      if ( v33 )
        ++v13;
      v10 = 1;
      v33 = 1;
      if ( v13 == a3 )
        goto LABEL_49;
LABEL_75:
      v15 = -1;
      v34 = -1;
      ++v43;
      v41 = -1;
      goto LABEL_77;
    }
    if ( v33 )
      ++v13;
    v10 = 1;
    v33 = 1;
    if ( v13 == a3 )
      goto LABEL_57;
LABEL_74:
    v14 = -1;
    v42 = -1;
    ++v45;
    if ( v27 )
      goto LABEL_75;
    v15 = v34;
LABEL_77:
    if ( v36 )
    {
      (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v46);
      v36 = 0;
    }
    v10 = 1;
    v8 = a3;
    if ( v37 )
    {
      (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a2 + 20) + 8))(*(_DWORD *)(a2 + 20), &v44);
      v8 = a3;
      v37 = 0;
    }
  }
  v28 = CmpCompareKeysByName(v26, v37);
  if ( v28 < 0 )
  {
    if ( v33 )
      ++v13;
    v10 = 1;
    v33 = 1;
    if ( v13 == a3 )
      goto LABEL_57;
    goto LABEL_74;
  }
  if ( v28 > 0 )
  {
    if ( v33 )
      ++v13;
    v10 = 1;
    v33 = 1;
    if ( v13 == a3 )
    {
LABEL_49:
      v23 = a2;
      *a5 = *(_DWORD *)(a2 + 20);
      *a6 = v34;
      if ( a7 )
      {
        *a7 = v12;
        v12 = 0;
      }
      v9 = 0;
LABEL_52:
      v18 = a1;
      goto LABEL_85;
    }
    goto LABEL_75;
  }
  if ( v33 )
    ++v13;
  v10 = 1;
  v33 = 1;
  if ( v13 != a3 )
  {
    v27 = 1;
    goto LABEL_74;
  }
LABEL_57:
  *a5 = *(_DWORD *)(a1 + 20);
  *a6 = v14;
  if ( a7 )
  {
    *a7 = v11;
    v11 = 0;
  }
  v9 = 0;
LABEL_83:
  v18 = a1;
LABEL_84:
  v23 = a2;
LABEL_85:
  if ( v11 )
    CmpDelayDerefKeyControlBlock(v11);
  if ( v12 )
    CmpDelayDerefKeyControlBlock(v12);
  if ( v37 )
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(v23 + 20) + 8))(*(_DWORD *)(v23 + 20), &v44);
  if ( v36 )
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(v18 + 20) + 8))(*(_DWORD *)(v18 + 20), &v46);
  v29 = v13 + 1;
  if ( !v10 )
    v29 = 0;
  *a8 = v29;
  return v9;
}
