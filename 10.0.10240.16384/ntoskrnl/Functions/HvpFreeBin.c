// HvpFreeBin 
 
int __fastcall HvpFreeBin(int result, int a2, int a3, int a4, int a5)
{
  int v7; // r6
  int v8; // r0

  v7 = result;
  if ( (*(_BYTE *)(result + 72) & 4) == 0 || a3 )
  {
    CmpProtectPool(a4, a2);
    v8 = a4;
  }
  else
  {
    if ( !a5 )
      return result;
    CmpProtectPool(a5, a2);
    v8 = a5;
  }
  return (*(int (__fastcall **)(int, int))(v7 + 16))(v8, a2);
}
