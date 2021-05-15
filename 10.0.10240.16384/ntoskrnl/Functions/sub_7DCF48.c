// sub_7DCF48 
 
void sub_7DCF48()
{
  int v0; // r4
  _BYTE *v1; // r7

  if ( **(_BYTE **)(v0 + 4) == 46 )
  {
    if ( v1 )
      *v1 = 0;
    JUMPOUT(0x6E95DC);
  }
  JUMPOUT(0x6E957C);
}
