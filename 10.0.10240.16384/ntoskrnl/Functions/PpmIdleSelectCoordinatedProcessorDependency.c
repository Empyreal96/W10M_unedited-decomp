// PpmIdleSelectCoordinatedProcessorDependency 
 
int __fastcall PpmIdleSelectCoordinatedProcessorDependency(__int64 a1, unsigned int a2, int a3, unsigned __int64 a4, unsigned int *a5, _DWORD *a6)
{
  unsigned int v6; // lr
  unsigned int v7; // r6
  int v8; // r5
  int v9; // r4
  int v11; // [sp+10h] [bp-28h]
  unsigned int v12; // [sp+14h] [bp-24h]
  unsigned int v13; // [sp+18h] [bp-20h]

  v12 = a2;
  v13 = HIDWORD(a1);
  v6 = HIDWORD(a1);
  v11 = a1;
  LODWORD(a1) = -2147483647;
  v7 = 0;
  if ( *a5 )
  {
    v8 = 0;
    do
    {
      v9 = a5[1] + v8;
      if ( *(_BYTE *)(v9 + 1) )
      {
        LODWORD(a1) = PpmIdleCheckProcessorStateEligibility(
                        v11,
                        v6,
                        a2,
                        *(_DWORD *)(v9 + 4),
                        a4,
                        *(_DWORD *)(v9 + 4),
                        PpmIdleCoordinatedMode == 0);
        if ( !a1 )
        {
          *a6 = *(_DWORD *)(v9 + 4);
          return a1;
        }
        a2 = v12;
        v6 = v13;
      }
      ++v7;
      v8 += 16;
    }
    while ( v7 < *a5 );
  }
  return a1;
}
