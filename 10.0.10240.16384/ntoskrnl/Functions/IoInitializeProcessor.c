// IoInitializeProcessor 
 
int __fastcall IoInitializeProcessor(int a1, int a2)
{
  int v5; // r0
  int v6; // r4
  int v7; // r3

  if ( !a2 )
    return sub_7CF3C8();
  v5 = ExAllocatePoolWithTag(512, 640, 28489);
  v6 = v5;
  if ( IopIrpCreditsEnabled > 0 )
    v7 = *(_DWORD *)(a2 + 28);
  else
    v7 = 0x7FFFFFFF;
  *(_DWORD *)(a1 + 1616) = v7;
  *(_DWORD *)(a1 + 1468) = &IopCompletionLookasideList;
  if ( v5 )
  {
    ExInitializeSystemLookasideList(v5, 512, 28, 1349542729, *(_WORD *)(a2 + 6), (int)&ExSystemLookasideListHead);
    *(_DWORD *)(a1 + 1464) = v6;
    v6 += 128;
  }
  else
  {
    *(_DWORD *)(a1 + 1464) = &IopCompletionLookasideList;
  }
  *(_DWORD *)(a1 + 1428) = &IopLargeIrpLookasideList;
  if ( v6 )
  {
    ExInitializeSystemLookasideList(
      v6,
      512,
      *(_DWORD *)(a2 + 20),
      1282437705,
      *(_WORD *)(a2 + 4),
      (int)&ExSystemLookasideListHead);
    *(_DWORD *)(a1 + 1424) = v6;
    v6 += 128;
  }
  else
  {
    *(_DWORD *)(a1 + 1424) = &IopLargeIrpLookasideList;
  }
  *(_DWORD *)(a1 + 1420) = &IopMediumIrpLookasideList;
  if ( v6 )
  {
    ExInitializeSystemLookasideList(
      v6,
      512,
      *(_DWORD *)(a2 + 16),
      1299214921,
      *(_WORD *)(a2 + 2),
      (int)&ExSystemLookasideListHead);
    *(_DWORD *)(a1 + 1416) = v6;
    v6 += 128;
  }
  else
  {
    *(_DWORD *)(a1 + 1416) = &IopMediumIrpLookasideList;
  }
  *(_DWORD *)(a1 + 1412) = &IopSmallIrpLookasideList;
  if ( v6 )
  {
    ExInitializeSystemLookasideList(
      v6,
      512,
      *(_DWORD *)(a2 + 12),
      1399878217,
      *(_WORD *)a2,
      (int)&ExSystemLookasideListHead);
    *(_DWORD *)(a1 + 1408) = v6;
    v6 += 128;
  }
  else
  {
    *(_DWORD *)(a1 + 1408) = &IopSmallIrpLookasideList;
  }
  *(_DWORD *)(a1 + 1436) = &IopMdlLookasideList;
  if ( v6 )
  {
    ExInitializeSystemLookasideList(
      v6,
      512,
      *(_DWORD *)(a2 + 24),
      1349280845,
      *(_WORD *)(a2 + 8),
      (int)&ExSystemLookasideListHead);
    *(_DWORD *)(a1 + 1432) = v6;
  }
  else
  {
    *(_DWORD *)(a1 + 1432) = &IopMdlLookasideList;
  }
  if ( (IopIrpStackProfilerFlags & 3) != 0 )
  {
    memset((_BYTE *)(a1 + 17448), 0, 80);
    *(_DWORD *)(a1 + 17528) = 0;
    memset((_BYTE *)(a1 + 17532), 0, 80);
    *(_DWORD *)(a1 + 17612) = 0;
  }
  return 0;
}
