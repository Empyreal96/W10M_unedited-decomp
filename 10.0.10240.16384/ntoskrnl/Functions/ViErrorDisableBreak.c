// ViErrorDisableBreak 
 
unsigned int __fastcall ViErrorDisableBreak(unsigned int result)
{
  int v1; // r2
  int *v2; // r1
  int v3; // t1
  unsigned int *v4; // r2

  v1 = 0;
  v2 = &ViErrorDescriptions;
  while ( 1 )
  {
    v3 = *v2;
    v2 += 3;
    if ( v3 == result )
      break;
    if ( (unsigned int)++v1 >= 0x3F )
      return result;
  }
  __dmb(0xBu);
  v4 = (unsigned int *)&algn_9287C4[12 * v1];
  do
    result = __ldrex(v4);
  while ( __strex(result | 1, v4) );
  __dmb(0xBu);
  return result;
}
