// sub_54F734 
 
void sub_54F734()
{
  unsigned int v0; // r6
  int v1; // r7
  unsigned int v2; // r8
  _DWORD *v3; // r5
  int v4; // r0

  v3 = (_DWORD *)(((v0 >> 10) & 0x3FFFFC) - v1);
  if ( ((v0 >> 10) & 0x3FFFFC) > v2 )
  {
    *v3 = 0;
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
    if ( (unsigned int)(v3 + 267649024) <= 0xFFF )
    {
      v4 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v4, (_DWORD *)(v4 + 4 * ((unsigned __int16)v3 & 0xFFF)), 0);
    }
  }
  KeFlushSingleTb(v0, 1);
  JUMPOUT(0x4EA488);
}
