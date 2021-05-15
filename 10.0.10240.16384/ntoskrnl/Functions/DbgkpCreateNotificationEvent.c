// DbgkpCreateNotificationEvent 
 
int __fastcall DbgkpCreateNotificationEvent(int a1)
{
  int v2; // r4
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r5
  unsigned int v6; // r0
  unsigned int v7; // r0
  char v9[24]; // [sp+10h] [bp-50h] BYREF
  int v10; // [sp+28h] [bp-38h]
  int v11; // [sp+2Ch] [bp-34h]
  int v12; // [sp+30h] [bp-30h]
  int v13; // [sp+34h] [bp-2Ch]
  char *v14; // [sp+38h] [bp-28h]
  int v15; // [sp+3Ch] [bp-24h]

  v2 = RtlCreateSecurityDescriptor(v9, 1);
  if ( v2 < 0 )
    return v2;
  v3 = *(unsigned __int8 *)(SeAllAppPackagesSid + 1)
     + *(unsigned __int8 *)(SeWorldSid + 1)
     + *(unsigned __int8 *)(SeLocalSystemSid + 1)
     + *(unsigned __int8 *)(SeLocalSid + 1)
     + 22;
  v4 = ExAllocatePoolWithTag(1, 4 * v3, 1818452292);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  v2 = RtlCreateAcl(v4, 4 * v3, 2);
  v6 = v5;
  if ( v2 < 0
    || (v2 = RtlAddAccessAllowedAce(v5, 2, 1179649, SeLocalSid), v6 = v5, v2 < 0)
    || (v2 = RtlAddAccessAllowedAce(v5, 2, 1179649, SeAllAppPackagesSid), v6 = v5, v2 < 0)
    || (v2 = RtlAddAccessAllowedAce(v5, 2, 2031619, SeLocalSystemSid), v6 = v5, v2 < 0) )
  {
LABEL_14:
    ExFreePoolWithTag(v6);
    return v2;
  }
  v2 = RtlAddAccessAllowedAce(v5, 2, 1179649, SeWorldSid);
  if ( v2 < 0 || (v2 = RtlSetDaclSecurityDescriptor((int)v9, 1, v5, 0), v2 < 0) )
  {
    v6 = v5;
    goto LABEL_14;
  }
  v10 = 24;
  v11 = 0;
  v12 = a1;
  v13 = 528;
  v14 = v9;
  v15 = 0;
  v2 = ZwCreateEvent();
  v7 = ExFreePoolWithTag(v5);
  if ( v2 >= 0 )
    return sub_96E3C4(v7);
  return v2;
}
