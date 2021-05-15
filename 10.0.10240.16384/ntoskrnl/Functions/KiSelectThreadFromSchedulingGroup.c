// KiSelectThreadFromSchedulingGroup 
 
int __fastcall KiSelectThreadFromSchedulingGroup(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r4
  unsigned int v6; // [sp+0h] [bp-8h]

  v3 = *(unsigned __int16 *)(a2 + 94) >> a3;
  v4 = 0;
  if ( v3 )
  {
    v6 = a3 - __clz(v3) + 31;
    v4 = *(_DWORD *)(a2 + 8 * v6 + 100) - 144;
    KiRemoveThreadFromScbQueue(a1, a2, v4, v6);
  }
  return v4;
}
