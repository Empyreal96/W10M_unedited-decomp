// KiStartDynamicProcessor 
 
int KiStartDynamicProcessor(int a1, ...)
{
  int v1; // r6
  int v2; // r8
  int v3; // r10
  int v4; // r9
  int v5; // r5
  bool v6; // nf
  int v7; // r4
  int v8; // r5
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  void *v14; // r9
  int v15; // r8
  int v16; // r1
  int v17; // r2
  void *v18; // r7
  unsigned __int16 v20; // [sp+20h] [bp-4A0h] BYREF
  int v21; // [sp+24h] [bp-49Ch]
  int v22; // [sp+28h] [bp-498h]
  unsigned int v23; // [sp+2Ch] [bp-494h]
  int v24; // [sp+30h] [bp-490h]
  int v25; // [sp+34h] [bp-48Ch] BYREF
  int v26; // [sp+38h] [bp-488h]
  void *v27; // [sp+3Ch] [bp-484h]
  int v28; // [sp+40h] [bp-480h]
  int v29; // [sp+44h] [bp-47Ch]
  int v30[46]; // [sp+48h] [bp-478h] BYREF
  char var3C0[964]; // [sp+100h] [bp-3C0h] BYREF
  int varg_r1; // [sp+4CCh] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+4CCh] [bp+Ch]
  int varg_r2; // [sp+4D0h] [bp+10h]
  int varg_r3; // [sp+4D4h] [bp+14h]
  va_list va1; // [sp+4D8h] [bp+18h] BYREF

  va_start(va1, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(va1, _DWORD);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v22 = varg_r3;
  v1 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v2 = 0;
  v21 = 0;
  v3 = 0;
  v4 = 0;
  v20 = 0;
  if ( (unsigned int)KeNumberProcessors_0 >= 0x20
    || KeNumprocSpecified && KeNumberProcessors_0 >= (unsigned int)KeNumprocSpecified )
  {
    v5 = -1073741223;
LABEL_36:
    v6 = v5 < 0;
LABEL_37:
    if ( !v6 )
      return v5;
    v7 = v24;
    goto LABEL_40;
  }
  v5 = HalRegisterDynamicProcessor(KeRegisteredProcessors);
  if ( v5 < 0 )
  {
    v7 = 0;
    goto LABEL_44;
  }
  v20 = varg_r2;
  v5 = KiQueryProcessorNode(v22, (int)varg_r1a, &v20);
  v6 = v5 < 0;
  if ( v5 )
    goto LABEL_37;
  KiAdjustGroupConfiguration((unsigned int)*(&KeNodeBlock + v20));
  v23 = KiComputeProcessorDataSize(KeMaximumProcessors);
  v7 = MmAllocateIndependentPages(v23, v20);
  v24 = v7;
  if ( v7 )
  {
    v8 = v22;
    v28 = ExCreatePoolTagTable(v22, v20);
    if ( v28 )
    {
      v2 = MmCreateKernelStack(0, v20, 0);
      v21 = v2;
      if ( v2 )
      {
        v4 = MmCreateKernelStack(0, v20, 0);
        v29 = v4;
        if ( v4 )
        {
          if ( !MmAllocateIsrStack(&v25, v20) )
          {
            v5 = -1073741670;
            v3 = v25;
            goto LABEL_44;
          }
          v27 = *(&KeNodeBlock + v20);
          memset(v30, 0, sizeof(v30));
          v3 = v25;
          v7 = v24;
          v30[4] = PsLoadedModuleList;
          v30[5] = dword_62127C;
          v1 = KiInitializeProcessorState(
                 (int)var3C0,
                 (int)v30,
                 v24,
                 1,
                 v23,
                 v20,
                 v8,
                 KeMaximumProcessors,
                 v21,
                 v4,
                 v25);
          v26 = (int)*(&KeNodeBlock + v20);
          if ( !MmInitializeProcessor((_DWORD *)v1) )
          {
            v5 = -1073741823;
LABEL_40:
            if ( v1 )
              KiRemoveProcessorFromGroupDatabase(v1);
            v2 = v21;
            goto LABEL_44;
          }
          v5 = KiInitializePrcbContext(v1);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = KeInitializeTimerTable(v1);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = ExInitializeProcessor(v1, 1);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = ObInitializeProcessor((_DWORD *)v1);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = IoInitializeProcessor(v1, 0);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = CcInitializeProcessor(v1);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = EtwInitializeProcessor(v1);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = WheaInitializeProcessor(v1, 0);
          if ( v5 < 0 )
            goto LABEL_40;
          v5 = xHalTimerWatchdogStop();
          if ( v5 < 0 )
            goto LABEL_40;
          MiLockPagableImageSection(ExPageLockHandle, 1, v9, v10);
          KiAddProcessorToGroupSchedulingDatabase(v1, v11, v12, v13);
          KiBarrierWait = 1;
          v14 = KeLoaderBlock_0;
          if ( !KeLoaderBlock_0 )
          {
            v30[4] = PsLoadedModuleList;
            v30[5] = dword_62127C;
            KeLoaderBlock_0 = v30;
          }
          v5 = KiDynamicProcessorAddNotification(
                 0,
                 *(_DWORD *)(v1 + 20),
                 *(unsigned __int8 *)(v1 + 1052),
                 *(_BYTE *)(v1 + 1053),
                 varg_r1,
                 0);
          v15 = 2;
          if ( v5 >= 0 )
          {
            if ( HalStartDynamicProcessor(var3C0, v22, varg_r1, v20) )
            {
              while ( v30[19] )
              {
                __dmb(0xAu);
                __yield();
              }
              KiInitializeDynamicProcessor(v1, v16, v17, 0);
              v15 = 1;
            }
            else
            {
              v5 = -1073741823;
            }
          }
          KiDynamicProcessorAddNotification(
            v15,
            *(_DWORD *)(v1 + 20),
            *(unsigned __int8 *)(v1 + 1052),
            *(_BYTE *)(v1 + 1053),
            varg_r1,
            v5);
          if ( v5 >= 0 )
          {
            WheaInitializeProcessor(v1, 1);
            CmInitializeProcessor(v1);
          }
          KeLoaderBlock_0 = v14;
          MmUnlockPagableImageSection(ExPageLockHandle);
          v4 = v29;
          goto LABEL_36;
        }
      }
    }
  }
  v5 = -1073741670;
LABEL_44:
  __dmb(0xBu);
  v18 = v27;
  KiBarrierWait = 0;
  if ( v27 )
  {
    memmove((int)v27, v26, 0x180u);
    *(&KeNodeBlock + v20) = v18;
  }
  if ( v1 )
  {
    MmDeleteProcessor(v1);
    EtwDeleteProcessor(v1);
  }
  if ( v28 )
    ExDeletePoolTagTable(v22);
  if ( v7 )
    MmFreeIndependentPages(v7, v23);
  if ( v2 )
    MmDeleteKernelStack(v2, 0);
  if ( v4 )
    MmDeleteKernelStack(v4, 0);
  if ( v3 )
    MmFreeIsrStack(v3);
  return v5;
}
