// WheaInitializeRecordHeader 
 
int __fastcall WheaInitializeRecordHeader(int a1)
{
  unsigned __int64 v2; // kr00_8

  memset((_BYTE *)a1, 0, 128);
  *(_DWORD *)a1 = 1380274243;
  *(_WORD *)(a1 + 4) = 528;
  *(_DWORD *)(a1 + 6) = -1;
  *(_WORD *)(a1 + 10) = 0;
  *(_DWORD *)(a1 + 12) = 3;
  *(_DWORD *)(a1 + 16) |= 2u;
  *(_DWORD *)(a1 + 64) = -821574467;
  *(_DWORD *)(a1 + 68) = 1310242697;
  *(_DWORD *)(a1 + 72) = 1931461811;
  *(_DWORD *)(a1 + 76) = 829535532;
  WheapGetTimestamp(a1 + 24);
  __dmb(0xBu);
  do
    v2 = __ldrexd(&WheapErrorRecordId);
  while ( __strexd(v2 + 1, &WheapErrorRecordId) );
  __dmb(0xBu);
  *(_QWORD *)(a1 + 96) = v2 + 1;
  return 0;
}
