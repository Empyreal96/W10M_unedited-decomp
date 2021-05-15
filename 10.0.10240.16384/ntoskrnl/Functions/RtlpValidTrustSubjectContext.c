// RtlpValidTrustSubjectContext 
 
int __fastcall RtlpValidTrustSubjectContext(int a1, int a2, int a3, int *a4)
{
  int result; // r0
  int *v5; // [sp+0h] [bp-8h] BYREF

  v5 = a4;
  LOBYTE(v5) = 0;
  if ( !a1 )
    return sub_5552FC();
  *a4 = RtlSidDominatesForTrust(a1, a2, &v5);
  result = (unsigned __int8)v5;
  if ( !(_BYTE)v5 )
    JUMPOUT(0x5552FE);
  return result;
}
