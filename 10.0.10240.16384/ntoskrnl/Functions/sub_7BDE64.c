// sub_7BDE64 
 
void sub_7BDE64()
{
  int v0; // r4
  int v1; // r5

  **(_DWORD **)(v1 + 8) = 1;
  if ( *(_DWORD *)v1 )
  {
    if ( IopAppendLegacyVeto(v1, v0 + 20) )
      JUMPOUT(0x77E88C);
  }
  JUMPOUT(0x77E8A4);
}
