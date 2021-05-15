// sub_517B18 
 
void sub_517B18()
{
  int v0; // r5
  int v1; // r6

  *(_WORD *)(v0 + 2) = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 16) + 24) + 2);
  *(_WORD *)v0 = **(_WORD **)(*(_DWORD *)(v1 + 16) + 24);
  *(_DWORD *)(v0 + 4) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 16) + 24) + 4);
  JUMPOUT(0x439D70);
}
