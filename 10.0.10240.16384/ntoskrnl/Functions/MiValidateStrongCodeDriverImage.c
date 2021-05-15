// MiValidateStrongCodeDriverImage 
 
int __fastcall MiValidateStrongCodeDriverImage(int a1)
{
  int v1; // r2
  int v2; // r1
  int v3; // r4
  int result; // r0

  v1 = *(unsigned __int16 *)(a1 + 6);
  v2 = *(unsigned __int16 *)(a1 + 20) + a1 + 24;
  if ( !*(_WORD *)(a1 + 6) )
    return 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(v2 + 36);
    if ( (v3 & 0xA0000000) == -1610612736 && (v3 & 0x2000000) == 0 )
      break;
    --v1;
    v2 += 40;
    if ( !v1 )
      return 0;
  }
  result = -1073741701;
  dword_632EE4 = 194;
  return result;
}
