// ObInitializeProcessor 
 
int __fastcall ObInitializeProcessor(_DWORD *a1)
{
  int v3; // r0
  void *v4; // r8
  int v5; // r0
  void *v6; // r4

  if ( MmIsThisAnNtAsSystem() )
    return sub_7CF3C0();
  a1[361] = &ObpCreateInfoLookasideList;
  v3 = ExAllocatePoolWithTag(512, 128, 1229152847);
  v4 = (void *)v3;
  if ( v3 )
    ExInitializeSystemLookasideList(v3, 512, 44, 1229152847, 32, (int)&ExSystemLookasideListHead);
  else
    v4 = &ObpCreateInfoLookasideList;
  a1[363] = &ObpNameBufferLookasideList;
  a1[360] = v4;
  v5 = ExAllocatePoolWithTag(512, 128, 1296982607);
  v6 = (void *)v5;
  if ( v5 )
    ExInitializeSystemLookasideList(v5, 1, 248, 1296982607, 16, (int)&ExSystemLookasideListHead);
  else
    v6 = &ObpNameBufferLookasideList;
  a1[362] = v6;
  return 0;
}
