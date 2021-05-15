// PiPnpRtlCacheObjectBaseKey 
 
int __fastcall PiPnpRtlCacheObjectBaseKey(int a1, int a2, int a3, _DWORD *a4)
{
  int v8; // r5
  int v9; // r3
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // [sp+10h] [bp-28h] BYREF
  int v16[9]; // [sp+14h] [bp-24h] BYREF

  v15 = 0;
  v16[0] = 0;
  if ( a3 >= 6 )
    return -1073741637;
  v8 = PiPnpRtlGetCurrentOperation(&v15);
  if ( v8 >= 0 )
  {
    v9 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
    ExAcquireResourceSharedLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1);
    v8 = PiPnpRtlObjectEventCreate(a2, a3, v15, v16);
    if ( v8 >= 0 )
    {
      v10 = v16[0];
      if ( v16[0] )
      {
        if ( *(_DWORD *)(v16[0] + 12)
          || (v8 = PnpOpenObjectRegKey(a1, a2, a3, 0x2000000, 0, v16[0] + 12, 0, 0), v8 >= 0) )
        {
          *a4 = *(_DWORD *)(v10 + 12);
        }
        else
        {
          *(_DWORD *)(v10 + 12) = 0;
        }
      }
    }
    v11 = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 )
      return sub_7C69E8(v11);
  }
  return v8;
}
