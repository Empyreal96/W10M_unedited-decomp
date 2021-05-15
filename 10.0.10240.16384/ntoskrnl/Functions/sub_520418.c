// sub_520418 
 
void sub_520418()
{
  int v0; // r4

  if ( (*(_WORD *)(v0 + 10) & 1) != 0 )
    RtlRaiseStatus(-1073741670);
  JUMPOUT(0x451C56);
}
