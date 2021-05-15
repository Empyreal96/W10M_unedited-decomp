// KiSelectThreadFromScbQueue 
 
int __fastcall KiSelectThreadFromScbQueue(int a1, int a2, char a3, int a4, _BYTE *a5)
{
  int v5; // r4
  int v7; // r1

  v5 = *(_DWORD *)(a1 + 4);
  if ( v5 )
  {
    v7 = v5 - 80;
    if ( *(unsigned __int16 *)(v5 + 14) >= (unsigned int)(1 << a3) )
      return KiSelectThreadFromSchedulingGroup(a2, v7, a3);
    if ( v7 != a4 )
      return sub_51C2D0();
    *a5 = 1;
  }
  return 0;
}
