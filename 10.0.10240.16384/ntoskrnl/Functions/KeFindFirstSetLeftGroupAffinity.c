// KeFindFirstSetLeftGroupAffinity 
 
unsigned int __fastcall KeFindFirstSetLeftGroupAffinity(unsigned int *a1)
{
  unsigned int result; // r0

  if ( *a1 )
    result = 31 - __clz(*a1);
  else
    result = -1;
  return result;
}
