// SepCheckForAllAppPackagesAceRemoval 
 
int __fastcall SepCheckForAllAppPackagesAceRemoval(int result, int a2, _BYTE *a3, _BYTE *a4)
{
  int v7; // r8
  int v8; // r2
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r0
  char v13; // [sp+8h] [bp-30h] BYREF
  char v14; // [sp+9h] [bp-2Fh] BYREF
  char v15; // [sp+Ah] [bp-2Eh] BYREF
  char v16[5]; // [sp+Bh] [bp-2Dh] BYREF
  int v17[10]; // [sp+10h] [bp-28h] BYREF

  v7 = result;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  if ( !SepAllowAllApplicationAceRemoval )
  {
    v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    result = SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v8, (int)&SeTcbPrivilege);
    if ( !result )
    {
      SeCaptureSubjectContext(v17, v9, v10, v11);
      v12 = v17[0];
      if ( !v17[0] )
        v12 = v17[2];
      if ( SepSidInToken(v12, 0, SeTrustedInstallerSid, 0, 0) )
      {
        result = SeReleaseSubjectContext((int)v17);
      }
      else
      {
        SeReleaseSubjectContext((int)v17);
        result = SepHasAllAppPackagesPresent(v7, &v13, &v14, &v15);
        if ( result )
        {
          result = SepHasAllAppPackagesPresent(a2, v16, &v14, &v15);
          if ( !result )
          {
            if ( v13 && v14 && !v15 && a4 )
              *a4 = 1;
            if ( a3 )
              *a3 = 1;
          }
        }
      }
    }
  }
  return result;
}
