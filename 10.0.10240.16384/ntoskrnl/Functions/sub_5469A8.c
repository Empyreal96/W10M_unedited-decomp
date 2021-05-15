// sub_5469A8 
 
void sub_5469A8()
{
  int v0; // r4
  int v1; // r4

  v1 = *(_DWORD *)(v0 + 8);
  if ( v1 )
  {
    if ( *(_DWORD *)(v1 + 64) )
    {
      if ( MiReferenceSubsection(v1) )
        JUMPOUT(0x4C170C);
    }
    JUMPOUT(0x4C17A4);
  }
  JUMPOUT(0x4C17AA);
}
