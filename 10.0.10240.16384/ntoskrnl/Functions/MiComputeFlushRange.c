// MiComputeFlushRange 
 
int __fastcall MiComputeFlushRange(int a1, int a2, int a3, int a4)
{
  _DWORD *v7; // r0
  int v8; // r3
  int v10[4]; // [sp+8h] [bp-10h] BYREF

  v10[0] = a4;
  v7 = (_DWORD *)MiLockSectionControlArea(a1, 1, v10);
  if ( v7 )
  {
    v8 = v7[7];
    if ( (v8 & 1) == 0 && (v8 & 2) == 0 && v7[4] )
      return MiComputeDataFlushRange(v7, LOBYTE(v10[0]), a2, a3, 0, a4);
    if ( (dword_682604 & 0x10000) != 0 )
      return sub_53D1B0();
    __dmb(0xBu);
    v7[9] = 0;
    KfLowerIrql(LOBYTE(v10[0]));
  }
  return 0;
}
