// sub_8137BC 
 
void sub_8137BC()
{
  unsigned int v0; // r5

  if ( BiModifyBootEntry(v0) < 0 )
  {
    ExFreePoolWithTag(v0);
    JUMPOUT(0x7A5702);
  }
  JUMPOUT(0x7A56F6);
}
