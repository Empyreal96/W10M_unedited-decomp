// NtQueryDebugFilterState 
 
int __fastcall NtQueryDebugFilterState(unsigned int a1, unsigned int a2)
{
  if ( a1 >= 0x9A )
    return sub_529C7C();
  if ( a2 <= 0x1F )
    a2 = 1 << a2;
  return (Kd_WIN2000_Mask & a2) != 0 || (*(_DWORD *)*(&KdComponentTable + a1) & a2) != 0;
}
