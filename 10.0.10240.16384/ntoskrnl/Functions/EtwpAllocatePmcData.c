// EtwpAllocatePmcData 
 
int __fastcall EtwpAllocatePmcData(int a1, int a2)
{
  int v3; // r5
  _BYTE *v4; // r0
  _BYTE *v5; // r4

  v3 = KeQueryMaximumProcessorCountEx(0xFFFFu, a2) + 8;
  v4 = (_BYTE *)ExAllocatePoolWithTag(512, 4 * v3, 1484223557);
  v5 = v4;
  if ( !v4 )
    return -1073741801;
  memset(v4, 0, 4 * v3);
  *(_DWORD *)(a1 + 628) = v5;
  return 0;
}
