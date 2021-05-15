// NtMakePermanentObject 
 
int NtMakePermanentObject()
{
  int v0; // r2
  int result; // r0

  v0 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeCreatePermanentPrivilege, dword_9227A4, v0, (int)&SeCreatePermanentPrivilege) )
    result = sub_7EBD8C();
  else
    result = -1073741727;
  return result;
}
