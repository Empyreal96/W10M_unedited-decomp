// SmSwapStore 
 
int __fastcall SmSwapStore(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v7; // r2
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v8[0] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v5 = SmpKeyedStoreEntryGet((int)byte_636CC4, (int)v8, 0, 0);
  if ( !v5 )
    return -1073741275;
  if ( a1 == 2 )
    v7 = 2;
  else
    v7 = a1 != 0;
  return SMKM_STORE_MGR<SM_TRAITS>::SmSwapStore(
           (int)SmGlobals,
           (_DWORD *)SmGlobals[24 * (*(_WORD *)(v5 + 8) & 0x1F)],
           v7);
}
