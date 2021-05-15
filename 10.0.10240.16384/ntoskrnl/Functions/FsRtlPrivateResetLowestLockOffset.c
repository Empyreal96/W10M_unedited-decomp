// FsRtlPrivateResetLowestLockOffset 
 
_DWORD *__fastcall FsRtlPrivateResetLowestLockOffset(_DWORD *result)
{
  int v1; // r2
  int v2; // r4
  int i; // r3
  int v4; // r1
  _DWORD *v5; // r2
  int v6; // r3
  int j; // r3

  v1 = result[5];
  v2 = 0;
  if ( v1 )
  {
    for ( i = *(_DWORD *)(v1 + 4); i; i = *(_DWORD *)(i + 4) )
      v1 = i;
    v2 = *(_DWORD *)(v1 - 16);
  }
  else if ( !result[6] )
  {
    v6 = -1;
    *result = -1;
    goto LABEL_8;
  }
  v4 = result[6];
  if ( !v4 )
  {
    v5 = (_DWORD *)(v2 + 8);
LABEL_7:
    *result = *v5;
    v6 = v5[1];
LABEL_8:
    result[1] = v6;
    return result;
  }
  for ( j = *(_DWORD *)(v4 + 4); j; j = *(_DWORD *)(j + 4) )
    v4 = j;
  if ( !v2 )
  {
    v5 = (_DWORD *)(v4 + 16);
    goto LABEL_7;
  }
  return (_DWORD *)sub_51E340();
}
