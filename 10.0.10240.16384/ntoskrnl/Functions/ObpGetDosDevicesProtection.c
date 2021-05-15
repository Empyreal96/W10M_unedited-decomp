// ObpGetDosDevicesProtection 
 
int __fastcall ObpGetDosDevicesProtection(_BYTE *a1)
{
  int v2; // r0
  int v4; // r10
  int v5; // r0
  unsigned __int8 *v6; // r4
  int v7[8]; // [sp+0h] [bp-20h] BYREF

  v7[0] = 0;
  v2 = RtlCreateSecurityDescriptor(a1, 1);
  if ( (ObpProtectionMode & 1) == 0 )
    return sub_96E8C0(v2);
  v4 = *(unsigned __int8 *)(SeCreatorOwnerSid + 1)
     + 2 * (*(unsigned __int8 *)(SeWorldSid + 1) + *(unsigned __int8 *)(SeLocalSystemSid + 1) + 16)
     + *(unsigned __int8 *)(SeAliasAdminsSid + 1);
  v5 = ExAllocatePoolWithTag(1, 4 * v4, 1818452292);
  v6 = (unsigned __int8 *)v5;
  if ( !v5 )
    return -1073741801;
  RtlCreateAcl(v5, 4 * v4, 2);
  RtlAddAccessAllowedAce((int)v6, 2, -1610612736, SeWorldSid);
  RtlAddAccessAllowedAce((int)v6, 2, 0x10000000, SeLocalSystemSid);
  RtlAddAccessAllowedAce((int)v6, 2, 0x20000000, SeWorldSid);
  RtlGetAce(v6, 2u, (int)v7);
  *(_BYTE *)(v7[0] + 1) |= 0xBu;
  RtlAddAccessAllowedAce((int)v6, 2, 0x10000000, SeAliasAdminsSid);
  RtlGetAce(v6, 3u, (int)v7);
  *(_BYTE *)(v7[0] + 1) |= 0xBu;
  RtlAddAccessAllowedAce((int)v6, 2, 0x10000000, SeLocalSystemSid);
  RtlGetAce(v6, 4u, (int)v7);
  *(_BYTE *)(v7[0] + 1) |= 0xBu;
  RtlAddAccessAllowedAce((int)v6, 2, 0x10000000, SeCreatorOwnerSid);
  RtlGetAce(v6, 5u, (int)v7);
  *(_BYTE *)(v7[0] + 1) |= 0xBu;
  RtlSetDaclSecurityDescriptor((int)a1, 1, (int)v6, 0);
  return 0;
}
