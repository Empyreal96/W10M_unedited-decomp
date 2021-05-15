// HvReallocateCell 
 
int __fastcall HvReallocateCell(int a1, unsigned int a2, int a3, int a4, int *a5, _DWORD *a6)
{
  unsigned int v6; // r6
  int v11; // r0
  int v12; // r7
  unsigned int v13; // r9
  int v14; // r6
  int v15; // r5
  int v16; // r5
  int v17; // [sp+8h] [bp-28h] BYREF
  int v18; // [sp+Ch] [bp-24h] BYREF
  int v19[8]; // [sp+10h] [bp-20h] BYREF

  v6 = (a3 + 11) & 0xFFFFFFF8;
  v17 = -1;
  v18 = -1;
  v19[0] = 0;
  if ( v6 > 0x4000 )
    return sub_805CBC(0);
  v11 = (*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, a2, &v17);
  v12 = v11;
  if ( !v11 )
    return -1;
  v13 = -4 - *(_DWORD *)(v11 - 4);
  if ( v6 <= -*(_DWORD *)(v11 - 4) )
  {
    *a5 = v11;
    v14 = a2;
    *a6 = v17;
    HvpGetCellContextReinitialize(&v17);
  }
  else
  {
    v14 = HvpDoAllocateCell(a1, v6, a2 >> 31, v19, &v18);
    if ( v14 == -1 )
    {
      v14 = -1;
      v16 = v19[0];
    }
    else
    {
      v15 = v19[0];
      memmove(v19[0], v12, v13);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
      v12 = 0;
      if ( a4 == 1 )
        HvFreeCell(a1, a2);
      *a5 = v15;
      v16 = 0;
      *a6 = v18;
      HvpGetCellContextReinitialize(&v18);
    }
    if ( v12 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
    if ( v16 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v18);
  }
  return v14;
}
