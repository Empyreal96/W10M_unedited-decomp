// NtAlpcRevokeSecurityContext 
 
int __fastcall NtAlpcRevokeSecurityContext(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r4
  char v7; // r3
  int v8; // r7
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned __int8 *v14; // r6
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r1
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r1
  int v23[6]; // [sp+8h] [bp-18h] BYREF

  v23[0] = a4;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  if ( a2 )
  {
    v6 = -1073741811;
  }
  else
  {
    v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v7, (int)v23, 0);
    v6 = a1;
    if ( a1 >= 0 )
    {
      v8 = v23[0];
      v9 = AlpcReferenceBlobByHandle((_DWORD *)(*(_DWORD *)(v23[0] + 8) + 20), a3, AlpcSecurityType);
      v10 = v9;
      if ( v9 )
      {
        if ( v8 == *(_DWORD *)(v9 + 12) )
        {
          v14 = (unsigned __int8 *)(v9 - 4);
          v15 = KeAbPreAcquire(v9 - 4, 0, 0);
          v16 = v15;
          do
            v17 = __ldrex(v14);
          while ( __strex(v17 | 1, v14) );
          __dmb(0xBu);
          if ( (v17 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx((_DWORD *)(v10 - 4), v15, v10 - 4);
          if ( v16 )
            *(_BYTE *)(v16 + 14) |= 1u;
          v18 = *(_DWORD *)(v10 + 76);
          if ( (v18 & 2) != 0 )
          {
            v6 = -1073741823;
          }
          else
          {
            *(_DWORD *)(v10 + 76) = v18 | 1;
            v6 = 0;
          }
          __dmb(0xBu);
          do
            v19 = __ldrex((unsigned int *)v14);
          while ( __strex(v19 - 1, (unsigned int *)v14) );
          if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v10 - 4));
          KeAbPostRelease(v10 - 4);
        }
        else
        {
          v6 = -1073741790;
        }
        __dmb(0xBu);
        v20 = (unsigned int *)(v10 - 12);
        do
        {
          v21 = __ldrex(v20);
          v22 = v21 - 1;
        }
        while ( __strex(v22, v20) );
        __dmb(0xBu);
        if ( v22 <= 0 )
        {
          if ( v22 )
            KeBugCheckEx(24, 0, v10, 33, v22);
          AlpcpDestroyBlob(v10);
        }
      }
      else
      {
        v6 = -1073741816;
      }
      a1 = ObfDereferenceObject(v8);
    }
  }
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v6;
}
