// sub_5112C4 
 
void sub_5112C4()
{
  unsigned int v0; // r4
  _DWORD *v1; // r5
  int v2; // r6
  int v3; // r7

  *(_DWORD *)(v2 + 4 * v3) = *v1;
  if ( v0 < 4 )
  {
    if ( v0 == 2 )
    {
      SmKmFreeMdlForLock(v1[1]);
    }
    else if ( v0 == 3 )
    {
      SmAcquireReleaseCharges(*(unsigned __int16 *)(v2 + 54) << 12, 1, 1);
    }
    else
    {
      ExFreePoolWithTag(v1[1], 0);
    }
  }
  else
  {
    MmFreeMappingAddress(v1[1], 1834118515);
  }
  ExFreePoolWithTag(v1, 0);
  JUMPOUT(0x429E66);
}
