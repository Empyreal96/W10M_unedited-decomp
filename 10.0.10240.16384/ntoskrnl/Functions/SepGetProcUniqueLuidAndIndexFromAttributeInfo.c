// SepGetProcUniqueLuidAndIndexFromAttributeInfo 
 
int __fastcall SepGetProcUniqueLuidAndIndexFromAttributeInfo(int a1, _DWORD *a2, _DWORD *a3)
{
  int result; // r0
  int v7; // r2
  int v8; // [sp+0h] [bp-38h] BYREF
  _DWORD v9[8]; // [sp+4h] [bp-34h] BYREF

  if ( (SepTokenSingletonAttributesConfig & 3) != 3 )
    return -1073741275;
  memset(v9, 0, sizeof(v9));
  v8 = a1;
  v9[0] = SepProcUniqueAttributeName;
  v9[1] = off_61795C;
  result = AuthzBasepQuerySecurityAttributeAndValues(&v8);
  if ( result >= 0 )
  {
    *a2 = *(_DWORD *)v9[5];
    result = AuthzBasepQuerySecurityAttributeAndValues(&v8);
    if ( result >= 0 )
    {
      v7 = v9[5];
      *a3 = *(_DWORD *)v9[5];
      a3[1] = *(_DWORD *)(v7 + 4);
    }
  }
  return result;
}
