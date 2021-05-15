// _wtol 
 
int __fastcall wtol(int a1)
{
  int result; // r0

  if ( a1 )
    result = wcstolX(a1, 0, 10, 1);
  else
    result = 0;
  return result;
}
