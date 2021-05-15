// sub_7C5148 
 
void __fastcall sub_7C5148(int a1)
{
  int v1; // r5

  if ( !RtlIsParentOfChildAppContainer(a1, v1) )
    JUMPOUT(0x6C1AFE);
  JUMPOUT(0x6C1ACA);
}
