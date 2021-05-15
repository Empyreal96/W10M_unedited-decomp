// BgpDisplayCharacterEx 
 
int __fastcall BgpDisplayCharacterEx(int a1, int *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int result; // r0
  int v13; // r0
  _DWORD v14[2]; // [sp+10h] [bp-28h] BYREF
  int v15[8]; // [sp+18h] [bp-20h] BYREF

  if ( (dword_619018 & 1) == 0 )
    return -1073741823;
  v14[0] = a3;
  v14[1] = a4;
  v13 = a2[5];
  v15[0] = a5;
  v15[1] = a6;
  v15[3] = a2[1];
  v15[2] = *a2;
  result = BgpTxtAdjustStaticRegion(v13, v14, v15);
  if ( result >= 0 )
    result = BgpTxtDisplayCharacter(a2[5], a1, 0, a7, a8, 0, a10);
  return result;
}
