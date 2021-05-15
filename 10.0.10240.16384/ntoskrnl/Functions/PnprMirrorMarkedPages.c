// PnprMirrorMarkedPages 
 
int PnprMirrorMarkedPages()
{
  int v0; // r9
  _DWORD *v1; // r0
  int v2; // r10
  BOOL v3; // r8
  _DWORD *v4; // r5
  unsigned int i; // r0
  unsigned __int64 v6; // r2
  int v7; // r4
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int j; // r3
  int v14; // [sp+8h] [bp-30h] BYREF
  int (__fastcall *v15)(_DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int); // [sp+Ch] [bp-2Ch]
  int v16[10]; // [sp+10h] [bp-28h] BYREF

  v0 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v1 = (_DWORD *)PnprContext;
  v2 = 0;
  if ( *(_DWORD *)(*(_DWORD *)(PnprContext + 104) + 12 * v0) )
  {
    v15 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int))(PnprContext + 580);
    v3 = v0 == *(_DWORD *)(PnprContext + 128);
    do
    {
      v4 = (_DWORD *)v1[28];
      while ( 2 )
      {
        if ( v4 != v1 + 28 )
        {
          KeAcquireInStackQueuedSpinLockAtDpcLevel(v1 + 30, v16);
          for ( i = RtlFindFirstRunClear(v4 + 4, (unsigned int *)&v14);
                ;
                i = RtlFindNextForwardRunClear((int)(v4 + 4), v7, (int)&v14) )
          {
            v8 = i;
            if ( i )
            {
              if ( i >= 0x140 )
                v8 = 320;
              RtlSetBits((_BYTE *)v4 + 16, v14, v8);
            }
            KeReleaseInStackQueuedSpinLockFromDpcLevel(v16);
            if ( !v8 )
              break;
            v6 = (unsigned __int64)(unsigned int)(v14 + v4[2]) << 12;
            v2 = v15(*(_DWORD *)(PnprContext + 552), v15, v6, HIDWORD(v6), v8 << 12, v8 >> 20);
            if ( v2 < 0 )
            {
              v1 = (_DWORD *)PnprContext;
              v10 = *(_DWORD *)(PnprContext + 608);
              if ( !v10 )
                v10 = 3559;
              *(_DWORD *)(PnprContext + 608) = v10;
              v11 = v1[153];
              if ( !v11 )
                v11 = 8;
              v1[153] = v11;
              goto LABEL_24;
            }
            v7 = v8 + v14;
            v14 = v7;
            KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(PnprContext + 120), v16);
          }
          v9 = *(_DWORD *)(PnprContext + 148);
          __dmb(0xBu);
          v1 = (_DWORD *)PnprContext;
          if ( v9 != 3 )
          {
            v4 = (_DWORD *)*v4;
            continue;
          }
          v3 = 1;
        }
        break;
      }
    }
    while ( !v3 );
  }
LABEL_24:
  if ( v0 != v1[32] )
  {
    for ( j = v1[37]; ; j = *(_DWORD *)(PnprContext + 148) )
    {
      __dmb(0xBu);
      if ( j >= 3 )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  return v2;
}
