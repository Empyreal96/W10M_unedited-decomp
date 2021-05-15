// NtAssociateWaitCompletionPacket 
 
int __fastcall NtAssociateWaitCompletionPacket(int a1, int a2, int a3, int a4, int a5, int a6, int a7, char *a8)
{
  int v9; // r10
  int v10; // r5
  int v11; // r6
  int v12; // r4
  int v13; // r9
  int v14; // r0
  int v15; // lr
  int v16; // r4
  unsigned int *v17; // r9
  unsigned int v18; // r2
  int v19; // r3
  int v20; // r6
  int v21; // r2
  int v22; // r0
  unsigned int v23; // r2
  unsigned int v24; // r2
  int v25; // r2
  unsigned int v26; // lr
  int v27; // r1
  BOOL v28; // r2
  int v29; // r0
  unsigned int v30; // r2
  unsigned int v31; // r2
  int v32; // r3
  int *v33; // r1
  unsigned int v34; // r1
  unsigned int v35; // r0
  char v36; // r4
  int *v37; // r1
  unsigned int v38; // r1
  char *v39; // r1
  int v41; // [sp+Ch] [bp-44h] BYREF
  int v42; // [sp+10h] [bp-40h] BYREF
  int v43; // [sp+14h] [bp-3Ch] BYREF
  int v44; // [sp+18h] [bp-38h]
  unsigned int v45; // [sp+1Ch] [bp-34h]
  int v46; // [sp+20h] [bp-30h]
  int v47; // [sp+24h] [bp-2Ch]
  int v48; // [sp+28h] [bp-28h]
  int v49; // [sp+2Ch] [bp-24h]

  v45 = a4;
  v44 = a3;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v10 = ObReferenceObjectByHandle(a1, 1, IopWaitCompletionPacketObjectType, v9, &v42, 0);
  v11 = v42;
  v46 = v42;
  if ( v10 >= 0 )
  {
    v10 = ObReferenceObjectByHandle(a2, 2, IoCompletionObjectType, v9, &v41, 0);
    v12 = v41;
    v48 = v41;
    if ( v10 < 0 )
    {
LABEL_81:
      v14 = v11;
      goto LABEL_82;
    }
    v10 = ObReferenceObjectByHandle(v44, 0x100000, 0, v9, &v43, 0);
    v13 = v43;
    v49 = v43;
    v47 = v10;
    if ( v10 < 0 )
    {
      ObfDereferenceObjectWithTag(v11);
      v14 = v12;
LABEL_82:
      ObfDereferenceObjectWithTag(v14);
      return v10;
    }
    v15 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v43 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v43 - 12)];
    v16 = *(_DWORD *)(v15 + 16);
    if ( (v16 & 1) != 0 )
    {
      if ( (v16 & 2) != 0 )
      {
        if ( (*(_DWORD *)(*(unsigned __int16 *)(v15 + 124) + v43) & *(_DWORD *)(v15 + 120)) == *(_DWORD *)(v15 + 120) )
          v16 = *(_DWORD *)(*(unsigned __int16 *)(v15 + 126) + v43);
        else
          v16 = v43 + v16 - 3;
      }
      else
      {
        v16 = *(_DWORD *)(v43 + v16 - 1);
      }
    }
    else if ( v16 >= 0 )
    {
      v16 += v43;
    }
    if ( (char *)v16 == &ObpDefaultObject || !v16 || (*(_BYTE *)v16 & 0x7F) == 2 )
    {
      v10 = -1073741583;
LABEL_80:
      ObfDereferenceObjectWithTag(v41);
      ObfDereferenceObjectWithTag(v13);
      goto LABEL_81;
    }
    v17 = (unsigned int *)(v11 + 48);
    v44 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v11 + 48);
    }
    else
    {
      do
        v18 = __ldrex(v17);
      while ( __strex(1u, v17) );
      __dmb(0xBu);
      if ( v18 )
        KxWaitForSpinLockAndAcquire(v11 + 48);
    }
    v19 = *(unsigned __int8 *)(v11 + 52);
    __dmb(0xBu);
    if ( v19 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v11 + 48);
      }
      else
      {
        __dmb(0xBu);
        *v17 = 0;
      }
      KfLowerIrql(v44);
      v10 = -1073741585;
      v11 = v42;
      v13 = v43;
      goto LABEL_80;
    }
    __dmb(0xBu);
    *(_BYTE *)(v11 + 52) = 1;
    v20 = v42;
    *(_DWORD *)(v42 + 24) = v45;
    *(_DWORD *)(v20 + 28) = a5;
    *(_DWORD *)(v20 + 36) = a6;
    *(_DWORD *)(v20 + 32) = a7;
    *(_DWORD *)(v20 + 40) = v43;
    v21 = v41;
    *(_DWORD *)(v20 + 44) = v41;
    *(_BYTE *)(v20 + 8) = 2;
    *(_BYTE *)(v20 + 9) = 4;
    *(_DWORD *)(v20 + 12) = v21;
    *(_DWORD *)(v20 + 16) = v16;
    v22 = KfRaiseIrql(2);
    v46 = v22;
    do
      v23 = __ldrex((unsigned __int8 *)v16);
    while ( __strex(v23 | 0x80, (unsigned __int8 *)v16) );
    __dmb(0xBu);
    if ( v23 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v16 & 0x80) != 0 );
        do
          v24 = __ldrex((unsigned __int8 *)v16);
        while ( __strex(v24 | 0x80, (unsigned __int8 *)v16) );
        __dmb(0xBu);
      }
      while ( v24 >> 7 );
    }
    v25 = *(_DWORD *)(v16 + 4);
    if ( v25 <= 0 )
    {
      v37 = *(int **)(v16 + 12);
      *(_DWORD *)v20 = v16 + 8;
      *(_DWORD *)(v20 + 4) = v37;
      if ( *v37 != v16 + 8 )
        __fastfail(3u);
      *v37 = v20;
      *(_DWORD *)(v16 + 12) = v20;
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned int *)v16);
      while ( __strex(v38 & 0xFFFFFF7F, (unsigned int *)v16) );
      KfLowerIrql(v22);
      v36 = 0;
    }
    else
    {
      if ( (*(_BYTE *)v16 & 7) == 1 )
      {
        *(_DWORD *)(v16 + 4) = 0;
      }
      else if ( (*(_BYTE *)v16 & 0x7F) == 5 )
      {
        *(_DWORD *)(v16 + 4) = v25 - 1;
      }
      *(_BYTE *)(v20 + 9) = 5;
      *(_DWORD *)v20 = 0;
      v42 = v41 + 8;
      KfRaiseIrql(2);
      v26 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v45 = v26;
      v27 = *(_DWORD *)(v26 + 1412);
      v43 = v27;
      if ( (dword_682604 & 0x1000000) != 0 )
      {
        v28 = *(_BYTE *)(v27 + 132) == 2
           && *(_DWORD *)(v27 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        EtwTraceEnqueueWork(v43, v20, v28);
        v26 = v45;
        v27 = v43;
      }
      v29 = v41;
      do
        v30 = __ldrex((unsigned __int8 *)v29);
      while ( __strex(v30 | 0x80, (unsigned __int8 *)v29) );
      __dmb(0xBu);
      if ( v30 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v29 & 0x80) != 0 );
          do
            v31 = __ldrex((unsigned __int8 *)v29);
          while ( __strex(v31 | 0x80, (unsigned __int8 *)v29) );
          __dmb(0xBu);
        }
        while ( v31 >> 7 );
        v27 = v43;
      }
      if ( *(_DWORD *)(v42 + 4) == v42
        || *(_DWORD *)(v29 + 24) >= *(_DWORD *)(v29 + 28)
        || *(_DWORD *)(v27 + 152) == v29 && *(_BYTE *)(v27 + 395) == 15 )
      {
        v32 = 0;
      }
      else
      {
        v32 = KiWakeQueueWaiter(v26 + 1408, v29, v20);
        v29 = v41;
      }
      if ( !v32 )
      {
        ++*(_DWORD *)(v29 + 4);
        v33 = *(int **)(v29 + 20);
        *(_DWORD *)v20 = v29 + 16;
        *(_DWORD *)(v20 + 4) = v33;
        if ( *v33 != v29 + 16 )
          __fastfail(3u);
        *v33 = v20;
        *(_DWORD *)(v29 + 20) = v20;
      }
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)v29);
      while ( __strex(v34 & 0xFFFFFF7F, (unsigned int *)v29) );
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)v16);
      while ( __strex(v35 & 0xFFFFFF7F, (unsigned int *)v16) );
      KiExitDispatcher(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0, 1, 0, v46);
      v36 = 1;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v17);
    }
    else
    {
      __dmb(0xBu);
      *v17 = 0;
    }
    KfLowerIrql(v44);
    if ( a8 )
    {
      if ( v9 )
      {
        v39 = a8;
        if ( (unsigned int)a8 >= MmUserProbeAddress )
          v39 = (char *)MmUserProbeAddress;
        *v39 = *v39;
      }
      *a8 = v36;
    }
  }
  return v10;
}
