// CmpCloseKeyObject 
 
int __fastcall CmpCloseKeyObject(int result, _DWORD *a2, int a3, unsigned int a4)
{
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r1
  int v8; // r0
  int v9; // r0
  __int16 v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r3
  int v14[2]; // [sp+10h] [bp-40h] BYREF
  _DWORD v15[2]; // [sp+18h] [bp-38h] BYREF
  int v16[12]; // [sp+20h] [bp-30h] BYREF

  v16[0] = 0;
  v16[1] = 0;
  v16[2] = 0;
  v16[3] = 0;
  if ( CmpTraceRoutine )
    return sub_7DD554();
  if ( a4 <= 1 && *a2 == 1803104306 && a2[2] )
  {
    v14[1] = (int)v14;
    v15[0] = v15;
    v15[1] = v15;
    v14[0] = (int)v14;
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    CmpLockRegistry(result, v5);
    CmpLockKcbShared(a2[1]);
    v6 = a2[1];
    if ( (*(_DWORD *)(v6 + 4) & 0x20000) != 0 || (a2[6] & 1) != 0 )
    {
      v11 = CmpUnlockKcb(v6);
      result = CmpUnlockRegistry(v11);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
      *(_WORD *)(v12 + 308) = v13;
      if ( v13 || *(_DWORD *)(v12 + 100) == v12 + 100 || *(_WORD *)(v12 + 310) )
        goto LABEL_6;
    }
    else
    {
      CmLockHive(*(_DWORD *)(v6 + 20));
      v8 = a2[2];
      if ( v8 && *(_DWORD *)(v8 + 8) != v8 + 8 )
        CmpPostNotify(v8, v7, v8 + 8);
      CmUnlockHive(*(_DWORD *)(a2[1] + 20));
      v9 = CmpUnlockKcb(a2[1]);
      CmpUnlockRegistry(v9);
      CmpDelayedDerefKeys(v15);
      CmpSignalDeferredPosts(v14);
      result = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10 = *(_WORD *)(result + 0x134);
      *(_WORD *)(result + 308) = v10 + 1;
      if ( v10 != -1 || *(_DWORD *)(result + 100) == result + 100 || *(_WORD *)(result + 310) )
        goto LABEL_6;
    }
    result = KiCheckForKernelApcDelivery(result);
  }
LABEL_6:
  if ( CmpTraceRoutine )
    result = ((int (__fastcall *)(int, int *, _DWORD, _DWORD, _DWORD, _DWORD))CmpTraceRoutine)(27, v16, 0, 0, 0, 0);
  return result;
}
