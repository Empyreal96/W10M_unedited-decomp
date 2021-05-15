// KeFindFirstSetRightGroupAffinity 
 
unsigned int __fastcall KeFindFirstSetRightGroupAffinity(unsigned int *a1)
{
  unsigned int result; // r0

  if ( *a1 )
    result = __clz(__rbit(*a1));
  else
    result = -1;
  return result;
}
