// PsGetProcessSessionId 
 
int __fastcall PsGetProcessSessionId(int a1)
{
  int result; // r0

  result = MmGetSessionIdEx(a1);
  if ( result == -1 )
    result = 0;
  return result;
}
