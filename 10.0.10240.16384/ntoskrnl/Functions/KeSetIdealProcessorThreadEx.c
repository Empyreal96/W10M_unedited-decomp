// KeSetIdealProcessorThreadEx 
 
int __fastcall KeSetIdealProcessorThreadEx(int a1, int a2, unsigned int *a3, int a4)
{
  int v5; // r6
  unsigned int v6; // r7
  unsigned int *v9; // r9
  unsigned int v10; // r4
  unsigned int v12; // r4
  int v13; // r3
  int v14; // r3
  unsigned int *v15; // r3
  int v16; // [sp+0h] [bp-28h] BYREF
  unsigned int *v17; // [sp+4h] [bp-24h] BYREF
  int v18; // [sp+8h] [bp-20h]

  v16 = a2;
  v17 = a3;
  v18 = a4;
  v5 = -1073741823;
  v6 = (unsigned int)*(&KiProcessorBlock + a2);
  v18 = KfRaiseIrql(2);
  v9 = (unsigned int *)(a1 + 44);
  do
    v10 = __ldrex(v9);
  while ( __strex(1u, v9) );
  __dmb(0xBu);
  if ( v10 )
    return sub_54EA2C();
  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || (*(_DWORD *)(a1 + 76) & 8) == 0 )
  {
    v12 = *(_DWORD *)(a1 + 364);
    if ( *(unsigned __int8 *)(v6 + 1052) == *(unsigned __int16 *)(a1 + 360)
      && (*(_DWORD *)(a1 + 356) & *(_DWORD *)(v6 + 1048)) != 0 )
    {
      KiAcquireThreadStateLock(a1, &v16, &v17);
      v13 = *(_DWORD *)(a1 + 76);
      *(_DWORD *)(a1 + 364) = a2;
      if ( (v13 & 8) == 0 )
        *(_DWORD *)(a1 + 124) = a2;
      KiUpdateSharedReadyQueueAffinityThread(v6, a1);
      v14 = v16;
      if ( v16 )
      {
        __dmb(0xBu);
        *(_DWORD *)(v14 + 24) = 0;
      }
      v15 = v17;
      if ( v17 )
      {
        __dmb(0xBu);
        *v15 = 0;
      }
      goto LABEL_14;
    }
  }
  else
  {
    v12 = *(_DWORD *)(a1 + 124);
    if ( *(unsigned __int8 *)(v6 + 1052) == *(unsigned __int16 *)(a1 + 344)
      && (*(_DWORD *)(v6 + 1048) & *(_DWORD *)(a1 + 340)) != 0 )
    {
      *(_DWORD *)(a1 + 124) = a2;
LABEL_14:
      v5 = 0;
      goto LABEL_15;
    }
  }
LABEL_15:
  __dmb(0xBu);
  *v9 = 0;
  KfLowerIrql(v18);
  if ( a3 )
    *a3 = v12;
  return v5;
}
