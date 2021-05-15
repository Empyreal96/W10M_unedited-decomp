// SepFreeTokenCapabilities 
 
int __fastcall SepFreeTokenCapabilities(int a1)
{
  if ( SepTokenCapabilitySidSharingEnabled )
    SepDeReferenceSharedSidEntries(*(_DWORD *)(a1 + 484), *(_DWORD *)(a1 + 488));
  return ExFreePoolWithTag(*(_DWORD *)(a1 + 484), 0);
}
