// PopFxCreateDeviceCommon 
 
int __fastcall PopFxCreateDeviceCommon(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r4
  _BYTE *v7; // r0
  _BYTE *v8; // r5
  int v10; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+Ch] [bp-1Ch]

  v10 = 0;
  v11 = 0;
  v6 = PopFxDuplicateUniqueId(a1, &v10);
  if ( v6 < 0 )
    JUMPOUT(0x55149E);
  v7 = (_BYTE *)ExAllocatePoolWithTag(512, 400);
  v8 = v7;
  if ( !v7 )
    return sub_55149C();
  memset(v7, 0, 400);
  *((_DWORD *)v8 + 25) = v10;
  *((_DWORD *)v8 + 26) = v11;
  *(_DWORD *)v8 = v8;
  *((_DWORD *)v8 + 1) = v8;
  *((_DWORD *)v8 + 23) = v8 + 92;
  *((_DWORD *)v8 + 24) = v8 + 92;
  v8[320] = 0;
  v8[321] = 0;
  v8[322] = 4;
  *((_DWORD *)v8 + 81) = 1;
  *((_DWORD *)v8 + 82) = v8 + 328;
  *((_DWORD *)v8 + 83) = v8 + 328;
  *((_DWORD *)v8 + 46) = 0;
  KeInitializeTimerEx((_DWORD *)v8 + 48, 1);
  v8[240] = 19;
  v8[241] = 1;
  *((_DWORD *)v8 + 63) = PopFxIdleTimeoutDpcRoutine;
  *((_DWORD *)v8 + 64) = v8;
  *((_WORD *)v8 + 121) = 0;
  *((_DWORD *)v8 + 67) = 0;
  *((_DWORD *)v8 + 62) = 0;
  IoInitializeRemoveLockEx((int)(v8 + 108), 1297630800, 0, 0, 24);
  *((_DWORD *)v8 + 41) = PopFxDeviceWork;
  *((_DWORD *)v8 + 42) = v8;
  *((_DWORD *)v8 + 39) = 0;
  IoInitializeRemoveLockEx((int)(v8 + 132), 1297630800, 0, 0, 24);
  __dmb(0xBu);
  *((_DWORD *)v8 + 96) = a4;
  *a5 = v8;
  return v6;
}
