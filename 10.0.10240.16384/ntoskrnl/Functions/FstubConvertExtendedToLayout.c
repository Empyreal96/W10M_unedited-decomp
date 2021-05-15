// FstubConvertExtendedToLayout 
 
_DWORD *__fastcall FstubConvertExtendedToLayout(_DWORD *a1)
{
  _DWORD *result; // r0
  unsigned int v3; // r5
  _DWORD *v4; // r2
  _DWORD *v5; // r1
  int v6; // r3

  if ( *a1 )
    return 0;
  result = (_DWORD *)ExAllocatePoolWithTag(512, 32 * a1[1] + 8, 1114927942);
  if ( !result )
    return 0;
  v3 = 0;
  result[1] = a1[2];
  *result = a1[1];
  if ( a1[1] )
  {
    v4 = a1 + 12;
    v5 = result + 2;
    do
    {
      ++v3;
      *v5 = v4[2];
      v5[1] = v4[3];
      v5[2] = v4[4];
      v5[3] = v4[5];
      *((_BYTE *)v5 + 27) = *((_BYTE *)v4 + 28);
      v5[5] = v4[6];
      *((_BYTE *)v5 + 24) = *((_BYTE *)v4 + 32);
      *((_BYTE *)v5 + 25) = *((_BYTE *)v4 + 33);
      *((_BYTE *)v5 + 26) = *((_BYTE *)v4 + 34);
      v6 = v4[9];
      v4 += 36;
      v5[4] = v6;
      v5 += 8;
    }
    while ( v3 < a1[1] );
  }
  return result;
}
