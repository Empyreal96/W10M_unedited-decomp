// SmcVolumePnpNotification 
 
int __fastcall SmcVolumePnpNotification(int a1)
{
  unsigned int v2; // r5
  _DWORD *v3; // r8
  int v4; // r4
  int v5; // r0
  int v6; // r6
  _DWORD *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1

  if ( !memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_QUERY_REMOVE, 16)
    || !memcmp(a1 + 4, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_COMPLETE, 16) )
  {
    v2 = 0;
    v3 = SmGlobals;
    do
    {
      v4 = v3[1500] & 0xFFF;
      v5 = SmcCacheReference((int)&unk_636CE4, v2 | (16 * v4));
      v6 = v5;
      if ( v5 )
      {
        if ( *(_DWORD *)(v5 + 44) != *(_DWORD *)(a1 + 20) )
          v6 = 0;
        v7 = (_DWORD *)((char *)&unk_636CE8 + 16 * (((unsigned __int8)v2 | (unsigned __int8)(16 * v4)) & 0xF));
        __pld(v7);
        v8 = *v7 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v9 = __ldrex(v7);
        while ( v9 == v8 && __strex(v8 - 2, v7) );
        if ( v9 != v8 )
          ExfReleaseRundownProtection((unsigned __int8 *)v7);
        if ( v6 )
          SmcCacheDelete((int)&unk_636CE4);
      }
      ++v2;
      v3 += 4;
    }
    while ( v2 < 0x10 );
  }
  return 0;
}
