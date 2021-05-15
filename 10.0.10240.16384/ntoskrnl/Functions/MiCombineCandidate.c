// MiCombineCandidate 
 
int __fastcall MiCombineCandidate(__int16 **a1, int a2)
{
  unsigned int v3; // r5
  int v4; // r1
  unsigned int v5; // r0
  unsigned int v6; // r7
  unsigned int v7; // r1
  int result; // r0
  unsigned int v9; // r2
  int v10; // r3

  v3 = *(_DWORD *)(a2 + 4);
  if ( MiSystemPartition != *a1 )
    return 0;
  v4 = *(_DWORD *)(a2 + 20);
  if ( (v4 & 0x8000000) != 0 )
    return 0;
  if ( !*(_DWORD *)a2 )
    return 0;
  v5 = *(unsigned __int8 *)(a2 + 19);
  if ( (v5 & 8) != 0
    || v3 + 0x40000000 > 0x3FFFFF
    || (*(_DWORD *)(a2 + 12) & 0x40000000) != 0
    || (v4 & 0x7000000) == 0x4000000
    || (v3 | 0x80000000) <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000
    && (v3 | 0x80000000) >= 0xC0000000
    && ((v5 >> 5) & 1) != 0 )
  {
    return 0;
  }
  v6 = *(_DWORD *)(a2 + 8);
  if ( !MiValidCombineProtection((v6 >> 5) & 0x1F) || MiGetPagePrivilege() )
    return 0;
  v7 = v3 << 10;
  if ( v3 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 )
  {
    result = 1;
    goto LABEL_15;
  }
  if ( v7 < dword_63389C )
    return 0;
  v10 = *((unsigned __int8 *)&MiState[2423]
        + ((int)(((v7 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  if ( v10 == 6 )
  {
LABEL_32:
    result = 2;
    goto LABEL_15;
  }
  if ( v10 != 1 )
  {
    if ( v10 == 14 )
      goto LABEL_32;
    if ( v10 != 11 )
      return 0;
  }
  if ( v7 >= MmSessionSpace && v7 <= dword_633798 )
    return 0;
  result = 3;
LABEL_15:
  v9 = *(_BYTE *)(a2 + 18) & 7;
  if ( v9 > 3 || v9 < 2 || *(_WORD *)(a2 + 16) )
  {
    if ( v9 == 6
      && (*(_DWORD *)(a2 + 20) & 0xFFFFF) != 1048573
      && *(_WORD *)(a2 + 16) == 1
      && (*(_DWORD *)(a2 + 12) & 0x3FFFFFFF) == 1
      && (result != 1 || (v6 & 2) != 0 || (v6 & 0xC18) != 0 || (v6 & 0xFFFFE000) != 0x2000) )
    {
      return result;
    }
    return 0;
  }
  if ( result == 1 && (v6 & 2) == 0 && (v6 & 0xC18) == 0 && (v6 & 0xFFFFE000) == 0x2000 )
    return 0;
  return result;
}
