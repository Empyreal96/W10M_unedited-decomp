// sub_801230 
 
void sub_801230()
{
  int v0; // r5
  int v1; // r8

  DbgUnLoadImageSymbolsUnicode(
    (unsigned __int16 *)((*(_DWORD *)(v0 + 32) & 0xFFFFFFF8) + 48),
    *(_DWORD *)(v1 + 24),
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  JUMPOUT(0x73E374);
}
