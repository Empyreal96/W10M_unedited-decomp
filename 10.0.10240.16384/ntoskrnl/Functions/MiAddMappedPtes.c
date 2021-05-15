// MiAddMappedPtes 
 
int __fastcall MiAddMappedPtes(unsigned int *a1, unsigned int a2, _DWORD *a3, unsigned __int64 *a4, int a5)
{
  unsigned int *v5; // r5
  unsigned int v6; // r8
  unsigned int *v8; // r7
  int result; // r0
  _DWORD *v10; // r0
  int v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r6
  unsigned int v16; // r1
  unsigned int i; // r7
  unsigned int v18; // r1
  __int64 v20[5]; // [sp+10h] [bp-28h] BYREF

  v5 = a1;
  v6 = (unsigned int)&a1[a2];
  v8 = MiOffsetToProtos(a3, *a4, (int)v20);
  if ( !v8 )
    return sub_7D4FB8();
  v10 = a3;
  v11 = v20[0];
  if ( (a3[7] & 0x420) == 0 )
  {
    result = MiAddViewsForSection((int)v8, v20[0] + a2, 0);
    if ( result < 0 )
      return result;
    v10 = a3;
  }
  if ( (*((_WORD *)v8 + 9) & 2) != 0 && (v10[7] & 0x4000000) != 0 )
    goto LABEL_28;
  if ( (v10[7] & 0x20) != 0 )
  {
    v12 = v8[3];
    if ( v12 )
      goto LABEL_24;
  }
  v13 = v8[1];
  v14 = v13 + 4 * v11;
  v15 = v13 + 4 * v8[7];
  while ( (unsigned int)v5 < v6 )
  {
    if ( v14 >= v15 )
    {
      v8 = (unsigned int *)v8[2];
      if ( !v8 )
      {
        for ( i = v10[21] + 4 * *(_DWORD *)(*v10 + 4); v14 < i; v14 += 4 )
        {
          v18 = v14 & 0x1FC | (4 * (v14 & 0xFFFFFE00 | 0x100));
          if ( (unsigned int)(v5 + 0x10000000) > 0x3FFFFF )
          {
            *v5 = v18;
          }
          else
          {
            __dmb(0xBu);
            *v5 = v18;
            if ( (unsigned int)(v5 + 267649024) <= 0xFFF )
              MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v18, (__int16)v5);
          }
          if ( (unsigned int)++v5 >= v6 )
            break;
        }
        return 0;
      }
      if ( (*((_WORD *)v8 + 9) & 2) != 0 && (v10[7] & 0x4000000) != 0 )
      {
LABEL_28:
        v14 = *(_DWORD *)(MiGetSharedProtos((int)v10, a5, (int)v8) + 16);
        v10 = a3;
      }
      else if ( (v10[7] & 0x20) != 0 && (v12 = v8[3]) != 0 )
      {
LABEL_24:
        v14 = *(_DWORD *)(v12 + 16);
      }
      else
      {
        v14 = v8[1];
      }
      v15 = v14 + 4 * v8[7];
    }
    v16 = v14 & 0x1FC | (4 * (v14 & 0xFFFFFE00 | 0x100));
    if ( (unsigned int)v5 < 0xC0000000 || (unsigned int)v5 > 0xC03FFFFF )
    {
      *v5 = v16;
    }
    else
    {
      __dmb(0xBu);
      *v5 = v16;
      if ( (unsigned int)(v5 + 267649024) <= 0xFFF )
      {
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v16, (__int16)v5);
        v10 = a3;
      }
    }
    ++v5;
    v14 += 4;
  }
  return 0;
}
