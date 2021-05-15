// sub_812E5C 
 
// local variable allocation has failed, the output may be wrong!
void sub_812E5C()
{
  unsigned int v0; // r0
  _DWORD *v1; // r6
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED

  *(_QWORD *)&v2 = *(_QWORD *)v1;
  if ( *(_DWORD **)(*v1 + 4) == v1 && (_DWORD *)*v3 == v1 )
  {
    *v3 = v2;
    *(_DWORD *)(v2 + 4) = v3;
    if ( (v1[8] & 1) != 0 )
    {
      v0 = v1[7];
      if ( v0 )
        ExFreePoolWithTag(v0);
    }
    ExFreePoolWithTag((unsigned int)v1);
    JUMPOUT(0x7A468C);
  }
  __fastfail(3u);
}
