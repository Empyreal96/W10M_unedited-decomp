// sub_968910 
 
void sub_968910()
{
  _BYTE *v0; // r7

  if ( ZwSetValueKey() >= 0 )
    *v0 = 1;
  JUMPOUT(0x9504BC);
}
