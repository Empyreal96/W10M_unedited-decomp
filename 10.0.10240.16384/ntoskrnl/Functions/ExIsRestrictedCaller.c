// ExIsRestrictedCaller 
 
BOOL __fastcall ExIsRestrictedCaller(char a1)
{
  int v1; // r4
  BOOL result; // r0
  int v3; // [sp+18h] [bp-20h] BYREF
  char v4[4]; // [sp+1Ch] [bp-1Ch] BYREF
  char v5[24]; // [sp+20h] [bp-18h] BYREF

  result = 0;
  if ( a1 )
  {
    SeCaptureSubjectContext(v5);
    v1 = SeAccessCheck(
           SeMediumDaclSd,
           (int)v5,
           0,
           0x20000,
           0,
           0,
           (int)ExpRestrictedGenericMapping,
           1,
           (int)v4,
           (int)&v3);
    SeReleaseSubjectContext(v5);
    if ( v1 != 1 || v3 < 0 )
      result = 1;
  }
  return result;
}
