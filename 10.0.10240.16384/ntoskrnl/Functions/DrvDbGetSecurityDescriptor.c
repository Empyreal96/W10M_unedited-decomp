// DrvDbGetSecurityDescriptor 
 
unsigned int DrvDbGetSecurityDescriptor()
{
  unsigned int v0; // r9
  int v1; // r4
  int v2; // r0
  _BYTE *v3; // r10
  int v4; // r0
  _BYTE *v5; // r8
  int v6; // r0
  _BYTE *v7; // r7
  int v8; // r0
  int v9; // r0
  _BYTE *v10; // r6
  int v11; // r5
  int v12; // r4
  int v13; // r4
  int v14; // r0
  unsigned __int8 *v15; // r5
  int v16; // r1
  unsigned int v17; // r0
  int v18; // r9
  _BYTE *v19; // r0
  unsigned int v20; // r4
  unsigned int v22; // [sp+8h] [bp-48h] BYREF
  char v23; // [sp+Ch] [bp-44h]
  char v24; // [sp+Dh] [bp-43h]
  char v25[8]; // [sp+10h] [bp-40h] BYREF
  char v26[8]; // [sp+18h] [bp-38h] BYREF
  char v27[2]; // [sp+20h] [bp-30h] BYREF
  __int16 v28; // [sp+22h] [bp-2Eh]

  v22 = 0;
  v23 = 0;
  v24 = 5;
  v25[0] = 0;
  v25[1] = 0;
  v25[2] = 0;
  v25[3] = 0;
  v25[4] = 0;
  v25[5] = 3;
  v26[0] = 0;
  v26[1] = 0;
  v26[2] = 0;
  v26[3] = 0;
  v26[4] = 0;
  v26[5] = 1;
  v0 = 0;
  v1 = RtlLengthRequiredSid(1u);
  v2 = ExAllocatePoolWithTag(1, v1, 1111770192);
  v3 = (_BYTE *)v2;
  if ( v2 )
  {
    if ( RtlInitializeSid(v2, (int)&v22, 1u) >= 0 )
    {
      *(_DWORD *)RtlSubAuthoritySid((int)v3, 0) = 18;
      if ( RtlValidSid(v3) )
      {
        v4 = ExAllocatePoolWithTag(1, v1, 1111770192);
        v5 = (_BYTE *)v4;
        if ( v4 )
        {
          if ( RtlInitializeSid(v4, (int)v25, 1u) >= 0 )
          {
            *(_DWORD *)RtlSubAuthoritySid((int)v5, 0) = 4;
            if ( RtlValidSid(v5) )
            {
              v6 = ExAllocatePoolWithTag(1, v1, 1111770192);
              v7 = (_BYTE *)v6;
              if ( v6 )
              {
                if ( RtlInitializeSid(v6, (int)v26, 1u) >= 0 )
                {
                  *(_DWORD *)RtlSubAuthoritySid((int)v7, 0) = 0;
                  if ( RtlValidSid(v7) )
                  {
                    v8 = RtlLengthRequiredSid(2u);
                    v9 = ExAllocatePoolWithTag(1, v8, 1111770192);
                    v10 = (_BYTE *)v9;
                    if ( v9 )
                    {
                      if ( RtlInitializeSid(v9, (int)&v22, 2u) >= 0 )
                      {
                        *(_DWORD *)RtlSubAuthoritySid((int)v10, 0) = 32;
                        *(_DWORD *)RtlSubAuthoritySid((int)v10, 1) = 544;
                        if ( RtlValidSid(v10) )
                        {
                          v11 = RtlLengthSid((int)v5);
                          v12 = RtlLengthSid((int)v7);
                          v13 = RtlLengthSid((int)v3) + v12 + v11;
                          v14 = ExAllocatePoolWithTag(1, v13 + 32, 1111770192);
                          v15 = (unsigned __int8 *)v14;
                          if ( v14 )
                          {
                            if ( RtlCreateAcl(v14, v13 + 32, 2) >= 0
                              && RtlpAddKnownAce(v15, 2u, 2, 983103, v3, 0) >= 0
                              && RtlpAddKnownAce(v15, 2u, 2, 0x20000, v5, 0) >= 0
                              && RtlpAddKnownAce(v15, 2u, 2, 131097, v7, 0) >= 0
                              && RtlCreateSecurityDescriptor(v27, 1) >= 0
                              && RtlSetDaclSecurityDescriptor((int)v27, 1, (int)v15, 0) >= 0
                              && RtlSetOwnerSecurityDescriptor((int)v27, (int)v10, 1) >= 0
                              && RtlSetGroupSecurityDescriptor((int)v27, (int)v10, 1) >= 0 )
                            {
                              v28 |= 0x1400u;
                              if ( RtlValidSecurityDescriptor((int)v27, v16) )
                              {
                                v17 = RtlLengthSecurityDescriptor((int)v27);
                                v18 = v17;
                                v22 = v17;
                                if ( v17 >= 0x14
                                  && (v19 = (_BYTE *)ExAllocatePoolWithTag(1, v17, 1111770192),
                                      (v20 = (unsigned int)v19) != 0) )
                                {
                                  memset(v19, 0, v18);
                                  if ( RtlAbsoluteToSelfRelativeSD((int)v27) < 0 )
                                  {
                                    v0 = 0;
                                  }
                                  else
                                  {
                                    v0 = v20;
                                    v20 = 0;
                                  }
                                  if ( v20 )
                                    ExFreePoolWithTag(v20);
                                }
                                else
                                {
                                  v0 = 0;
                                }
                              }
                            }
                            ExFreePoolWithTag((unsigned int)v15);
                          }
                        }
                      }
                      ExFreePoolWithTag((unsigned int)v10);
                    }
                  }
                }
                ExFreePoolWithTag((unsigned int)v7);
              }
            }
          }
          ExFreePoolWithTag((unsigned int)v5);
        }
      }
    }
    ExFreePoolWithTag((unsigned int)v3);
  }
  return v0;
}
