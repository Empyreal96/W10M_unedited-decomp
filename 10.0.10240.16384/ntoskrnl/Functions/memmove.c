// memmove 
 
int __fastcall memmove(int a1, int a2, unsigned int a3)
{
  int result; // r0

  if ( a1 - a2 >= a3 )
    result = memcpy_strict_align();
  else
    result = _memcpy_reverse();
  return result;
}
