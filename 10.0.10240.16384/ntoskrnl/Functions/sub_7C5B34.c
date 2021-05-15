// sub_7C5B34 
 
void sub_7C5B34()
{
  if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, 1, (int)&SeTcbPrivilege) )
    JUMPOUT(0x6C578A);
  JUMPOUT(0x6C5702);
}
