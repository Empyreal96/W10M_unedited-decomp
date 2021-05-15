// WmipUnlinkInstanceSetFromGuidEntry 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall WmipUnlinkInstanceSetFromGuidEntry(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED

  v1 = result;
  --*(_DWORD *)(result[7] + 20);
  *(_QWORD *)&v2 = *(_QWORD *)result;
  if ( *(_DWORD **)(*result + 4) != result || (_DWORD *)*v3 != result )
    __fastfail(3u);
  *v3 = v2;
  *(_DWORD *)(v2 + 4) = v3;
  if ( (result[2] & 0x80000) != 0 )
  {
    result = WmipUnregisterEtwProvider(result);
    v1[2] &= 0xFFCFFFFF;
  }
  return result;
}
