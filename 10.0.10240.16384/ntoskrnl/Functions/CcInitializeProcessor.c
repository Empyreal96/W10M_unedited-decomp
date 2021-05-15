// CcInitializeProcessor 
 
int __fastcall CcInitializeProcessor(int a1)
{
  __int16 v2; // r5
  int v3; // r0
  void *v4; // r4

  v2 = 128;
  if ( MmIsThisAnNtAsSystem() )
    v2 = 256;
  *(_DWORD *)(a1 + 1460) = &CcTwilightLookasideList;
  v3 = ExAllocatePoolWithTag(512, 128, 1264018243);
  v4 = (void *)v3;
  if ( v3 )
    ExInitializeSystemLookasideList(v3, 512, 72, 1264018243, v2, (int)&ExSystemLookasideListHead);
  else
    v4 = &CcTwilightLookasideList;
  *(_DWORD *)(a1 + 1456) = v4;
  return 0;
}
