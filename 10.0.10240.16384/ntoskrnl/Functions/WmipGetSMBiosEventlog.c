// WmipGetSMBiosEventlog 
 
int __fastcall WmipGetSMBiosEventlog(int a1, unsigned int *a2, int a3, int a4)
{
  int result; // r0
  int v7; // r5
  unsigned int v8; // r6
  unsigned int v9; // r8
  int v10; // r4
  int v11; // r0
  int v12; // r2
  unsigned int v13; // r6
  int v14; // r9
  int v15; // r0
  unsigned int v16; // r4
  unsigned int v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h] BYREF
  int v19[8]; // [sp+8h] [bp-20h] BYREF

  v18 = a3;
  v19[0] = a4;
  result = WmipFindSMBiosStructure(15, v19, &v17, &v18);
  if ( result < 0 )
    return result;
  v7 = v19[0];
  v8 = *(unsigned __int8 *)(v19[0] + 1);
  v9 = *(unsigned __int16 *)(v19[0] + 4);
  v10 = *(unsigned __int8 *)(v19[0] + 10);
  v19[0] = *(_DWORD *)(v19[0] + 16);
  if ( v8 < 0x17 )
  {
    v12 = 0;
    v11 = 0;
  }
  else
  {
    v11 = 1;
    v12 = *(unsigned __int8 *)(v7 + 22) * *(unsigned __int8 *)(v7 + 21);
    if ( v8 != v12 + 23 )
    {
      if ( v17 )
        MmUnmapIoSpace(v17, v18);
      return -1073741823;
    }
  }
  v13 = v12 + v9 + 23;
  if ( *a2 < v13 )
  {
    if ( v17 )
      MmUnmapIoSpace(v17, v18);
    result = -1073741789;
  }
  else
  {
    *(_BYTE *)(a1 + 3) = 0;
    *(_WORD *)a1 = v12;
    *(_BYTE *)(a1 + 2) = v11;
    v14 = v12 + a1;
    if ( v11 == 1 )
    {
      memmove(a1 + 4, v7 + 4, *(unsigned __int8 *)(v7 + 1) - 4);
    }
    else
    {
      *(_DWORD *)(a1 + 4) = *(_DWORD *)(v7 + 4);
      *(_DWORD *)(a1 + 8) = *(_DWORD *)(v7 + 8);
      *(_DWORD *)(a1 + 12) = *(_DWORD *)(v7 + 12);
      *(_DWORD *)(a1 + 16) = *(_DWORD *)(v7 + 16);
      *(_WORD *)(a1 + 20) = 0;
      *(_BYTE *)(a1 + 22) = 0;
    }
    if ( v17 )
      MmUnmapIoSpace(v17, v18);
    if ( !v10
      || v10 == 1
      || v10 == 2
      || v10 != 3
      || (v15 = MmMapIoSpaceEx(v19[0], 0, v9, 4), v16 = v15, v14 == -23)
      || !v15 )
    {
      result = -1073741823;
    }
    else
    {
      memmove(v14 + 23, v15, v9);
      MmUnmapIoSpace(v16, v9);
      result = 0;
    }
  }
  *a2 = v13;
  return result;
}
