// CmpAllocateExtraHashInfo 
 
_DWORD *CmpAllocateExtraHashInfo()
{
  _DWORD *v0; // r4
  int v1; // r5
  _DWORD *result; // r0
  int v3; // r5
  __int64 v4; // kr00_8
  int v5; // r0

  v0 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  v1 = v0[720];
  ++*(_DWORD *)(v1 + 12);
  result = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v1);
  if ( result )
    goto LABEL_2;
  ++*(_DWORD *)(v1 + 16);
  v3 = v0[721];
  ++*(_DWORD *)(v3 + 12);
  result = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v3);
  if ( result
    || (v4 = *(_QWORD *)(v3 + 32),
        v5 = *(_DWORD *)(v3 + 28),
        ++*(_DWORD *)(v3 + 16),
        (result = (_DWORD *)(*(int (__fastcall **)(int, _DWORD, _DWORD))(v3 + 40))(v5, HIDWORD(v4), v4)) != 0) )
  {
LABEL_2:
    *result = v0[357];
  }
  return result;
}
