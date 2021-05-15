// ExpWnfCheckCrossScopeAccess 
 
int __fastcall ExpWnfCheckCrossScopeAccess(__int64 a1)
{
  int v1; // r4
  int v2; // r2
  int v3; // r4
  unsigned int v4; // r5
  int v5; // r4
  unsigned int v7; // [sp+18h] [bp-20h] BYREF
  char v8[4]; // [sp+1Ch] [bp-1Ch] BYREF
  char var18[28]; // [sp+20h] [bp-18h] BYREF
  __int64 vars8; // [sp+40h] [bp+8h]

  v1 = (a1 >> 6) & 0xF;
  vars8 = a1;
  if ( v1 == 3 )
    return 0;
  v2 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v2) )
    return 0;
  if ( v1 != 1 || ((vars8 >> 4) & 3) != 0 )
    return -1073741727;
  v3 = ExpWnfLookupPermanentName(vars8);
  if ( v3 >= 0 )
  {
    v4 = v7;
    v5 = *(_DWORD *)(v7 + 8);
    SeCaptureSubjectContext(var18);
    SeAccessCheck(v5, (int)var18, 0, 16, 0, 0, (int)ExpWnfNotificationMapping, 1, (int)v8, (int)&v7);
    SeReleaseSubjectContext(var18);
    v3 = v7;
    ExFreePoolWithTag(v4);
  }
  if ( v3 == -1073741790 )
    return -1073741727;
  return v3;
}
