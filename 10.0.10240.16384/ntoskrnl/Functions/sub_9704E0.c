// sub_9704E0 
 
void __fastcall sub_9704E0(int a1, int a2)
{
  int *v2; // r4
  int v3; // r5
  unsigned int v4; // r8
  int v5; // r9
  unsigned int v6; // r10
  int v7; // r3
  int v8; // r7
  int v9; // r0

  if ( (unsigned int)v2 <= v4 )
  {
    v7 = *v2;
    v8 = 0;
    __dmb(0xBu);
    *v2 = v3;
    if ( (v7 & a2) == 0 )
      v8 = 1;
    if ( (unsigned int)v2 + v5 <= v6 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v9, (_DWORD *)(v9 + 4 * ((unsigned __int16)v2 & 0xFFF)), v3);
    }
    if ( v8 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    JUMPOUT(0x9642DC);
  }
  JUMPOUT(0x9642DA);
}
