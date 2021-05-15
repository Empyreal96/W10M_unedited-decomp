// ObpReleaseHandleInfo 
 
int __fastcall ObpReleaseHandleInfo(int result, int a2, int *a3)
{
  int v4; // r4
  int v5; // r2
  int v6; // r2

  if ( (*(_BYTE *)(result + 14) & 4) != 0 )
    v4 = result - ObpInfoMaskToOffset[*(_BYTE *)(result + 14) & 7];
  else
    v4 = 0;
  if ( (*(_BYTE *)(result + 15) & 0x40) != 0 )
  {
LABEL_4:
    v5 = *(_DWORD *)(v4 + 4);
    *a3 = v5 & 0xFFFFFF;
    *(_DWORD *)(v4 + 4) = v5 & 0xFF000000 | (v5 - 1) & 0xFFFFFF;
    goto LABEL_5;
  }
  v6 = **(_DWORD **)v4;
  v4 = *(_DWORD *)v4 + 4;
  if ( v6 )
  {
    while ( (*(_DWORD *)(v4 + 4) & 0xFFFFFF) == 0 || *(_DWORD *)v4 != a2 )
    {
      v4 += 8;
      if ( !--v6 )
        goto LABEL_5;
    }
    goto LABEL_4;
  }
LABEL_5:
  if ( !*(_BYTE *)(v4 + 7) && (*(_DWORD *)(v4 + 4) & 0xFFFFFF) == 0 )
    *(_DWORD *)v4 = 0;
  return result;
}
