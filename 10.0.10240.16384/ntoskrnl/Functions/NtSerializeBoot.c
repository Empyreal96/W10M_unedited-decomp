// NtSerializeBoot 
 
int NtSerializeBoot()
{
  int result; // r0

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1 )
    JUMPOUT(0x81C5FA);
  if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, 1, (int)&SeTcbPrivilege) )
    result = PnpSerializeBoot();
  else
    result = sub_81C5F8();
  return result;
}
