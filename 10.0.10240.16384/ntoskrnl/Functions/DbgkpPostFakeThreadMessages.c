// DbgkpPostFakeThreadMessages 
 
int __fastcall DbgkpPostFakeThreadMessages(int a1, int a2, int a3, int *a4, int *a5)
{
  _DWORD *v5; // r5
  int v7; // r9
  int v8; // r6
  int v9; // r8
  unsigned int *v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r1
  int v13; // r4
  int v14; // r0
  int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int *v18; // r0
  unsigned int v19; // r4
  int v21; // [sp+4h] [bp-124h]
  int v22; // [sp+8h] [bp-120h]
  int v23; // [sp+Ch] [bp-11Ch]
  int v24; // [sp+18h] [bp-110h]
  unsigned int v27; // [sp+24h] [bp-104h]
  _DWORD v28[42]; // [sp+48h] [bp-E0h] BYREF
  _BYTE v29[56]; // [sp+F0h] [bp-38h] BYREF

  v5 = (_DWORD *)a3;
  v7 = 0;
  v8 = 0;
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = -1073741823;
  if ( a3 )
  {
    v23 = 0;
    LOBYTE(v22) = 0;
    v7 = a3;
    ObfReferenceObjectWithTag(a3);
  }
  else
  {
    v5 = PsGetNextProcessThread(a1, 0);
    v23 = 1;
    LOBYTE(v22) = 1;
  }
  while ( v5 )
  {
    if ( v8 )
      ObfDereferenceObjectWithTag(v8);
    v8 = (int)v5;
    ObfReferenceObjectWithTag((int)v5);
    if ( (v5[19] & 0x400) == 0 )
    {
      if ( (v5[240] & 2) != 0 || (PsSynchronizeWithThreadInsertion(v5, v27), (v5[240] & 2) != 0) )
      {
        v10 = v5 + 235;
        __pld(v5 + 235);
        v11 = v5[235] & 0xFFFFFFFE;
        do
          v12 = __ldrex(v10);
        while ( v12 == v11 && __strex(v11 + 2, v10) );
        __dmb(0xBu);
        if ( v12 == v11 || ExfAcquireRundownProtection(v10) )
        {
          v13 = 10;
          if ( PsSuspendThread((int)v5, 0) >= 0 )
            v13 = 42;
        }
        else
        {
          v13 = 18;
        }
        memset(v28, 0, sizeof(v28));
        if ( !v23 || (v13 & 0x10) != 0 )
        {
          v24 = 0;
          v28[6] = 1;
          v28[9] = v5[231];
        }
        else
        {
          v24 = 1;
          BYTE1(v22) = 1;
          v28[6] = 2;
          v14 = *(_DWORD *)(a1 + 292);
          if ( v14 )
            v28[9] = DbgkpSectionToFileHandle(v14);
          else
            v28[9] = 0;
          v28[10] = *(_DWORD *)(a1 + 296);
          KiStackAttachProcess(a1, 0, (int)v29);
          v15 = RtlImageNtHeader(*(_DWORD *)(a1 + 296));
          if ( v15 )
          {
            v28[14] = 0;
            v28[11] = *(_DWORD *)(v15 + 12);
            v28[12] = *(_DWORD *)(v15 + 16);
          }
          KiUnstackDetachProcess((unsigned int)v29, 0);
        }
        v9 = DbgkpQueueMessage(a1, v5, v28, v13, a2, v21, v22);
        if ( v9 < 0 )
        {
          if ( (v13 & 0x20) != 0 )
            PsResumeThread((int)v5, 0);
          if ( (v13 & 8) != 0 )
          {
            v18 = v5 + 235;
            __pld(v5 + 235);
            v19 = v5[235] & 0xFFFFFFFE;
            __dmb(0xBu);
            v17 = v19 - 2;
            do
              v16 = __ldrex(v18);
            while ( v16 == v19 && __strex(v17, v18) );
            if ( v16 != v19 )
              ExfReleaseRundownProtection((unsigned __int8 *)v18);
          }
          if ( v28[6] == 2 && v28[9] )
            ObCloseHandle(v28[9]);
          PsQuitNextProcessThread(v5, v16, v17);
          break;
        }
        if ( v24 )
        {
          v23 = 0;
          LOBYTE(v22) = 0;
          ObfReferenceObjectWithTag((int)v5);
          v7 = (int)v5;
          DbgkSendSystemDllMessages((int)v5, a2, v28);
        }
      }
    }
    v5 = PsGetNextProcessThread(a1, (int)v5);
  }
  if ( v9 >= 0 )
  {
    if ( v7 )
    {
      *a4 = v7;
      *a5 = v8;
    }
    else
    {
      if ( v8 )
        ObfDereferenceObjectWithTag(v8);
      v9 = -1073741823;
    }
  }
  else
  {
    if ( v7 )
      ObfDereferenceObjectWithTag(v7);
    if ( v8 )
      ObfDereferenceObjectWithTag(v8);
  }
  return v9;
}
