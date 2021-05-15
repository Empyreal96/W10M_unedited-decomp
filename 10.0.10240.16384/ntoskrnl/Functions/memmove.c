// memmove 
 
int __fastcall memmove(int a1, int a2, unsigned int a3)
{
  int result; // r0

  if ( a1 - a2 >= a3 )
    result = memcpy_strict_align(a1, (char *)a2, a3);
  else
    result = _memcpy_reverse(a1, a2, a3);
  return result;
}
