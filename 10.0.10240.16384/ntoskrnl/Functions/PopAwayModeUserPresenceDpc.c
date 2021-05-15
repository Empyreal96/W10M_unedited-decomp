// PopAwayModeUserPresenceDpc 
 
int __fastcall PopAwayModeUserPresenceDpc(int a1, unsigned int *a2)
{
  int result; // r0
  unsigned int v3; // r2

  __dmb(0xBu);
  result = 0;
  do
    v3 = __ldrex(a2);
  while ( __strex(0, a2) );
  __dmb(0xBu);
  return result;
}
