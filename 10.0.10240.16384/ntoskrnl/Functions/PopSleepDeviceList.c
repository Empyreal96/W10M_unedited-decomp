// PopSleepDeviceList 
 
int __fastcall PopSleepDeviceList(int a1, int a2)
{
  int v2; // r8
  int *v3; // r3
  int v4; // r4
  int v5; // r6
  int *v7; // r7
  int result; // r0
  int v9; // r3
  int v10; // r6
  __int64 v11; // r2
  int *v12; // r1
  unsigned int v13[2]; // [sp+10h] [bp-70h] BYREF
  char v14[16]; // [sp+18h] [bp-68h] BYREF
  char v15[16]; // [sp+28h] [bp-58h] BYREF
  char v16[24]; // [sp+38h] [bp-48h] BYREF
  char v17[48]; // [sp+50h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(int **)(a2 + 16);
  v4 = 0;
  v5 = 0;
  v7 = (int *)(a2 + 16);
  while ( v3 != v7 )
  {
    v3 = (int *)*v3;
    ++v5;
  }
  KeInitializeEvent((int)v15, 1, 0);
  KeInitializeSemaphore((int)v17, v5, v2);
  result = KeInitializeSemaphore((int)v16, 0, v2);
  *(_DWORD *)(a1 + 16) = v15;
  *(_DWORD *)(a1 + 20) = v17;
  *(_DWORD *)(a1 + 24) = v16;
  v13[0] = (unsigned int)v15;
  v13[1] = (unsigned int)v17;
  if ( v2 > 0 )
  {
    do
    {
      result = KeWaitForMultipleObjects(2u, v13, 1, 0, 0, 0, 0, 0);
      if ( *(int *)(a1 + 244) < 0 )
        break;
      KeAcquireInStackQueuedSpinLock((unsigned int *)(dword_61E84C + 8), (unsigned int)v14);
      v9 = __mrc(15, 0, 13, 0, 3);
      v10 = *v7;
      PopDevStateLockThread = v9 & 0xFFFFFFC0;
      v11 = *(_QWORD *)v10;
      if ( *(int **)(v10 + 4) != v7 || *(_DWORD *)(v11 + 4) != v10 )
        __fastfail(3u);
      *v7 = v11;
      *(_DWORD *)(v11 + 4) = v7;
      v12 = *(int **)(a1 + 240);
      *(_DWORD *)v10 = a1 + 236;
      *(_DWORD *)(v10 + 4) = v12;
      if ( *v12 != a1 + 236 )
        __fastfail(3u);
      *v12 = v10;
      PopDevStateLockThread = 0;
      *(_DWORD *)(a1 + 240) = v10;
      KeReleaseInStackQueuedSpinLock((int)v14);
      --v2;
      ++v4;
      result = PopNotifyDevice((unsigned __int8 *)a1, v10);
      if ( (PopSimulate & 0x80000) != 0 && v4 > 0 )
      {
        do
        {
          result = KeWaitForSingleObject((unsigned int)v16, 0, 0, 0, 0);
          --v4;
        }
        while ( v4 > 0 );
      }
    }
    while ( v2 > 0 );
    while ( v4 > 0 )
    {
      result = KeWaitForSingleObject((unsigned int)v16, 0, 0, 0, 0);
      --v4;
    }
  }
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  return result;
}
