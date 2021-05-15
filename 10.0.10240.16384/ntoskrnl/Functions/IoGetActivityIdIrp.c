// IoGetActivityIdIrp 
 
int __fastcall IoGetActivityIdIrp(int a1, _DWORD *a2)
{
  int v2; // r2
  int result; // r0
  _DWORD *v5; // r2

  v2 = *(_DWORD *)(a1 + 104);
  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
    return -1073741275;
  if ( !v2 || (*(_WORD *)(v2 + 2) & 1) == 0 )
    return -1073741275;
  v5 = *(_DWORD **)(a1 + 104);
  result = 0;
  *a2 = v5[3];
  a2[1] = v5[4];
  a2[2] = v5[5];
  a2[3] = v5[6];
  return result;
}
