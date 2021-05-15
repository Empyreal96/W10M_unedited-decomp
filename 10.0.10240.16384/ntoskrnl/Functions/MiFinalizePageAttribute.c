// MiFinalizePageAttribute 
 
int __fastcall MiFinalizePageAttribute(int a1, int a2, int a3)
{
  if ( *(unsigned __int8 *)(a1 + 18) >> 6 != a2 )
    MiChangePageAttribute(a1, a2, a3 == 1);
  return MiSetPfnTbFlushStamp(a1, 0, a3);
}
