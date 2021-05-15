// sub_811558 
 
// local variable allocation has failed, the output may be wrong!
void sub_811558()
{
  unsigned int v0; // r4
  int v1; // r1 OVERLAPPED
  _DWORD *v2; // r2 OVERLAPPED
  __int64 v3; // kr00_8

  *(_QWORD *)&v1 = *(_QWORD *)v0;
  if ( *(_DWORD *)(*(_DWORD *)v0 + 4) == v0 && *v2 == v0 )
  {
    *v2 = v1;
    *(_DWORD *)(v1 + 4) = v2;
    v3 = *(_QWORD *)(v0 + 12);
    if ( *(_DWORD *)(v3 + 4) == v0 + 12 && *(_DWORD *)HIDWORD(v3) == v0 + 12 )
    {
      *(_DWORD *)HIDWORD(v3) = v3;
      *(_DWORD *)(v3 + 4) = HIDWORD(v3);
      ExFreePoolWithTag(v0);
      JUMPOUT(0x7A143C);
    }
    __fastfail(3u);
  }
  __fastfail(3u);
}
