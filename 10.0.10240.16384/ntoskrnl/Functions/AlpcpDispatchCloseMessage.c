// AlpcpDispatchCloseMessage 
 
int __fastcall AlpcpDispatchCloseMessage(int *a1, int a2, int a3, int a4)
{
  int v4; // r8
  int v6; // r5
  _DWORD *v7; // r9
  int result; // r0
  int v9; // r7
  int v10; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1
  int v14; // r3
  signed int v15; // r0
  int v16; // r3
  unsigned int *v17; // r8
  unsigned int v18; // r2
  int v19; // r8
  int v20; // r3
  unsigned int *v21; // r5
  unsigned int v22; // r2
  int v23; // [sp+0h] [bp-28h] BYREF
  int v24[9]; // [sp+4h] [bp-24h] BYREF

  v23 = a2;
  v24[0] = a3;
  v24[1] = a4;
  v4 = *a1;
  v6 = a1[1];
  a1[3] = 0;
  a1[4] = 0;
  a1[5] = 0;
  v7 = *(_DWORD **)(v4 + 8);
  result = AlpcpReferenceAndLockTargetPortsAndCommunicationInfo(v4, v24, &v23);
  if ( result >= 0 )
  {
    v9 = v24[0];
    if ( (*(_DWORD *)(v24[0] + 152) & 0x20000) != 0 )
    {
      *(_DWORD *)(v6 + 20) |= 0x200u;
      *(_WORD *)(v6 + 124) &= 0xDFFFu;
      __dmb(0xBu);
      v10 = v23;
      v11 = (unsigned int *)(v23 + 232);
      do
      {
        v12 = __ldrex(v11);
        v13 = v12 + 1;
      }
      while ( __strex(v13, v11) );
      __dmb(0xBu);
      *(_DWORD *)(v6 + 24) = v13;
      v14 = *(_DWORD *)(v10 + 28);
      *(_DWORD *)(v6 + 92) = v7;
      *(_DWORD *)(v6 + 64) = v14;
      *(_DWORD *)(v6 + 96) = *v7;
      if ( (*(_DWORD *)(v4 + 152) & 0x1000) != 0 )
      {
        ObfReferenceObject(v10);
        v20 = *(_DWORD *)(v6 + 20);
        *(_DWORD *)(v6 + 12) = v10;
        v19 = 1;
        *(_DWORD *)(v6 + 20) = v20 | 0x1000;
      }
      else
      {
        v15 = ObfReferenceObject(v4);
        v16 = *(_DWORD *)(v6 + 20);
        *(_DWORD *)(v6 + 12) = v4;
        *(_DWORD *)(v6 + 20) = v16 | 0x1000;
        if ( v10 != v9 )
        {
          v17 = (unsigned int *)(v10 + 208);
          __dmb(0xBu);
          do
            v18 = __ldrex(v17);
          while ( v18 == 17 && __strex(0, v17) );
          if ( v18 != 17 )
            return sub_807754(v15, 0);
          KeAbPostRelease(v10 + 208);
        }
        v19 = 0;
      }
      if ( AlpcpLogEnabled )
        AlpcpLogClosePort(v6);
      a1[4] = v9;
      a1[2] = (int)v7;
      AlpcpCompleteDispatchMessage((int)a1);
      if ( v19 && v10 != v9 )
      {
        v21 = (unsigned int *)(v10 + 208);
        __dmb(0xBu);
        do
          v22 = __ldrex(v21);
        while ( v22 == 17 && __strex(0, v21) );
        if ( v22 != 17 )
          ExfReleasePushLockShared((_DWORD *)(v10 + 208));
        KeAbPostRelease(v10 + 208);
      }
      ObfDereferenceObject(v10);
      result = 0;
    }
    else
    {
      AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo((int)v7, v24[0], v23);
      result = -1073740025;
    }
  }
  return result;
}
