// RtlCopyRangeList 
 
int __fastcall RtlCopyRangeList(_DWORD *a1, _DWORD *a2)
{
  int result; // r0

  if ( a1[3] )
    return -1073741811;
  a1[2] = a2[2];
  a1[3] = a2[3];
  a1[4] = a2[4];
  if ( a2 == (_DWORD *)*a2 )
    result = 0;
  else
    result = sub_80E7C0();
  return result;
}
