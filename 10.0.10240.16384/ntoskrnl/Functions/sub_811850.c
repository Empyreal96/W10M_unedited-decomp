// sub_811850 
 
// local variable allocation has failed, the output may be wrong!
void sub_811850()
{
  unsigned int v0; // r5
  int v1; // r1 OVERLAPPED
  _DWORD *v2; // r2 OVERLAPPED
  int v3; // r1 OVERLAPPED
  _DWORD *v4; // r2 OVERLAPPED

  *(_QWORD *)&v1 = *(_QWORD *)v0;
  if ( *(_DWORD *)(*(_DWORD *)v0 + 4) == v0 && *v2 == v0 )
  {
    *v2 = v1;
    *(_DWORD *)(v1 + 4) = v2;
    *(_QWORD *)&v3 = *(_QWORD *)(v0 + 12);
    if ( *(_DWORD *)(v3 + 4) == v0 + 12 && *v4 == v0 + 12 )
    {
      *v4 = v3;
      *(_DWORD *)(v3 + 4) = v4;
      ExFreePoolWithTag(v0);
      JUMPOUT(0x7A1628);
    }
    __fastfail(3u);
  }
  __fastfail(3u);
}
