// CmpFindSubKeyByNameWithStatus 
 
int __fastcall CmpFindSubKeyByNameWithStatus(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r4
  int v6; // r7
  unsigned int v9; // r8
  _WORD *v10; // r0
  int v11; // r4
  int v12; // r0
  int v14; // [sp+8h] [bp-30h] BYREF
  int v15; // [sp+Ch] [bp-2Ch] BYREF
  int v16; // [sp+10h] [bp-28h]
  char v17[36]; // [sp+14h] [bp-24h] BYREF

  v4 = *(_DWORD *)(a1 + 144);
  v6 = -1073741772;
  v16 = a3;
  v14 = -1;
  *a4 = -1;
  v9 = 0;
  if ( !v4 )
    return v6;
  while ( !*(_DWORD *)(a2 + 20) )
  {
LABEL_13:
    ++v9;
    a2 += 4;
    if ( v9 >= *(_DWORD *)(a1 + 144) )
      return v6;
  }
  v10 = (_WORD *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(a2 + 28), &v14);
  if ( !v10 )
    return -1073741670;
  v11 = v16;
  if ( *v10 != 26994 )
    goto LABEL_5;
  if ( CmpFindSubKeyInRoot(a1, (int)v10, v16, &v15) < 0 )
  {
    v6 = -1073741670;
    goto LABEL_10;
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
  if ( v15 == -1 )
    goto LABEL_13;
  v10 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v15, &v14);
  if ( v10 )
  {
LABEL_5:
    if ( *v10 == 26732 )
      v12 = CmpFindSubKeyByHashWithStatus(a1, v10, v11, &v15);
    else
      v12 = CmpFindSubKeyInLeafWithStatus(a1, v10, v11, &v15, v17);
    v6 = v12;
    if ( v12 < 0 && v12 != -1073741772 )
      goto LABEL_10;
    if ( v15 != -1 )
    {
      *a4 = v15;
      v6 = 0;
LABEL_10:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
      return v6;
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
    goto LABEL_13;
  }
  return -1073741670;
}
