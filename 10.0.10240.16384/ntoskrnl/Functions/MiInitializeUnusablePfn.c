// MiInitializeUnusablePfn 
 
void __fastcall MiInitializeUnusablePfn(int a1)
{
  unsigned __int8 *v2; // r4
  unsigned int v3; // r2

  __mrc(15, 0, 13, 0, 3);
  KfRaiseIrql(2);
  v2 = (unsigned __int8 *)(a1 + 15);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  JUMPOUT(0x96B30A);
}
