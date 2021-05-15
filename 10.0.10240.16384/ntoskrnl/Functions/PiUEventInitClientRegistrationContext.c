// PiUEventInitClientRegistrationContext 
 
int PiUEventInitClientRegistrationContext()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r7
  int v2; // r0
  int v3; // r9
  int v4; // r6
  int v5; // r5
  int v6; // r4
  int v7; // r5
  int v8; // r0
  unsigned int v9; // r4
  unsigned int v11; // r0
  char v12[48]; // [sp+10h] [bp-30h] BYREF

  v0 = (_BYTE *)ExAllocatePoolWithTag(1, 88, 1500540496);
  v1 = v0;
  if ( !v0 )
    return (int)v1;
  memset(v0, 0, 88);
  v2 = ExAllocatePoolWithTag(512, 32, 1500540496);
  *((_DWORD *)v1 + 2) = v2;
  if ( v2 )
  {
    KeInitializeGuardedMutex(v2);
    *((_DWORD *)v1 + 16) = v1 + 64;
    *((_DWORD *)v1 + 17) = v1 + 64;
    *((_DWORD *)v1 + 14) = v1 + 56;
    *((_DWORD *)v1 + 15) = v1 + 56;
    *((_DWORD *)v1 + 19) = 4;
    v1[84] = 1;
    if ( RtlCreateSecurityDescriptor(v12, 1) >= 0 )
    {
      v3 = SeLocalSystemSid;
      if ( RtlSetOwnerSecurityDescriptor(v12, SeLocalSystemSid, 1) >= 0 )
      {
        v4 = RtlLengthSid(SeWorldSid);
        v5 = RtlLengthSid(SeAllAppPackagesSid);
        v6 = RtlLengthSid(SeLowMandatorySid);
        v7 = RtlLengthSid(v3) + v6 + v5 + v4;
        v8 = ExAllocatePoolWithTag(1, v7 + 40, 1500540496);
        v9 = v8;
        if ( v8 )
        {
          if ( RtlCreateAcl(v8, v7 + 40, 2) >= 0
            && RtlpAddKnownAce(v9, 2, 2, 0x10000000, SeLocalSystemSid, 0) >= 0
            && RtlpAddKnownAce(v9, 2, 2, 1, SeWorldSid, 0) >= 0
            && RtlpAddKnownAce(v9, 2, 2, 1, SeAllAppPackagesSid, 0) >= 0
            && RtlpAddKnownAce(v9, 2, 2, 1, SeLowMandatorySid, 0) >= 0
            && RtlSetDaclSecurityDescriptor(v12, 1, v9, 0) >= 0
            && ZwCreateWnfStateName() >= 0 )
          {
            if ( v9 )
              ExFreePoolWithTag(v9);
            return (int)v1;
          }
        }
      }
    }
  }
  v11 = *((_DWORD *)v1 + 2);
  if ( v11 )
    v11 = ExFreePoolWithTag(v11);
  return sub_7C2560(v11);
}
