// sub_7C1270 
 
void __fastcall sub_7C1270(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // r8
  int *v13; // r9
  unsigned int v14; // r2
  int v15; // r3
  int v16; // r0
  int *v17; // r3
  _BYTE *v18; // r4
  _DWORD *v19; // r5
  unsigned int v20; // r7
  int v21; // r9
  int v22; // r8
  int v23; // r1
  int v24; // r2
  _DWORD *v25; // r10
  unsigned __int8 v26; // r5
  unsigned int v27; // r1
  int *v28; // [sp+20h] [bp+20h]
  int v29; // [sp+20h] [bp+20h]

  v22 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
  v23 = KfRaiseIrql(1);
  v29 = v23;
  do
    v24 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
  while ( __strex(v24 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
  __dmb(0xBu);
  if ( (v24 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&PiUEventClientRegistrationListLock, v22);
    v23 = v29;
  }
  if ( v22 )
    *(_BYTE *)(v22 + 14) |= 1u;
  dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6308FC = v23;
  v17 = &PiUEventDevHandleClientList[2 * PiUEventHashStringIntoBucket(v21, v23, v24, dword_6308E4)];
  v13 = (int *)*v17;
  v28 = v17;
  if ( (int *)*v17 != v17 )
  {
    v25 = &v18[4 * v20];
    do
    {
      v12 = (int)v13;
      v13 = (int *)*v13;
      if ( (!a10 || !*(_BYTE *)(v12 + 20)) && !wcsicmp(a9, *(unsigned __int16 **)(*(_DWORD *)(v12 + 12) + 12)) )
      {
        if ( PiUEventApplyAdditionalFilters(v19, v12) )
        {
          v16 = PiUEventNotifyClient((int)v19, v12, v14, v15);
          if ( v18 )
          {
            if ( v16 >= 0 )
            {
              if ( v20 >= 0x400 )
              {
                a12 = 1;
              }
              else
              {
                ++v20;
                *v25++ = *(_DWORD *)(v12 + 28);
              }
            }
          }
        }
      }
    }
    while ( v13 != v28 );
  }
  if ( v18 && v20 > 1 )
  {
    if ( a12 )
    {
      memset(v18, 0, 4096);
      *(_DWORD *)v18 = -1;
    }
    else
    {
      *(_DWORD *)v18 = v20 - 1;
    }
    ZwUpdateWnfStateData();
  }
  dword_6308E4 = 0;
  v26 = dword_6308FC;
  __dmb(0xBu);
  do
    v27 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
  while ( !v27 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
  if ( v27 )
    ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v27);
  KfLowerIrql(v26);
  KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
  if ( v18 )
    ExFreePoolWithTag((unsigned int)v18);
  JUMPOUT(0x6A8F4A);
}
