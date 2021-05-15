// EtwpCreateActivityId 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpCreateActivityId(int result)
{
  _DWORD *v1; // r4
  unsigned __int64 *v2; // r3
  unsigned __int64 v3; // kr00_8

  v1 = (_DWORD *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C) + 896);
  __dmb(0xBu);
  v2 = (unsigned __int64 *)(v1 + 2);
  do
    v3 = __ldrexd(v2);
  while ( __strexd(v3 + 1, v2) );
  __dmb(0xBu);
  *(_QWORD *)(result + 8) = v3 + 1;
  *(_DWORD *)result = *v1;
  *(_DWORD *)(result + 4) = v1[1];
  return result;
}
