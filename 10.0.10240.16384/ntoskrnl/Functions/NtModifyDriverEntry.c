// NtModifyDriverEntry 
 
int __fastcall NtModifyDriverEntry(unsigned int a1)
{
  int result; // r0

  if ( dword_61A1F0 == 2 )
    result = ExpSetDriverEntry(0, a1, 0, dword_61A1F0);
  else
    result = -1073741822;
  return result;
}
