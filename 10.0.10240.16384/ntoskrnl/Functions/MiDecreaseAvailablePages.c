// MiDecreaseAvailablePages 
 
int __fastcall MiDecreaseAvailablePages(int result, int a2)
{
  int v2; // r6
  unsigned int *v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r4
  unsigned int v8; // r4

  v2 = result;
  v3 = (unsigned int *)(result + 3712);
  if ( a2 == 1 )
  {
    do
    {
      v7 = __ldrex(v3);
      v8 = v7 - 1;
    }
    while ( __strex(v8, v3) );
    if ( v8 == *(_DWORD *)(result + 2988) || v8 == *(_DWORD *)(result + 2992) )
      result = MiUpdateAvailableEvents(result);
    if ( v8 <= 0x400 )
      result = sub_537984();
  }
  else
  {
    result = -a2;
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 - a2, v3) );
    v5 = *(_DWORD *)(v2 + 2992);
    if ( v4 > v5 && v4 - a2 <= v5 || (v6 = *(_DWORD *)(v2 + 2988), v4 - a2 <= v6) && v4 > v6 )
      result = MiUpdateAvailableEvents(v2);
  }
  return result;
}
