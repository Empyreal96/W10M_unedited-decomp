// sub_7F6B30 
 
void sub_7F6B30()
{
  int v0; // r5

  if ( (*(_WORD *)(v0 + 2) & 1) != 0 )
    RtlRaiseStatus(-1073741637);
  JUMPOUT(0x71B326);
}
