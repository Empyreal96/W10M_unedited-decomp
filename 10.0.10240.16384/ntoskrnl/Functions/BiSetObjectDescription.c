// BiSetObjectDescription 
 
int __fastcall BiSetObjectDescription(int a1, int a2)
{
  int result; // r0
  char v5[4]; // [sp+8h] [bp-18h] BYREF
  int v6[5]; // [sp+Ch] [bp-14h] BYREF

  v6[0] = 0;
  result = BiCreateKey(a1, L"Description", 131097, 1, v6, v5);
  if ( result >= 0 )
  {
    BiCloseKey(v6[0]);
    result = BiSetRegistryValue(a1, L"Type", L"Description", 4, a2 + 4, 4);
  }
  return result;
}
