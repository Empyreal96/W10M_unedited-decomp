// sub_511DA8 
 
void __fastcall sub_511DA8(int a1, char a2, int a3)
{
  _DWORD *v3; // lr
  int v4; // r4
  int v5; // r0

  v4 = 0;
  __dmb(0xBu);
  *v3 = a3;
  if ( (a2 & 2) == 0 && (a3 & 2) != 0 )
    v4 = 1;
  if ( (unsigned int)(v3 + 267649024) <= 0xFFF )
  {
    v5 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v5, (_DWORD *)(v5 + 4 * ((unsigned __int16)v3 & 0xFFF)), a3);
  }
  if ( v4 == 1 )
  {
    __dsb(0xFu);
    __isb(0xFu);
  }
  JUMPOUT(0x42B228);
}
