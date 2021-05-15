// ExpAllocateAsid 
 
unsigned int __fastcall ExpAllocateAsid(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  unsigned int v5; // r5
  int v6; // r8
  unsigned int v7; // r0
  int v8; // r7
  int v9; // r2
  unsigned int v10; // r6
  _DWORD *v11; // r1
  unsigned int v12; // r5
  _DWORD v14[10]; // [sp+0h] [bp-28h] BYREF

  v14[0] = a1;
  v14[1] = a2;
  v14[2] = a3;
  v14[3] = a4;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
LABEL_14:
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_619EF0, (unsigned int)v14);
  v7 = dword_619EE4;
  while ( 1 )
  {
    v9 = dword_619EE8;
    v10 = v7;
    if ( v7 != dword_619EE8 )
      break;
    if ( v7 == ExpSvmAgents )
    {
      KeReleaseInStackQueuedSpinLock((int)v14);
      return 0;
    }
    KeReleaseInStackQueuedSpinLock((int)v14);
    v5 = v10 + 8;
    if ( v10 + 8 > v10 )
    {
      if ( v5 > ExpSvmAgents )
        v5 = ExpSvmAgents;
    }
    else
    {
      v5 = ExpSvmAgents;
    }
    v6 = ExAllocatePoolWithTag(512, 8 * v5);
    if ( !v6 )
      return 0;
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_619EF0, (unsigned int)v14);
    v7 = dword_619EE4;
    v8 = v6;
    if ( v10 == dword_619EE4 )
    {
      v8 = dword_619EEC;
      if ( dword_619EEC )
        memmove(v6, dword_619EEC, 8 * v10);
      memset((_BYTE *)(v6 + 8 * v10), 0, 8 * (v5 - v10));
      dword_619EEC = v6;
      dword_619EE4 = v5;
      v7 = v5;
    }
    if ( v8 )
    {
      KeReleaseInStackQueuedSpinLock((int)v14);
      ExFreePoolWithTag(v8);
      goto LABEL_14;
    }
  }
  v11 = (_DWORD *)dword_619EEC;
  v12 = 0;
  if ( v7 )
  {
    while ( *v11 )
    {
      ++v12;
      v11 += 2;
      if ( v12 >= v7 )
        goto LABEL_23;
    }
    *v11 = v4;
    v11[1] = 1;
    v9 = dword_619EE8;
  }
LABEL_23:
  dword_619EE8 = v9 + 1;
  KeReleaseInStackQueuedSpinLock((int)v14);
  return v12 + 1;
}
