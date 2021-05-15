// AlpcpExposeContextAttribute 
 
int __fastcall AlpcpExposeContextAttribute(int result, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r3
  int v6; // r3

  if ( a2[8] == result || a2[9] == result )
    *a3 = a2[17];
  else
    *a3 = a2[16];
  if ( a2[8] == result || a2[9] == result )
    v5 = a2[10];
  else
    v5 = a2[6];
  a3[2] = v5;
  if ( (*(_DWORD *)(result + 244) & 6) == 4 )
    v6 = a2[14];
  else
    v6 = a2[15];
  a3[1] = v6;
  a3[3] = a2[34];
  a3[4] = a2[35];
  if ( *a3 )
    *a4 |= 0x20000000u;
  return result;
}
