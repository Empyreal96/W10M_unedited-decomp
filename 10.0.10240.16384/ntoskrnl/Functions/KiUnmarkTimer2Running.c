// KiUnmarkTimer2Running 
 
int __fastcall KiUnmarkTimer2Running(unsigned int *a1)
{
  unsigned int v1; // r1
  int result; // r0

  __dmb(0xBu);
  do
    v1 = __ldrex(a1);
  while ( __strex(v1 & 0xFFFFEFFF, a1) );
  __dmb(0xBu);
  if ( KiTimer2IsFullyDisabled(v1 & 0xFFFFEFFF) )
    result = sub_523E10();
  else
    result = 0;
  return result;
}
