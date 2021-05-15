// PopFreeSessionStateInList 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PopFreeSessionStateInList(unsigned int result, int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r4
  int v5; // r3
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED

  v2 = (_DWORD *)result;
  v3 = *(_DWORD **)result;
  while ( v3 != v2 )
  {
    result = (unsigned int)v3;
    if ( v3[8] != a2 )
      goto LABEL_5;
    v5 = v3[9];
    if ( (v5 & 2) != 0 )
    {
      v3[9] = v5 | 4;
LABEL_5:
      v3 = (_DWORD *)*v3;
    }
    else
    {
      *(_QWORD *)&v6 = *(_QWORD *)v3;
      v3 = (_DWORD *)*v3;
      if ( *(_DWORD *)(*(_DWORD *)result + 4) != result || *v7 != result )
        __fastfail(3u);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
      result = PopFreeRegistration(result);
    }
  }
  return result;
}
