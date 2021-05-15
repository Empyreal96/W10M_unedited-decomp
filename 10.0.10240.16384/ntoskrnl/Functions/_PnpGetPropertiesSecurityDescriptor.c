// _PnpGetPropertiesSecurityDescriptor 
 
int PnpGetPropertiesSecurityDescriptor()
{
  _BYTE *v0; // r7
  int v1; // r4
  int v2; // r0
  unsigned __int8 *v3; // r6
  int v4; // r1
  unsigned int v5; // r0
  int v6; // r5
  _BYTE *v7; // r0
  _BYTE *v8; // r4
  unsigned int v10; // [sp+8h] [bp-40h] BYREF
  char v11; // [sp+Ch] [bp-3Ch]
  char v12; // [sp+Dh] [bp-3Bh]
  char v13[2]; // [sp+10h] [bp-38h] BYREF
  __int16 v14; // [sp+12h] [bp-36h]
  char v15[32]; // [sp+28h] [bp-20h] BYREF

  v10 = 0;
  v11 = 0;
  v12 = 5;
  v0 = 0;
  if ( RtlInitializeSid((int)v15, (int)&v10, 1u) >= 0 )
  {
    *(_DWORD *)RtlSubAuthoritySid((int)v15, 0) = 18;
    if ( RtlValidSid(v15) )
    {
      v1 = RtlLengthSid((int)v15);
      v2 = ExAllocatePoolWithTag(1, v1 + 16, 1380994640);
      v3 = (unsigned __int8 *)v2;
      if ( v2 )
      {
        if ( RtlCreateAcl(v2, v1 + 16, 2) >= 0
          && RtlpAddKnownAce(v3, 2u, 2, 983103, v15, 0) >= 0
          && RtlCreateSecurityDescriptor(v13, 1) >= 0
          && RtlSetDaclSecurityDescriptor((int)v13, 1, (int)v3, 0) >= 0
          && RtlSetOwnerSecurityDescriptor((int)v13, (int)v15, 1) >= 0
          && RtlSetGroupSecurityDescriptor((int)v13, (int)v15, 1) >= 0 )
        {
          v14 |= 0x1400u;
          if ( RtlValidSecurityDescriptor((int)v13, v4) )
          {
            v5 = RtlLengthSecurityDescriptor((int)v13);
            v6 = v5;
            v10 = v5;
            if ( v5 >= 0x14 )
            {
              v7 = (_BYTE *)ExAllocatePoolWithTag(1, v5, 1380994640);
              v8 = v7;
              if ( v7 )
              {
                memset(v7, 0, v6);
                if ( RtlAbsoluteToSelfRelativeSD((int)v13) >= 0 )
                {
                  v0 = v8;
                  v8 = 0;
                }
                if ( v8 )
                  return sub_7F0558();
              }
            }
          }
        }
        ExFreePoolWithTag((unsigned int)v3);
      }
    }
  }
  return (int)v0;
}
