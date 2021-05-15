// SepRemoveAceFromTokenDefaultDacl 
 
int __fastcall SepRemoveAceFromTokenDefaultDacl(int result, unsigned __int16 *a2, int a3, unsigned int a4)
{
  int v4; // r4
  unsigned int v5; // [sp+0h] [bp-8h] BYREF

  v5 = a4;
  v4 = *(_DWORD *)(result + 164);
  v5 = 0;
  if ( v4 )
  {
    result = RtlFindAceBySid(v4, a2, &v5);
    if ( result )
      result = RtlDeleteAce(v4, v5);
  }
  return result;
}
