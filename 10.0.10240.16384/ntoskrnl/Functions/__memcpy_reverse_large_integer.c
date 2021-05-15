// __memcpy_reverse_large_integer 
 
void __fastcall _memcpy_reverse_large_integer(int a1, int a2, unsigned int a3, int a4)
{
  bool v4; // cf
  char v5; // t1
  __int16 v6; // t1
  unsigned int v7; // r2
  int v8; // r4
  int v9; // r5
  int v10; // r6
  int v11; // r7
  int v12; // r8
  int v13; // r9
  int v14; // r12
  int v15; // lr
  int v16; // r4
  int v17; // r5
  int v18; // r6
  int v19; // r7
  int v20; // r8
  int v21; // r9
  int v22; // r12
  int v23; // lr
  unsigned int v24; // r2
  int v25; // r4
  int v26; // r5
  int v27; // r6
  int v28; // r7
  unsigned int v29; // r2
  __int64 v30; // t1
  unsigned int v31; // r2
  int v32; // t1
  unsigned int v33; // r2
  __int16 v34; // t1

  v4 = __CFSHL__(a4, 31);
  __pld((void *)(a2 - 32));
  if ( (a4 & 1) != 0 )
  {
    v5 = *(_BYTE *)--a2;
    --a3;
    *(_BYTE *)--a4 = v5;
  }
  if ( v4 )
  {
    v6 = *(_WORD *)(a2 - 2);
    a2 -= 2;
    a3 -= 2;
    *(_WORD *)(a4 - 2) = v6;
    a4 -= 2;
  }
  v4 = a3 >= 0x20;
  v7 = a3 - 32;
  if ( v4 )
  {
    v4 = v7 >= 0x20;
    v7 -= 32;
    __pld((void *)(a2 - 64));
    for ( ; v4; a4 -= 32 )
    {
      __pld((void *)(a2 - 96));
      v8 = *(_DWORD *)(a2 - 32);
      v9 = *(_DWORD *)(a2 - 28);
      v10 = *(_DWORD *)(a2 - 24);
      v11 = *(_DWORD *)(a2 - 20);
      v12 = *(_DWORD *)(a2 - 16);
      v13 = *(_DWORD *)(a2 - 12);
      v14 = *(_DWORD *)(a2 - 8);
      v15 = *(_DWORD *)(a2 - 4);
      a2 -= 32;
      v4 = v7 >= 0x20;
      v7 -= 32;
      *(_DWORD *)(a4 - 32) = v8;
      *(_DWORD *)(a4 - 28) = v9;
      *(_DWORD *)(a4 - 24) = v10;
      *(_DWORD *)(a4 - 20) = v11;
      *(_DWORD *)(a4 - 16) = v12;
      *(_DWORD *)(a4 - 12) = v13;
      *(_DWORD *)(a4 - 8) = v14;
      *(_DWORD *)(a4 - 4) = v15;
    }
    v16 = *(_DWORD *)(a2 - 32);
    v17 = *(_DWORD *)(a2 - 28);
    v18 = *(_DWORD *)(a2 - 24);
    v19 = *(_DWORD *)(a2 - 20);
    v20 = *(_DWORD *)(a2 - 16);
    v21 = *(_DWORD *)(a2 - 12);
    v22 = *(_DWORD *)(a2 - 8);
    v23 = *(_DWORD *)(a2 - 4);
    a2 -= 32;
    *(_DWORD *)(a4 - 32) = v16;
    *(_DWORD *)(a4 - 28) = v17;
    *(_DWORD *)(a4 - 24) = v18;
    *(_DWORD *)(a4 - 20) = v19;
    *(_DWORD *)(a4 - 16) = v20;
    *(_DWORD *)(a4 - 12) = v21;
    *(_DWORD *)(a4 - 8) = v22;
    *(_DWORD *)(a4 - 4) = v23;
    a4 -= 32;
  }
  v4 = __CFADD__(v7, 16);
  v24 = v7 + 16;
  if ( v4 )
  {
    v25 = *(_DWORD *)(a2 - 16);
    v26 = *(_DWORD *)(a2 - 12);
    v27 = *(_DWORD *)(a2 - 8);
    v28 = *(_DWORD *)(a2 - 4);
    a2 -= 16;
    v24 -= 16;
    *(_DWORD *)(a4 - 16) = v25;
    *(_DWORD *)(a4 - 12) = v26;
    *(_DWORD *)(a4 - 8) = v27;
    *(_DWORD *)(a4 - 4) = v28;
    a4 -= 16;
  }
  v4 = __CFADD__(v24, 8);
  v29 = v24 + 8;
  if ( v4 )
  {
    v30 = *(_QWORD *)(a2 - 8);
    a2 -= 8;
    v29 -= 8;
    *(_QWORD *)(a4 - 8) = v30;
    a4 -= 8;
  }
  v4 = __CFADD__(v29, 4);
  v31 = v29 + 4;
  if ( v4 )
  {
    v32 = *(_DWORD *)(a2 - 4);
    a2 -= 4;
    v31 -= 4;
    *(_DWORD *)(a4 - 4) = v32;
    a4 -= 4;
  }
  v4 = __CFADD__(v31, 2);
  v33 = v31 + 2;
  if ( v4 )
  {
    v34 = *(_WORD *)(a2 - 2);
    a2 -= 2;
    v33 -= 2;
    *(_WORD *)(a4 - 2) = v34;
    a4 -= 2;
  }
  if ( v33 != -2 )
    *(_BYTE *)(a4 - 1) = *(_BYTE *)(a2 - 1);
}
