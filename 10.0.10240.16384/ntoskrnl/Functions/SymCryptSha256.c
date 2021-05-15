// SymCryptSha256 
 
int __fastcall SymCryptSha256(int a1, int a2, int a3)
{
  _BYTE v7[136]; // [sp-4h] [bp-88h] BYREF

  SymCryptSha256Init(v7);
  SymCryptSha256Append(v7, a1, a2);
  return SymCryptSha256Result(v7, a3);
}
