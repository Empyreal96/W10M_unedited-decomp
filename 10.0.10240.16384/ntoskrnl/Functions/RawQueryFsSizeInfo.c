// RawQueryFsSizeInfo 
 
int __fastcall RawQueryFsSizeInfo(int a1, int a2, int a3, _DWORD *a4)
{
  int v9; // r3
  int v10; // r8
  int v11; // r0
  int v12; // r4
  int v13; // r0
  int v14; // r0
  unsigned __int64 v15; // r2
  int v16; // r1
  unsigned int v17; // r0
  int v18; // r1
  int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r0
  int v24; // r0
  int v25; // [sp+18h] [bp-80h]
  char v26[16]; // [sp+20h] [bp-78h] BYREF
  __int64 v27; // [sp+30h] [bp-68h] BYREF
  unsigned __int64 v28; // [sp+38h] [bp-60h] BYREF
  char v29[8]; // [sp+40h] [bp-58h] BYREF
  unsigned __int64 v30; // [sp+48h] [bp-50h]
  __int64 v31; // [sp+60h] [bp-38h] BYREF
  int v32; // [sp+6Ch] [bp-2Ch]
  int v33; // [sp+70h] [bp-28h]
  unsigned int v34; // [sp+74h] [bp-24h]

  if ( *a4 < 0x18u )
    return sub_7CFF80();
  v9 = *(_DWORD *)(a1 + 148);
  if ( v9 && a2 == v9 || ExAcquireRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1) )
  {
    memset((_BYTE *)a3, 0, 24);
    KeInitializeEvent((int)v26, 0, 0);
    v10 = *(_DWORD *)(*(_DWORD *)(a1 + 140) + 12);
    v11 = IoBuildDeviceIoControlRequest(458752, v10, 0, 0, (int)&v31, 24);
    if ( v11 )
    {
      v12 = IofCallDriver(v10, v11);
      if ( v12 == 259 )
      {
        KeWaitForSingleObject((unsigned int)v26, 0, 0, 0, 0);
        v12 = v25;
      }
      if ( v12 < 0 )
      {
        *a4 = 0;
        v22 = *(_DWORD *)(a1 + 148);
        if ( !v22 || a2 != v22 )
          ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
        return v12;
      }
      if ( (*(_DWORD *)(v10 + 32) & 4) != 0 )
      {
        v16 = 0;
        v15 = 0i64;
        v30 = 0i64;
        goto LABEL_15;
      }
      KeResetEvent((int)v26);
      v13 = IoBuildDeviceIoControlRequest(475228, v10, 0, 0, (int)&v28, 8);
      if ( v13 )
      {
        v14 = IofCallDriver(v10, v13);
        if ( v14 == 259 )
        {
          KeWaitForSingleObject((unsigned int)v26, 0, 0, 0, 0);
          v14 = v25;
        }
        v15 = v28;
        v30 = v28;
        if ( v14 >= 0 )
        {
LABEL_14:
          v16 = 1;
LABEL_15:
          v17 = v34;
          *(_DWORD *)(a3 + 16) = 1;
          *(_DWORD *)(a3 + 20) = v17;
          if ( v16 == 1 )
          {
            RtlExtendedLargeIntegerDivide(&v27, v15, v17, 0);
            v19 = HIDWORD(v27);
            v18 = v27;
          }
          else
          {
            v18 = v33 * v32 * v31;
            v19 = (unsigned __int64)(v33 * v32 * v31) >> 32;
          }
          *(_DWORD *)(a3 + 8) = v18;
          *(_DWORD *)(a3 + 12) = v19;
          *(_DWORD *)a3 = v18;
          *(_DWORD *)(a3 + 4) = v19;
          *a4 -= 24;
          v20 = *(_DWORD *)(a1 + 148);
          if ( !v20 || a2 != v20 )
            ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
          return 0;
        }
        KeResetEvent((int)v26);
        v23 = IoBuildDeviceIoControlRequest(475140, v10, 0, 0, (int)v29, 32);
        if ( v23 )
        {
          v24 = IofCallDriver(v10, v23);
          if ( v24 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v26, 0, 0, 0, 0);
            v24 = v25;
          }
          v15 = v30;
          if ( v24 < 0 )
          {
            v16 = 0;
            goto LABEL_15;
          }
          goto LABEL_14;
        }
      }
    }
    v21 = *(_DWORD *)(a1 + 148);
    if ( !v21 || a2 != v21 )
      ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(a1 + 156), 1);
    return -1073741670;
  }
  return -1073741202;
}
