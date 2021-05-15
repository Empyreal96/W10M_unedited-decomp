// PopEndMirroring 
 
int __fastcall PopEndMirroring(int a1)
{
  int v2; // r4
  int v3; // r3
  int v4; // r0
  int v5; // r0
  unsigned int v6; // r6
  unsigned int v7; // r2
  int v8; // r10
  int v9; // r3
  int v11[4]; // [sp+10h] [bp-50h] BYREF
  char v12[2]; // [sp+20h] [bp-40h] BYREF
  __int16 v13; // [sp+22h] [bp-3Eh]

  if ( a1 )
  {
    if ( a1 != 1 )
    {
      v2 = -1073741823;
      goto LABEL_4;
    }
    v2 = *(_DWORD *)(dword_61EC98 + 120);
    if ( v2 >= 0 )
    {
      v2 = PopInvokeSystemStateHandler(PopHibernatePowerStateHandlerType);
      if ( v2 >= 0 )
      {
        if ( PoResumeFromHibernate )
          v2 = 1073742484;
        goto LABEL_25;
      }
    }
LABEL_4:
    IoAddTriageDumpDataBlock((int)PopAction, 256);
    if ( dword_61EC94 )
      IoAddTriageDumpDataBlock(dword_61EC94, 260);
    if ( dword_61EC98 )
    {
      IoAddTriageDumpDataBlock(dword_61EC98, 312);
      v3 = dword_61EC98;
      v4 = *(_DWORD *)(dword_61EC98 + 108);
      if ( v4 )
      {
        IoAddTriageDumpDataBlock(v4, 256);
        v3 = dword_61EC98;
      }
      v5 = *(_DWORD *)(v3 + 128);
      if ( v5 )
        IoAddTriageDumpDataBlock(v5, 784);
    }
    KeBugCheckEx(160, 9, v2, a1, 0);
  }
  if ( (dword_682614 & 1) != 0 )
    EtwKernelMemoryRundown();
  KeSetEvent(PopSleeperHandoff, 0, 1);
  KeWaitForSingleObject(PopSleeperHandoff + 16, 0, 0, 0, 0);
  v2 = PopBuildMemoryImageHeader(dword_61EC98, 0);
  if ( v2 < 0 )
    goto LABEL_4;
  v11[1] = 0;
  v11[2] = 0;
  v11[0] = 1;
  KeSetSystemGroupAffinityThread((int)v11, 0);
  KfRaiseIrql(2);
  memset(PopHibernateSystemContext, 0, 56);
  dword_61F29C = KeNumberProcessors_0;
  dword_61F2A8 = KeNumberProcessors_0;
  __dmb(0xBu);
  dword_61F2A4 = 1;
  unk_61F2B0 = 0;
  unk_61F2B4 = 0;
  KeInitializeDpc((int)v12, (int)PopInvokeStateHandlerTargetProcessor, (int)PopHibernateSystemContext);
  v6 = dword_681D78[0];
  v12[1] = 2;
  while ( v6 )
  {
    v7 = __clz(__rbit(v6));
    v6 &= ~(1 << v7);
    if ( v7 )
    {
      v8 = dword_61F2A0;
      v13 = v7 + 32;
      KeInsertQueueDpc((int)v12);
      do
      {
        v9 = dword_61F2A0;
        __dmb(0xBu);
      }
      while ( v8 == v9 );
    }
  }
LABEL_25:
  if ( v2 != 1073742484 )
    v2 = 0;
  return v2;
}
