// WheapPfaRetireExpiredMemoryEntries 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall WheapPfaRetireExpiredMemoryEntries(unsigned __int64 a1)
{
  unsigned int v1; // r7
  unsigned int v2; // r8
  unsigned __int64 v3; // kr00_8
  int v4; // r5
  unsigned int v5; // r4
  unsigned __int64 v6; // r2
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  int v10[14]; // [sp+0h] [bp-38h] BYREF

  v1 = HIDWORD(a1);
  v2 = a1;
  if ( WheapPolicyMemPfaTimeout && a1 >= WheapPolicyMemPfaTimeout )
  {
    v3 = a1 - WheapPolicyMemPfaTimeout;
    v4 = WheapPfaList;
    while ( (int *)v4 != &WheapPfaList )
    {
      v5 = v4;
      v6 = *(_QWORD *)(v4 + 24);
      v4 = *(_DWORD *)v4;
      if ( v6 <= v3 )
      {
        *(_QWORD *)&v7 = *(_QWORD *)v5;
        if ( *(_DWORD *)(*(_DWORD *)v5 + 4) != v5 || *v8 != v5 )
          __fastfail(3u);
        v10[1] = 2;
        *v8 = v7;
        v10[0] = 1;
        *(_DWORD *)(v7 + 4) = v8;
        v10[3] = _rt_udiv64((unsigned int)dword_989680, __PAIR64__(v1, v2) - *(_QWORD *)(v5 + 16));
        v10[2] = 1;
        v10[5] = *(unsigned __int16 *)(v5 + 8);
        v10[4] = 1;
        WheapSqmAddToStream(7213, 3, v10);
        WheapSqmCollectWheaPolicyTelemetry();
        LODWORD(a1) = ExFreePoolWithTag(v5);
      }
    }
  }
  return a1;
}
