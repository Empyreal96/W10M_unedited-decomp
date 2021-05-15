// EtwpPrepareHeader 
 
int __fastcall EtwpPrepareHeader(int a1, int a2, int a3)
{
  int v4; // r3
  int result; // r0
  int v6; // r1
  int v7; // r2

  v4 = *(_DWORD *)(a2 + 4);
  if ( !v4 )
    return sub_809BEC();
  *(_DWORD *)(a2 + 48) = v4;
  if ( a3 != 1 && v4 == 72 )
    goto LABEL_10;
  *(_WORD *)(a2 + 52) = a3 | 0x20;
  if ( *(_DWORD *)(a1 + 592) )
  {
    v6 = *(_DWORD *)(a2 + 48);
    v7 = *(_DWORD *)(a1 + 4) - v6;
    if ( v7 > 0 )
      memset((_BYTE *)(v6 + a2), 255, v7);
  }
  if ( *(_DWORD *)(a2 + 48) == 72 )
LABEL_10:
    result = -2147483614;
  else
    result = 0;
  return result;
}
