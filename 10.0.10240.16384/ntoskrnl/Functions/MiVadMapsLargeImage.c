// MiVadMapsLargeImage 
 
BOOL __fastcall MiVadMapsLargeImage(int a1)
{
  return (*(_DWORD *)(a1 + 28) & 7) == 2 && (*(_BYTE *)(a1 + 43) & 1) != 0;
}
