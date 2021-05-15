// NtSetDefaultHardErrorPort 
 
int NtSetDefaultHardErrorPort()
{
  int v0; // r2
  int result; // r0

  PsGetCurrentServerSiloGlobals();
  v0 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v0, (int)&SeTcbPrivilege) )
    result = sub_80F3AC();
  else
    result = -1073741727;
  return result;
}
