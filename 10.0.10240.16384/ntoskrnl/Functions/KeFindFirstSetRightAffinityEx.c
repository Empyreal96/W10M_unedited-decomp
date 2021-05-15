// KeFindFirstSetRightAffinityEx 
 
unsigned int __fastcall KeFindFirstSetRightAffinityEx(int a1)
{
  unsigned int v1; // r3
  unsigned int result; // r0

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 )
    result = __clz(__rbit(v1));
  else
    result = -1;
  return result;
}
