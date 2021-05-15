// CmpSelectLeaf 
 
int __fastcall CmpSelectLeaf(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r5
  int v6; // r1
  int v8; // r6
  int v10; // r0
  int v11; // r5
  int v12; // r7
  int v13; // r8
  int v15; // r0
  int v16; // [sp+0h] [bp-38h] BYREF
  int v17[2]; // [sp+4h] [bp-34h] BYREF
  int v18[11]; // [sp+Ch] [bp-2Ch] BYREF

  v5 = a2 + 4 * a4;
  v6 = *(_DWORD *)(v5 + 28);
  v18[1] = v5;
  v18[2] = a4;
  v17[1] = a3;
  v8 = -1;
  v18[0] = -1;
  v16 = -1;
  if ( HvpMarkCellDirty(a1, v6, 0, 0) )
  {
    v10 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v5 + 28), v18);
    v11 = v10;
    if ( v10 )
    {
      v12 = CmpFindSubKeyInRoot(a1, v10, a3, v17);
      if ( v12 < 0 )
        goto LABEL_10;
      v13 = v17[0];
      if ( v17[0] == -1 )
        return sub_818A58(a1);
      v15 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v17[0], &v16);
      if ( !v15 )
LABEL_10:
        JUMPOUT(0x818B8C);
      if ( *(unsigned __int16 *)(v15 + 2) >= 0x3F5u )
        JUMPOUT(0x818B34);
      *a5 = v11 + 4 * (v12 + 1);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v18);
      v8 = v13;
    }
  }
  return v8;
}
