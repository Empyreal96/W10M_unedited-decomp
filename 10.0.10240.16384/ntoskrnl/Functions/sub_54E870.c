// sub_54E870 
 
void sub_54E870()
{
  int v0; // r5
  _DWORD *v1; // r7

  if ( v0 )
    ExFreePoolWithTag(v0, 0);
  if ( *v1 )
  {
    if ( !ExAllocatePoolWithTag(512, *v1) )
      JUMPOUT(0x4E71B0);
    JUMPOUT(0x4E70FC);
  }
  JUMPOUT(0x4E7120);
}
