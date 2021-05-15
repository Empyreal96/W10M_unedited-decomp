// MmBuildMdlForNonPagedPool 
 
unsigned int __fastcall MmBuildMdlForNonPagedPool(int a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r1
  int v4; // r9
  unsigned int result; // r0
  int v6; // r3
  int v7; // lr
  unsigned int v8; // r2
  int v9; // r8
  unsigned int v10; // r1
  unsigned int v11; // [sp+4h] [bp-24h]

  v2 = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 8) = 0;
  v3 = *(_DWORD *)(a1 + 24) + v2;
  v4 = a1 + 28;
  result = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
  v6 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 12) = v3;
  v7 = (v2 >> 20) & 0xFFC;
  v8 = *(_DWORD *)(v7 - 1070596096);
  v11 = result + 4 * (((v3 & 0xFFF) + v6 + 4095) >> 12);
  v9 = 0;
  if ( (v8 & 0x400) != 0 )
  {
    v10 = ((v2 >> 12) & 0x3FF) + (v8 >> 12);
  }
  else
  {
    v10 = *(_DWORD *)result >> 12;
    if ( v2 >= dword_63389C
      && *((_BYTE *)&MiState[2423] + ((int)(v7 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 5 )
    {
      v9 = 1;
    }
  }
  while ( 1 )
  {
    if ( v9 == 1 )
    {
      result = MiSetNonPagedPoolNoSteal(result);
      v10 = *(_DWORD *)result >> 12;
    }
    *(_DWORD *)(v4 - ((v2 >> 10) & 0x3FFFFC) + 0x40000000 + result) = v10;
    if ( (*(_WORD *)(a1 + 6) & 0x800) == 0
      && (v10 > dword_633850 || dword_634C9C && ((*(_DWORD *)(dword_634C9C + 4 * (v10 >> 5)) >> (v10 & 0x1F)) & 1) == 0) )
    {
      *(_WORD *)(a1 + 6) |= 0x800u;
    }
    result += 4;
    if ( result >= v11 )
    {
      *(_WORD *)(a1 + 6) |= 4u;
      return result;
    }
    if ( (result & 0xFFF) == 0 )
      break;
    if ( (*(_DWORD *)(v7 - 1070596096) & 0x400) != 0 )
      ++v10;
    else
      v10 = *(_DWORD *)result >> 12;
  }
  return sub_51AA08();
}
