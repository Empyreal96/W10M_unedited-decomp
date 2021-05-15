// RtlpQueryPackageIdentityAttributes 
 
int __fastcall RtlpQueryPackageIdentityAttributes(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r6
  int v6; // r7
  int result; // r0
  _DWORD *v10; // r2
  int v11; // r3

  v5 = 1;
  v6 = 1;
  if ( a4 )
    v6 = 2;
  result = SeQuerySecurityAttributesToken(a1, &dword_4015A0, v6, a3);
  if ( result < 0 )
  {
    if ( result != -1073741275 )
      return result;
    if ( v6 == 1 )
      return result;
    result = SeQuerySecurityAttributesToken(a1, &dword_4015A0, 1, a3);
    if ( result < 0 )
      return result;
    v5 = 0;
  }
  if ( !*(_DWORD *)(a3 + 4) )
    return -1073741275;
  if ( a4 )
  {
    if ( v5 )
    {
      v10 = *(_DWORD **)(*(_DWORD *)(a3 + 8) + 44);
      *a4 = *v10;
      v11 = v10[1];
    }
    else
    {
      v11 = 0;
      *a4 = 0;
    }
    a4[1] = v11;
  }
  return 0;
}
