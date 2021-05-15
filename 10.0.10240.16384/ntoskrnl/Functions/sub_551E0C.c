// sub_551E0C 
 
void sub_551E0C()
{
  int v0; // r7

  while ( CcUnmapInactiveViews(64, 1, 0) )
  {
    if ( *(_DWORD *)(v0 + 10384) > 0x8000000u )
      JUMPOUT(0x4F0390);
  }
  JUMPOUT(0x4F0354);
}
