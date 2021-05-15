// MiImagePageOk 
 
int __fastcall MiImagePageOk(unsigned int a1, int a2)
{
  int v2; // r3
  _WORD *v3; // r6
  int v4; // r5
  int result; // r0
  int v6; // r4
  _DWORD *v7; // r0
  int v8; // r2

  if ( a1 >= dword_63389C && (MiFlags & 0x30000) == 0 )
    goto LABEL_9;
  v2 = *(_DWORD *)(a2 + 20);
  if ( (v2 & 0x8000000) == 0 )
    goto LABEL_9;
  if ( (*(_DWORD *)(a2 + 8) & 0x400) == 0 )
    goto LABEL_9;
  if ( (v2 & 0x7000000) == 50331648 )
    goto LABEL_9;
  v3 = (_WORD *)(*(_DWORD *)(a2 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a2 + 8) & 0x3FC)));
  v4 = *(_DWORD *)v3;
  if ( (*(_DWORD *)(*(_DWORD *)v3 + 28) & 0x20) == 0 )
    goto LABEL_9;
  if ( (BYTE2(MiFlags) & 3u) > 1 )
    return sub_543F10();
  if ( (v6 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 4)) == 0
    || (v6 & 0xFFFFFFF8) == 8
    || (*(_DWORD *)(*(_DWORD *)(v4 + 56) + 4) & 3) == 2
    || ((MiFlags & 0x100000) == 0 || (*(_DWORD *)(v4 + 52) & 0xC000000) == 0)
    && (v7 = MiLocateAddress(a1)) != 0
    && (v8 = v7[7], (v8 & 7) == 2)
    && ((v8 & 0xF8) == 8 || (v7[10] & 0x10000000) != 0 && (v6 & 4) == 0 || (MiFlags & 0x400) != 0 && (v3[9] & 2) != 0) )
  {
LABEL_9:
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
