// StEtaCleanup 
 
int __fastcall StEtaCleanup(int a1)
{
  int v2; // r5
  int result; // r0

  v2 = 2;
  do
  {
    result = *(_DWORD *)(a1 + 16);
    if ( result )
      result = ExFreePoolWithTag(result, 0);
    a1 += 4;
    --v2;
  }
  while ( v2 );
  return result;
}
