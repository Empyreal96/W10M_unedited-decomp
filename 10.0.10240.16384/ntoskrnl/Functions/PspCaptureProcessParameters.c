// PspCaptureProcessParameters 
 
int __fastcall PspCaptureProcessParameters(char a1, int a2, int a3)
{
  int v4; // r3
  int result; // r0
  char v6; // r2
  char v7; // r3

  v4 = *(unsigned __int8 *)(a3 + 8);
  if ( a1 )
  {
    result = PspCaptureUserProcessParameters((unsigned int **)(a3 + 120), a2, (v4 & 8) != 0, v4);
    if ( result < 0 )
      return result;
    v6 = *(_BYTE *)(a3 + 8);
    if ( (v6 & 8) != 0 )
      *(_BYTE *)(a3 + 9) &= 0xF9u;
    v7 = v6 | 4;
  }
  else
  {
    v7 = v4 & 0xFB;
    *(_DWORD *)(a3 + 120) = a2;
  }
  result = 0;
  *(_BYTE *)(a3 + 8) = v7;
  return result;
}
