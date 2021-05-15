// MmGetSectionInformation 
 
int __fastcall MmGetSectionInformation(int a1, int a2, int *a3)
{
  int v4; // r6
  int v5; // r5
  int v6; // r4
  _DWORD *v7; // r0
  _DWORD *v8; // r1
  _DWORD *v9; // r10
  int v10; // r3
  int v11; // r3
  bool v12; // zf
  int v13; // r0
  _DWORD v17[20]; // [sp+10h] [bp-50h] BYREF

  v4 = *(_DWORD *)(a1 + 32);
  v5 = 0;
  v6 = 0;
  v7 = (_DWORD *)MiSectionControlArea(a1);
  v9 = v7;
  v10 = a2;
  if ( !a2 )
  {
    if ( (v4 & 0x20) != 0 )
      v6 = 0x1000000;
    if ( (v4 & 0x40) != 0 )
      v6 |= 0x200000u;
    if ( (v4 & 0x80) != 0 )
      v6 |= 0x800000u;
    if ( (*(_WORD *)(*v7 + 8) & 0x8000) != 0 )
      v6 |= 0x10000000u;
    if ( (*(_WORD *)(*v7 + 8) & 0x4000) != 0 )
      v6 |= 0x40000000u;
    if ( (v4 & 0x1000) != 0 )
      v6 |= 0x4000000u;
    if ( (v4 & 0x2000) != 0 )
      v6 |= 0x8000000u;
    v11 = v7[7];
    v8 = (_DWORD *)a1;
    if ( (v11 & 0x20) != 0 )
    {
      v12 = (v11 & 0x20000) == 0;
      v10 = 0;
      if ( !v12 )
        v6 |= 0x20000000u;
    }
    else
    {
      v10 = 0;
    }
  }
  if ( !v10 )
  {
    *a3 = v8[3] << 12;
    a3[2] = v8[6];
    a3[3] = v8[7];
    a3[1] = v6;
    return v5;
  }
  if ( v10 == 1 )
  {
    if ( (v4 & 0x20) != 0 )
    {
      memmove((int)v17, *(_DWORD *)(*v7 + 36), 0x30u);
      if ( (v9[7] & 0x10000000) != 0 )
        v17[0] = dword_6337C0 | LOWORD(v17[0]);
      memmove((int)a3, (int)v17, 0x30u);
      return v5;
    }
    return -1073741751;
  }
  if ( (v4 & 0x20) == 0 )
    return -1073741751;
  v13 = MiRelocateAmount(v7, v8);
  if ( (v9[7] & 0x10000000) != 0 )
    v13 = dword_6337C0 + v13 - *(_DWORD *)(*v9 + 24);
  *a3 = v13;
  return v5;
}
