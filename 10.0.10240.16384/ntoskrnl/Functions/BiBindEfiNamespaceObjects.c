// BiBindEfiNamespaceObjects 
 
int __fastcall BiBindEfiNamespaceObjects(int a1, int a2)
{
  int v3; // r4
  int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[1] = (int)v5;
  v5[0] = (int)v5;
  v3 = BiBuildIdentifierList(a1, a2, v5);
  if ( v3 >= 0 )
  {
    v3 = BiBindEfiEntries(a1, v5);
    if ( v3 >= 0 )
      v3 = BiBindEfiBootManager(a1, v5);
  }
  BiFreeIdentifierList(v5);
  return v3;
}
