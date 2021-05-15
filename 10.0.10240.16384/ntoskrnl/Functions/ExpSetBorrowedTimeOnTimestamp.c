// ExpSetBorrowedTimeOnTimestamp 
 
char __fastcall ExpSetBorrowedTimeOnTimestamp(char result, _DWORD *a2)
{
  int v2; // r2

  v2 = 0;
  if ( (result & 1) != 0 )
    v2 = 0x8000000;
  if ( (result & 2) != 0 )
    v2 |= 0x4000000u;
  if ( (result & 4) != 0 )
    v2 |= 0x2000000u;
  if ( (result & 8) != 0 )
    v2 |= 0x1000000u;
  if ( (result & 0x10) != 0 )
    v2 |= 0x800000u;
  *a2 |= v2;
  return result;
}
