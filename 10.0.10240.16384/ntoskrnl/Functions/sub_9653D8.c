// sub_9653D8 
 
void __fastcall sub_9653D8(int a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1

  *(_DWORD *)(a1 + 12) = 0;
  v1 = *(unsigned int **)a1;
  *(_DWORD *)(a1 + 8) = -1437226411;
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  JUMPOUT(0x95DEFA);
}
