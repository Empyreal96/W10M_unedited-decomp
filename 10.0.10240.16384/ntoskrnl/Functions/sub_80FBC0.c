// sub_80FBC0 
 
void __fastcall sub_80FBC0(char a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  int v5; // r8
  int v6; // r9
  int v7; // r10
  _BYTE *v8; // r1
  int v9; // r0
  _BYTE *v10; // r0
  int v11; // t1
  int v12; // r2
  _BYTE *v13; // r3
  _BYTE *v14; // r3

  v8 = (_BYTE *)(v5 + *(_DWORD *)(v7 + 24));
  if ( *(_DWORD *)(v6 + 4) )
  {
    v8[99] = 2;
    a3 = *(_DWORD *)(v4 + 3448);
  }
  if ( *(_DWORD *)a3 != -1 )
  {
    do
    {
      if ( *(unsigned __int16 *)(a3 + 6) == v3 )
      {
        v9 = *(unsigned __int16 *)(a3 + 8);
        if ( *(_BYTE *)(a3 + 10) )
        {
          v10 = &v8[v9];
          if ( v10[99] != 2 )
            v10[99] = 1;
        }
        else
        {
          v8[v9 + 99] = 2;
        }
      }
      v11 = *(_DWORD *)(a3 + 12);
      a3 += 12;
    }
    while ( v11 != -1 );
    a1 = 0;
  }
  v12 = 0;
  if ( v8[99] == 2 )
  {
    v8[97] = a1;
    v8[98] = a1;
    v12 = 1;
  }
  if ( v8[99] == 1 )
  {
    v13 = &v8[v12];
    v13[97] = a1;
    v13[98] = a1;
    ++v12;
  }
  if ( !v8[99] )
  {
    v14 = &v8[v12];
    v14[97] = a1;
    v14[98] = a1;
  }
  JUMPOUT(0x79BF3C);
}
