// MiCloneNoChange 
 
int __fastcall MiCloneNoChange(int a1, int a2)
{
  _DWORD *i; // r2
  int v3; // r3
  int v4; // r0

  for ( i = *(_DWORD **)(a1 + 36); ; i = (_DWORD *)*i )
  {
    if ( !i )
      return 0;
    if ( i[1] == 2 )
    {
      v3 = i[2];
      v4 = 0;
      if ( (v3 & 4) != 0 )
        v4 = 0x80000000;
      if ( (v3 & 8) == 0 )
        goto LABEL_9;
      if ( v4 || (v3 & 3) == 0 )
        break;
    }
LABEL_10:
    ;
  }
  v4 |= 1u;
LABEL_9:
  if ( !v4 )
    goto LABEL_10;
  if ( MiAddSecureEntry(a2, *(_DWORD *)(a2 + 12) << 12, (*(_DWORD *)(a2 + 16) << 12) | 0xFFF, v4, (i[2] & 0x20) != 0) )
    return 0;
  return -1073741670;
}
