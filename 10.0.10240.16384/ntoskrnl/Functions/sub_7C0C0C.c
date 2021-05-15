// sub_7C0C0C 
 
// positive sp value has been detected, the output may be wrong!
unsigned int __fastcall sub_7C0C0C(int a1, _DWORD *a2, int a3)
{
  unsigned int v4; // r4
  int v5; // r5

  if ( *a2 != v4 )
    __fastfail(3u);
  *a2 = v5;
  *(_DWORD *)(v5 + 4) = a2;
  if ( !a3 )
    --*(_DWORD *)(a1 + 72);
  PiUEventDereferenceEventEntry(*(_DWORD *)(v4 + 16));
  return ExFreePoolWithTag(v4);
}
