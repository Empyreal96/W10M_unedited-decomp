// sub_81BA74 
 
void __fastcall sub_81BA74(int a1, int a2, int a3)
{
  if ( SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, a3, (int)&SeDebugPrivilege) )
    JUMPOUT(0x7BB9DC);
  JUMPOUT(0x7BBA02);
}
