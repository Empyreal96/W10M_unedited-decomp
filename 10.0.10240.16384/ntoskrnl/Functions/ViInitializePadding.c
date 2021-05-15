// ViInitializePadding 
 
_BYTE *__fastcall ViInitializePadding(_BYTE *a1, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // r4

  v5 = 0;
  if ( !a4 )
    return memset(a1, 15, a2);
  memset(a1, 15, a3 - (_DWORD)a1);
  memset((_BYTE *)(a3 + a4), 15, (int)&a1[-a3 - a4 + a2]);
  if ( (unsigned int)(a1 + 8) <= a3 )
    v5 = 1;
  if ( a3 + a4 - (unsigned int)a1 + 8 <= a2 )
    v5 |= 2u;
  return (_BYTE *)ViTagBuffer(a3, a4, v5);
}
