// NtAddBootEntry 
 
int __fastcall NtAddBootEntry(int a1, int a2)
{
  int result; // r0

  if ( dword_61A1F0 == 2 )
    result = ExpSetBootEntry(1, a1, a2);
  else
    result = -1073741822;
  return result;
}
