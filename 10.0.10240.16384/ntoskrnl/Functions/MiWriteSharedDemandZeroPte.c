// MiWriteSharedDemandZeroPte 
 
int __fastcall MiWriteSharedDemandZeroPte(int a1, int *a2, unsigned int *a3, _DWORD *a4)
{
  int v7; // r2
  int v8; // r2
  int result; // r0
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r0

  v7 = a2[3];
  if ( v7 )
  {
    ++a2[2];
    a2[3] = v7 + 1;
    ++*a4;
  }
  else
  {
    v8 = ((unsigned int)a2[2] >> 22) & 0x3E0;
    result = (int)(a2 + 0x10000000);
    if ( (unsigned int)(a2 + 0x10000000) > 0x3FFFFF )
    {
      *a2 = v8;
    }
    else
    {
      __dmb(0xBu);
      *a2 = v8;
      if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
      {
        v10 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        result = MiArmWriteConvertedHardwarePde(v10, (_DWORD *)(v10 + 4 * ((unsigned __int16)a2 & 0xFFF)), v8);
      }
    }
    a2[2] = a2[2] & 0xF8000000 | 1;
    a2[3] = 1;
    ++a4[1];
  }
  v11 = (unsigned __int16)a2 & 0x1FC | (4 * ((unsigned int)a2 & 0xFFFFFE00 | 0x180));
  if ( (unsigned int)(a3 + 0x10000000) > 0x3FFFFF )
  {
    *a3 = v11;
  }
  else
  {
    __dmb(0xBu);
    *a3 = v11;
    if ( (unsigned int)(a3 + 267649024) <= 0xFFF )
    {
      v12 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v12, (_DWORD *)(v12 + 4 * ((unsigned __int16)a3 & 0xFFF)), v11);
    }
  }
  return result;
}
