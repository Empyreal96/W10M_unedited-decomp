// SepSetTokenCapabilities 
 
int __fastcall SepSetTokenCapabilities(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r4
  int v8; // r4
  int *v9; // r7
  int v10; // r0
  int v11; // r4
  int v13; // r0
  int v14[8]; // [sp+18h] [bp-20h] BYREF

  v4 = *(_DWORD *)(a1 + 484);
  v14[0] = 0;
  v14[1] = 0;
  if ( !v4 )
  {
    if ( !a4 )
    {
      if ( *(_DWORD *)(a1 + 484) )
        SepFreeTokenCapabilities(a1);
      *(_DWORD *)(a1 + 484) = 0;
      *(_DWORD *)(a1 + 488) = 0;
      return 0;
    }
    if ( a4 > 0x1000 )
      return -1073741811;
    if ( SepTokenCapabilitySidSharingEnabled )
    {
      v8 = ((8 * a4 + 3) & 0xFFFFFFFC) + 8 * a4;
      goto LABEL_6;
    }
    v13 = SepLengthSidAndAttributesArray(a3, a4, v14);
    v11 = v13;
    if ( v13 >= 0 )
    {
      v8 = v14[0];
LABEL_6:
      v9 = (int *)ExAllocatePoolWithTag(1, v8, 1934845267);
      if ( v9 )
      {
        if ( SepTokenCapabilitySidSharingEnabled )
          v10 = SepInsertOrReferenceSharedSidEntries(a3, v9, a4);
        else
          v10 = SeCaptureSidAndAttributesArray(a3, a4, 0, v9, v8);
        v11 = v10;
        if ( v10 < 0 )
        {
          ExFreePoolWithTag((unsigned int)v9);
        }
        else
        {
          if ( *(_DWORD *)(a1 + 484) )
            SepFreeTokenCapabilities(a1);
          *(_DWORD *)(a1 + 484) = v9;
          *(_DWORD *)(a1 + 488) = a4;
          RtlSidHashInitialize(v9, a4, a1 + 492);
        }
      }
      else
      {
        v11 = -1073741670;
      }
    }
    return v11;
  }
  return sub_7C5170();
}
