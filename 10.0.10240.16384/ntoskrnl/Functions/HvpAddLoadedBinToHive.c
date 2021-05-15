// HvpAddLoadedBinToHive 
 
int __fastcall HvpAddLoadedBinToHive(int a1, int a2, int a3, int *a4)
{
  int v8; // r4
  unsigned int v9; // r4
  int v10; // r5
  int v11; // r3
  int v12; // r2
  unsigned int v14; // [sp+10h] [bp-20h] BYREF
  unsigned int v15[7]; // [sp+14h] [bp-1Ch] BYREF

  v8 = HvpAllocateBin(a1, *(_DWORD *)(a2 + 8), 0, a3, 825445699, (int *)&v14, (int *)v15);
  if ( v8 < 0 )
  {
    v11 = v14;
    v12 = v15[0];
  }
  else
  {
    v9 = v15[0];
    if ( v15[0] )
      v10 = v15[0];
    else
      v10 = v14;
    memmove(v10, a2, *(_DWORD *)(a2 + 8));
    HvpPointMapEntriesToBuffer(a1, v14, v9, *(_DWORD *)(v10 + 8), a3, 0);
    v11 = 0;
    v12 = 0;
    v8 = 0;
    *a4 = v10;
  }
  if ( v11 || v12 )
    HvpFreeBin(a1, *(_DWORD *)(a2 + 8), 0, v11, v12);
  return v8;
}
