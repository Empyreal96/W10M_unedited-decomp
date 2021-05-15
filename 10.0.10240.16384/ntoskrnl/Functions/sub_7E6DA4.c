// sub_7E6DA4 
 
void sub_7E6DA4()
{
  int v0; // r6
  int v1; // r9

  DbgUnLoadImageSymbolsUnicode(
    (unsigned __int16 *)((*(_DWORD *)(v1 + 32) & 0xFFFFFFF8) + 48),
    *(_DWORD *)(v0 + 24),
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  *(_WORD *)(v0 + 8) &= 0xDFFFu;
  JUMPOUT(0x6F3252);
}
