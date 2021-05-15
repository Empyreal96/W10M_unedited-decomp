// PopCreateNotificationName 
 
int PopCreateNotificationName()
{
  char v1[24]; // [sp+10h] [bp-118h] BYREF
  char v2[256]; // [sp+28h] [bp-100h] BYREF

  RtlCreateAcl((int)v2, 0xF8u, 2);
  RtlAddAccessAllowedAce((int)v2, 2, 2031619, SeLocalSystemSid);
  RtlAddAccessAllowedAce((int)v2, 2, 1179649, SeWorldSid);
  RtlAddAccessAllowedAce((int)v2, 2, 1179649, SeAllAppPackagesSid);
  RtlCreateSecurityDescriptor(v1, 1);
  RtlSetDaclSecurityDescriptor((int)v1, 1, (int)v2, 0);
  return ZwCreateWnfStateName();
}
