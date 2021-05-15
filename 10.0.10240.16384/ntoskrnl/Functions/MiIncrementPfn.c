// MiIncrementPfn 
 
void __fastcall MiIncrementPfn(int a1)
{
  unsigned __int8 *v2; // r1
  unsigned int v3; // r2

  KfRaiseIrql(2);
  v2 = (unsigned __int8 *)(a1 + 15);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  JUMPOUT(0x50B84E);
}
