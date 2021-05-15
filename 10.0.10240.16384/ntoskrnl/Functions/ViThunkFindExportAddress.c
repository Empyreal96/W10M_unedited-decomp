// ViThunkFindExportAddress 
 
int __fastcall ViThunkFindExportAddress(int a1, int a2, int *a3)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r7
  int v5; // r9
  int v6; // r6
  _DWORD *v7; // r0
  _DWORD *v8; // r5
  signed int v9; // r8
  int v10; // r2
  int v11; // r7
  unsigned int v12; // r10
  signed int v13; // r0
  bool v14; // cc
  int v16; // r0
  int v17; // r2
  _DWORD *v18; // [sp+0h] [bp-30h]
  int v20; // [sp+8h] [bp-28h]
  int v21; // [sp+Ch] [bp-24h] BYREF
  int *v22; // [sp+10h] [bp-20h]

  v3 = *(_DWORD **)(a1 + 16);
  v4 = (_DWORD *)(a1 + 16);
  *a3 = 0;
  v5 = 0;
  v22 = a3;
  v18 = (_DWORD *)(a1 + 16);
  while ( 1 )
  {
    if ( v3 == v4 )
      return 0;
    v6 = v3[6];
    v7 = (_DWORD *)RtlImageDirectoryEntryToData(v6, 1, 0, (int)&v21);
    v8 = v7;
    if ( v7 )
      break;
LABEL_19:
    if ( ++v5 == 2 )
      return 0;
    v3 = (_DWORD *)*v3;
  }
  v9 = 0;
  v10 = v6 + v7[8];
  v20 = v10;
  v21 = v7[9] + v6;
  v11 = v7[6] - 1;
  while ( 1 )
  {
    v12 = (unsigned int)(v11 + v9) >> 1;
    v13 = strcmp(a2, (unsigned int *)(*(_DWORD *)(v10 + 4 * v12) + v6));
    if ( v13 >= 0 )
      break;
    if ( !v12 )
      return sub_969984();
    v11 = v12 - 1;
LABEL_8:
    v14 = v11 < v9;
    if ( v11 < (unsigned int)v9 )
      goto LABEL_14;
    v10 = v20;
  }
  if ( v13 > 0 )
  {
    v9 = v12 + 1;
    goto LABEL_8;
  }
  v14 = v11 < v9;
LABEL_14:
  if ( v14 || (unsigned int)*(unsigned __int16 *)(v21 + 2 * v12) >= v8[5] )
  {
    v4 = v18;
    goto LABEL_19;
  }
  v16 = ViThunkIsExportAddressShared(v6, v8);
  *v22 = v16;
  return *(_DWORD *)(v6 + 4 * v17 + v8[7]) + v6;
}
