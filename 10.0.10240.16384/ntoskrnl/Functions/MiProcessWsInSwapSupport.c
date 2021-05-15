// MiProcessWsInSwapSupport 
 
int __fastcall MiProcessWsInSwapSupport(int result, int a2)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r5
  unsigned int v4; // r6
  int v5; // r3
  unsigned int v6; // r1
  int v7; // r3
  int v8; // r7
  int _18; // [sp+18h] [bp+8h]

  _18 = result;
  v2 = *(_DWORD **)result;
  v3 = *(_DWORD **)result;
  v4 = *(_DWORD *)result + 8 * *(_DWORD *)(result + 8);
  v5 = 0;
  if ( *(_DWORD *)result < v4 )
  {
    do
    {
      v6 = v2[1];
      if ( v5 + (v6 >> 12) >= 0x1000 )
      {
        v7 = 4096 - v5;
        v8 = (v6 >> 12) - v7;
        v7 <<= 12;
        v2[1] = v7;
        result = MiProcessWsInSwapRanges(v3, (int)v2, a2, v7);
        if ( v8 )
        {
          v3 = v2;
          *v2 += v2[1];
          v2[1] = v8 << 12;
          v2 -= 2;
        }
        else
        {
          v3 = v2 + 2;
        }
        v5 = 0;
      }
      else
      {
        v5 += v6 >> 12;
      }
      v2 += 2;
    }
    while ( (unsigned int)v2 < v4 );
    if ( v5 )
      result = MiProcessWsInSwapRanges(v3, (int)(v2 - 2), a2, v5);
  }
  return result;
}
