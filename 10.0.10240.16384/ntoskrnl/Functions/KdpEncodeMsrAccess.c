// KdpEncodeMsrAccess 
 
int __fastcall KdpEncodeMsrAccess(int a1, unsigned int a2, int a3)
{
  int v4; // r0
  unsigned int v5; // r3
  __int16 v6; // r3

  v4 = *(_DWORD *)a1 & 0xFFFFFFF0 | (a2 >> 8) & 0xF;
  *(_DWORD *)a1 = v4;
  *(_DWORD *)a1 = v4 & 0xFFFFFF0F | (a2 >> 7) & 0xE0 | (16 * (a3 != 0));
  *(_BYTE *)(a1 + 1) = -18;
  v5 = *(_DWORD *)a1 & 0xF010FFFF | ((a2 & 0xF0000 | (16 * (a2 & 0xF0 | ((a2 & 7) << 9) | 0x100))) << 8);
  *(_DWORD *)a1 = v5;
  if ( a3 )
  {
    *(_DWORD *)a1 = v5 & 0xFFFFFFF | 0x10000000;
    v6 = 24577;
  }
  else
  {
    *(_DWORD *)a1 = v5 & 0xFFFFFFF;
    v6 = -16640;
  }
  *(_WORD *)(a1 + 4) = v6;
  *(_BYTE *)(a1 + 6) = 1;
  *(_WORD *)(a1 + 6) = 8193;
  *(_WORD *)(a1 + 8) = 18288;
  KiSweepIcacheTarget(v4);
  return a1 + 1;
}
