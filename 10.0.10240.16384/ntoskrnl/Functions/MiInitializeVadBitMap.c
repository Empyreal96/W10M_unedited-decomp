// MiInitializeVadBitMap 
 
int MiInitializeVadBitMap()
{
  int v0; // r7
  int v1; // r6
  int v2; // r4

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(_DWORD *)(v0 + 0x74);
  MEMORY[0xC040211C] = (unsigned int)(*(_DWORD *)(v1 + 392) - 65537) >> 16;
  MEMORY[0xC0402104] = MEMORY[0xC0402110] & 0x7FFF;
  MEMORY[0xC040212C] = 4 * ((MEMORY[0xC0402110] >> 15 << 12 >> 2) - 267386880);
  LOCK_ADDRESS_SPACE(v0, v1);
  v2 = MiExpandVadBitMap(1);
  MEMORY[0xC0402108] = MEMORY[0xC0402104];
  UNLOCK_ADDRESS_SPACE(v0, v1);
  return v2;
}
