// PiAuCreateLocalSystemSecurityObject 
 
int __fastcall PiAuCreateLocalSystemSecurityObject(int *a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r0
  unsigned int v5; // r7
  int v6; // r4
  int v7; // r1
  unsigned int v8; // r0
  int v9; // r4
  _BYTE *v10; // r0
  unsigned int v11; // r0
  char v13[40]; // [sp+10h] [bp-28h] BYREF

  v2 = 0;
  v3 = *(unsigned __int8 *)(*a1 + 1) + 6;
  v4 = ExAllocatePoolWithTag(1, 4 * v3, 1198550608);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  v6 = RtlCreateAcl(v4, 4 * v3, 2);
  if ( v6 >= 0 )
  {
    v6 = RtlAddAccessAllowedAceEx(v5, 2, 0, 983040, *a1);
    if ( v6 >= 0 )
    {
      v6 = RtlCreateSecurityDescriptor(v13, 1);
      if ( v6 >= 0 )
      {
        v6 = RtlSetDaclSecurityDescriptor((int)v13, 1, v5, 0);
        if ( v6 >= 0 )
        {
          v6 = RtlSetOwnerSecurityDescriptor((int)v13, *a1, 0);
          if ( v6 >= 0 )
          {
            v6 = RtlSetGroupSecurityDescriptor((int)v13, *a1, 0);
            if ( v6 >= 0 )
            {
              if ( RtlValidSecurityDescriptor((int)v13, v7)
                && (v8 = RtlLengthSecurityDescriptor((int)v13), v9 = v8, v8 >= 0x14) )
              {
                v10 = (_BYTE *)ExAllocatePoolWithTag(1, v8, 1198550608);
                v2 = (int)v10;
                if ( v10 )
                {
                  memset(v10, 0, v9);
                  v6 = RtlAbsoluteToSelfRelativeSD((int)v13);
                  if ( v6 >= 0 )
                  {
                    PiAuLocalSystemSecurityObject = v2;
                    v2 = 0;
                  }
                }
                else
                {
                  v6 = -1073741670;
                }
              }
              else
              {
                v6 = -1073741595;
              }
            }
          }
        }
      }
    }
  }
  v11 = ExFreePoolWithTag(v5);
  if ( v2 )
    return sub_96E3F4(v11);
  return v6;
}
