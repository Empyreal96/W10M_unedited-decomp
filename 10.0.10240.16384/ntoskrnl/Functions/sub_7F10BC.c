// sub_7F10BC 
 
void sub_7F10BC()
{
  int v0; // r5
  char v1; // r4

  v1 = *(_BYTE *)(v0 + 145);
  if ( (v1 & 1) == 0 )
  {
    v1 = v1 & 0xFE | PopConnectedStandbyCompliantNic() & 1;
    *(_BYTE *)(v0 + 145) = v1;
  }
  if ( (v1 & 2) != 0 )
    *(_BYTE *)(v0 + 145) ^= (*(_BYTE *)(v0 + 145) ^ (2 * PopDisconnectedStandbyEnabled(0))) & 2;
  JUMPOUT(0x78BDE4);
}
