// sub_52D3BC 
 
void __fastcall sub_52D3BC(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r6
  int v5; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r1

  v5 = *(_DWORD *)(v3 + 152);
  __dmb(0xBu);
  v6 = (unsigned int *)(v5 + 4 * (a3 + 68));
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 - 1, v6) );
  __dmb(0xBu);
  v8 = (unsigned int *)(v5 + 4 * (v4 + 68));
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 + 1, v8) );
  __dmb(0xBu);
  JUMPOUT(0x478518);
}
