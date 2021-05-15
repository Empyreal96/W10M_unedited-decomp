// HvpProtectBin 
 
int __fastcall HvpProtectBin(int a1, int a2, int a3, int a4, unsigned int a5, char a6)
{
  int result; // r0

  if ( ((*(_BYTE *)(a1 + 72) & 4) == 0 || a3 || a6) && !ExProtectPool(a5, a2, 4) )
    return -1073741670;
  if ( (*(_BYTE *)(a1 + 72) & 4) == 0
    || a3
    || (result = HvViewMapPinForFileOffset(a1 + 152, a4 + 4096, a2), result >= 0) )
  {
    result = 0;
  }
  return result;
}
