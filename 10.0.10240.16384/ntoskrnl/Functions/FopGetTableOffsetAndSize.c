// FopGetTableOffsetAndSize 
 
int __fastcall FopGetTableOffsetAndSize(_DWORD *a1, int a2, int a3, unsigned int *a4, unsigned int *a5)
{
  int result; // r0
  unsigned int v10; // r5
  unsigned int v11; // r4
  int v12; // r6
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // [sp+0h] [bp-30h] BYREF
  unsigned int v16; // [sp+4h] [bp-2Ch]
  unsigned int v17; // [sp+8h] [bp-28h]
  unsigned int v18; // [sp+Ch] [bp-24h]

  result = FioFwReadBytesAtOffset(a1, a2, 0xCu, (int)&v15);
  if ( result < 0 )
  {
    v10 = (unsigned __int16)v16;
  }
  else
  {
    if ( bswap32(v15) != 0x10000 )
      return -1073741637;
    result = 0;
    v10 = __rev16((unsigned __int16)v16);
  }
  if ( result >= 0 )
  {
    v11 = 0;
    v12 = a2 + 12;
    if ( v10 )
    {
      while ( 1 )
      {
        if ( FioFwReadBytesAtOffset(a1, v12, 0x10u, (int)&v15) < 0 )
          return sub_975FA0();
        result = 0;
        v15 = bswap32(v15);
        v13 = bswap32(v17);
        v17 = v13;
        v14 = bswap32(v18);
        v18 = v14;
        v16 = bswap32(v16);
        if ( v15 == a3 )
          break;
        ++v11;
        v12 += 16;
        if ( v11 >= v10 )
          goto LABEL_10;
      }
      *a4 = v13;
      *a5 = v14;
    }
    else
    {
LABEL_10:
      result = -1073741275;
    }
  }
  return result;
}
