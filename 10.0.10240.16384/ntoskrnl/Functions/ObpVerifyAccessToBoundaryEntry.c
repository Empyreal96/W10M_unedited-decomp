// ObpVerifyAccessToBoundaryEntry 
 
int __fastcall ObpVerifyAccessToBoundaryEntry(int *a1, int *a2)
{
  int v3; // r3
  int v6; // r1
  char v7; // r2
  int v8; // [sp+0h] [bp-148h]
  int v9; // [sp+20h] [bp-128h] BYREF
  char v10[24]; // [sp+28h] [bp-120h] BYREF
  unsigned __int8 v11[88]; // [sp+40h] [bp-108h] BYREF
  char v12[176]; // [sp+98h] [bp-B0h] BYREF

  v3 = *a1;
  if ( *a1 != 2 )
  {
    if ( v3 == 3 )
      JUMPOUT(0x7EF7DA);
    if ( v3 != 1 )
      JUMPOUT(0x7EF836);
    return 1;
  }
  if ( RtlIsPackageSid((int)(a1 + 2)) )
    return sub_7EF7A0();
  RtlCreateAcl((int)v12, 0xA0u, 2);
  RtlAddAccessAllowedAce((int)v12, 2, 983055, (int)(a1 + 2));
  if ( a2[4] )
    JUMPOUT(0x7EF7CA);
  RtlCreateAcl((int)v11, 0x54u, 2);
  RtlAddMandatoryAce(v11, v6, 0, a2[5], v8, 7);
  RtlCreateSecurityDescriptor(v10, 1);
  RtlSetDaclSecurityDescriptor((int)v10, 1, (int)v12, 0);
  RtlSetSaclSecurityDescriptor((int)v10, 1, (int)v11, 0);
  v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  return SeAccessCheckWithHint((int)v10, 1, a2, 1, 0xF000Fu, 0, 0, ObpDirectoryObjectType + 52, v7, &v9, a2 + 6) != 0;
}
