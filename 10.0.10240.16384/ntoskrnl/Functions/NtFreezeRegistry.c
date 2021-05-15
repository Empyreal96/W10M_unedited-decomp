// NtFreezeRegistry 
 
int __fastcall NtFreezeRegistry(unsigned int a1)
{
  int result; // r0
  int v3; // r2

  if ( a1 > 0x384 )
    return -1073741811;
  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v3) )
    result = CmFreezeRegistry(a1);
  else
    result = -1073741727;
  return result;
}
