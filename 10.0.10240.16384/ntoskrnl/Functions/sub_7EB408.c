// sub_7EB408 
 
void __fastcall sub_7EB408(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r1

  __dmb(0xBu);
  v6 = (unsigned int *)(v5 + 40);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  EtwpUnreferenceDataBlock(a5);
  JUMPOUT(0x764EFE);
}
