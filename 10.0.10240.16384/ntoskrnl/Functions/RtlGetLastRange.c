// RtlGetLastRange 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlGetLastRange(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // r3
  int result; // r0
  int v6; // r4 OVERLAPPED
  int v7; // r3
  int v8; // r3

  *a2 = a1;
  v4 = a1[4];
  result = 0;
  a2[3] = v4;
  if ( (_DWORD *)*a1 == a1 )
  {
    v8 = 0;
    a2[1] = 0;
    a2[2] = 0;
    result = -2147483622;
  }
  else
  {
    v6 = a1[1] - 28;
    if ( (*(_WORD *)(v6 + 26) & 1) != 0 )
      return sub_80E648(0);
    v7 = 0;
    *(_QWORD *)(a2 + 1) = *(_QWORD *)(&v6 - 1);
    v8 = a2[2];
  }
  *a3 = v8;
  return result;
}
