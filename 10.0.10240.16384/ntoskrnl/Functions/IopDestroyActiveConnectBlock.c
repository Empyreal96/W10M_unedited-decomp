// IopDestroyActiveConnectBlock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopDestroyActiveConnectBlock(int result)
{
  _DWORD *v1; // r4
  unsigned int *v2; // r8
  unsigned int *v3; // r6
  int v4; // r7
  int v5; // r0
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  unsigned int v10; // r2
  unsigned int v11; // r1
  __int16 v12; // r3
  char v13[40]; // [sp+8h] [bp-28h] BYREF

  v1 = (_DWORD *)result;
  if ( *(_DWORD *)(result + 12) )
  {
    v2 = (unsigned int *)(result + 36);
    v3 = *(unsigned int **)(result + 16);
    KeInitializeEvent((int)v13, 1, 0);
    v4 = 0;
    v5 = IopAcquireReleaseConnectLockInternal(0, 1, 2);
    __dmb(0xBu);
    do
    {
      v6 = __ldrex(v3);
      v7 = v6 - 1;
    }
    while ( __strex(v7, v3) );
    __dmb(0xBu);
    if ( v3 == v2 )
    {
      if ( v7 )
      {
        v1[10] = v13;
        v4 = 1;
      }
      *(_QWORD *)&v8 = *(_QWORD *)v1;
      if ( *(_DWORD **)(*v1 + 4) != v1 || (_DWORD *)*v9 != v1 )
        __fastfail(3u);
      *v9 = v8;
      *(_DWORD *)(v8 + 4) = v9;
      result = IopAcquireReleaseConnectLockInternal(0, 0, 2);
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v10 + 308);
      if ( v4 )
        result = KeWaitForSingleObject((unsigned int)v13, 0, 0, 0, 0);
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = *(_WORD *)(v11 + 0x134) + 1;
      *(_WORD *)(v11 + 308) = v12;
      if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
        result = KiCheckForKernelApcDelivery(result);
    }
    else
    {
      result = sub_7DEFC4(v5);
    }
  }
  return result;
}
