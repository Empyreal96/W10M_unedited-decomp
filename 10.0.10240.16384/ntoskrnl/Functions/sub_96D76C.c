// sub_96D76C 
 
void __fastcall sub_96D76C(int a1)
{
  __int64 v1; // r4
  int v2; // r0

  v2 = BapdpProcessEtwEvents(a1);
  BapdpProcessHSTIResults(v2);
  HIDWORD(v1) = *(_DWORD *)(v1 + 4);
  if ( __PAIR64__(**(_DWORD **)(HIDWORD(v1) + 4), *(_DWORD *)HIDWORD(v1)) != v1 )
    __fastfail(3u);
  JUMPOUT(0x95E7AC);
}
