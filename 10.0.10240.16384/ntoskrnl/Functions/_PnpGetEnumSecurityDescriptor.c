// _PnpGetEnumSecurityDescriptor 
 
int PnpGetEnumSecurityDescriptor()
{
  _BYTE *v0; // r7
  int v1; // r5
  int v2; // r4
  int v3; // r4
  int v4; // r0
  unsigned __int8 *v5; // r5
  int v6; // r1
  unsigned int v7; // r0
  int v8; // r6
  _BYTE *v9; // r0
  _BYTE *v10; // r4
  unsigned int v12; // [sp+8h] [bp-88h] BYREF
  char v13; // [sp+Ch] [bp-84h]
  char v14; // [sp+Dh] [bp-83h]
  char v15[8]; // [sp+10h] [bp-80h] BYREF
  char v16[8]; // [sp+18h] [bp-78h] BYREF
  char v17[2]; // [sp+20h] [bp-70h] BYREF
  __int16 v18; // [sp+22h] [bp-6Eh]
  char v19[16]; // [sp+38h] [bp-58h] BYREF
  char v20[16]; // [sp+48h] [bp-48h] BYREF
  char v21[16]; // [sp+58h] [bp-38h] BYREF
  char v22[40]; // [sp+68h] [bp-28h] BYREF

  v12 = 0;
  v13 = 0;
  v14 = 5;
  v15[0] = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  v15[4] = 0;
  v15[5] = 3;
  v16[0] = 0;
  v16[1] = 0;
  v16[2] = 0;
  v16[3] = 0;
  v16[4] = 0;
  v16[5] = 1;
  v0 = 0;
  if ( RtlInitializeSid((int)v19, (int)&v12, 1u) >= 0 )
  {
    *(_DWORD *)RtlSubAuthoritySid((int)v19, 0) = 18;
    if ( RtlValidSid(v19) )
    {
      if ( RtlInitializeSid((int)v20, (int)v15, 1u) >= 0 )
      {
        *(_DWORD *)RtlSubAuthoritySid((int)v20, 0) = 4;
        if ( RtlValidSid(v20) )
        {
          if ( RtlInitializeSid((int)v21, (int)v16, 1u) >= 0 )
          {
            *(_DWORD *)RtlSubAuthoritySid((int)v21, 0) = 0;
            if ( RtlValidSid(v21) )
            {
              if ( RtlInitializeSid((int)v22, (int)&v12, 2u) >= 0 )
              {
                *(_DWORD *)RtlSubAuthoritySid((int)v22, 0) = 32;
                *(_DWORD *)RtlSubAuthoritySid((int)v22, 1) = 544;
                if ( RtlValidSid(v22) )
                {
                  v1 = RtlLengthSid((int)v19);
                  v2 = RtlLengthSid((int)v20);
                  v3 = RtlLengthSid((int)v21) + v2 + v1;
                  v4 = ExAllocatePoolWithTag(1, v3 + 32, 1380994640);
                  v5 = (unsigned __int8 *)v4;
                  if ( v4 )
                  {
                    if ( RtlCreateAcl(v4, v3 + 32, 2) >= 0
                      && RtlpAddKnownAce(v5, 2u, 2, 983103, v19, 0) >= 0
                      && RtlpAddKnownAce(v5, 2u, 2, 0x20000, v20, 0) >= 0
                      && RtlpAddKnownAce(v5, 2u, 2, 131097, v21, 0) >= 0
                      && RtlCreateSecurityDescriptor(v17, 1) >= 0
                      && RtlSetDaclSecurityDescriptor((int)v17, 1, (int)v5, 0) >= 0
                      && RtlSetOwnerSecurityDescriptor((int)v17, (int)v22, 1) >= 0
                      && RtlSetGroupSecurityDescriptor((int)v17, (int)v22, 1) >= 0 )
                    {
                      v18 |= 0x1400u;
                      if ( RtlValidSecurityDescriptor((int)v17, v6) )
                      {
                        v7 = RtlLengthSecurityDescriptor((int)v17);
                        v8 = v7;
                        v12 = v7;
                        if ( v7 >= 0x14 )
                        {
                          v9 = (_BYTE *)ExAllocatePoolWithTag(1, v7, 1380994640);
                          v10 = v9;
                          if ( v9 )
                          {
                            memset(v9, 0, v8);
                            if ( RtlAbsoluteToSelfRelativeSD((int)v17) >= 0 )
                            {
                              v0 = v10;
                              v10 = 0;
                            }
                            if ( v10 )
                              return sub_81A2D8();
                          }
                        }
                      }
                    }
                    ExFreePoolWithTag((unsigned int)v5);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return (int)v0;
}
