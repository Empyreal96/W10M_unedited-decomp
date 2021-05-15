// KiIntSteerClearCpuSetAssignment 
 
int __fastcall KiIntSteerClearCpuSetAssignment(int result)
{
  if ( *(_DWORD *)(result + 104) )
  {
    *(_WORD *)(result + 108) = 0;
    *(_DWORD *)(result + 104) = 0;
    *(_DWORD *)(result + 132) = 0;
  }
  return result;
}
