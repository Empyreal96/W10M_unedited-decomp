// sub_7CFF34 
 
void sub_7CFF34()
{
  int v0; // r4
  int v1; // r5

  if ( (*(_DWORD *)(v0 + 72) & 8) != 0 )
  {
    ExFreePoolWithTag(*(_DWORD *)(v0 + 140));
    *(_DWORD *)(v0 + 140) = v1;
  }
  JUMPOUT(0x789BEC);
}
