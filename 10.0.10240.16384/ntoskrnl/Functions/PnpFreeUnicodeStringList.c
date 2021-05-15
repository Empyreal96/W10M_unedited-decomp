// PnpFreeUnicodeStringList 
 
int __fastcall PnpFreeUnicodeStringList(int result, int a2)
{
  int v2; // r6
  int v3; // r5
  int v4; // r4
  int v5; // r0

  v2 = result;
  v3 = a2;
  if ( result )
  {
    if ( a2 )
    {
      v4 = result;
      do
      {
        v5 = *(_DWORD *)(v4 + 4);
        if ( v5 )
          ExFreePoolWithTag(v5, 0);
        v4 += 8;
        --v3;
      }
      while ( v3 );
    }
    result = ExFreePoolWithTag(v2, 0);
  }
  return result;
}
