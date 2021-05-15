// sub_7DF024 
 
void __fastcall sub_7DF024(int a1)
{
  int v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r1

  *(_DWORD *)(v1 + 12) = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(v1 + 16) = *(_DWORD *)(a1 + 16);
  __dmb(0xBu);
  v2 = *(unsigned int **)(a1 + 16);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + 1, v2) );
  __dmb(0xBu);
  JUMPOUT(0x6EE0F6);
}
