// CmpAccountForLogReservation 
 
int __fastcall CmpAccountForLogReservation(int a1, int a2, int a3)
{
  unsigned int v4; // r1
  int v5; // r3
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 80), 1, a3, v5);
  v6 = ClfsReserveAndAppendLog(*(_DWORD *)(a1 + 56), 0);
  v7 = ExReleaseResourceLite(*(_DWORD *)(a1 + 80));
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return v6;
}
