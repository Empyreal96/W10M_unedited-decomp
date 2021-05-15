// NtAddDriverEntry 
 
int __fastcall NtAddDriverEntry(unsigned int a1, unsigned int *a2)
{
  int result; // r0

  if ( dword_61A1F0 == 2 )
    result = ExpSetDriverEntry(1, a1, a2, dword_61A1F0);
  else
    result = -1073741822;
  return result;
}
