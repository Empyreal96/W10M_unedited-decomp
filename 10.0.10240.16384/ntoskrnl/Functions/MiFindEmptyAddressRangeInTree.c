// MiFindEmptyAddressRangeInTree 
 
int __fastcall MiFindEmptyAddressRangeInTree(_DWORD **a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int *a6)
{
  unsigned int v6; // lr
  unsigned int v7; // r6
  _DWORD *v9; // r2
  unsigned int v10; // r7
  unsigned int v11; // r0
  unsigned int v12; // r2
  int result; // r0
  unsigned int v14; // r4
  _DWORD *v15; // r1
  unsigned int v16; // r3
  _DWORD *v17; // r5
  unsigned int v18; // r2
  _DWORD *i; // r3
  int v20; // r3
  unsigned int v21; // r1
  unsigned int v22; // r1
  unsigned int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r2

  v6 = a3 >> 12;
  v7 = (unsigned int)(a2 + 4095) >> 12;
  if ( a4 > a5 )
    return -1073741801;
  v9 = *a1;
  v10 = v6 - 1;
  v11 = (v6 + (a4 >> 12) - 1) & ~(v6 - 1);
  if ( !*a1 )
    goto LABEL_3;
  v14 = a5 >> 12;
  if ( v11 > a5 >> 12 || v7 > v14 - v11 + 1 )
    return -1073741801;
  do
  {
    v15 = v9;
    v9 = (_DWORD *)*v9;
  }
  while ( v9 );
  v16 = v15[3];
  v17 = v15;
  if ( v16 > v11 && v7 <= v16 - v11 )
  {
LABEL_3:
    v12 = v11 << 12;
    result = 0;
    *a6 = v12;
    return result;
  }
  while ( 1 )
  {
    v18 = v15[1];
    if ( v18 )
    {
      for ( i = *(_DWORD **)v18; i; i = (_DWORD *)*i )
        v18 = (unsigned int)i;
    }
    else
    {
      v20 = v15[2];
      while ( 1 )
      {
        v18 = v20 & 0xFFFFFFFC;
        if ( (v20 & 0xFFFFFFFC) == 0 || *(_DWORD **)v18 == v15 )
          break;
        v20 = *(_DWORD *)(v18 + 8);
        v15 = (_DWORD *)v18;
      }
    }
    if ( !v18 )
      break;
    v21 = v17[4] + v6;
    if ( ((v21 - 1) & ~v10) >= v11 )
    {
      v22 = v21 & ~v10;
    }
    else
    {
      if ( *(_DWORD *)(v18 + 12) <= v11 )
        goto LABEL_27;
      v22 = v11;
    }
    if ( v22 >= v14 )
      return -1073741801;
    v23 = *(_DWORD *)(v18 + 12);
    if ( v23 > v22 && v7 <= v23 - v22 && v7 <= v14 - v22 )
      goto LABEL_35;
LABEL_27:
    v15 = (_DWORD *)v18;
    v17 = (_DWORD *)v18;
  }
  if ( (unsigned int)(MmHighestUserAddress - 0x10000) <= 0x7FFE0000 )
    v24 = MmHighestUserAddress - 0xFFFF;
  else
    v24 = MmUserProbeAddress;
  v25 = v24 >> 12;
  if ( v14 < v24 >> 12 )
    v25 = a5 >> 12;
  v22 = (v17[4] + v6) & ~v10;
  if ( v25 > v22 && v7 <= v25 - v22 )
  {
LABEL_35:
    result = 0;
    *a6 = v22 << 12;
    return result;
  }
  return -1073741801;
}
