// IopQueryConflictListInternal 
 
int __fastcall IopQueryConflictListInternal(int a1, int a2, int a3, _DWORD *a4, unsigned int a5)
{
  _DWORD *v7; // r2
  int v8; // r4
  int v9; // r3
  int v10; // r4
  int v11; // r0
  int v12; // r5
  int v13; // r3
  int v14; // r3
  int v15; // r6
  unsigned int v16; // r5
  int v17; // r2
  int v18; // r2
  int v19; // r0
  int v20; // r3
  int v21; // r2
  int v22; // r0
  unsigned int v24; // [sp+8h] [bp-68h] BYREF
  unsigned int v25; // [sp+Ch] [bp-64h] BYREF
  unsigned int v26; // [sp+10h] [bp-60h] BYREF
  int v27[10]; // [sp+18h] [bp-58h] BYREF
  int v28[12]; // [sp+40h] [bp-30h] BYREF

  v26 = 0;
  a4[2] = 0;
  a4[3] = 0;
  a4[4] = 32;
  if ( a1 )
    v7 = *(_DWORD **)(*(_DWORD *)(a1 + 176) + 20);
  else
    v7 = 0;
  if ( !v7 )
    return -1073741810;
  v9 = *(unsigned __int8 *)(a2 + 20);
  if ( v9 != 1 )
  {
    if ( v9 == 2 )
      goto LABEL_14;
    if ( v9 != 3 )
    {
      if ( v9 == 4 )
        goto LABEL_14;
      if ( v9 != 7 )
        return -1073741811;
    }
  }
  if ( !*(_DWORD *)(a2 + 32) )
    return 0;
LABEL_14:
  v10 = v7[77];
  v11 = v7[74];
  v12 = PnpDefaultInterfaceType;
  if ( v10 == -1 )
  {
    if ( !v11 || (v13 = *(_DWORD *)(v11 + 4), v13 == -1) )
      *(_DWORD *)(a2 + 4) = PnpDefaultInterfaceType;
    else
      *(_DWORD *)(a2 + 4) = v13;
  }
  else
  {
    *(_DWORD *)(a2 + 4) = v10;
  }
  if ( *(_DWORD *)(a2 + 4) == 8 )
    *(_DWORD *)(a2 + 4) = v12;
  v14 = v7[78];
  if ( v14 == -1 && (!v11 || (v14 = *(_DWORD *)(v11 + 8), v14 == -1)) )
    *(_DWORD *)(a2 + 8) = 0;
  else
    *(_DWORD *)(a2 + 8) = v14;
  v15 = PnpCmResourcesToIoResources(v11, (int *)a2, 0);
  if ( !v15 )
    return -1073741811;
  memset(v27, 0, sizeof(v27));
  v27[0] = a1;
  v27[5] = v15;
  v27[2] = -1;
  v8 = IopResourceRequirementsListToReqList(v27, &v26);
  v16 = v26;
  if ( v8 >= 0 )
  {
    if ( v26
      && (v17 = *(_DWORD *)(v26 + 24), *(_DWORD *)(v26 + 12) = v26 + 24, *(_DWORD *)(v17 + 16) == 1)
      && (v18 = *(_DWORD *)(v17 + 20), *(_BYTE *)(v18 + 8)) )
    {
      v19 = *(_DWORD *)(v18 + 176);
      v20 = *(_DWORD *)(*(_DWORD *)(v18 + 20) + 36);
      v21 = *(unsigned __int8 *)(v20 + 1);
      if ( v21 == 128 || v21 == 240 )
        v20 += 32;
      v28[0] = a1;
      v28[1] = v20;
      v28[2] = (int)&v25;
      v24 = 0;
      v25 = 0;
      v28[3] = (int)&v24;
      v22 = IopCallArbiter(v19, 6, v28);
      v8 = v22;
      if ( v22 < 0 )
      {
        if ( v22 == -1073741172 )
          v8 = IopQueryConflictFillConflicts(0, 0, 0, (int)a4, a5, 4);
      }
      else
      {
        v8 = IopQueryConflictFillConflicts(a1, v25, v24, (int)a4, a5, 0);
        if ( v24 )
          ExFreePoolWithTag(v24);
      }
    }
    else
    {
      v8 = -1073741811;
    }
  }
  ExFreePoolWithTag(v15);
  if ( v16 )
    IopFreeReqList(v16);
  return v8;
}
