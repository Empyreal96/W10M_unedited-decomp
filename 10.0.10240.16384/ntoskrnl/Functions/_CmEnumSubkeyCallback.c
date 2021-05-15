// _CmEnumSubkeyCallback 
 
int __fastcall CmEnumSubkeyCallback(int *a1, int a2, int a3, int a4)
{
  unsigned int v7; // r7
  unsigned __int16 *v8; // r0
  unsigned __int16 *v9; // r6
  unsigned int v10; // r1
  _WORD *v11; // r0
  unsigned int v12; // r1
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r4
  int (__fastcall *v17)(int *, unsigned __int16 *, int, _DWORD); // lr
  __int64 v18; // kr00_8
  unsigned int v19; // r3
  int v20; // r0
  _BYTE *v21; // r0
  _WORD *v22; // [sp+10h] [bp-30h] BYREF
  unsigned int v23; // [sp+14h] [bp-2Ch] BYREF
  int v24; // [sp+18h] [bp-28h] BYREF

  v24 = a2;
  v22 = 0;
  v7 = 0;
  v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 400, 1380994640);
  v9 = v8;
  if ( !v8 )
    return 0;
  if ( *(_WORD *)(a4 + 4) )
  {
    if ( RtlStringCchCopyExW(v8, 200, a4 + 4, &v22, &v23, 2304, 0) < 0 )
      goto LABEL_17;
    v10 = v23;
    if ( v23 < 2 )
      goto LABEL_17;
    v11 = v22;
    *v22 = 92;
    v8 = v11 + 1;
    v12 = v10 - 2;
    *v8 = 0;
  }
  else
  {
    v12 = 200;
  }
  v13 = RtlStringCchCopyW(v8, v12, a3);
  if ( v13 >= 0 )
  {
    if ( *(_DWORD *)a4 < 3u )
    {
      v20 = PnpCtxRegOpenKey(a1, v24, a3, 8);
      if ( v20 == -1073741444 )
        goto LABEL_17;
      if ( v20 < 0 )
        goto LABEL_17;
      v21 = (_BYTE *)ExAllocatePoolWithTag(1, 428, 1380994640);
      v7 = (unsigned int)v21;
      if ( !v21 )
        goto LABEL_17;
      memset(v21, 0, 428);
      *(_DWORD *)v7 = *(_DWORD *)a4 + 1;
      RtlStringCchCopyExW((_WORD *)(v7 + 4), 200, v9, 0, 0, 2304);
      *(_BYTE *)(v7 + 404) = *(_BYTE *)(a4 + 404);
      *(_DWORD *)(v7 + 408) = *(_DWORD *)(a4 + 408);
      *(_DWORD *)(v7 + 412) = *(_DWORD *)(a4 + 412);
      *(_DWORD *)(v7 + 416) = *(_DWORD *)(a4 + 416);
      *(_DWORD *)(v7 + 420) = *(_DWORD *)(a4 + 420);
      *(_DWORD *)(v7 + 424) = *(_DWORD *)(a4 + 424);
      PnpCtxRegEnumKeyWithCallback(a1, 0, (int)CmEnumSubkeyCallback, v7);
      *(_DWORD *)(a4 + 424) = *(_DWORD *)(v7 + 424);
      *(_DWORD *)(a4 + 416) = *(_DWORD *)(v7 + 416);
      v19 = *(_DWORD *)(v7 + 420);
    }
    else
    {
      if ( CmValidateDeviceName(v13, v9, v14, *(_DWORD *)a4) < 0 || RtlInitUnicodeStringEx((int)&v24, v9) < 0 )
        goto LABEL_17;
      v15 = HIWORD(v24) >> 1;
      if ( *(_BYTE *)(a4 + 404) )
        return sub_811D0C();
      v17 = *(int (__fastcall **)(int *, unsigned __int16 *, int, _DWORD))(a4 + 408);
      if ( v17 )
      {
        if ( !v17(a1, v9, 1, *(_DWORD *)(a4 + 412)) )
          goto LABEL_17;
      }
      v18 = *(_QWORD *)(a4 + 420);
      *(_DWORD *)(a4 + 424) = HIDWORD(v18) + v15;
      if ( (unsigned int)v18 <= v15 )
        goto LABEL_17;
      RtlStringCchCopyExW(*(_WORD **)(a4 + 416), v18, v9);
      *(_DWORD *)(a4 + 416) += 2 * v15;
      v19 = *(_DWORD *)(a4 + 420) - v15;
    }
    *(_DWORD *)(a4 + 420) = v19;
    if ( v7 )
      ExFreePoolWithTag(v7);
  }
LABEL_17:
  ExFreePoolWithTag((unsigned int)v9);
  return 0;
}
