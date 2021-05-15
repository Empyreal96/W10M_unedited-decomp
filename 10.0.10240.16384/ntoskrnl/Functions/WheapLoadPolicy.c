// WheapLoadPolicy 
 
int WheapLoadPolicy()
{
  int v0; // r0
  int result; // r0
  int v2; // r6
  int v3; // r3
  int v4; // r5
  int v5; // r4
  int v6; // [sp+8h] [bp-38h]
  int v7; // [sp+Ch] [bp-34h]
  int v8; // [sp+10h] [bp-30h]
  char v9[40]; // [sp+18h] [bp-28h] BYREF

  v0 = WheaRegPolicyDisableOffline;
  if ( WheaRegPolicyDisableOffline != -1 )
    return sub_96F2F4();
  v2 = WheaRegPolicyMemPersistOffline;
  if ( WheaRegPolicyMemPersistOffline == -1 )
  {
    RtlInitUnicodeString((unsigned int)v9, L"Kernel-PersistDefectiveMemoryList");
    if ( ZwQueryLicenseValue() >= 0 && v7 == 4 && v6 == 4 )
      WheapPolicyMemPersistOffline = v8 != 0;
    v2 = WheaRegPolicyMemPersistOffline;
    v0 = WheaRegPolicyDisableOffline;
  }
  else
  {
    WheapPolicyMemPersistOffline = WheaRegPolicyMemPersistOffline != 0;
  }
  if ( WheaRegPolicyMemPfaDisable != -1 )
    WheapPolicyMemPfaDisable = WheaRegPolicyMemPfaDisable != 0;
  if ( (unsigned int)(WheaRegPolicyMemPfaPageCount - 1) > 0xFFFF )
  {
    if ( (unsigned int)(WheapMaxCorrectedMCEOutstanding - 1) > 0xFFFF )
    {
      v4 = WheapPolicyMemPfaPageCount;
    }
    else
    {
      v4 = WheapMaxCorrectedMCEOutstanding;
      WheapPolicyMemPfaPageCount = WheapMaxCorrectedMCEOutstanding;
    }
  }
  else
  {
    v4 = WheaRegPolicyMemPfaPageCount;
    WheapPolicyMemPfaPageCount = WheaRegPolicyMemPfaPageCount;
  }
  if ( (unsigned int)(WheaRegPolicyMemPfaThreshold - 1) > 0xFFFF )
  {
    if ( (unsigned int)(WheapSingleBitEccErrorThreshold - 1) > 0xFFFF )
    {
      v5 = WheapPolicyMemPfaThreshold;
    }
    else
    {
      v5 = WheapSingleBitEccErrorThreshold;
      WheapPolicyMemPfaThreshold = WheapSingleBitEccErrorThreshold;
    }
  }
  else
  {
    v5 = WheaRegPolicyMemPfaThreshold;
    WheapPolicyMemPfaThreshold = WheaRegPolicyMemPfaThreshold;
  }
  if ( (unsigned int)WheaRegPolicyMemPfaTimeout <= 0x93A80 )
    WheapPolicyMemPfaTimeout = (unsigned int)WheaRegPolicyMemPfaTimeout * (unsigned __int64)(unsigned int)dword_989680;
  if ( !v4 || !v5 )
    WheapPolicyMemPfaDisable = 1;
  if ( WheaRegPolicyIgnoreDummyWrite != -1 )
    WheapPolicyIgnoreDummyWrite = WheaRegPolicyIgnoreDummyWrite != 0;
  v3 = WheaRegistryKeysPresent;
  if ( v0 != -1 )
  {
    v3 = WheaRegistryKeysPresent | 1;
    WheaRegistryKeysPresent |= 1u;
  }
  if ( v2 != -1 )
  {
    v3 |= 2u;
    WheaRegistryKeysPresent = v3;
  }
  if ( WheaRegPolicyMemPfaDisable != -1 )
  {
    v3 |= 4u;
    WheaRegistryKeysPresent = v3;
  }
  if ( WheaRegPolicyMemPfaPageCount != -1 )
  {
    v3 |= 8u;
    WheaRegistryKeysPresent = v3;
  }
  if ( WheaRegPolicyMemPfaThreshold != -1 )
  {
    v3 |= 0x10u;
    WheaRegistryKeysPresent = v3;
  }
  result = WheaRegPolicyMemPfaTimeout;
  if ( WheaRegPolicyMemPfaTimeout != -1 )
  {
    v3 |= 0x20u;
    WheaRegistryKeysPresent = v3;
  }
  if ( WheapSingleBitEccErrorThreshold != -1 )
  {
    v3 |= 0x40u;
    WheaRegistryKeysPresent = v3;
  }
  if ( WheapMaxCorrectedMCEOutstanding != -1 )
  {
    v3 |= 0x80u;
    WheaRegistryKeysPresent = v3;
  }
  if ( WheaRegPolicyIgnoreDummyWrite != -1 )
    WheaRegistryKeysPresent = v3 | 0x100;
  return result;
}
