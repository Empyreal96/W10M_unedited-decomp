// NtSetTimer2 
 
int __fastcall NtSetTimer2(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a3 )
    result = -1073741822;
  else
    result = ExpSetTimer2(a1, a2, a4);
  return result;
}
