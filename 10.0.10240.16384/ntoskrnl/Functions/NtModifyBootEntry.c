// NtModifyBootEntry 
 
int __fastcall NtModifyBootEntry(unsigned int a1)
{
  int result; // r0

  if ( dword_61A1F0 == 2 )
    result = ExpSetBootEntry(0, a1, 0, dword_61A1F0);
  else
    result = -1073741822;
  return result;
}
