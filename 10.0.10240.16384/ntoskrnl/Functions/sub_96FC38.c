// sub_96FC38 
 
int __fastcall sub_96FC38(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  unsigned int v6; // r5
  unsigned int v7; // r9
  unsigned int v8; // r10
  int v9; // lr
  _DWORD *v10; // r2
  _DWORD *v11; // r3
  unsigned int v12; // r7
  unsigned int v13; // r8
  int v14; // r6
  _DWORD *v15; // r1
  _DWORD *v16; // r4
  _DWORD *v17; // r1
  BOOL v18; // r0
  _DWORD *v19; // lr
  unsigned int v20; // r4
  int v21; // r4
  unsigned int v22; // lr
  int v23; // r6
  __int64 v24; // kr00_8
  int v25; // r0
  int v27; // [sp-30h] [bp-30h]
  int v28; // [sp-2Ch] [bp-2Ch]
  int v29; // [sp-28h] [bp-28h]
  int (__fastcall *v30)(int, int, int, int, _DWORD *, int, _DWORD *); // [sp-4h] [bp-4h]
  _DWORD *i; // [sp+8h] [bp+8h]

  v10 = (_DWORD *)(a1 + 24);
  v11 = *(_DWORD **)(a1 + 24);
  v12 = v8 >> 12;
  for ( i = v11; ; v11 = i )
  {
    v13 = (v9 + 1023) & 0xFFFFFC00;
    v14 = v9 + 1;
    v15 = v11;
    if ( v11 == v10 )
    {
      v16 = a5;
    }
    else
    {
      do
      {
        v16 = v15;
        a5 = v15;
        if ( v15[3] == v12 )
          break;
        v15 = (_DWORD *)*v15;
      }
      while ( v15 != v10 );
    }
    v17 = (_DWORD *)*v16;
    v18 = (_DWORD *)*v16 != v10 || (v14 & 0x3FF) == 0;
    if ( v17 != v10 )
    {
      do
      {
        v19 = v17;
        v20 = v17[3];
        v17 = (_DWORD *)*v17;
        if ( v20 >= v13 )
          break;
        if ( v20 != v14 )
          goto LABEL_38;
        v14 += v19[4];
        if ( v19[2] != 5 && v20 != v8 >> 12 && v20 != v6 >> 12 )
        {
          v18 = 0;
          break;
        }
      }
      while ( v14 != v13 && v17 != v10 );
      v16 = a5;
    }
    if ( v18 )
    {
      v21 = v16[1];
      v22 = v12;
      if ( (_DWORD *)v21 == v10 )
      {
        if ( (v12 & 0x3FF) != 0 )
LABEL_23:
          v18 = 0;
      }
      else
      {
        do
        {
          v23 = v21;
          v24 = *(_QWORD *)(v21 + 12);
          v21 = *(_DWORD *)(v21 + 4);
          if ( HIDWORD(v24) + (int)v24 <= v7 )
            break;
          if ( HIDWORD(v24) + (_DWORD)v24 != v22 )
            goto LABEL_38;
          v22 = v24;
          if ( *(_DWORD *)(v23 + 8) != 5 && (_DWORD)v24 != v8 >> 12 && (_DWORD)v24 != v6 >> 12 )
            goto LABEL_23;
        }
        while ( (_DWORD)v24 != v7 && (_DWORD *)v21 != v10 );
      }
    }
    if ( !v18 )
      break;
    if ( v12 == v6 >> 12
      || (v12 = v6 >> 12, v7 == ((v6 >> 12) & 0xFFFFFC00)) && v13 == ((a6 + (v6 >> 12) + 1022) & 0xFFFFFC00) )
    {
      v25 = 1;
      return v30(v25, v27, v28, v29, a5, a6, i);
    }
    v7 = (v6 >> 12) & 0xFFFFFC00;
    v9 = a6 + (v6 >> 12) - 1;
  }
LABEL_38:
  v25 = 0;
  return v30(v25, v27, v28, v29, a5, a6, i);
}
