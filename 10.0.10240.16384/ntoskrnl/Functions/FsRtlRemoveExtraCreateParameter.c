// FsRtlRemoveExtraCreateParameter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlRemoveExtraCreateParameter(int a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // r4
  int v5; // r6
  _DWORD *v6; // r5
  int result; // r0
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED

  *a3 = 0;
  v4 = *(_DWORD **)(a1 + 8);
  v5 = -1073741275;
  v6 = (_DWORD *)(a1 + 8);
  if ( v4 == (_DWORD *)(a1 + 8) )
    return v5;
  while ( memcmp((unsigned int)(v4 + 2), a2, 16) )
  {
    v4 = (_DWORD *)*v4;
    if ( v4 == v6 )
      return v5;
  }
  v5 = 0;
  v4[7] |= 4u;
  *(_QWORD *)&v11 = *(_QWORD *)v4;
  if ( *(_DWORD **)(*v4 + 4) != v4 || (_DWORD *)*v12 != v4 )
    sub_7FA0C8();
  *v12 = v11;
  *(_DWORD *)(v11 + 4) = v12;
  *v4 = 0;
  v4[1] = 0;
  *a3 = v4 + 11;
  if ( !a4 )
    return v5;
  result = 0;
  *a4 = v4[8] - 52;
  return result;
}
