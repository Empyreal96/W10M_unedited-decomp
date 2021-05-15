// MiWorkingSetVeryLarge 
 
BOOL __fastcall MiWorkingSetVeryLarge(_DWORD *a1, int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r0
  BOOL result; // r0
  int v5; // r5

  v2 = a1[15];
  if ( a2 == 1 )
    v3 = *(_DWORD *)(a1[23] + 4);
  else
    v3 = a1[12];
  result = v2 > v3
        && v2 - v3 >= 3 * ((unsigned int)dword_640508 >> 2)
        && ((v5 = dword_6404B8, a2 != 1) || MiGetStandbyRepurposed((int)MiSystemPartition, 1u) != *(_DWORD *)(v5 + 36))
        && dword_640580 < (unsigned int)(4 * *(_DWORD *)(v5 + 1240));
  return result;
}
