// _atoi64 
 
int __fastcall atoi64(int a1)
{
  int result; // r0

  if ( a1 )
    result = strtoi64(a1, 0, 10);
  else
    result = 0;
  return result;
}
