// KiGroupSchedulingMoveThread 
 
int __fastcall KiGroupSchedulingMoveThread(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  unsigned int v6; // r1
  unsigned int v7; // r7
  int v8; // r5
  int result; // r0
  _DWORD *v10; // r3
  unsigned int v11; // r2

  v3 = *(_DWORD *)(a3 + 4);
  while ( 1 )
  {
    if ( !v3 )
      return 0;
    v6 = v3 - 80;
    if ( *(_WORD *)(v3 + 14) )
      break;
    if ( *(_DWORD *)(v3 + 148) )
    {
      result = KiGroupSchedulingMoveThread(a1, a2, v3 + 148);
      if ( result )
        return result;
    }
    v10 = *(_DWORD **)(v3 + 4);
    v11 = v3;
    if ( v10 )
    {
      do
      {
        v3 = (unsigned int)v10;
        v10 = (_DWORD *)*v10;
      }
      while ( v10 );
    }
    else
    {
      while ( 1 )
      {
        v3 = *(_DWORD *)(v3 + 8) & 0xFFFFFFFC;
        if ( !v3 || *(_DWORD *)v3 == v11 )
          break;
        v11 = v3;
      }
    }
  }
  v7 = 31 - __clz(*(unsigned __int16 *)(v3 + 14));
  v8 = *(_DWORD *)(v6 + 8 * v7 + 100);
  if ( *(unsigned __int8 *)(a1 + 1052) != *(unsigned __int16 *)(v8 + 216)
    || (*(_DWORD *)(v8 + 212) & *(_DWORD *)(a1 + 1048)) == 0 )
  {
    return sub_51C320();
  }
  KiRemoveThreadFromScbQueue(a2, v6, v8 - 144, v7);
  result = v8 - 144;
  *(_DWORD *)(v8 + 184) = *(_DWORD *)(a1 + 20);
  return result;
}
