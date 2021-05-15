// sub_7C74D4 
 
void sub_7C74D4()
{
  int v0; // r4
  int v1; // r7
  int v2; // r0

  if ( (*(_DWORD *)(v1 + 176) & 0x20) == 0 )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(v1 + 192) + 88);
    if ( v2 )
    {
      if ( v0 == *(_DWORD *)PsGetServerSiloGlobals(v2) )
        JUMPOUT(0x6CC24E);
    }
  }
  JUMPOUT(0x6CC250);
}
