// sub_510620 
 
void sub_510620()
{
  _DWORD *v0; // r5
  int v1; // r0

  if ( (unsigned int)(v0 + 0x10000000) > 0x3FFFFF )
  {
    *v0 = 0;
  }
  else
  {
    __dmb(0xBu);
    *v0 = 0;
    if ( (unsigned int)(v0 + 267649024) <= 0xFFF )
    {
      v1 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v1, (_DWORD *)(v1 + 4 * ((unsigned __int16)v0 & 0xFFF)), 0);
      JUMPOUT(0x427A04);
    }
  }
  JUMPOUT(0x427A06);
}
