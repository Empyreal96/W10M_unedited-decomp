// KdpIsBreakpoint 
 
// local variable allocation has failed, the output may be wrong!
BOOL __fastcall KdpIsBreakpoint(int a1, int *a2)
{
  int v2; // r3
  int v3; // r4 OVERLAPPED
  int v4; // r3
  int v6; // r2
  int v7; // r3

  v2 = *(unsigned __int8 *)(a1 + 28);
  switch ( v2 )
  {
    case 1:
      v6 = *(unsigned __int8 *)(a1 + 8);
      v7 = *(unsigned __int8 *)a2;
      return v7 == v6;
    case 2:
      v6 = *(unsigned __int16 *)(a1 + 8);
      v7 = *(unsigned __int16 *)a2;
      return v7 == v6;
    case 4:
      v6 = *(_DWORD *)(a1 + 8);
      v7 = *a2;
      return v7 == v6;
  }
  if ( v2 != 8 )
    return 0;
  *(_QWORD *)(&v3 - 1) = *(_QWORD *)(a1 + 8);
  if ( *a2 != v4 )
    return 0;
  return a2[1] == v3;
}
