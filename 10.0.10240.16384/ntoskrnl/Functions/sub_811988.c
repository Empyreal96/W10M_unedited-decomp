// sub_811988 
 
// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
unsigned int __fastcall sub_811988(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED

  if ( *a3 != v3 )
    JUMPOUT(0x7A1822);
  *a3 = a2;
  *(_DWORD *)(a2 + 4) = a3;
  *(_QWORD *)&v4 = *(_QWORD *)(v3 + 36);
  if ( *(_DWORD *)(v4 + 4) != v3 + 36 || *v5 != v3 + 36 )
    __fastfail(3u);
  *v5 = v4;
  *(_DWORD *)(v4 + 4) = v5;
  return ExFreePoolWithTag(v3);
}
