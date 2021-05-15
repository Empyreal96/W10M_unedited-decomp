// KeConfigureHeteroProcessors 
 
int __fastcall KeConfigureHeteroProcessors(int a1)
{
  int v2; // r0
  __int16 v3[2]; // [sp+4h] [bp-28h] BYREF
  int v4; // [sp+8h] [bp-24h]
  int v5; // [sp+Ch] [bp-20h]

  if ( a1 )
    return sub_6942CC();
  v3[0] = 1;
  v3[1] = 1;
  v4 = 0;
  v5 = 0;
  v2 = KiDetectHeterogeneousSets(v3);
  if ( KiHeteroSystem != v2 )
    return sub_6942CC();
  PopHeteroSystem = v2;
  return 0;
}
