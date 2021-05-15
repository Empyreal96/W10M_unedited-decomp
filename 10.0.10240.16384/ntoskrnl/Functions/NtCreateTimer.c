// NtCreateTimer 
 
int __fastcall NtCreateTimer(unsigned int a1, int a2, int a3, int a4)
{
  char v4; // r8
  _DWORD *v7; // r5
  int result; // r0
  int v9; // r6
  _DWORD *v10; // r2
  int v11; // r4
  int v12; // r0
  int v13; // [sp+0h] [bp-48h]
  int v14; // [sp+20h] [bp-28h] BYREF
  int _24[15]; // [sp+24h] [bp-24h] BYREF

  v4 = a4;
  _24[14] = a4;
  _24[13] = a3;
  _24[12] = a2;
  v7 = (_DWORD *)a1;
  _24[11] = a1;
  if ( a4 && a4 != 1 )
    return -1073741582;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v9 )
  {
    v10 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
  }
  result = ObCreateObjectEx(v9, (_DWORD *)ExTimerObjectType, a3, v9, v13, 192, 0, 0, _24, 0);
  if ( result >= 0 )
  {
    v11 = _24[0];
    KeInitializeDpc(_24[0] + 100, (int)ExpTimerDpcRoutine, _24[0]);
    KeInitializeTimerEx((_DWORD *)v11, v4);
    *(_DWORD *)(v11 + 48) = 0;
    *(_BYTE *)(v11 + 144) = 0;
    *(_DWORD *)(v11 + 148) = 0;
    *(_DWORD *)(v11 + 152) = 0;
    *(_DWORD *)(v11 + 160) = 0;
    if ( v9 )
    {
      v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( (*(_DWORD *)(v12 + 100) & 0x10) != 0 )
        PsInsertVirtualizedTimer(v12, (_DWORD *)(v11 + 164), (_DWORD *)(v11 + 160));
    }
    result = ObInsertObjectEx(v11, 0, a2, 0, 0, 0, &v14);
    _24[0] = result;
    if ( result >= 0 )
      *v7 = v14;
  }
  return result;
}
