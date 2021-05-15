// atol 
 
int __fastcall atol(int a1)
{
  int result; // r0

  if ( a1 )
    result = strtolX(a1, 0, 10, 1);
  else
    result = 0;
  return result;
}
