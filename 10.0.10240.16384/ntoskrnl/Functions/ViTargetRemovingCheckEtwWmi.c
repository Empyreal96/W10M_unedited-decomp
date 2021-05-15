// ViTargetRemovingCheckEtwWmi 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall ViTargetRemovingCheckEtwWmi(_DWORD *result, int a2)
{
  _DWORD *v2; // r4
  int v3; // r3
  _DWORD *v5; // r4
  _DWORD *v6; // t1
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED

  v2 = result;
  v3 = result[1];
  if ( v3 && (MmVerifierData & 0x800) != 0 )
    result = (_DWORD *)VerifierBugCheckIfAppropriate(196, 218, a2, v3, 0);
  v6 = (_DWORD *)v2[2];
  v5 = v2 + 2;
  if ( v6 != v5 )
  {
    if ( (MmVerifierData & 0x800) != 0 )
      VerifierBugCheckIfAppropriate(196, 221, *(_DWORD *)(*v5 + 16), a2, *(_DWORD *)(*v5 + 8));
    result = (_DWORD *)*v5;
    do
    {
      *(_QWORD *)&v7 = *(_QWORD *)result;
      if ( *(_DWORD **)(*result + 4) != result || (_DWORD *)*v8 != result )
        __fastfail(3u);
      *v8 = v7;
      *(_DWORD *)(v7 + 4) = v8;
      ExFreePoolWithTag((unsigned int)result);
      result = (_DWORD *)*v5;
    }
    while ( (_DWORD *)*v5 != v5 );
  }
  return result;
}
