// KiIntSteerAssignCpuSet 
 
int __fastcall KiIntSteerAssignCpuSet(int a1, int a2, int a3)
{
  int v4; // r2

  if ( !*(_BYTE *)(a1 + 100) )
    return -1073741637;
  if ( *(unsigned __int16 *)(a1 + 48) != a2 )
    return -1073741811;
  if ( *(_DWORD *)(a1 + 104) == a3 )
    return 0;
  *(_DWORD *)(a1 + 104) = a3;
  v4 = KiIntSteerComputeCpuSet(a1);
  if ( v4 < 0 )
    KiIntSteerClearCpuSetAssignment(a1);
  return v4;
}
