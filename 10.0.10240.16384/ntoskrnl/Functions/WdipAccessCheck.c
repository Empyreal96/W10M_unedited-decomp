// WdipAccessCheck 
 
int WdipAccessCheck()
{
  int v0; // r5
  int v1; // r0
  int v2; // r0
  int v3; // r6
  int v4; // r4
  int v5; // r7
  int v6; // r0
  int v8; // [sp+18h] [bp-48h] BYREF
  char v9[8]; // [sp+20h] [bp-40h] BYREF
  int v10[4]; // [sp+28h] [bp-38h] BYREF
  char v11[40]; // [sp+38h] [bp-28h] BYREF

  v9[0] = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  v9[4] = 0;
  v9[5] = 5;
  v10[0] = 131073;
  v10[1] = 0x20000;
  v10[2] = 0x20000;
  v0 = 0;
  v10[3] = 2031617;
  v1 = RtlLengthRequiredSid(6);
  v2 = ExAllocatePoolWithTag(1, v1);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  v4 = RtlInitializeSid(v2, v9, 6);
  if ( v4 >= 0 )
  {
    *(_DWORD *)(v3 + 8) = 80;
    *(_DWORD *)(v3 + 12) = -1324354722;
    *(_DWORD *)(v3 + 16) = 78537857;
    *(_DWORD *)(v3 + 20) = 698502321;
    *(_DWORD *)(v3 + 24) = 558674196;
    *(_DWORD *)(v3 + 28) = 1451644582;
    v5 = 4
       * (*(unsigned __int8 *)(SeAliasAdminsSid + 1)
        + *(unsigned __int8 *)(v3 + 1)
        + *(unsigned __int8 *)(SeLocalSystemSid + 1)
        + 22);
    v6 = ExAllocatePoolWithTag(1, v5);
    v0 = v6;
    if ( v6 )
    {
      v4 = RtlCreateSecurityDescriptor(v6, 1);
      if ( v4 >= 0 )
      {
        v4 = RtlCreateAcl(v0 + 20, v5 - 20, 2);
        if ( v4 >= 0 )
        {
          v4 = RtlAddAccessAllowedAce(v0 + 20, 2, 1, SeAliasAdminsSid);
          if ( v4 >= 0 )
          {
            v4 = RtlAddAccessAllowedAce(v0 + 20, 2, 1, SeLocalSystemSid);
            if ( v4 >= 0 )
            {
              v4 = RtlAddAccessAllowedAce(v0 + 20, 2, 1, v3);
              if ( v4 >= 0 )
              {
                v4 = RtlSetDaclSecurityDescriptor(v0, 1, v0 + 20, 0);
                v8 = v4;
                if ( v4 >= 0 )
                {
                  SeCaptureSubjectContext(v11);
                  SeAccessCheck(v0, (int)v11, 0, 1, 0, 0, (int)v10, 1, (int)v9, (int)&v8);
                  SeReleaseSubjectContext(v11);
                  v4 = v8;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v4 = -1073741670;
    }
  }
  ExFreePoolWithTag(v3);
  if ( v0 )
    ExFreePoolWithTag(v0);
  return v4;
}
