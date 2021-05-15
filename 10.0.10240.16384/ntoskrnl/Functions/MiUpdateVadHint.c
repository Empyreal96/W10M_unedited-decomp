// MiUpdateVadHint 
 
BOOL __fastcall MiUpdateVadHint(_DWORD *a1)
{
  unsigned int v1; // r1

  v1 = (a1[4] + 1) << 12;
  if ( v1 > MEMORY[0xC0402138] && v1 <= MEMORY[0xC0402134] )
    MEMORY[0xC0402138] = (a1[4] + 1) << 12;
  return (a1[7] & 0x8000) == 0 && (a1[8] & 0x7FFFFFFFu) < 0x7FFFE;
}
