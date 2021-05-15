// SepDeleteTokenUserAndGroups 
 
_DWORD *__fastcall SepDeleteTokenUserAndGroups(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r2
  unsigned int v3; // r5
  unsigned int *v4; // r2
  unsigned int v5; // r1
  signed int v6; // r1

  v1 = result;
  if ( result[162] )
  {
    v2 = result[46];
    if ( v2 != -1 )
    {
      *(_DWORD *)(result[37] + 8 * v2) = 0;
      result[46] = -1;
    }
    result = (_DWORD *)ExFreePoolWithTag(result[162]);
    v1[162] = 0;
  }
  v3 = v1[163];
  if ( !v3 )
    goto LABEL_10;
  __dmb(0xBu);
  v4 = (unsigned int *)(v3 + 4);
  do
  {
    v5 = __ldrex(v4);
    v6 = v5 - 1;
  }
  while ( __strex(v6, v4) );
  if ( v6 > 0 )
  {
    v1[163] = 0;
LABEL_10:
    v1[37] = 0;
    v1[31] = 0;
    return result;
  }
  if ( v6 )
    sub_7DBAE4();
  __dmb(0xBu);
  SepLogTokenSidManagement(5, v3, 0, v1);
  result = (_DWORD *)ExFreePoolWithTag(v3);
  v1[163] = 0;
  v1[37] = 0;
  v1[31] = 0;
  return result;
}
