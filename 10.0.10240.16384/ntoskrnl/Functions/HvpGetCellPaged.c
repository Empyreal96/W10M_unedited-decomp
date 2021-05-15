// HvpGetCellPaged 
 
int __fastcall HvpGetCellPaged(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  int v6; // r3
  int v7; // r0
  int v8; // r4
  char v10[4]; // [sp+0h] [bp-18h] BYREF
  _DWORD v11[5]; // [sp+4h] [bp-14h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v6 = (unsigned __int8)HvShutdownComplete;
  __dmb(0xBu);
  if ( v6 == 1 )
    return 0;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 412 * (a2 >> 31) + 956) + 4 * ((a2 >> 21) & 0x3FF));
  v8 = (a2 & 0xFFF) + HvpMapEntryGetBlockAddress(v7, (int *)(v7 + 20 * ((a2 >> 12) & 0x1FF)), v10, v11);
  HvpFaultCellWithClustering();
  *a3 = a2 & 0xFFFFFFFE | v10[0] & 1;
  return v8 + 4;
}
