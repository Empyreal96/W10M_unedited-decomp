// sub_534C90 
 
void sub_534C90()
{
  int v0; // r4

  if ( (*(_DWORD *)(v0 + 8) & 0x400) != 0 )
  {
    if ( MiChargeCommit((int)MiSystemPartition, 1u, 4) )
      JUMPOUT(0x48F0A4);
    JUMPOUT(0x48F0F8);
  }
  JUMPOUT(0x48F088);
}
