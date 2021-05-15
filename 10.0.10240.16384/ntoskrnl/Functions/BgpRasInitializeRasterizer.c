// BgpRasInitializeRasterizer 
 
int __fastcall BgpRasInitializeRasterizer(int a1)
{
  int v2; // r6
  _DWORD *v3; // r5
  int result; // r0
  __int16 v5; // r2
  unsigned int v6; // r3
  int v7; // [sp+8h] [bp-50h] BYREF
  char v8[4]; // [sp+Ch] [bp-4Ch] BYREF
  char v9[4]; // [sp+10h] [bp-48h] BYREF
  unsigned __int16 v10; // [sp+14h] [bp-44h]
  unsigned __int16 v11; // [sp+16h] [bp-42h]
  unsigned __int16 v12; // [sp+1Ah] [bp-3Eh]
  unsigned __int16 v13; // [sp+20h] [bp-38h]
  unsigned __int16 v14; // [sp+22h] [bp-36h]
  unsigned __int16 v15; // [sp+32h] [bp-26h]
  unsigned __int16 v16; // [sp+42h] [bp-16h]

  v2 = *(_DWORD *)(a1 + 24);
  v3 = *(_DWORD **)(*(_DWORD *)(a1 + 8) + 8);
  result = FopGetTableOffsetAndSize(v3, v2, 1751474532, a1 + 44, &v7);
  if ( result >= 0 )
  {
    result = FopGetTableOffsetAndSize(v3, v2, 1735162214, a1 + 40, &v7);
    if ( result >= 0 )
    {
      result = FopGetTableOffsetAndSize(v3, v2, 1819239265, a1 + 52, &v7);
      if ( result >= 0 )
      {
        result = FopGetTableOffsetAndSize(v3, v2, 1752003704, a1 + 48, &v7);
        if ( result >= 0 )
        {
          result = FioFwReadBytesAtOffset(v3, *(_DWORD *)(a1 + 44), 0x36u, (int)v9);
          if ( result >= 0 )
          {
            *(_WORD *)(a1 + 56) = __rev16(v16);
            *(_WORD *)(a1 + 88) = __rev16(v14);
            result = FopGetTableOffsetAndSize(v3, v2, 1751672161, &v7, v8);
            if ( result >= 0 )
            {
              result = FioFwReadBytesAtOffset(v3, v7, 0x24u, (int)v9);
              if ( result >= 0 )
              {
                *(_WORD *)(a1 + 68) = __rev16(v15);
                *(_WORD *)(a1 + 58) = __rev16(v12);
                v5 = __rev16(v10);
                v6 = v11;
                *(_WORD *)(a1 + 62) = v5;
                *(_WORD *)(a1 + 66) = v5;
                *(_WORD *)(a1 + 64) = __rev16(v6);
                *(_WORD *)(a1 + 60) = __rev16(v13);
                *(_DWORD *)(a1 + 76) = 96;
                if ( !RasterizerInitialized )
                {
                  RaspBitmapCache = (int)&RaspBitmapCache;
                  *(_DWORD *)algn_618F84 = &RaspBitmapCache;
                  dword_618F9C = 100;
                  dword_618FA0 = 0;
                  RasterizerInitialized = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
