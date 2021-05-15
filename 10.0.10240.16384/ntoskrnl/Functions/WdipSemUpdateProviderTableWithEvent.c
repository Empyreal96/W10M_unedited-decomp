// WdipSemUpdateProviderTableWithEvent 
 
int __fastcall WdipSemUpdateProviderTableWithEvent(_DWORD *a1)
{
  int v2; // r5
  unsigned int v3; // r0
  _BYTE *v4; // r0
  _DWORD *v5; // r8
  int v6; // r2
  int v7; // r3
  int v8; // r4

  v2 = 0;
  if ( !a1 )
    return -1073741811;
  v3 = WdipSemQueryProviderTable((unsigned int)a1);
  if ( v3 )
  {
    a1[10] = v3;
  }
  else if ( (unsigned int)dword_61C760 < 0x400 )
  {
    v4 = (_BYTE *)WdipSemFastAllocate(2, 80);
    v5 = v4;
    if ( v4 )
    {
      memset(v4, 0, 80);
      v6 = a1[1];
      v7 = a1[2];
      v8 = a1[3];
      *v5 = *a1;
      v5[1] = v6;
      v5[2] = v7;
      v5[3] = v8;
      WdipSemProviderTable[dword_61C760++] = (int)v5;
      a1[10] = v5;
    }
    else
    {
      v2 = -1073741670;
    }
  }
  else
  {
    if ( EtwEventEnabled(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_INIT_PROVIDER_MAX) )
      WdipSemWriteProviderLimitExceededEvent(a1);
    v2 = -1073741823;
  }
  return v2;
}
