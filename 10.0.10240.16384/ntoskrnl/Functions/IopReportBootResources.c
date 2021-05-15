// IopReportBootResources 
 
int __fastcall IopReportBootResources(int a1, int a2, int *a3)
{
  int result; // r0

  if ( !PnpDetermineResourceListSize(a3) )
    return 0;
  if ( !a2 )
    JUMPOUT(0x969772);
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 176) + 20) + 268) & 1) != 0 )
    result = sub_969740();
  else
    result = IopAllocateBootResources(a1, a2, (int)a3);
  return result;
}
