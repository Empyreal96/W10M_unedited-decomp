// PopFxPlatformIdleVeto 
 
int __fastcall PopFxPlatformIdleVeto(int a1, int a2, int a3, char a4)
{
  int v5; // r5
  unsigned int *v6; // r0
  unsigned int v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r2
  int v10; // r0
  int (__fastcall *v11)(int, GUID *, _DWORD *, int, _DWORD, _DWORD, int *); // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v16; // [sp+10h] [bp-28h] BYREF
  _DWORD v17[2]; // [sp+18h] [bp-20h] BYREF
  char v18; // [sp+20h] [bp-18h]

  v5 = -1073741822;
  if ( *(_DWORD *)(a1 + 80) )
  {
    __dmb(0xBu);
    v6 = (unsigned int *)(a1 + 112);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 + 1, v6) );
    __dmb(0xBu);
    if ( *(_BYTE *)(a1 + 108) )
    {
      __dmb(0xBu);
      do
      {
        v8 = __ldrex(v6);
        v9 = v8 - 1;
      }
      while ( __strex(v9, v6) );
      __dmb(0xBu);
      if ( !v9 )
        KeSetEvent(a1 + 116, 0, 0);
      v5 = -1073741738;
    }
    else
    {
      v18 = a4;
      v16 = 0;
      v10 = *(_DWORD *)(a1 + 88);
      v11 = *(int (__fastcall **)(int, GUID *, _DWORD *, int, _DWORD, _DWORD, int *))(a1 + 80);
      v17[0] = a2;
      v17[1] = a3;
      v5 = v11(v10, &GUID_PLATFORM_IDLE_VETO, v17, 12, 0, 0, &v16);
      __dmb(0xBu);
      v12 = (unsigned int *)(a1 + 112);
      do
      {
        v13 = __ldrex(v12);
        v14 = v13 - 1;
      }
      while ( __strex(v14, v12) );
      __dmb(0xBu);
      if ( !v14 )
        KeSetEvent(a1 + 116, 0, 0);
    }
  }
  return v5;
}
