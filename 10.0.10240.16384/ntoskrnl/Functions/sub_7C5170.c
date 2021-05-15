// sub_7C5170 
 
void __fastcall sub_7C5170(int a1, int a2)
{
  int v2; // r5
  int v3; // r0

  if ( !a2 || (v3 = *(_DWORD *)(v2 + 480)) != 0 && !RtlIsParentOfChildAppContainer(v3, a2) )
    JUMPOUT(0x6C1C54);
  JUMPOUT(0x6C1BEC);
}
