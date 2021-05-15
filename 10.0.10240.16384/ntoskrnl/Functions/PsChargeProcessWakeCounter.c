// PsChargeProcessWakeCounter 
 
int __fastcall PsChargeProcessWakeCounter(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v9; // r4
  int v10; // r7
  unsigned int v11; // r3
  int v12; // r4
  char v13; // r2
  int v14; // r4

  v4 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( !v4 )
    return 0;
  v9 = *(_DWORD *)(v4 + 744);
  if ( (v9 & 0x1000) == 0 )
    return 0;
  v10 = a2 & 2;
  if ( (a2 & 2) != 0 && (v9 & 0x800000) != 0 )
    return 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_DWORD *)(v11 + 116);
  if ( (a2 & 1) != 0 && !PspCheckConditionalWakeCharge(*(_DWORD *)(v11 + 116), v4, a3) )
    return 0;
  v13 = 1;
  if ( (*(_DWORD *)(v12 + 188) & 0x40) != 0 || !v10 )
  {
    v14 = a3;
  }
  else
  {
    v14 = 5;
    v13 = 5;
    if ( a2 < 0 )
      v13 = 7;
  }
  PspChargeJobWakeCounter((_DWORD *)v4, 0, a3, 0, 1u, 0, v13, a1, a4);
  ObfReferenceObjectWithTag(v4);
  return v14 | v4;
}
