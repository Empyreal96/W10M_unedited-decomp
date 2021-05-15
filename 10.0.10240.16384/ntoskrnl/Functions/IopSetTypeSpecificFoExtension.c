// IopSetTypeSpecificFoExtension 
 
int __fastcall IopSetTypeSpecificFoExtension(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int *v3; // r1
  unsigned int v4; // r0
  int result; // r0

  if ( a2 > 6 )
    return -1073741811;
  __dmb(0xBu);
  v3 = (unsigned int *)(a1 + 4 * (a2 + 1));
  do
    v4 = __ldrex(v3);
  while ( !v4 && __strex(a3, v3) );
  __dmb(0xBu);
  if ( v4 )
    result = -1073741823;
  else
    result = 0;
  return result;
}
