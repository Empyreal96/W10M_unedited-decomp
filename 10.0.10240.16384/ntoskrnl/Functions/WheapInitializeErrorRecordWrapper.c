// WheapInitializeErrorRecordWrapper 
 
unsigned int __fastcall WheapInitializeErrorRecordWrapper(int a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r2
  unsigned int result; // r0
  int v7; // r1

  *(_DWORD *)(a1 + 8) = a2;
  *(_DWORD *)(a1 + 24) = a3;
  *(_DWORD *)(a1 + 28) = 1380274243;
  *(_WORD *)(a1 + 32) = 528;
  *(_DWORD *)(a1 + 34) = -1;
  v4 = a1 + 156;
  *(_DWORD *)(a1 + 92) = -821574467;
  *(_DWORD *)(a1 + 96) = 1310242697;
  *(_DWORD *)(a1 + 100) = 1931461811;
  *(_DWORD *)(a1 + 104) = 829535532;
  *(_WORD *)(a1 + 38) = *(_DWORD *)(a3 + 44);
  *(_DWORD *)(a1 + 40) = 3;
  *(_DWORD *)(a1 + 48) = a2 - 28;
  v5 = *(_DWORD *)(a3 + 44);
  result = 0;
  v7 = 72 * v5 + 128;
  if ( v5 )
  {
    do
    {
      *(_DWORD *)v4 = v7;
      ++result;
      *(_DWORD *)(v4 + 4) = *(_DWORD *)(a3 + 48);
      *(_WORD *)(v4 + 8) = 513;
      v4 += 72;
      v7 += *(_DWORD *)(a3 + 48);
    }
    while ( result < *(_DWORD *)(a3 + 44) );
  }
  return result;
}
