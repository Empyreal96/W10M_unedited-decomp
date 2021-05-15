// FsRtlPruneTunnelCache 
 
_DWORD *__fastcall FsRtlPruneTunnelCache(int a1, unsigned int a2)
{
  _DWORD *result; // r0
  __int64 v5; // r8
  __int64 v6; // kr00_8
  __int64 v7; // r2
  char v8[8]; // [sp+0h] [bp-30h] BYREF
  __int64 v9[5]; // [sp+8h] [bp-28h] BYREF

  v8[0] = 1;
  result = KeQuerySystemTime(v9);
  v5 = v9[0];
  v6 = v9[0] - (unsigned int)TunnelMaxAge;
  while ( *(_DWORD *)(a1 + 36) != a1 + 36 )
  {
    result = *(_DWORD **)(a1 + 36);
    v7 = *(_QWORD *)(result + 3);
    if ( v7 >= v6 && v7 <= v5 )
      break;
    result = (_DWORD *)FsRtlRemoveNodeFromTunnel(a1, (unsigned int)(result - 3), a2, v8);
  }
  while ( *(unsigned __int16 *)(a1 + 44) > (unsigned int)TunnelMaxEntries )
    result = (_DWORD *)FsRtlRemoveNodeFromTunnel(a1, *(_DWORD *)(a1 + 36) - 12, a2, v8);
  return result;
}
