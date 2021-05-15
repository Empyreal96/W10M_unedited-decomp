// MiIsPoolHeader 
 
BOOL __fastcall MiIsPoolHeader(_WORD *a1)
{
  return (*a1 & 0x1FF) == 0 && (*a1 & 0xFE00) == 0 && (a1[1] & 0x1FF) != 0;
}
