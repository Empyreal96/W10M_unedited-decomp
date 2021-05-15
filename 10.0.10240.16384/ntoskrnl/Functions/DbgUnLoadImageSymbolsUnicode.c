// DbgUnLoadImageSymbolsUnicode 
 
int __fastcall DbgUnLoadImageSymbolsUnicode(unsigned __int16 *a1, int a2, int a3)
{
  _DWORD v6[8]; // [sp+0h] [bp-20h] BYREF

  if ( DbgUnicodeStringToAnsiString((int)v6, a1) )
  {
    v6[4] = 0;
    v6[5] = 0;
    v6[2] = a2;
    v6[3] = a3;
    DebugService2();
  }
  return 0;
}
