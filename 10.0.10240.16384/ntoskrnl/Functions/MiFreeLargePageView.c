// MiFreeLargePageView 
 
int __fastcall MiFreeLargePageView(int a1, int a2, char a3)
{
  char v4; // r5
  int v6; // r0
  int v7; // r9
  int v8; // r10
  int v9; // r8
  unsigned int *v10; // r1
  unsigned int v11; // r6
  __int16 *v12; // r0
  int v13; // r2
  int v14; // r3
  _DWORD *v17; // [sp+4h] [bp-24h]
  unsigned int v18; // [sp+8h] [bp-20h]

  v4 = a3;
  v6 = MiGetVadWakeList(a2, 16);
  v17 = *(_DWORD **)(v6 + 8);
  v18 = v6;
  v7 = *(_DWORD *)(a2 + 32) & 0x7FFFFFFF;
  v8 = MiReturnLargePages(v17);
  if ( (v4 & 1) == 0 )
  {
    v9 = __mrc(15, 0, 13, 0, 3);
    v10 = (unsigned int *)(a1 + 648);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 - v7, v10) );
    if ( (a3 & 2) == 0 )
      LOCK_ADDRESS_SPACE_SHARED(v9 & 0xFFFFFFC0, a1);
    v12 = MiGetThreadPartition();
    MiReturnCommit((int)v12, v8);
    MiReturnFullProcessCharges(a1, v7, v13, v14);
    if ( (a3 & 2) == 0 )
      UNLOCK_ADDRESS_SPACE_SHARED(v9 & 0xFFFFFFC0, a1);
  }
  ExFreePoolWithTag((unsigned int)v17);
  ExFreePoolWithTag(v18);
  return v7 - v8;
}
