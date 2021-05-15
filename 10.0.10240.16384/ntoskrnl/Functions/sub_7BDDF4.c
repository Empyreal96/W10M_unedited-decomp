// sub_7BDDF4 
 
// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
unsigned int __fastcall sub_7BDDF4(unsigned int a1)
{
  int v1; // r1 OVERLAPPED
  _DWORD *v2; // r2 OVERLAPPED

  *(_QWORD *)&v1 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v2 != a1 )
    __fastfail(3u);
  *v2 = v1;
  *(_DWORD *)(v1 + 4) = v2;
  return ExFreePoolWithTag(a1);
}
