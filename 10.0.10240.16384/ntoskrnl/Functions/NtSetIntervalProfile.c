// NtSetIntervalProfile 
 
int __fastcall NtSetIntervalProfile(int *a1, int a2)
{
  int v4; // r2

  v4 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !SeSinglePrivilegeCheck(SeSystemProfilePrivilege, dword_922A0C, v4, (int)&SeSystemProfilePrivilege) )
    return -1073741727;
  KeSetIntervalProfile(a1, a2);
  return 0;
}
