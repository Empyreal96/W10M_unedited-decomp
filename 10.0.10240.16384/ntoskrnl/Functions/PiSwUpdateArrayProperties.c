// PiSwUpdateArrayProperties 
 
int __fastcall PiSwUpdateArrayProperties(_DWORD *a1, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  unsigned int v4; // r4
  int v5; // r10
  unsigned int v6; // r9
  _DWORD *v8; // r8
  unsigned int v9; // r7
  _DWORD *v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r5
  int v14; // r1
  int v15; // r0
  unsigned int v16; // [sp+0h] [bp-28h]

  v4 = a2;
  v5 = 0;
  v16 = a4;
  v6 = 0;
  v8 = a1;
  if ( !a4 )
    return v5;
  while ( 1 )
  {
    v9 = 0;
    if ( v4 )
      break;
LABEL_7:
    ++v6;
    a3 += 10;
    if ( v6 >= a4 )
      return v5;
  }
  while ( a3[4] != v8[4] || memcmp((unsigned int)a3, (unsigned int)v8, 16) || a3[5] != v8[5] )
  {
    v4 = a2;
    ++v9;
    v8 += 10;
    if ( v9 >= a2 )
    {
      v8 = a1;
LABEL_6:
      a4 = v16;
      goto LABEL_7;
    }
  }
  if ( a3[6] == v8[6] )
  {
    v8 = a1;
    v11 = &a1[10 * v9];
    v12 = v11[8];
    if ( a3[8] == v12 )
    {
LABEL_14:
      v11[7] = a3[7];
      if ( v12 )
        memmove(v11[9], a3[9], v12);
      v4 = a2;
      goto LABEL_6;
    }
    v13 = v11[9];
    v11[9] = 0;
    v14 = a3[8];
    if ( !v14 || (v15 = ExAllocatePoolWithTag(1, v14, 1466986064), (v11[9] = v15) != 0) )
    {
      if ( v13 )
        ExFreePoolWithTag(v13);
      v12 = a3[8];
      v11[8] = v12;
      goto LABEL_14;
    }
    v5 = -1073741670;
    a1[10 * v9 + 9] = v13;
    return v5;
  }
  return sub_7E938C();
}
