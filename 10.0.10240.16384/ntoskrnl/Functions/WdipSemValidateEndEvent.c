// WdipSemValidateEndEvent 
 
int __fastcall WdipSemValidateEndEvent(unsigned int a1, int a2, int a3)
{
  int v4; // r4
  unsigned int v7; // r6
  unsigned int v8; // r5
  unsigned int v9; // r8

  v4 = a3;
  if ( !a1 || !a3 )
    return -1073741811;
  v7 = *(_DWORD *)(a3 + 52);
  v8 = 0;
  if ( !v7 )
    return -1073741823;
  while ( 1 )
  {
    v9 = *(_DWORD *)(v4 + 552);
    if ( !memcmp(a1, v9, 16) && a2 == *(unsigned __int16 *)(v9 + 16) )
      break;
    ++v8;
    v4 += 4;
    if ( v8 >= v7 )
      return -1073741823;
  }
  return 0;
}
