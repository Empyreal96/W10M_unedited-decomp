// PopWakeDeviceList 
 
int __fastcall PopWakeDeviceList(int a1, _DWORD *a2)
{
  int v2; // r5
  int v3; // r6
  int v4; // r4
  int v5; // r7
  int *v6; // r3
  int *v7; // r8
  int result; // r0
  int v9; // r3
  int v10; // r6
  __int64 v11; // r2
  int *v12; // r1
  char v14[16]; // [sp+10h] [bp-58h] BYREF
  char v15[24]; // [sp+20h] [bp-48h] BYREF
  char v16[48]; // [sp+38h] [bp-30h] BYREF

  v2 = a1;
  v3 = 0;
  v4 = 0;
  v5 = *a2 - a2[1];
  v6 = (int *)a2[6];
  v7 = a2 + 6;
  while ( v6 != v7 )
  {
    v6 = (int *)*v6;
    ++v3;
  }
  KeInitializeSemaphore((int)v16, v3, v5);
  result = KeInitializeSemaphore((int)v15, 0, v5);
  *(_DWORD *)(v2 + 20) = v16;
  *(_DWORD *)(v2 + 24) = v15;
  if ( v5 > 0 )
  {
    do
    {
      KeWaitForSingleObject((unsigned int)v16, 0, 0, 0, 0);
      KeAcquireInStackQueuedSpinLock((unsigned int *)(dword_61E84C + 8), (unsigned int)v14);
      v9 = __mrc(15, 0, 13, 0, 3);
      v10 = *v7;
      PopDevStateLockThread = v9 & 0xFFFFFFC0;
      v11 = *(_QWORD *)v10;
      if ( *(int **)(v10 + 4) != v7 || *(_DWORD *)(v11 + 4) != v10 )
        __fastfail(3u);
      *v7 = v11;
      *(_DWORD *)(v11 + 4) = v7;
      v12 = *(int **)(v2 + 240);
      *(_DWORD *)v10 = v2 + 236;
      *(_DWORD *)(v10 + 4) = v12;
      if ( *v12 != v2 + 236 )
        __fastfail(3u);
      *v12 = v10;
      PopDevStateLockThread = 0;
      *(_DWORD *)(v2 + 240) = v10;
      KeReleaseInStackQueuedSpinLock((int)v14);
      --v5;
      ++v4;
      result = PopNotifyDevice((unsigned __int8 *)v2, v10);
      if ( (PopSimulate & 0x80000) != 0 && v4 > 0 )
      {
        do
        {
          result = KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
          --v4;
        }
        while ( v4 > 0 );
      }
    }
    while ( v5 > 0 );
    if ( v4 > 0 )
    {
      do
      {
        result = KeWaitForSingleObject((unsigned int)v15, 0, 0, 0, 0);
        --v4;
      }
      while ( v4 > 0 );
      v2 = a1;
    }
  }
  *(_DWORD *)(v2 + 20) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  return result;
}
