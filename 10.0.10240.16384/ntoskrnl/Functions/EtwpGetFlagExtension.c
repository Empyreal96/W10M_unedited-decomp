// EtwpGetFlagExtension 
 
unsigned __int16 *__fastcall EtwpGetFlagExtension(int a1, int a2)
{
  unsigned __int16 *result; // r0
  unsigned int v3; // r2
  int v4; // r3
  int v5; // [sp+0h] [bp-8h]

  v5 = *(_DWORD *)(a1 + 72);
  if ( v5 >= 0 )
    return 0;
  LOWORD(v3) = 0;
  v4 = (unsigned __int16)v5 + a1;
  result = (unsigned __int16 *)(v4 + 4);
  if ( !*(_WORD *)(v4 + 2) )
    return 0;
  while ( result[1] != a2 )
  {
    result += 2 * *result;
    v3 = (unsigned __int16)(v3 + 1);
    if ( v3 >= *(unsigned __int16 *)(v4 + 2) )
      return 0;
  }
  return result;
}
