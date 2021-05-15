// MiReferenceControlAreaForCacheManager 
 
int __fastcall MiReferenceControlAreaForCacheManager(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r0
  _DWORD var10[8]; // [sp+0h] [bp-10h] BYREF
  int varg_r2; // [sp+20h] [bp+10h]
  int varg_r3; // [sp+24h] [bp+14h]

  var10[6] = a1;
  var10[7] = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  var10[0] = a3;
  var10[1] = a4;
  v4 = MiLockSectionControlArea(*(_DWORD *)(a1 + 20), (a2 & 0x1000000) == 0, var10);
  v5 = (_DWORD *)v4;
  if ( !v4 )
    return -1073741823;
  v6 = *(_DWORD *)(v4 + 28);
  if ( (v6 & 1) != 0 || (v6 & 2) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4 + 36);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v4 + 36) = 0;
    }
    KfLowerIrql(LOBYTE(var10[0]));
    return -1073741823;
  }
  v7 = MiBuildWakeList(v4, 4);
  ++v5[3];
  v8 = MiRemoveUnusedSegment(v5);
  if ( (varg_r2 & 1) == 0 )
    return sub_522B94(v8);
  v5[7] |= 0x8000u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
  }
  else
  {
    __dmb(0xBu);
    v5[9] = 0;
  }
  KfLowerIrql(LOBYTE(var10[0]));
  MiReleaseControlAreaWaiters(v7);
  return 0;
}
