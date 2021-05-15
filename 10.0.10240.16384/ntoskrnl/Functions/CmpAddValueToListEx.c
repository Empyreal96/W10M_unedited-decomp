// CmpAddValueToListEx 
 
int __fastcall CmpAddValueToListEx(int a1, int a2, unsigned int a3, int a4, unsigned int *a5, int a6)
{
  unsigned int v7; // r4
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r3
  int v13; // r0
  int v15; // r2
  int v16; // r2
  unsigned int v17; // r1
  int v18; // t1
  int v19; // [sp+8h] [bp-20h] BYREF
  _DWORD v20[7]; // [sp+Ch] [bp-1Ch] BYREF

  v19 = a3;
  v20[0] = a4;
  v7 = *a5 + 1;
  v19 = 0;
  v20[0] = -1;
  if ( v7 <= 1 )
  {
    v15 = a6;
    if ( !a6 )
      v15 = 1;
    v11 = HvAllocateCell(a1, 4 * v15);
  }
  else
  {
    if ( v7 >= 0x64 )
    {
      v10 = 4 * ((v7 + 99) & 0xFFFFFF9C);
      if ( v10 > 0x1000 )
        return sub_805C9C();
    }
    else
    {
      v10 = 4 * v7;
    }
    v11 = HvReallocateCell(a1, a5[1], v10, 1, &v19, v20);
  }
  if ( v11 == -1 )
    return -1073741670;
  v12 = v7 - 1;
  a5[1] = v11;
  v13 = v19;
  if ( v7 - 1 > a3 )
  {
    v16 = v19 + 4 * v12;
    v17 = v12 - a3;
    do
    {
      v18 = *(_DWORD *)(v16 - 4);
      v16 -= 4;
      --v17;
      *(_DWORD *)(v16 + 4) = v18;
    }
    while ( v17 );
  }
  *(_DWORD *)(v13 + 4 * a3) = a2;
  *a5 = v7;
  (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v20);
  return 0;
}
