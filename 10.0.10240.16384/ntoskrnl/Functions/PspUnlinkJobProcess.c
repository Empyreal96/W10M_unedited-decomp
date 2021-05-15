// PspUnlinkJobProcess 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspUnlinkJobProcess(int a1, int a2)
{
  int result; // r0
  int v3; // r1 OVERLAPPED
  _DWORD *v4; // r2 OVERLAPPED

  if ( *(_DWORD *)(a1 + 580) != a1 + 580 )
    return sub_7C0B0C();
  result = a2 + 384;
  *(_QWORD *)&v3 = *(_QWORD *)(a2 + 384);
  if ( *(_DWORD *)(v3 + 4) != result || *v4 != result )
    __fastfail(3u);
  *v4 = v3;
  *(_DWORD *)(v3 + 4) = v4;
  return result;
}
