// MiUnlockDriverCode 
 
int __fastcall MiUnlockDriverCode(int result)
{
  unsigned int v1; // r4
  int v2; // r9
  int v3; // r1
  int v4; // r1
  unsigned int v5; // r6
  int v6; // r5
  int v7; // r3

  v1 = *(_DWORD *)(result + 24);
  v2 = result;
  if ( (*(_DWORD *)(((v1 >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 )
  {
    if ( v1 < dword_63389C
      || (result = MiGetSystemRegionIndex(*(_DWORD *)(result + 24)), *(_BYTE *)(result + v3 + 9692) != 1)
      && (result = MiGetSystemRegionIndex(v1), *(_BYTE *)(result + v4 + 9692) != 11) )
    {
      result = RtlImageNtHeader(v1);
      v5 = 0;
      v6 = *(unsigned __int16 *)(result + 20) + result + 24;
      if ( *(_WORD *)(result + 6) )
      {
        while ( 1 )
        {
          v7 = *(_DWORD *)(*(_DWORD *)(v2 + 128) + 4 * v5);
          __dmb(0xBu);
          if ( v7 )
            break;
          ++v5;
          v6 += 40;
          if ( v5 >= *(unsigned __int16 *)(result + 6) )
            return result;
        }
        result = sub_7CE9D8();
      }
    }
  }
  return result;
}
