// IovpAdvanceStackDownwards 
 
int __fastcall IovpAdvanceStackDownwards(int a1, char a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  int v8; // lr
  BOOL v9; // r5
  unsigned __int8 *v10; // r4
  int v11; // r8
  int v12; // r10
  int v13; // r5
  _DWORD *v14; // r6
  _DWORD *v15; // r7
  unsigned __int8 *v16; // r3
  int v17; // r9
  unsigned __int8 *v18; // r8
  int v19; // r3
  int result; // r0
  int v22; // [sp+4h] [bp-24h]

  v8 = a3;
  v9 = a4 == 0;
  v10 = (unsigned __int8 *)(a1 + 80 * a2 - 80);
  v11 = a7;
  if ( !*v10 && a7 )
  {
    memset(v10, 0, 80);
    v8 = a3;
    *((_DWORD *)v10 + 3) = v10 + 12;
    *((_DWORD *)v10 + 4) = v10 + 12;
    *((_DWORD *)v10 + 5) = a3;
  }
  v12 = 0;
  if ( v9 )
  {
    v13 = 0;
    v14 = 0;
    v15 = 0;
  }
  else
  {
    if ( a5 > 0 )
    {
      v16 = &v10[80 * a5];
      v13 = *((_DWORD *)v16 + 2);
      v17 = *((_DWORD *)v16 + 6);
      v15 = v16 + 32;
      *((_DWORD *)v10 + 2) = v13;
      v14 = v16 + 40;
      v12 = *((_DWORD *)v16 + 1) & 0x10000000;
      *((_DWORD *)v10 + 1) |= v12;
      goto LABEL_10;
    }
    v13 = *((_DWORD *)v10 + 2);
    v15 = 0;
    v14 = 0;
  }
  v17 = 0;
LABEL_10:
  if ( a5 > 1 )
  {
    v22 = a5 - 1;
    v18 = v10;
    do
    {
      memset(v18 + 80, 0, 80);
      v8 += 40;
      *((_DWORD *)v18 + 23) = v18 + 92;
      *((_DWORD *)v18 + 24) = v18 + 92;
      v18[80] = 1;
      v18 += 80;
      *((_DWORD *)v18 + 5) = v8;
      *((_DWORD *)v18 + 2) = v13;
      *((_DWORD *)v18 + 8) = *v15;
      *((_DWORD *)v18 + 9) = v15[1];
      *((_DWORD *)v18 + 10) = *v14;
      v19 = v14[1];
      *((_DWORD *)v18 + 6) = v17;
      *((_DWORD *)v18 + 11) = v19;
      *((_DWORD *)v18 + 1) |= v12 | 0x800000;
      --v22;
    }
    while ( v22 );
    v11 = a7;
  }
  *a8 = v10;
  if ( !v11 )
    return *v10;
  if ( a6 )
    *((_DWORD *)v10 + 2) = v10;
  result = *v10;
  *v10 = 1;
  return result;
}
