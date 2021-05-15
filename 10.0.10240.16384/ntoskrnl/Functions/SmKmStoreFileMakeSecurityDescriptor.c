// SmKmStoreFileMakeSecurityDescriptor 
 
int __fastcall SmKmStoreFileMakeSecurityDescriptor(_BYTE *a1, unsigned int *a2)
{
  unsigned int v3; // r7
  unsigned int v4; // r6
  unsigned int v5; // r5
  int v6; // r10
  int v7; // r0
  unsigned int v8; // r8
  int v9; // r4
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13; // r5
  int v14; // r4
  int v15; // r4
  int v16; // r0
  char v19[8]; // [sp+8h] [bp-30h] BYREF
  char v20[40]; // [sp+10h] [bp-28h] BYREF

  v20[0] = 0;
  v20[1] = 0;
  v20[2] = 0;
  v20[3] = 0;
  v20[4] = 0;
  v20[5] = 1;
  v19[0] = 0;
  v19[1] = 0;
  v19[2] = 0;
  v19[3] = 0;
  v19[4] = 0;
  v19[5] = 5;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = RtlLengthRequiredSid(1u);
  v7 = ExAllocatePoolWithTag(1, v6, 1396993395);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  v9 = RtlInitializeSid(v7, (int)v20, 1u);
  if ( v9 >= 0 )
  {
    v10 = ExAllocatePoolWithTag(1, v6, 1396993395);
    v3 = v10;
    if ( !v10 )
      goto LABEL_9;
    v9 = RtlInitializeSid(v10, (int)v19, 1u);
    if ( v9 < 0 )
      goto LABEL_17;
    v11 = RtlLengthRequiredSid(2u);
    v12 = ExAllocatePoolWithTag(1, v11, 1396993395);
    v4 = v12;
    if ( !v12 )
    {
LABEL_9:
      v9 = -1073741670;
      goto LABEL_17;
    }
    v9 = RtlInitializeSid(v12, (int)v19, 2u);
    if ( v9 >= 0 )
    {
      *(_DWORD *)RtlSubAuthoritySid(v8, 0) = 0;
      *(_DWORD *)RtlSubAuthoritySid(v3, 0) = 18;
      *(_DWORD *)RtlSubAuthoritySid(v4, 0) = 32;
      *(_DWORD *)RtlSubAuthoritySid(v4, 1) = 544;
      v13 = RtlLengthSid(v8);
      v14 = RtlLengthSid(v3);
      v15 = RtlLengthSid(v4) + v14 + v13;
      v16 = ExAllocatePoolWithTag(1, v15 + 32, 1631874419);
      v5 = v16;
      if ( v16 )
      {
        v9 = RtlCreateAcl(v16, v15 + 32, 2);
        if ( v9 >= 0 )
        {
          v9 = RtlAddAccessAllowedAce(v5, 2, 2032127, v4);
          if ( v9 >= 0 )
          {
            v9 = RtlAddAccessAllowedAce(v5, 2, 2032127, v3);
            if ( v9 >= 0 )
            {
              v9 = RtlAddAccessAllowedAce(v5, 2, 0x10000, v8);
              if ( v9 >= 0 )
              {
                v9 = RtlCreateSecurityDescriptor(a1, 1);
                if ( v9 >= 0 )
                {
                  v9 = RtlSetDaclSecurityDescriptor((int)a1, 1, v5, 0);
                  if ( v9 >= 0 )
                  {
                    *a2 = v5;
                    v5 = 0;
                    v9 = 0;
                  }
                }
              }
            }
          }
        }
        goto LABEL_17;
      }
      goto LABEL_9;
    }
  }
LABEL_17:
  ExFreePoolWithTag(v8);
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v9;
}
