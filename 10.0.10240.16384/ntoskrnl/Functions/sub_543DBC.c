// sub_543DBC 
 
void sub_543DBC()
{
  int v0; // r4
  int v1; // r5
  char v2; // r6
  int v3; // r9
  int v4; // r10
  unsigned int v5; // r2
  int v6; // r3

  if ( !MiCanPageMove(v4)
    || (*(_DWORD *)(v1 + 52) & 0xC000000) != 0
    && (*(_DWORD *)(v3 + 4) & 0xFFFFFFF8) != 8
    && ((v5 = *(_DWORD *)(v4 + 8), (v5 & 0x400) != 0) ? (v6 = (*(unsigned __int16 *)((*(_DWORD *)(v4 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v4 + 8) & 0x3FC)))
                                                                                   + 0x10) >> 1) & 0x1F) : (v6 = (v5 >> 5) & 0x1F),
        (v6 & 2) != 0) )
  {
    *(_BYTE *)(v0 + 114) = v2 & 0xF7;
  }
  JUMPOUT(0x4B901A);
}
