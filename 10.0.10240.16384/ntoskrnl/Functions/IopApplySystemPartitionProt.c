// IopApplySystemPartitionProt 
 
int __fastcall IopApplySystemPartitionProt(int a1)
{
  int v2; // r4
  int v3; // r0
  int v4; // r3
  unsigned int v5; // r5
  int v6; // r4
  int v7; // r3
  _DWORD v9[8]; // [sp+10h] [bp-170h] BYREF
  unsigned __int16 v10[4]; // [sp+30h] [bp-150h] BYREF
  char v11[24]; // [sp+38h] [bp-148h] BYREF
  char v12[16]; // [sp+58h] [bp-128h] BYREF
  char v13[280]; // [sp+68h] [bp-118h] BYREF

  strcpy(v12, "\\ArcName\\%s");
  v2 = *(unsigned __int8 *)(SeLocalSystemSid + 1) + *(unsigned __int8 *)(SeAliasAdminsSid + 1) + 14;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v4 = 40;
    else
      v4 = 32;
    v3 = ExAllocatePoolWithTagPriority(1, 4 * v2, 538996553, v4);
  }
  else
  {
    v3 = ExAllocatePoolWithTag(1, 4 * v2, 538996553);
  }
  v5 = v3;
  if ( !v3 )
    return -1073741670;
  v6 = RtlCreateAcl(v3, 4 * v2, 2);
  if ( v6 >= 0 )
  {
    v6 = RtlAddAccessAllowedAce(v5, 2, 0x10000000, SeLocalSystemSid);
    if ( v6 >= 0 )
    {
      v6 = RtlAddAccessAllowedAce(v5, 2, -536739840, SeAliasAdminsSid);
      if ( v6 >= 0 )
      {
        v6 = RtlCreateSecurityDescriptor(v11, 1);
        if ( v6 >= 0 )
        {
          v6 = RtlSetDaclSecurityDescriptor((int)v11, 1, v5, 0);
          if ( v6 >= 0 )
          {
            RtlStringCchPrintfA(v13, 0x100u, (int)v12, *(_DWORD *)(a1 + 108));
            RtlInitAnsiString((unsigned int)v10, (unsigned int)v13);
            v6 = RtlAnsiStringToUnicodeString((unsigned __int16 *)v9, v10, 1, v7);
            if ( v6 >= 0 )
            {
              v9[2] = 24;
              v9[3] = 0;
              v9[5] = 576;
              v9[4] = v9;
              v9[6] = 0;
              v9[7] = 0;
              v6 = ZwOpenFile();
              RtlFreeAnsiString(v9);
              if ( v6 >= 0 )
              {
                v6 = ZwSetSecurityObject();
                NtClose();
              }
            }
          }
        }
      }
    }
  }
  ExFreePoolWithTag(v5);
  return v6;
}
