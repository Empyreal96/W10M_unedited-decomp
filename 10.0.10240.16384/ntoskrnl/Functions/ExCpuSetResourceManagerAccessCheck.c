// ExCpuSetResourceManagerAccessCheck 
 
int __fastcall ExCpuSetResourceManagerAccessCheck(char a1)
{
  int v1; // r4
  unsigned int v2; // r0
  int v4; // [sp+20h] [bp-20h] BYREF
  char v5[4]; // [sp+24h] [bp-1Ch] BYREF
  char v6[24]; // [sp+28h] [bp-18h] BYREF

  v1 = a1;
  if ( !a1 || SeSinglePrivilegeCheck(SeIncreaseBasePriorityPrivilege, dword_9227C4, a1) )
    return 0;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  SeCaptureSubjectContextEx(v2, *(_DWORD *)(v2 + 0x74), v6);
  SeAccessCheckWithHint(ExpCpuSetSecurityDescriptor, 3, v6, 0, 1, 0, 0, ExpRestrictedGenericMapping, v1, v5, &v4);
  SeReleaseSubjectContext(v6);
  return v4;
}
