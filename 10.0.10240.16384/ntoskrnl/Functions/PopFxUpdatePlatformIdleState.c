// PopFxUpdatePlatformIdleState 
 
int __fastcall PopFxUpdatePlatformIdleState(int a1, int a2, _DWORD *a3)
{
  int v6; // r4
  unsigned int *v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r2
  unsigned int v10; // r2
  int v11; // r3
  int v12; // r0
  int (__fastcall *v13)(int, GUID *, _DWORD *, int, _DWORD, _DWORD, int *); // r4
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r1
  int v18; // [sp+10h] [bp-28h] BYREF
  _DWORD v19[8]; // [sp+18h] [bp-20h] BYREF

  if ( !*a3 )
    return -1073741637;
  v6 = -1073741822;
  if ( *(_DWORD *)(a1 + 80) )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(a1 + 112);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 1, v7) );
    __dmb(0xBu);
    if ( *(_BYTE *)(a1 + 108) )
    {
      __dmb(0xBu);
      do
      {
        v9 = __ldrex(v7);
        v10 = v9 - 1;
      }
      while ( __strex(v10, v7) );
      __dmb(0xBu);
      if ( !v10 )
        KeSetEvent(a1 + 116, 0, 0);
      v6 = -1073741738;
    }
    else
    {
      v11 = a3[1];
      v12 = *(_DWORD *)(a1 + 88);
      v19[0] = a2;
      v19[1] = v11;
      v13 = *(int (__fastcall **)(int, GUID *, _DWORD *, int, _DWORD, _DWORD, int *))(a1 + 80);
      v19[2] = a3[2];
      v18 = 0;
      v6 = v13(v12, &GUID_PLATFORM_IDLE_UPDATE, v19, 12, 0, 0, &v18);
      __dmb(0xBu);
      v14 = (unsigned int *)(a1 + 112);
      do
      {
        v15 = __ldrex(v14);
        v16 = v15 - 1;
      }
      while ( __strex(v16, v14) );
      __dmb(0xBu);
      if ( !v16 )
        KeSetEvent(a1 + 116, 0, 0);
    }
  }
  return v6;
}
