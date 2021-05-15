// sub_8DF2F0 
 
void __fastcall sub_8DF2F0(int a1, _BYTE *a2)
{
  int v2; // r2
  int v3; // r0
  int v4; // r3
  void **v5; // r5
  __int64 v6; // r2

  v2 = 0;
  if ( (dword_619018 & 0x100000) != 0 && (dword_619018 & 0x1000) != 0 )
    v2 = 1;
  v3 = 0;
  v4 = dword_619018 & 0xC00;
  *a2 = 0;
  if ( v4 != 3072 && !v2 )
    v3 = KeCancelTimer((int)dword_653478);
  v5 = (void **)TxtpTextCache;
  v6 = *(_QWORD *)TxtpTextCache;
  if ( *((void ***)TxtpTextCache + 1) != &TxtpTextCache || *(void **)(v6 + 4) != TxtpTextCache )
    __fastfail(3u);
  while ( 1 )
  {
    TxtpTextCache = (void *)v6;
    *(_DWORD *)(v6 + 4) = &TxtpTextCache;
    if ( v5 == &TxtpTextCache )
      break;
    BgpGxRectangleDestroy((int)v5[8]);
    v3 = BgpFwFreeMemory((int)v5);
    v5 = (void **)TxtpTextCache;
    v6 = *(_QWORD *)TxtpTextCache;
    if ( *((void ***)TxtpTextCache + 1) != &TxtpTextCache || *(void **)(v6 + 4) != TxtpTextCache )
      __fastfail(3u);
  }
  dword_6174D4 = 0;
  if ( RasterizerInitialized )
    RaspClearCache(v3, (int)a2);
  JUMPOUT(0x8DD35E);
}
