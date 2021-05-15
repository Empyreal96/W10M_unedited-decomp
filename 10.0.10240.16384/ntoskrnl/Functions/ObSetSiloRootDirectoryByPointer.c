// ObSetSiloRootDirectoryByPointer 
 
int __fastcall ObSetSiloRootDirectoryByPointer(int a1, int a2, char a3)
{
  int v5; // r4
  _BYTE *v6; // r0
  _DWORD *v7; // r6
  int v8; // r8
  unsigned int v9; // r2
  int v10; // r9
  unsigned __int8 *v11; // r5
  int v12; // r0
  int v13; // r7
  unsigned int v14; // r2
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v22; // [sp+8h] [bp-48h]
  int v23; // [sp+Ch] [bp-44h] BYREF
  char v24[8]; // [sp+10h] [bp-40h] BYREF
  int v25; // [sp+18h] [bp-38h]
  int v26; // [sp+1Ch] [bp-34h]
  char *v27; // [sp+20h] [bp-30h]
  int v28; // [sp+24h] [bp-2Ch]
  int v29; // [sp+28h] [bp-28h]
  int v30; // [sp+2Ch] [bp-24h]

  v5 = ObReferenceObjectByHandle(a2, 2, ObpDirectoryObjectType, a3, (int)&v23, 0);
  if ( v5 >= 0 )
  {
    v5 = PsInsertSiloObjectByPointer(a1, &ObpDirectoryObjectType, v23);
    if ( v5 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v24, L"Global??");
      v25 = 24;
      v26 = a2;
      v28 = 576;
      v27 = v24;
      v29 = 0;
      v30 = 0;
      v5 = ZwOpenDirectoryObject();
      if ( v5 >= 0 )
      {
        v5 = ObReferenceObjectByHandle(v22, 2, ObpDirectoryObjectType, 0, (int)&v23, 0);
        if ( v5 >= 0 )
        {
          v6 = (_BYTE *)ExAllocatePoolWithTag(1, 52, 1833198159);
          v7 = v6;
          if ( !v6 )
          {
            ZwClose();
            ObfDereferenceObject(v23);
            return -1073741670;
          }
          memset(v6, 0, 52);
          v8 = v23;
          *v7 = v23;
          v7[3] = 1;
          PsGetMonitorContextServerSilo(ObSiloMonitor, -1, &v23);
          v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v9 + 310);
          v10 = v23;
          v11 = (unsigned __int8 *)(v23 + 112);
          v12 = KeAbPreAcquire(v23 + 112, 0, 0);
          v13 = v12;
          do
            v14 = __ldrex(v11);
          while ( __strex(v14 | 1, v11) );
          __dmb(0xBu);
          if ( (v14 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v11, v12, (unsigned int)v11);
          if ( v13 )
            *(_BYTE *)(v13 + 14) |= 1u;
          if ( !*(_DWORD *)(v8 + 152) )
          {
            *(_DWORD *)(v8 + 152) = v7;
            v7 = 0;
          }
          __pld(v11);
          v15 = *(_DWORD *)v11;
          v16 = *(_DWORD *)v11 - 16;
          if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
            v16 = 0;
          if ( (v15 & 2) != 0 )
            goto LABEL_23;
          __dmb(0xBu);
          do
            v17 = __ldrex((unsigned int *)v11);
          while ( v17 == v15 && __strex(v16, (unsigned int *)v11) );
          if ( v17 != v15 )
LABEL_23:
            ExfReleasePushLock(v11, v15);
          v18 = KeAbPostRelease((unsigned int)v11);
          v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v20 = *(_WORD *)(v19 + 0x136) + 1;
          *(_WORD *)(v19 + 310) = v20;
          if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
            KiCheckForKernelApcDelivery(v18);
          PsDereferenceMonitorContextServerSilo(v10);
          if ( v7 )
          {
            ExFreePoolWithTag((unsigned int)v7);
            ObfDereferenceObject(v8);
          }
        }
        ZwClose();
        return v5;
      }
    }
    else
    {
      ObfDereferenceObject(v23);
    }
  }
  return v5;
}
