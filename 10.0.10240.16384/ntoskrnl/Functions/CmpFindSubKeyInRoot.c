// CmpFindSubKeyInRoot 
 
int __fastcall CmpFindSubKeyInRoot(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r3
  int v6; // r4
  unsigned int v7; // r8
  unsigned int v9; // r9
  unsigned int v10; // r5
  int v11; // r10
  int v12; // r0
  int v14; // r4
  int v15; // r0
  int v16; // r0
  void (__fastcall *v17)(int, int *); // r3
  int v18; // r4
  int v19; // r0
  int v20; // r5
  int v21; // r10
  int v22; // r0
  int v23; // r0
  int v24; // r0
  int v25; // r0
  int v26; // [sp+8h] [bp-30h] BYREF
  int v27; // [sp+Ch] [bp-2Ch]
  int v28; // [sp+10h] [bp-28h]
  int v29; // [sp+14h] [bp-24h]

  v5 = a2;
  v6 = *(unsigned __int16 *)(a2 + 2);
  v27 = a2;
  v28 = a3;
  v7 = v6 - 1;
  v26 = -1;
  v9 = 0;
  while ( 1 )
  {
    v10 = v9 + ((v7 - v9) >> 1);
    v11 = *(_DWORD *)(v5 + 4 * v10 + 4);
    v12 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v11, &v26);
    v29 = v12;
    if ( !v12 )
      return sub_805188();
    v14 = v28;
    v15 = CmpCompareInIndex(a1, v28, *(unsigned __int16 *)(v12 + 2) - 1, v12, a4);
    if ( v15 == 2 )
      goto LABEL_28;
    if ( !v15 )
      break;
    if ( v15 >= 0 )
    {
      v9 += (v7 - v9) >> 1;
      goto LABEL_13;
    }
    v16 = CmpCompareInIndex(a1, v14, 0, v29, a4);
    if ( v16 == 2 )
      goto LABEL_28;
    if ( v16 >= 0 )
      break;
    v7 = v9 + ((v7 - v9) >> 1);
LABEL_13:
    v17 = *(void (__fastcall **)(int, int *))(a1 + 8);
    if ( v7 - v9 <= 1 )
    {
      v17(a1, &v26);
      v18 = *(_DWORD *)(v27 + 4 * v9 + 4);
      v19 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v18, &v26);
      v20 = v19;
      if ( v19 )
      {
        v21 = v28;
        v22 = CmpCompareInIndex(a1, v28, *(unsigned __int16 *)(v19 + 2) - 1, v19, a4);
        if ( v22 == 2 )
          goto LABEL_28;
        if ( !v22 )
        {
          *a4 = v18;
          v10 = v9;
          goto LABEL_11;
        }
        if ( v22 < 0 )
        {
          v23 = CmpCompareInIndex(a1, v21, 0, v20, a4);
          if ( v23 != 2 )
          {
            v10 = v9;
            if ( v23 < 0 )
            {
LABEL_26:
              *a4 = -1;
              goto LABEL_11;
            }
LABEL_21:
            *a4 = v18;
            goto LABEL_11;
          }
LABEL_28:
          v10 = 0x80000000;
          goto LABEL_26;
        }
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
        v18 = *(_DWORD *)(v27 + 4 * v7 + 4);
        v24 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v18, &v26);
        if ( v24 )
        {
          v25 = CmpCompareInIndex(a1, v21, *(unsigned __int16 *)(v24 + 2) - 1, v24, a4);
          if ( v25 != 2 )
          {
            v10 = v7;
            if ( v25 > 0 )
              goto LABEL_26;
            goto LABEL_21;
          }
          goto LABEL_28;
        }
      }
      return sub_805188();
    }
    v17(a1, &v26);
    v5 = v27;
  }
  *a4 = v11;
LABEL_11:
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
  return v10;
}
