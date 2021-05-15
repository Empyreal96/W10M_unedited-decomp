// BiGetFilePathFromEfiPath 
 
int __fastcall BiGetFilePathFromEfiPath(_BYTE *a1, int *a2, int *a3)
{
  int v6; // r6
  unsigned __int8 *i; // r1
  int v8; // r2
  int v9; // r6
  int v10; // r0
  int v11; // r7
  _WORD *v12; // r8
  unsigned __int8 *j; // r5
  int v14; // r2
  unsigned int v15; // r4
  unsigned int v16; // r3

  if ( (*a1 & 0x7F) == 127 )
    return -1073741766;
  v6 = 0;
  for ( i = &a1[(unsigned __int8)a1[2] | ((unsigned __int8)a1[3] << 8)]; ; i += i[2] | (i[3] << 8) )
  {
    v8 = *i;
    if ( (v8 & 0x7F) == 127 )
      break;
    if ( v8 == 4 && i[1] == 4 )
    {
      v16 = i[2] | (i[3] << 8);
      if ( v16 < 4 )
        return -1073741675;
      v6 += v16 - 4;
    }
  }
  if ( !v6 )
    return -1073741275;
  v9 = v6 + 2;
  v10 = ExAllocatePoolWithTag(1, v9, 1262764866);
  v11 = v10;
  if ( !v10 )
    return -1073741670;
  v12 = (_WORD *)v10;
  for ( j = &a1[(unsigned __int8)a1[2] | ((unsigned __int8)a1[3] << 8)]; ; j += j[2] | (j[3] << 8) )
  {
    v14 = *j;
    if ( (v14 & 0x7F) == 127 )
      break;
    if ( v14 == 4 && j[1] == 4 )
    {
      v15 = (j[2] | (j[3] << 8)) - 4;
      memmove((int)v12, (int)(j + 4), v15);
      v12 = (_WORD *)((char *)v12 + v15);
    }
  }
  *v12 = 0;
  *a2 = v11;
  *a3 = v9;
  return 0;
}
