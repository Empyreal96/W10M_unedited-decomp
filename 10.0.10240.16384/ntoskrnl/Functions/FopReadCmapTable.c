// FopReadCmapTable 
 
int __fastcall FopReadCmapTable(_DWORD *a1, int a2, int *a3)
{
  int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r0
  _DWORD *v9; // r0
  int v10; // r4
  unsigned int v11; // r8
  int v12; // r9
  unsigned __int16 *v13; // r6
  int v16; // [sp+8h] [bp-30h] BYREF

  v5 = FioFwReadBytesAtOffset(a1, a2, 4u, (int)&v16);
  if ( v5 >= 0 )
  {
    v6 = __rev16((unsigned __int16)v16);
    LOWORD(v16) = v6;
    v7 = __rev16(HIWORD(v16));
    HIWORD(v16) = v7;
    if ( v6 )
    {
      v5 = -1073741701;
    }
    else
    {
      v8 = 12;
      if ( v7 )
      {
        v8 = 8 * (v7 - 1) + 12;
        if ( v8 < 0xC )
          return -1073741675;
        v5 = 0;
      }
      v9 = (_DWORD *)BgpFwAllocateMemory(v8);
      v10 = (int)v9;
      if ( v9 )
      {
        v11 = 0;
        v12 = a2 + 4;
        *v9 = v16;
        if ( v7 )
        {
          v13 = (unsigned __int16 *)(v9 + 1);
          do
          {
            v5 = FioFwReadBytesAtOffset(a1, v12, 8u, (int)v13);
            if ( v5 < 0 )
              goto LABEL_16;
            v5 = 0;
            *v13 = __rev16(*v13);
            v13[1] = __rev16(v13[1]);
            *((_DWORD *)v13 + 1) = bswap32(*((_DWORD *)v13 + 1));
            ++v11;
            v13 += 4;
            v12 += 8;
          }
          while ( v11 < v7 );
        }
        *a3 = v10;
        if ( v5 < 0 )
        {
LABEL_16:
          BgpFwFreeMemory(v10);
          return v5;
        }
      }
      else
      {
        v5 = -1073741801;
      }
    }
  }
  return v5;
}
