// RtlQueryElevationFlags 
 
int __fastcall RtlQueryElevationFlags(_DWORD *a1)
{
  *a1 = 0;
  if ( (MEMORY[0xFFFF92F0] & 2) != 0 )
    return sub_81CA0C();
  if ( (MEMORY[0xFFFF92F0] & 4) != 0 )
    *a1 |= 2u;
  if ( (MEMORY[0xFFFF92F0] & 8) != 0 )
    *a1 |= 4u;
  return 0;
}
