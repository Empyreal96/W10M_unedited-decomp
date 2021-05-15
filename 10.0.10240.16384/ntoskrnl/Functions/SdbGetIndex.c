// SdbGetIndex 
 
int __fastcall SdbGetIndex(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r5
  int v9; // r4
  int i; // r0
  int v11; // r3

  v5 = 0;
  if ( a4 )
    *a4 = 0;
  if ( !*(_DWORD *)(a1 + 1324) )
    SdbpScanIndexes(a1, a2, a3);
  v9 = 0;
  for ( i = a1; ; i += 40 )
  {
    if ( !*(_WORD *)(i + 44) )
      return 0;
    if ( *(unsigned __int16 *)(i + 44) == a2 && *(unsigned __int16 *)(i + 46) == a3 )
      break;
    if ( ++v9 >= 32 )
      return v5;
  }
  v11 = a1 + 40 * v9;
  v5 = *(_DWORD *)(v11 + 40);
  if ( a4 )
    *a4 = *(_DWORD *)(v11 + 72);
  return v5;
}
