// PopWakeSourceSize 
 
int __fastcall PopWakeSourceSize(int a1)
{
  int v2; // r3
  int result; // r0
  _DWORD *v4; // r3

  v2 = *(_DWORD *)(a1 + 8);
  result = 0;
  if ( !v2 )
    return *(unsigned __int16 *)(a1 + 12) + 10;
  if ( v2 == 1 )
    return 12;
  if ( (unsigned int)(v2 - 2) <= 1 )
  {
    v4 = *(_DWORD **)(a1 + 12);
    if ( v4 )
      result = *v4 + 8;
    else
      result = 32;
  }
  return result;
}
