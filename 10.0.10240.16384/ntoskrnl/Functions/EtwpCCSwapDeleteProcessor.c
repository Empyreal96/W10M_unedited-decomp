// EtwpCCSwapDeleteProcessor 
 
int __fastcall EtwpCCSwapDeleteProcessor(int a1)
{
  int v2; // r5
  int result; // r0

  v2 = 4;
  do
  {
    result = *(_DWORD *)(a1 + 1884);
    if ( result )
      result = ExFreePoolWithTag(result);
    a1 += 4;
    --v2;
  }
  while ( v2 );
  return result;
}
