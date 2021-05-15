// FsRtlpValidateExtraCreateParameters 
 
int __fastcall FsRtlpValidateExtraCreateParameters(int result)
{
  _DWORD *v1; // r2

  v1 = *(_DWORD **)(result + 8);
  *(_DWORD *)(result + 4) |= 1u;
  if ( v1 == (_DWORD *)(result + 8) )
    sub_806CAC();
  do
  {
    v1[7] |= 1u;
    v1 = (_DWORD *)*v1;
  }
  while ( v1 != (_DWORD *)(result + 8) );
  return result;
}
