// SepMakeTokenEffectiveOnly 
 
_DWORD *__fastcall SepMakeTokenEffectiveOnly(_DWORD *result)
{
  int v1; // r1
  int v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  unsigned int v6; // r1
  int v7; // r3
  unsigned int v8; // r4
  unsigned int v9; // r5
  int v10; // r2
  _DWORD *v11; // r6
  _DWORD *v12; // r2

  v2 = result[19];
  v1 = result[18];
  v3 = result[17];
  result[16] &= v1;
  result[17] = v3 & v2;
  v4 = v1 & result[20];
  v5 = result[21];
  v6 = 1;
  result[20] = v4;
  v7 = v5 & v2;
  v8 = result[31];
  result[21] = v7;
  if ( v8 <= 1 )
  {
LABEL_6:
    result[31] = v8;
    return result;
  }
  v9 = v8 - 1;
  while ( 1 )
  {
    v10 = result[37];
    v11 = (_DWORD *)(v10 + 8 * v6);
    if ( (v11[1] & 0x34) == 0 )
      break;
    ++v6;
LABEL_5:
    if ( v6 >= v8 )
      goto LABEL_6;
  }
  if ( v6 != result[36] )
  {
    if ( v6 == result[46] )
      result[46] = -1;
    if ( v9 == result[46] )
      result[46] = v6;
    if ( v9 == result[36] )
      result[36] = v6;
    --v8;
    v12 = (_DWORD *)(v10 + 8 * v8);
    --v9;
    *v11 = *v12;
    v11[1] = v12[1];
    goto LABEL_5;
  }
  return (_DWORD *)sub_7E62A4();
}
