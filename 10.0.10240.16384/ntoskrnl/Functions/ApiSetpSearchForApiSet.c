// ApiSetpSearchForApiSet 
 
int __fastcall ApiSetpSearchForApiSet(_DWORD *a1, unsigned __int16 *a2, int a3)
{
  int v3; // r8
  unsigned __int16 *v4; // r9
  unsigned int v5; // lr
  unsigned __int16 *v6; // r5
  int v7; // r6
  unsigned int v8; // r4
  unsigned int v9; // t1
  char *v10; // r4
  int v11; // r1
  int v12; // r2
  int v13; // r5
  unsigned int *v14; // r6

  v3 = a3;
  v4 = a2;
  v5 = 0;
  v6 = a2;
  if ( a3 )
  {
    v7 = a3;
    do
    {
      v9 = *v6++;
      v8 = v9;
      if ( v9 <= 0x5A && v8 >= 0x41 )
        return sub_50F440();
      --v7;
      v5 = a1[6] * v5 + v8;
    }
    while ( v7 );
  }
  v10 = 0;
  v11 = 0;
  v12 = a1[3] - 1;
  if ( v12 < 0 )
    return (int)v10;
  while ( 1 )
  {
    v13 = (v12 + v11) >> 1;
    v14 = (_DWORD *)((char *)&a1[2 * v13] + a1[5]);
    if ( v5 >= *v14 )
      break;
    v12 = v13 - 1;
LABEL_8:
    if ( v11 > v12 )
      return (int)v10;
  }
  if ( v5 > *v14 )
  {
    v11 = v13 + 1;
    goto LABEL_8;
  }
  v10 = (char *)&a1[6 * v14[1]] + a1[4];
  if ( v10 )
  {
    if ( RtlCompareUnicodeStrings(v4, v3, (char *)a1 + *((_DWORD *)v10 + 1), *((_DWORD *)v10 + 3) >> 1) )
      v10 = 0;
  }
  return (int)v10;
}
