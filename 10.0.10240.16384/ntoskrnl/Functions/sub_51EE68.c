// sub_51EE68 
 
void __fastcall sub_51EE68(unsigned int *a1)
{
  int v1; // r6
  unsigned int v2; // r2
  unsigned int v3; // r2

  __dmb(0xBu);
  do
  {
    v2 = __ldrex(a1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, a1) );
  __dmb(0xBu);
  if ( !v3 )
    KeSetEvent(v1 + 116, 0, 0);
  JUMPOUT(0x44E5B8);
}
