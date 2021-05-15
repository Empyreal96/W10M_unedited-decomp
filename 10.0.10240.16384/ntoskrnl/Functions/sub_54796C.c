// sub_54796C 
 
void __fastcall sub_54796C(int a1, _DWORD *a2)
{
  if ( (*a2 & 0x200001) == 2097153 && !RtlGuardIsValidStackPointer(a2[14]) )
    JUMPOUT(0x4C50F2);
  JUMPOUT(0x4C50F0);
}
