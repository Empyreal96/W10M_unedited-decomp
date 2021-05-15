// PpmParkUpdateConcurrencyTracking 
 
int __fastcall PpmParkUpdateConcurrencyTracking(int result)
{
  int v1; // r2
  int v2; // r6
  unsigned __int16 v3; // r5
  int v4; // r2
  __int16 v5[2]; // [sp+0h] [bp-28h] BYREF
  int v6; // [sp+4h] [bp-24h]
  int v7; // [sp+8h] [bp-20h]

  v1 = 0;
  v2 = result;
  if ( PpmParkNumNodes )
  {
    v3 = 0;
    do
    {
      v4 = PpmParkNodes + 88 * v1;
      if ( v2 )
      {
        if ( (*(_BYTE *)(v4 + 82) & 8) == 0 )
        {
          *(_BYTE *)(v4 + 82) |= 8u;
          v5[0] = 1;
          v5[1] = 1;
          v6 = 0;
          v7 = 0;
          v7 = *(_DWORD *)(v4 + 8);
          result = PopExecuteOnTargetProcessors((int)v5, (int)PpmIdleInstallConcurrency, *(_DWORD *)(v4 + 28), 0);
        }
      }
      else if ( (*(_BYTE *)(v4 + 82) & 8) != 0 )
      {
        return sub_7F342C();
      }
      v1 = ++v3;
    }
    while ( v3 < (unsigned int)PpmParkNumNodes );
  }
  return result;
}
