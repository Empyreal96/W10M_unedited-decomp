// ObpRegisterPrivateNamespace 
 
int __fastcall ObpRegisterPrivateNamespace(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r1
  int result; // r0
  int v6; // r1
  char *v7; // r2
  char **v8; // r1
  int v9; // r0
  unsigned int v10; // r6
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v14; // r0
  unsigned int v15; // r6
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&dword_620C08, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_620C08);
  while ( __strex(v4 | 1, (unsigned __int8 *)&dword_620C08) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7EF694(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  if ( ObpLookupNamespaceEntry(v3, a1) )
  {
    __pld(&dword_620C08);
    v14 = dword_620C08;
    if ( (dword_620C08 & 0xFFFFFFF0) <= 0x10 )
      v15 = 0;
    else
      v15 = dword_620C08 - 16;
    if ( (dword_620C08 & 2) != 0 )
      goto LABEL_29;
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&dword_620C08);
    while ( v6 == v14 && __strex(v15, (unsigned int *)&dword_620C08) );
    if ( v6 != v14 )
LABEL_29:
      ExfReleasePushLock(&dword_620C08, v6);
    v16 = KeAbPostRelease((unsigned int)&dword_620C08);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
    result = -1073741771;
  }
  else
  {
    v7 = (char *)&ObpPrivateNamespaceLookupTable + 8 * *(unsigned __int8 *)(a1 + 20);
    v8 = (char **)*((_DWORD *)v7 + 1);
    *(_DWORD *)a1 = v7;
    *(_DWORD *)(a1 + 4) = v8;
    if ( *v8 != v7 )
      __fastfail(3u);
    *v8 = (char *)a1;
    *((_DWORD *)v7 + 1) = a1;
    ++dword_620C0C;
    __pld(&dword_620C08);
    v9 = dword_620C08;
    if ( (dword_620C08 & 0xFFFFFFF0) > 0x10 )
      v10 = dword_620C08 - 16;
    else
      v10 = 0;
    if ( (dword_620C08 & 2) != 0 )
      goto LABEL_20;
    __dmb(0xBu);
    do
      v8 = (char **)__ldrex((unsigned int *)&dword_620C08);
    while ( v8 == (char **)v9 && __strex(v10, (unsigned int *)&dword_620C08) );
    if ( v8 != (char **)v9 )
LABEL_20:
      ExfReleasePushLock(&dword_620C08, (int)v8);
    v11 = KeAbPostRelease((unsigned int)&dword_620C08);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery(v11);
    result = 0;
  }
  return result;
}
