// sub_818A58 
 
void __fastcall sub_818A58(int a1, int a2, int a3, int (__fastcall *a4)(int, int, int *), int a5, int a6, unsigned __int16 *a7)
{
  int v7; // r4
  int v8; // r5
  int v9; // r6
  unsigned int v10; // r7
  unsigned int v11; // r9
  int *v12; // r10
  int v13; // r0
  int v14; // r0
  void (__fastcall *v15)(int, int *); // r3
  int (__fastcall *v16)(int, int, int *); // r3
  int v17; // r0
  int (__fastcall *v18)(int, int, int *); // r3
  int v19; // r0
  int (__fastcall *v20)(int, int, int *); // r3
  int v21; // r0
  int (__fastcall *v22)(int, int, int *); // r3
  int v23; // r0
  unsigned __int16 *v24; // r10
  int v25; // r8
  int v26; // r7
  int v27; // [sp+0h] [bp-40h] BYREF
  int v28; // [sp+4h] [bp-3Ch] BYREF
  char v29[4]; // [sp+Ch] [bp-34h] BYREF
  int v30; // [sp+10h] [bp-30h]
  int v31; // [sp+14h] [bp-2Ch]

  v12 = (int *)(v8 + 4 * v10);
  v13 = a4(a1, v12[1], &a5);
  if ( !v13 )
    goto LABEL_22;
  v14 = CmpDoCompareKeyName(v7, a7, *(_DWORD *)(v13 + 4));
  if ( v14 == 2 )
    goto LABEL_21;
  v15 = *(void (__fastcall **)(int, int *))(v7 + 8);
  if ( v14 >= 0 )
  {
    v15(v7, &a5);
    v20 = *(int (__fastcall **)(int, int, int *))(v7 + 4);
    a6 = v12[1];
    v21 = v20(v7, a6, &a5);
    if ( !v21 )
      goto LABEL_22;
    if ( *(unsigned __int16 *)(v21 + 2) < v11 )
      JUMPOUT(0x7B31DE);
    if ( v10 < (unsigned int)*(unsigned __int16 *)(v8 + 2) - 1 )
    {
      (*(void (__fastcall **)(int, int *))(v7 + 8))(v7, &a5);
      v22 = *(int (__fastcall **)(int, int, int *))(v7 + 4);
      a6 = v12[2];
      v23 = v22(v7, a6, &a5);
      if ( !v23 )
        goto LABEL_22;
      if ( *(unsigned __int16 *)(v23 + 2) < v11 )
        JUMPOUT(0x7B31E0);
    }
LABEL_17:
    v24 = a7;
    v25 = v30;
    v26 = CmpSplitLeaf(v7, *(_DWORD *)(v30 + 28), v10, v31);
    if ( v26 != v9 )
    {
      (*(void (__fastcall **)(int, char *))(v7 + 8))(v7, v29);
      *(_DWORD *)(v25 + 28) = v26;
      v8 = (*(int (__fastcall **)(int, int, char *))(v7 + 4))(v7, v26, v29);
      if ( v8 )
      {
        (*(void (__fastcall **)(int, int *))(v7 + 8))(v7, &v27);
        if ( CmpFindSubKeyInRoot(v7, v8, (int)v24, &v28) >= 0 )
          JUMPOUT(0x7B31BC);
LABEL_22:
        if ( v8 )
          (*(void (__fastcall **)(int, char *))(v7 + 8))(v7, v29);
        JUMPOUT(0x7B31FA);
      }
    }
LABEL_21:
    (*(void (__fastcall **)(int, int *))(v7 + 8))(v7, &v27);
    goto LABEL_22;
  }
  if ( v10 )
  {
    v15(v7, &a5);
    v16 = *(int (__fastcall **)(int, int, int *))(v7 + 4);
    a6 = *v12;
    v17 = v16(v7, a6, &a5);
    if ( !v17 )
      goto LABEL_22;
    if ( *(unsigned __int16 *)(v17 + 2) >= v11 )
      goto LABEL_17;
  }
  else
  {
    v15(v7, &a5);
    v18 = *(int (__fastcall **)(int, int, int *))(v7 + 4);
    a6 = *(_DWORD *)(v8 + 4);
    v19 = v18(v7, a6, &a5);
    if ( !v19 )
      goto LABEL_22;
    if ( *(unsigned __int16 *)(v19 + 2) >= v11 )
      goto LABEL_17;
  }
  JUMPOUT(0x7B31E4);
}
