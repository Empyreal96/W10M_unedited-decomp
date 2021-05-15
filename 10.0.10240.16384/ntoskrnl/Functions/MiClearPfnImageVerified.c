// MiClearPfnImageVerified 
 
int __fastcall MiClearPfnImageVerified(int a1, char a2, int a3, int a4)
{
  unsigned int v6; // r7
  int v7; // [sp+0h] [bp-20h]
  _DWORD v8[6]; // [sp+8h] [bp-18h] BYREF

  v7 = a1;
  v8[0] = a3;
  v8[1] = a4;
  if ( (*(_BYTE *)(a1 + 23) & 7) == 3 )
  {
    if ( (a2 & 4) == 0 )
      return sub_5264E0();
    if ( (a2 & 8) != 0 && MiGetPagePrivilege(a1, 1, v8) )
    {
      v6 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
      if ( KeSetPagePrivilege() < 0 )
        KeBugCheckEx(26, 333067, v6 + (v6 >> 31));
    }
    *(_DWORD *)(a1 + 20) &= 0xF8FFFFFF;
  }
  return v7;
}
