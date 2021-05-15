// ViWdBeforeCallDriver 
 
int __fastcall ViWdBeforeCallDriver(int result, unsigned int a2, _DWORD *a3)
{
  int v4; // r4
  int v5; // r3

  v4 = result;
  if ( !*a3 && *(_BYTE *)(result + 32) == 1 )
  {
    result = VfTargetDriversIsEnabled(a2, a2);
    if ( result )
    {
      v5 = ViWdInitialized;
      __dmb(0xBu);
      if ( v5 )
      {
        result = ExAllocateFromNPagedLookasideList((int)&ViWdIrpLookasideList);
        if ( result )
        {
          *(_DWORD *)(result + 8) = v4;
          *(_BYTE *)(result + 17) = *(_BYTE *)(v4 + 35);
          __dmb(0xBu);
          *(_BYTE *)(result + 16) = 0;
          *a3 = result;
        }
      }
    }
  }
  return result;
}
