// sub_7F2AA0 
 
unsigned int sub_7F2AA0()
{
  int v0; // r8
  int v1; // r4
  unsigned int v2; // r5
  unsigned int *v3; // r6
  char v4; // r7
  int v5; // r10
  int *v6; // r4
  int v7; // r5
  _DWORD *v8; // r7
  int v9; // r1
  int v10; // r0
  int *v11; // r2
  __int64 v12; // kr00_8
  unsigned int v13; // r1

  ExpAcquireFastMutexContended((int)v3, v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= v4;
  v3[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = (int *)PopPowerSettings;
  v3[7] = v2;
  if ( v6 != &PopPowerSettings )
  {
    do
    {
      v7 = v6[2];
      v8 = v6 + 2;
      if ( (int *)v7 != v6 + 2 )
      {
        do
        {
          if ( *(_BYTE *)(v7 + 52) )
          {
            v7 = *(_DWORD *)v7;
          }
          else
          {
            *(_BYTE *)(v7 + 52) = 1;
            if ( *(_DWORD *)(v7 + 36) != v6[v5 + 12] )
              PopCallPowerSettingCallback(v7);
            v0 = *(_DWORD *)v7;
            *(_BYTE *)(v7 + 52) = 0;
            if ( *(_BYTE *)(v7 + 17) || *(_BYTE *)(v7 + 16) )
              PopUnregisterPowerSettingCallback(v7);
            v7 = v0;
          }
        }
        while ( (_DWORD *)v7 != v8 );
        v3 = (unsigned int *)&PopSettingLock;
      }
      if ( (_DWORD *)*v8 != v8 || v6[10] || v6[11] )
        goto LABEL_16;
      v9 = 1;
      v10 = 3;
      v11 = v6;
      do
      {
        if ( v11[12] )
          v9 = 0;
        ++v11;
        --v10;
      }
      while ( v10 );
      if ( !v9 )
      {
LABEL_16:
        v6 = (int *)*v6;
      }
      else
      {
        v12 = *(_QWORD *)v6;
        if ( *(int **)(*v6 + 4) != v6 || *(int **)HIDWORD(v12) != v6 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v12) = v12;
        *(_DWORD *)(v12 + 4) = HIDWORD(v12);
        ExFreePoolWithTag((unsigned int)v6);
        v6 = (int *)v12;
      }
    }
    while ( v6 != &PopPowerSettings );
    v2 = v3[7];
  }
  v3[1] = 0;
  __dmb(0xBu);
  do
    v13 = __ldrex(v3);
  while ( !v13 && __strex(1u, v3) );
  if ( v13 )
    ExpReleaseFastMutexContended(v3, v13);
  KfLowerIrql((unsigned __int8)v2);
  return KeAbPostRelease((unsigned int)v3);
}
