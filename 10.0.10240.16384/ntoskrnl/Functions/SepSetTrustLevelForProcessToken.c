// SepSetTrustLevelForProcessToken 
 
int __fastcall SepSetTrustLevelForProcessToken(int a1, int a2, _BYTE *a3, int a4)
{
  unsigned __int16 *v6; // r4
  unsigned __int16 *v7; // r0
  int result; // r0
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  *a3 = 0;
  LOBYTE(v9[0]) = *(_BYTE *)(a2 + 734);
  v6 = (unsigned __int16 *)SepSidFromProcessProtection(v9);
  v7 = *(unsigned __int16 **)(a1 + 640);
  if ( v7 )
  {
    if ( v6 && RtlEqualSid(v7, v6) )
      return 0;
  }
  else if ( !v6 )
  {
    return 0;
  }
  result = SepSetTokenTrust(a1, v6);
  if ( result >= 0 )
    *a3 = 1;
  return result;
}
