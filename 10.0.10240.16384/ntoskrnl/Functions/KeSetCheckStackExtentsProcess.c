// KeSetCheckStackExtentsProcess 
 
int __fastcall KeSetCheckStackExtentsProcess(int a1, int a2)
{
  unsigned __int8 *v2; // r3
  unsigned int v3; // r1

  __dmb(0xBu);
  v2 = (unsigned __int8 *)(a1 + 100);
  if ( a2 )
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 | 0x20, v2) );
  }
  else
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 & 0xDF, v2) );
  }
  __dmb(0xBu);
  return (unsigned __int8)(v3 & 0x20) >> 5;
}
