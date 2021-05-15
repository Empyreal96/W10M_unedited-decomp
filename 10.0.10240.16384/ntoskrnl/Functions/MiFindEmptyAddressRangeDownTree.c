// MiFindEmptyAddressRangeDownTree 
 
int __fastcall MiFindEmptyAddressRangeDownTree(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int *a6)
{
  unsigned int v7; // r5
  unsigned int v8; // r9
  unsigned int v9; // lr
  _DWORD *v10; // r3
  _DWORD *v12; // r1
  _DWORD *v13; // r8
  _DWORD *v14; // r0
  unsigned int v15; // r10
  unsigned int v16; // r2
  _DWORD *v17; // r3
  _DWORD *v18; // r2
  _DWORD *v19; // r4
  unsigned int v20; // r3
  unsigned int v21; // r3
  unsigned int v22; // r0
  _DWORD v23[18]; // [sp+0h] [bp-48h] BYREF

  v7 = (a2 + 4095) & 0xFFFFF000;
  if ( a4 >= a5 )
    return -1073741801;
  if ( a5 - a4 + 1 < v7 )
    return -1073741801;
  v8 = a3 - 1;
  v9 = (a5 - v7) & ~(a3 - 1);
  if ( v9 < a4 )
    return -1073741801;
  v10 = (_DWORD *)*a1;
  if ( !*a1 )
    return sub_7E69E0();
  v12 = 0;
  do
  {
    v13 = v10;
    v10 = (_DWORD *)v10[1];
  }
  while ( v10 );
  v14 = v13;
  v15 = a3 >> 12;
  while ( 1 )
  {
    v16 = v15 - 1;
    if ( v13 )
    {
      v12 = v13;
      v23[3] = (a5 + 1) >> 12;
      v13 = 0;
      v14 = v23;
    }
    else
    {
      v17 = (_DWORD *)*v12;
      v18 = v12;
      if ( *v12 )
      {
        do
        {
          v12 = v17;
          v17 = (_DWORD *)v17[1];
        }
        while ( v17 );
      }
      else
      {
        while ( 1 )
        {
          v12 = (_DWORD *)(v12[2] & 0xFFFFFFFC);
          if ( !v12 || (_DWORD *)v12[1] == v18 )
            break;
          v18 = v12;
        }
      }
      v16 = v15 - 1;
    }
    if ( v12 )
    {
      v19 = v12;
      v20 = v12[4] + 1;
      if ( v20 < a4 >> 12 )
      {
        v20 = a4 >> 12;
        v19 = v23;
      }
      v21 = (v20 + v15 - 1) & ~v16;
    }
    else
    {
      v23[4] = 0;
      v19 = v23;
      v21 = (v15 + (a4 >> 12) - 1) & ~(v15 - 1);
    }
    if ( v21 <= v9 >> 12 )
    {
      v22 = v14[3];
      if ( v22 > a5 >> 12 )
        v22 = a5 >> 12;
      if ( v22 > v21 && v7 >> 12 <= v22 - v21 )
        break;
    }
    v14 = v19;
    if ( v19 == v23 )
      return -1073741801;
  }
  *a6 = ((v22 << 12) - v7) & ~v8;
  return 0;
}
