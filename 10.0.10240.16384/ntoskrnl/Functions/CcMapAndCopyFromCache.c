// CcMapAndCopyFromCache 
 
int CcMapAndCopyFromCache(int a1, int a2, ...)
{
  unsigned int v2; // r5
  unsigned int v3; // r9
  int v4; // r10
  int v5; // r4
  int v6; // r8
  int v7; // r6
  int v8; // r0
  int v9; // r3
  int *v10; // r8
  unsigned int v12; // r7
  int *v13; // [sp+10h] [bp-30h] BYREF
  unsigned int v14; // [sp+14h] [bp-2Ch] BYREF
  int v15; // [sp+18h] [bp-28h]
  int v16; // [sp+1Ch] [bp-24h]
  __int64 anonymous0; // [sp+50h] [bp+10h] BYREF
  va_list va; // [sp+50h] [bp+10h]
  unsigned int v19; // [sp+58h] [bp+18h]
  int v20; // [sp+5Ch] [bp+1Ch]
  int v21; // [sp+60h] [bp+20h]
  _DWORD *v22; // [sp+64h] [bp+24h]
  int v23; // [sp+68h] [bp+28h]
  va_list va1; // [sp+6Ch] [bp+2Ch] BYREF

  va_start(va1, a2);
  va_start(va, a2);
  anonymous0 = va_arg(va1, __int64);
  v19 = va_arg(va1, _DWORD);
  v20 = va_arg(va1, _DWORD);
  v21 = va_arg(va1, _DWORD);
  v22 = va_arg(va1, _DWORD *);
  v23 = va_arg(va1, _DWORD);
  v2 = v19;
  v3 = anonymous0;
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  v5 = 0;
  v6 = HIDWORD(anonymous0);
  v15 = a1;
  v13 = 0;
  if ( !v19 )
    goto LABEL_13;
  v7 = v21;
  while ( 1 )
  {
    v8 = CcGetVirtualAddress(v4, (int)&v13, v3, v6, &v13, &v14, 0, v7 == 0);
    v9 = *(_DWORD *)(v4 + 96);
    v10 = v13;
    v16 = v8;
    if ( (v9 & 8) != 0 )
      return sub_806510();
    if ( !CcFetchDataForRead(v15, (int *)va, v2, (unsigned __int8)v20, v22, v13, v23) )
      break;
    v12 = v14;
    v6 = (anonymous0 + (unsigned __int64)v14) >> 32;
    v3 = anonymous0 + v14;
    if ( v14 > v2 )
    {
      v12 = v2;
      v14 = v2;
    }
    if ( v7 )
    {
      v5 = CcCopyBytesToUserBuffer(v7, v16, v12);
      if ( v5 < 0 )
        JUMPOUT(0x80651E);
      v7 += v12;
    }
    v2 -= v12;
    CcFreeVirtualAddress((int)v13);
    v13 = 0;
    anonymous0 = __PAIR64__(v6, v3);
    if ( !v2 )
      goto LABEL_12;
  }
  v5 = -1073741608;
  if ( v10 )
    CcFreeVirtualAddress((int)v10);
LABEL_12:
  if ( v5 == -1073741608 )
    return 0;
LABEL_13:
  if ( (*(_DWORD *)(v4 + 96) & 8) != 0 )
    CcUpdateSharedCacheMapFlag(v4, 8, 0);
  return 1;
}
