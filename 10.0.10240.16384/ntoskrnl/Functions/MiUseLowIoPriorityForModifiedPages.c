// MiUseLowIoPriorityForModifiedPages 
 
BOOL __fastcall MiUseLowIoPriorityForModifiedPages(_DWORD *a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r0
  unsigned int v4; // r6
  unsigned int v5; // r4
  unsigned int v6; // r0
  unsigned int v7; // r3
  BOOL result; // r0

  result = 0;
  if ( !a1[111] && !a1[166] )
  {
    v2 = a1[898];
    v3 = MiGetAvailablePagesBelowPriority(a1, 6);
    v4 = v3;
    if ( a1[1030] < 3 * (v2 >> 2) && (v3 > v2 >> 2 || v3 > 0x40000) )
    {
      v5 = *(_DWORD *)(a1[878] + 36);
      v6 = MiGetStandbyRepurposed((int)a1, 1u);
      v7 = v6 > v5 ? v6 - v5 : 0;
      if ( v7 < v4 >> 2 )
        result = 1;
    }
  }
  return result;
}
