// MiInitializeMdlPfn 
 
int __fastcall MiInitializeMdlPfn(int result, int a2)
{
  unsigned int v2; // r2
  int v3; // r3
  unsigned int v4; // r3

  if ( (a2 & 0x100) != 0 )
    return sub_51373C();
  v2 = *(_DWORD *)(result + 12) & 0xC0000000 | 1;
  *(_WORD *)(result + 16) = 2;
  *(_DWORD *)(result + 12) = v2;
  if ( (a2 & 0x80000200) != 0 )
    v3 = 0;
  else
    v3 = -1073741824;
  *(_DWORD *)(result + 4) = v3;
  if ( a2 < 0 )
    v4 = v2 & 0xBFFFFFFF;
  else
    v4 = v2 | 0x40000000;
  *(_DWORD *)(result + 12) = v4;
  if ( (a2 & 0x200) != 0 )
    *(_DWORD *)(result + 20) = *(_DWORD *)(result + 20) & 0xF8FFFFFF | 0x3000000;
  *(_BYTE *)(result + 18) = *(_BYTE *)(result + 18) & 0xF8 | 6;
  if ( (a2 & 0x80000000) != 0 )
    *(_DWORD *)(result + 20) = *(_DWORD *)(result + 20) & 0xF8FFFFFF | 0x1000000;
  return result;
}
