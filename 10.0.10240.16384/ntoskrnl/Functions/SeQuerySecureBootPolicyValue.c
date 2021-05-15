// SeQuerySecureBootPolicyValue 
 
int __fastcall SeQuerySecureBootPolicyValue(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int *a6)
{
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v12; // [sp+0h] [bp-18h] BYREF
  int v13[5]; // [sp+4h] [bp-14h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  if ( !dword_641874 )
    return -2143092730;
  v8 = SepSecureBootFindMatchingRegistryRule(a1, a1, a2);
  if ( !v8 )
    return -1073741772;
  v9 = SepSecureBootGetPolicyValueByRef(*(_DWORD *)(v8 + 12) + dword_64185C, a3, v13, &v12);
  if ( v9 >= 0 )
  {
    v10 = v12;
    *a6 = v12;
    if ( a4 )
    {
      if ( a5 < v10 )
        v9 = -1073741789;
      else
        memmove(a4, v13[0], v10);
    }
  }
  return v9;
}
