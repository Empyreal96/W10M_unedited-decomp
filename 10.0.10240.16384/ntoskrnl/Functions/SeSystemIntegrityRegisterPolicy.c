// SeSystemIntegrityRegisterPolicy 
 
int __fastcall SeSystemIntegrityRegisterPolicy(int a1, unsigned int a2)
{
  int v2; // r4
  int v4; // r0

  v2 = 0;
  if ( a2 < 4 )
    return -1073741811;
  g_SiPolicyBlob = a2;
  v4 = ExAllocatePoolWithTag(512, a2, 1767073107);
  dword_64A560 = v4;
  if ( !v4 )
    return -1073741801;
  memmove(v4, a1, g_SiPolicyBlob);
  return v2;
}
