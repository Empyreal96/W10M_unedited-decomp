// IopLiveDumpValidateSecondaryData 
 
int __fastcall IopLiveDumpValidateSecondaryData(_DWORD *a1)
{
  _DWORD *v1; // r2
  int result; // r0

  if ( a1[1] || *a1 )
    return -1073741811;
  v1 = (_DWORD *)a1[2];
  result = 0;
  while ( v1 )
  {
    if ( v1[6] || !v1[4] || !v1[5] )
      return -1073741811;
    v1 = (_DWORD *)v1[7];
  }
  return result;
}
