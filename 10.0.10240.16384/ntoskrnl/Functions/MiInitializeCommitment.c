// MiInitializeCommitment 
 
int __fastcall MiInitializeCommitment(int a1)
{
  int v2; // r3
  char v3; // r3
  int v4; // r7
  int v5; // r6
  int v6; // r1
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r3

  if ( *(_DWORD *)(a1 + 3592) < 0x4000u )
    v2 = 256;
  else
    v2 = 1280;
  *(_DWORD *)(a1 + 3228) = v2;
  *(_DWORD *)(a1 + 3224) = 0;
  *(_BYTE *)(a1 + 284) = 1;
  *(_DWORD *)(a1 + 248) = 1;
  *(_DWORD *)(a1 + 252) = 0;
  *(_BYTE *)(a1 + 276) = -1;
  v3 = *(_BYTE *)(a1 + 279);
  *(_DWORD *)(a1 + 232) = 0;
  *(_BYTE *)(a1 + 279) = v3 & 0xFD;
  *(_DWORD *)(a1 + 244) = a1;
  *(_DWORD *)(a1 + 272) = 0;
  *(_BYTE *)(a1 + 258) = 4;
  *(_BYTE *)(a1 + 256) = 0;
  *(_BYTE *)(a1 + 257) = 0;
  *(_DWORD *)(a1 + 260) = 0;
  *(_DWORD *)(a1 + 264) = a1 + 264;
  *(_DWORD *)(a1 + 268) = a1 + 264;
  v4 = dword_633818;
  v5 = *(_DWORD *)(a1 + 3712);
  if ( dword_633818 )
  {
    v6 = *(_DWORD *)(a1 + 1036);
    v7 = *(_DWORD *)(a1 + 1032) - v6;
    do
    {
      v8 = *(unsigned __int16 *)(v7 + v6 + 4);
      v9 = *(unsigned __int16 *)(v6 + 4);
      v6 += 8;
      v5 += v9 + v8;
      --v4;
    }
    while ( v4 );
  }
  v10 = *(_DWORD *)(a1 + 3592);
  *(_DWORD *)(a1 + 3840) = v5;
  result = MiIncreaseCommitLimits(a1, v10, v10, 0);
  v12 = *(_DWORD *)(a1 + 3592);
  if ( v12 != v5 )
    result = MiChargeCommit(a1, v12 - v5, 2);
  if ( (__int16 *)a1 == MiSystemPartition )
  {
    v13 = *(_DWORD *)(a1 + 3844);
    __dmb(0xBu);
    dword_634D90 = v13;
    __dmb(0xBu);
    v14 = v13 - dword_634D94;
    __dmb(0xBu);
    dword_634D90 = v14;
  }
  return result;
}
