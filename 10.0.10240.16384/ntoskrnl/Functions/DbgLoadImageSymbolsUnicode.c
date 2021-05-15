// DbgLoadImageSymbolsUnicode 
 
int __fastcall DbgLoadImageSymbolsUnicode(int a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v7 = a3;
  v8 = a4;
  if ( !DbgUnicodeStringToAnsiString(&v6, a1) )
    return 0;
  DbgLoadImageSymbols(&v6, a2, -1);
  ExFreePoolWithTag(v7, 0);
  return 1;
}
