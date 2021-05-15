// GetPropertyFromPropArray 
 
int __fastcall GetPropertyFromPropArray(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r3
  int v8; // r8
  int i; // r7
  _DWORD *v10; // r6

  *a3 = 0;
  *a4 = 0;
  *a5 = 0;
  v6 = -1073741275;
  v8 = 0;
  if ( !*a1 )
    return v6;
  for ( i = 0; ; i += 40 )
  {
    v10 = (_DWORD *)(a1[1] + i);
    if ( v10[4] == a2[4] && !memcmp(a1[1] + i, (unsigned int)a2, 16) && v10[5] == a2[5] )
      break;
    if ( (unsigned int)++v8 >= *a1 )
      return -1073741275;
  }
  if ( v10[6] == a2[6] )
  {
    *a3 = *(_DWORD *)(a1[1] + 40 * v8 + 28);
    *a4 = *(_DWORD *)(a1[1] + 40 * v8 + 32);
    *a5 = *(_DWORD *)(a1[1] + 40 * v8 + 36);
    return 0;
  }
  return sub_7EE04C();
}
