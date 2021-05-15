// sub_96D5BC 
 
int __fastcall sub_96D5BC(int a1, int a2, int a3)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r1
  unsigned int v6; // r7
  _DWORD *v7; // r1
  _DWORD *v8; // r0
  unsigned int v9; // r3
  unsigned int v10; // [sp+8h] [bp-30h]
  unsigned int v11; // [sp+1Ch] [bp-1Ch]
  int (__fastcall *v12)(_DWORD *); // [sp+34h] [bp-4h]

  if ( v6 >= *(_DWORD *)(a3 + 24) + a2 )
    JUMPOUT(0x95DF5E);
  v7 = *(_DWORD **)(a3 + 16);
  v8 = v7;
  if ( v7 )
    v9 = v11;
  else
    v9 = v10;
  if ( v7 )
  {
    if ( (v9 & 7) != 0 )
      KeBugCheck2(333, -3, v6, v9, 0, 0);
    v3 = &v7[2 * (v9 >> 3)];
    v4 = 0;
    while ( v8 != v3 )
    {
      if ( v4 )
      {
        if ( *v4 >= *v8 )
          KeBugCheck2(333, -2, v6, (unsigned int)v8, (unsigned int)v4, 0);
      }
      v4 = v8;
      v8 += 2;
    }
  }
  return v12(v8);
}
