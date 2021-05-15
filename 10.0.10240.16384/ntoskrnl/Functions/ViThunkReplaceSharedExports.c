// ViThunkReplaceSharedExports 
 
int __fastcall ViThunkReplaceSharedExports(int result, int a2)
{
  int *v2; // r4
  int v3; // r5

  v2 = (int *)result;
  v3 = a2;
  if ( result && a2 )
  {
    do
    {
      result = *v2;
      if ( *v2 )
        result = MmReplaceImportEntry(result, v2[1]);
      v2 += 2;
      --v3;
    }
    while ( v3 );
  }
  return result;
}
