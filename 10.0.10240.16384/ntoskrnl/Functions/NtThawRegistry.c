// NtThawRegistry 
 
int NtThawRegistry()
{
  int v0; // r2
  int result; // r0

  v0 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v0) )
    result = CmThawRegistry();
  else
    result = -1073741727;
  return result;
}
