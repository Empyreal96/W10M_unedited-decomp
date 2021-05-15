// ObpRemoveNamespaceFromTable 
 
int __fastcall ObpRemoveNamespaceFromTable(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r1
  int result; // r0
  __int64 v6; // r2
  __int64 v7; // r0
  unsigned int v8; // r6
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r0
  unsigned int v13; // r6
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&dword_620C08, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_620C08);
  while ( __strex(v4 | 1, (unsigned __int8 *)&dword_620C08) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7EB86C(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = *(_QWORD *)(a1 + 164);
  *(_DWORD *)(a1 + 168) = HIDWORD(v6) | 2;
  if ( (_DWORD)v6 )
  {
    *(_DWORD *)(a1 + 164) = 0;
    *(_DWORD *)(v6 + 8) = 0;
    v7 = *(_QWORD *)v6;
    if ( *(_DWORD *)(*(_DWORD *)v6 + 4) != (_DWORD)v6 || *(_DWORD *)HIDWORD(v7) != (_DWORD)v6 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
    --dword_620C0C;
    __pld(&dword_620C08);
    LODWORD(v7) = dword_620C08;
    if ( (dword_620C08 & 0xFFFFFFF0) > 0x10 )
      v8 = dword_620C08 - 16;
    else
      v8 = 0;
    if ( (dword_620C08 & 2) != 0 )
      goto LABEL_21;
    __dmb(0xBu);
    do
      HIDWORD(v7) = __ldrex((unsigned int *)&dword_620C08);
    while ( HIDWORD(v7) == (_DWORD)v7 && __strex(v8, (unsigned int *)&dword_620C08) );
    if ( HIDWORD(v7) != (_DWORD)v7 )
LABEL_21:
      ExfReleasePushLock(&dword_620C08, SHIDWORD(v7));
    v9 = KeAbPostRelease((unsigned int)&dword_620C08);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v9);
    ObfDereferenceObject(a1);
    result = 0;
  }
  else
  {
    __pld(&dword_620C08);
    v12 = dword_620C08;
    if ( (dword_620C08 & 0xFFFFFFF0) <= 0x10 )
      v13 = 0;
    else
      v13 = dword_620C08 - 16;
    if ( (dword_620C08 & 2) != 0 )
      goto LABEL_30;
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&dword_620C08);
    while ( v4 == v12 && __strex(v13, (unsigned int *)&dword_620C08) );
    if ( v4 != v12 )
LABEL_30:
      ExfReleasePushLock(&dword_620C08, v4);
    v14 = KeAbPostRelease((unsigned int)&dword_620C08);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
    result = -1072103391;
  }
  return result;
}
