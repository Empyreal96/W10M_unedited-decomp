// ExpKeyedEventInitialization 
 
int ExpKeyedEventInitialization()
{
  int v0; // r4
  int v1; // r4
  int v2; // r0
  unsigned int v3; // r5
  unsigned int v5; // r0
  int v6; // r4
  int v7; // r0
  unsigned __int8 *v8; // r6
  int v9; // r1
  int v10; // [sp+0h] [bp-C8h]
  int v11; // [sp+8h] [bp-C0h]
  char v12[8]; // [sp+10h] [bp-B8h] BYREF
  int v13[8]; // [sp+18h] [bp-B0h] BYREF
  char v14[24]; // [sp+38h] [bp-90h] BYREF
  __int16 v15; // [sp+50h] [bp-78h]
  _WORD v16[43]; // [sp+52h] [bp-76h] BYREF

  memset(v16, 0, sizeof(v16));
  RtlInitUnicodeString((unsigned int)v12, L"KeyedEvent");
  v15 = 88;
  *(_DWORD *)&v16[3] = 0;
  *(_DWORD *)&v16[5] = 131073;
  *(_DWORD *)&v16[17] = 1;
  *(_DWORD *)&v16[19] = 0;
  *(_DWORD *)&v16[21] = 0;
  LOBYTE(v16[0]) |= 4u;
  *(_DWORD *)&v16[11] = 983043;
  *(_DWORD *)&v16[13] = 983043;
  *(_DWORD *)&v16[7] = 131074;
  *(_DWORD *)&v16[9] = 0x20000;
  v0 = ObCreateObjectType();
  if ( v0 < 0 )
    return v0;
  v0 = RtlCreateSecurityDescriptor(v14, 1);
  if ( v0 < 0 )
    return v0;
  v1 = *(unsigned __int8 *)(SeLocalSystemSid + 1)
     + *(unsigned __int8 *)(SeWorldSid + 1)
     + *(unsigned __int8 *)(SeAliasAdminsSid + 1)
     + 17;
  v2 = ExAllocatePoolWithTag(1, 4 * v1, 1818452292);
  v3 = v2;
  if ( !v2 )
    return sub_96C4B4();
  v0 = RtlCreateAcl(v2, 4 * v1, 2);
  v5 = v3;
  if ( v0 < 0 )
    goto LABEL_20;
  v0 = RtlAddAccessAllowedAce(v3, 2, 131075, SeWorldSid);
  v5 = v3;
  if ( v0 < 0 )
    goto LABEL_20;
  v0 = RtlAddAccessAllowedAce(v3, 2, 983043, SeAliasAdminsSid);
  v5 = v3;
  if ( v0 < 0 )
    goto LABEL_20;
  v0 = RtlAddAccessAllowedAce(v3, 2, 983043, SeLocalSystemSid);
  if ( v0 < 0 )
    goto LABEL_18;
  v0 = RtlSetDaclSecurityDescriptor((int)v14, 1, v3, 0);
  if ( v0 < 0 )
    goto LABEL_18;
  v6 = *(unsigned __int8 *)(SeLowMandatorySid + 1) + 7;
  v7 = ExAllocatePoolWithTag(1, 4 * v6, 1818452292);
  v8 = (unsigned __int8 *)v7;
  if ( !v7 )
  {
    v0 = -1073741670;
LABEL_18:
    v5 = v3;
    goto LABEL_20;
  }
  v0 = RtlCreateAcl(v7, 4 * v6, 2);
  if ( v0 >= 0 )
  {
    v0 = RtlAddMandatoryAce(v8, v9, 0, SeLowMandatorySid, v10, 1);
    if ( v0 >= 0 )
    {
      v0 = RtlSetSaclSecurityDescriptor((int)v14, 1, (int)v8, 0);
      if ( v0 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v12, L"\\KernelObjects\\CritSecOutOfMemoryEvent");
        v13[2] = 24;
        v13[3] = 0;
        v13[5] = 16;
        v13[4] = (int)v12;
        v13[6] = (int)v14;
        v13[7] = 0;
        v0 = ZwCreateKeyedEvent();
        ExFreePoolWithTag(v3);
        ExFreePoolWithTag((unsigned int)v8);
        if ( v0 >= 0 )
        {
          v0 = ObReferenceObjectByHandle(v11, 983043, ExpKeyedEventObjectType, 0, (int)v13, 0);
          ExpCritSecOutOfMemoryEvent = v13[0];
          ZwClose();
        }
        return v0;
      }
    }
  }
  ExFreePoolWithTag(v3);
  v5 = (unsigned int)v8;
LABEL_20:
  ExFreePoolWithTag(v5);
  return v0;
}
