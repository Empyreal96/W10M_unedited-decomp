// MiCreateMemoryEvent 
 
int __fastcall MiCreateMemoryEvent(int a1)
{
  int v2; // r4
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r5
  unsigned int v6; // r0
  unsigned int v7; // r0
  char v9[8]; // [sp+8h] [bp-58h] BYREF
  char v10[24]; // [sp+10h] [bp-50h] BYREF
  int v11[14]; // [sp+28h] [bp-38h] BYREF

  v2 = RtlCreateSecurityDescriptor(v10, 1);
  if ( v2 < 0 )
    return v2;
  v3 = *(unsigned __int8 *)(SeLocalSystemSid + 1)
     + *(unsigned __int8 *)(SeAllAppPackagesSid + 1)
     + *(unsigned __int8 *)(SeWorldSid + 1)
     + *(unsigned __int8 *)(SeAliasAdminsSid + 1)
     + 22;
  v4 = ExAllocatePoolWithTag(1, 4 * v3, 1818452292);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  v2 = RtlCreateAcl(v4, 4 * v3, 2);
  v6 = v5;
  if ( v2 < 0
    || (v2 = RtlAddAccessAllowedAce(v5, 2, 1179649, SeWorldSid), v6 = v5, v2 < 0)
    || (v2 = RtlAddAccessAllowedAce(v5, 2, 2031619, SeAliasAdminsSid), v6 = v5, v2 < 0)
    || (v2 = RtlAddAccessAllowedAce(v5, 2, 2031619, SeLocalSystemSid), v6 = v5, v2 < 0) )
  {
LABEL_14:
    ExFreePoolWithTag(v6);
    return v2;
  }
  v2 = RtlAddAccessAllowedAce(v5, 2, 1179649, SeAllAppPackagesSid);
  if ( v2 < 0 || (v2 = RtlSetDaclSecurityDescriptor((int)v10, 1, v5, 0), v2 < 0) )
  {
    v6 = v5;
    goto LABEL_14;
  }
  v11[0] = 24;
  v11[1] = 0;
  v11[2] = a1;
  v11[3] = 528;
  v11[4] = (int)v10;
  v11[5] = 0;
  v2 = NtCreateEvent((unsigned int)v9, 2031619, (int)v11, 0, 0);
  v7 = ExFreePoolWithTag(v5);
  if ( v2 >= 0 )
    return sub_96A04C(v7);
  return v2;
}
