// __memcpy_reverse_large_neon 
 
void __fastcall _memcpy_reverse_large_neon(int a1, int a2, unsigned int a3, int a4)
{
  char v4; // t1
  bool v5; // cf
  unsigned int v6; // r2
  __int64 v7; // d1
  __int64 v8; // d2
  __int64 v9; // d3
  __int64 v10; // d1
  __int64 v11; // d2
  __int64 v12; // d3
  unsigned int v13; // r2
  __int64 v14; // d1
  unsigned int v15; // r2
  unsigned int v16; // r2
  char v17; // d1.b[0]
  char v18; // d2.b[0]
  char v19; // d3.b[0]
  unsigned int v20; // r2
  char v21; // d1.b[0]

  __pld((void *)(a2 - 32));
  if ( (a4 & 3) != 0 )
  {
    --a3;
    v4 = *(_BYTE *)--a2;
    *(_BYTE *)--a4 = v4;
  }
  v5 = a3 >= 0x20;
  v6 = a3 - 32;
  if ( v5 )
  {
    v5 = v6 >= 0x20;
    v6 -= 32;
    __pld((void *)(a2 - 64));
    for ( ; v5; *(_QWORD *)(a4 + 24) = v9 )
    {
      __pld((void *)(a2 - 96));
      a2 -= 32;
      a4 -= 32;
      v7 = *(_QWORD *)(a2 + 8);
      v8 = *(_QWORD *)(a2 + 16);
      v9 = *(_QWORD *)(a2 + 24);
      v5 = v6 >= 0x20;
      v6 -= 32;
      *(_QWORD *)a4 = *(_QWORD *)a2;
      *(_QWORD *)(a4 + 8) = v7;
      *(_QWORD *)(a4 + 16) = v8;
    }
    a2 -= 32;
    a4 -= 32;
    v10 = *(_QWORD *)(a2 + 8);
    v11 = *(_QWORD *)(a2 + 16);
    v12 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)a4 = *(_QWORD *)a2;
    *(_QWORD *)(a4 + 8) = v10;
    *(_QWORD *)(a4 + 16) = v11;
    *(_QWORD *)(a4 + 24) = v12;
  }
  v5 = __CFADD__(v6, 16);
  v13 = v6 + 16;
  if ( v5 )
  {
    a2 -= 16;
    a4 -= 16;
    v14 = *(_QWORD *)(a2 + 8);
    v13 -= 16;
    *(_QWORD *)a4 = *(_QWORD *)a2;
    *(_QWORD *)(a4 + 8) = v14;
  }
  v5 = __CFADD__(v13, 8);
  v15 = v13 + 8;
  if ( v5 )
  {
    a2 -= 8;
    a4 -= 8;
    v15 -= 8;
    *(_QWORD *)a4 = *(_QWORD *)a2;
  }
  v5 = __CFADD__(v15, 4);
  v16 = v15 + 4;
  if ( v5 )
  {
    a2 -= 4;
    a4 -= 4;
    v17 = *(_BYTE *)(a2 + 1);
    v18 = *(_BYTE *)(a2 + 2);
    v19 = *(_BYTE *)(a2 + 3);
    v16 -= 4;
    *(_BYTE *)a4 = *(_BYTE *)a2;
    *(_BYTE *)(a4 + 1) = v17;
    *(_BYTE *)(a4 + 2) = v18;
    *(_BYTE *)(a4 + 3) = v19;
  }
  v5 = __CFADD__(v16, 2);
  v20 = v16 + 2;
  if ( v5 )
  {
    a2 -= 2;
    a4 -= 2;
    v21 = *(_BYTE *)(a2 + 1);
    v20 -= 2;
    *(_BYTE *)a4 = *(_BYTE *)a2;
    *(_BYTE *)(a4 + 1) = v21;
  }
  if ( v20 != -2 )
    *(_BYTE *)(a4 - 1) = *(_BYTE *)(a2 - 1);
}
