// PnpRemoveEventFromQueue 
 
int __fastcall PnpRemoveEventFromQueue(_DWORD *a1)
{
  int v2; // r7
  int v3; // r6
  int v4; // r5
  int v5; // r8
  unsigned int v6; // r2
  _DWORD *v7; // r2
  _DWORD *v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  unsigned int *v12; // r4
  int v13; // r5
  unsigned int v14; // r1

  v2 = 0;
  v3 = PnpDeviceEventList + 36;
  v4 = KeAbPreAcquire(PnpDeviceEventList + 36, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended(v3, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v3 + 28) = v5;
  v7 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 != a1 )
  {
    v8 = (_DWORD *)a1[1];
    if ( (_DWORD *)v7[1] != a1 || (_DWORD *)*v8 != a1 )
      __fastfail(3u);
    *v8 = v7;
    v7[1] = v8;
    v2 = 1;
    __dmb(0xBu);
    v9 = a1 + 8;
    do
    {
      v10 = __ldrex(v9);
      v11 = v10 - 1;
    }
    while ( __strex(v11, v9) );
    __dmb(0xBu);
    if ( !v11 )
      ExFreePoolWithTag((unsigned int)a1);
  }
  v12 = (unsigned int *)(PnpDeviceEventList + 36);
  v13 = *(_DWORD *)(PnpDeviceEventList + 64);
  *(_DWORD *)(PnpDeviceEventList + 40) = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex(v12);
  while ( !v14 && __strex(1u, v12) );
  if ( v14 )
    ExpReleaseFastMutexContended(v12, v14);
  KfLowerIrql((unsigned __int8)v13);
  KeAbPostRelease((unsigned int)v12);
  return v2;
}
