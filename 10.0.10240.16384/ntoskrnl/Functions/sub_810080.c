// sub_810080 
 
void sub_810080()
{
  int v0; // r2

  v0 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v0, (int)&SeBackupPrivilege) )
  {
    CmpSyncNextBackupHive();
    JUMPOUT(0x79CF42);
  }
  JUMPOUT(0x79CF44);
}
