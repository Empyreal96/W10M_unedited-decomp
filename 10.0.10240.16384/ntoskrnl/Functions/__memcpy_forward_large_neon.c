// __memcpy_forward_large_neon 
 
void __fastcall _memcpy_forward_large_neon(int a1, __int64 *a2, unsigned int a3, int a4)
{
  bool v4; // cf
  unsigned int v5; // r2
  __int64 v6; // d0
  __int64 v7; // d1
  __int64 v8; // d2
  __int64 v9; // d3
  __int64 v10; // d0
  __int64 v11; // d1
  __int64 v12; // d2
  __int64 v13; // d3
  unsigned int v14; // r2
  __int64 v15; // d0
  __int64 v16; // d1
  unsigned int v17; // r2
  __int64 v18; // d0
  unsigned int v19; // r2
  char v20; // d0.b[0]
  char v21; // d1.b[0]
  char v22; // d2.b[0]
  char v23; // d3.b[0]
  unsigned int v24; // r2
  char v25; // d0.b[0]
  char v26; // d1.b[0]

  v4 = a3 >= 0x20;
  v5 = a3 - 32;
  if ( v4 )
  {
    v4 = v5 >= 0x20;
    v5 -= 32;
    __pld(a2 + 4);
    for ( ; v4; a4 += 32 )
    {
      __pld(a2 + 8);
      v6 = *a2;
      v7 = a2[1];
      v8 = a2[2];
      v9 = a2[3];
      a2 += 4;
      v4 = v5 >= 0x20;
      v5 -= 32;
      *(_QWORD *)a4 = v6;
      *(_QWORD *)(a4 + 8) = v7;
      *(_QWORD *)(a4 + 16) = v8;
      *(_QWORD *)(a4 + 24) = v9;
    }
    v10 = *a2;
    v11 = a2[1];
    v12 = a2[2];
    v13 = a2[3];
    a2 += 4;
    *(_QWORD *)a4 = v10;
    *(_QWORD *)(a4 + 8) = v11;
    *(_QWORD *)(a4 + 16) = v12;
    *(_QWORD *)(a4 + 24) = v13;
    a4 += 32;
  }
  v4 = __CFADD__(v5, 16);
  v14 = v5 + 16;
  if ( v4 )
  {
    v15 = *a2;
    v16 = a2[1];
    a2 += 2;
    v14 -= 16;
    *(_QWORD *)a4 = v15;
    *(_QWORD *)(a4 + 8) = v16;
    a4 += 16;
  }
  v4 = __CFADD__(v14, 8);
  v17 = v14 + 8;
  if ( v4 )
  {
    v18 = *a2++;
    v17 -= 8;
    *(_QWORD *)a4 = v18;
    a4 += 8;
  }
  v4 = __CFADD__(v17, 4);
  v19 = v17 + 4;
  if ( v4 )
  {
    v20 = *(_BYTE *)a2;
    v21 = *((_BYTE *)a2 + 1);
    v22 = *((_BYTE *)a2 + 2);
    v23 = *((_BYTE *)a2 + 3);
    a2 += 4;
    v19 -= 4;
    *(_BYTE *)a4 = v20;
    *(_BYTE *)(a4 + 1) = v21;
    *(_BYTE *)(a4 + 2) = v22;
    *(_BYTE *)(a4 + 3) = v23;
    a4 += 32;
  }
  v4 = __CFADD__(v19, 2);
  v24 = v19 + 2;
  if ( v4 )
  {
    v25 = *(_BYTE *)a2;
    v26 = *((_BYTE *)a2 + 1);
    a2 += 2;
    v24 -= 2;
    *(_BYTE *)a4 = v25;
    *(_BYTE *)(a4 + 1) = v26;
    a4 += 16;
  }
  if ( v24 != -2 )
    *(_BYTE *)a4 = *(_BYTE *)a2;
}
