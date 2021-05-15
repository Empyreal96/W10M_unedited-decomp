// KeInitializeTimerTable 
 
int __fastcall KeInitializeTimerTable(int a1)
{
  int v2; // r1
  _DWORD *v3; // r2
  int v5; // r6
  void *v6; // r5
  int *v7; // r2
  _BYTE *v8; // r0

  if ( !*(_DWORD *)(a1 + 20) )
  {
    if ( !KiSerializeTimerExpiration )
      return sub_7D09F0();
    if ( KiSerializeTimerExpiration != 1 )
      JUMPOUT(0x7D0A02);
    KiInitializeTimer2Data();
  }
  if ( !KiPendingTimerBitmaps[2 * *(unsigned __int8 *)(a1 + 1052) + 1] )
  {
    v5 = 0x8000;
    if ( *(_BYTE *)(a1 + 1052) )
    {
      if ( KiSerializeTimerExpiration )
      {
        v6 = 0;
      }
      else
      {
        v8 = (_BYTE *)ExAllocatePoolWithTag(516, 0x8000, 1649698123);
        v6 = v8;
        if ( !v8 )
          return -1073741670;
        memset(v8, 0, 0x8000);
      }
    }
    else
    {
      v6 = &KiPendingTimersMask0;
      if ( KiSerializeTimerExpiration )
        v5 = 32;
    }
    v7 = &KiPendingTimerBitmaps[2 * *(unsigned __int8 *)(a1 + 1052)];
    *v7 = 8 * v5;
    v7[1] = (int)v6;
  }
  *(_DWORD *)(a1 + 1764) = KeTickCount;
  KeInitializeDpc(a1 + 1944, (int)KiTimerExpirationDpc, 0);
  v2 = 256;
  *(_WORD *)(a1 + 1946) = *(_DWORD *)(a1 + 20) + 32;
  v3 = (_DWORD *)(a1 + 4352);
  do
  {
    *v3 = 0;
    v3[1] = v3 + 1;
    v3[2] = v3 + 1;
    v3[4] = 0;
    v3[5] = -1;
    v3 += 6;
    --v2;
  }
  while ( v2 );
  return 0;
}
