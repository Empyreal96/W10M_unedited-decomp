// KiUpdateChildrenCpuTarget 
 
_DWORD **__fastcall KiUpdateChildrenCpuTarget(_DWORD **a1, int a2)
{
  _DWORD **v3; // r4
  unsigned __int16 *v5; // r0
  _DWORD **result; // r0

  v3 = (_DWORD **)*a1;
  do
  {
    v5 = (unsigned __int16 *)(v3 - 10);
    if ( ((unsigned int)*(v3 - 9) & 1) != 0 )
      result = KiUpdateCpuTargetByRate(v5, a2);
    else
      result = KiUpdateCpuTargetByWeight(v5, a2);
    v3 = (_DWORD **)*v3;
  }
  while ( v3 != a1 );
  return result;
}
