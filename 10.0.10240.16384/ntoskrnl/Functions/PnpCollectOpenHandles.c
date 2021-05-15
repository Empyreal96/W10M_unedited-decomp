// PnpCollectOpenHandles 
 
int __fastcall PnpCollectOpenHandles(int result, int a2, int a3)
{
  int *v5; // r6
  int v6; // t1

  v5 = (int *)result;
  if ( *(_BYTE *)(a3 + 20) )
    result = IopDebugPrint(20, (int)"Beginning handle dump:\n");
  *(_DWORD *)(a3 + 16) = 0;
  *(_DWORD *)(a3 + 8) = a3 + 8;
  *(_DWORD *)(a3 + 12) = a3 + 8;
  if ( (*(_BYTE *)(a3 + 20) || *(_BYTE *)(a3 + 21)) && a2 )
  {
    do
    {
      *(_DWORD *)a3 = *v5;
      v6 = *v5++;
      result = PnpHandleEnumerateHandlesAgainstPdoStack(v6);
      --a2;
    }
    while ( a2 );
  }
  if ( *(_BYTE *)(a3 + 20) )
    result = IopDebugPrint(20, (int)"Dump complete - %d total handles found.\n", *(_DWORD *)(a3 + 16));
  return result;
}
