// WmipAllocGuidEntry 
 
// local variable allocation has failed, the output may be wrong!
int WmipAllocGuidEntry()
{
  int v0; // r5
  _DWORD *v1; // r0
  _DWORD *v2; // r4 OVERLAPPED
  int v4; // r2
  int (__fastcall *v5)(_DWORD); // r3

  v0 = ExAllocatePoolWithTag(512, 32, 1885957463);
  if ( !v0 )
    return 0;
  v1 = (_DWORD *)WmipAllocEntry(&WmipGEChunkInfo);
  v2 = v1;
  if ( v1 )
  {
    v1[16] = v0;
    v1[8] = v1 + 8;
    v1[9] = v1 + 8;
    v1[6] = v1 + 6;
    v1[7] = v1 + 6;
    v1[25] = v1 + 25;
    v1[26] = v1 + 25;
    v4 = v1[16];
    v5 = WmipLegacyEtwWorker;
    *(_QWORD *)(v4 + 24) = *(_QWORD *)(&v2 - 1);
    *(_DWORD *)(v4 + 16) = 0;
  }
  return sub_7CBD44();
}
