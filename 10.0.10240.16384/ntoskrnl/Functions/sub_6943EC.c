// sub_6943EC 
 
void __fastcall sub_6943EC(unsigned int *a1)
{
  int v1; // r9
  unsigned int v2; // r2

  do
    v2 = __ldrex(a1);
  while ( __strex(v2 - 1, a1) );
  KiAsidAlloc(v1);
  JUMPOUT(0x6935FC);
}
