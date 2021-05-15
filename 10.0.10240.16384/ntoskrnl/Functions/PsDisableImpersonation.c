// PsDisableImpersonation 
 
int __fastcall PsDisableImpersonation(_DWORD *a1, int a2)
{
  unsigned __int8 *v2; // r8
  int v5; // r9
  unsigned int v6; // r7
  unsigned __int8 *v7; // r10
  int v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r2
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r0
  __int16 v14; // r3
  int v16; // r3

  v2 = (unsigned __int8 *)(a1 + 240);
  v5 = 0;
  if ( (a1[240] & 8) == 0 )
    goto LABEL_28;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 0x134);
  v7 = (unsigned __int8 *)(a1 + 236);
  v8 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
  do
    v9 = __ldrex(v7);
  while ( __strex(v9 | 1, v7) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
  {
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    __dmb(0xBu);
    do
      v10 = __ldrex(v2);
    while ( __strex(v10 & 0xF7, v2) );
    __dmb(0xBu);
    if ( (unsigned __int8)(v10 & 8) >> 3 )
    {
      v5 = 1;
      *(_DWORD *)(a2 + 8) = a1[226] & 3;
      *(_BYTE *)(a2 + 5) = (a1[226] & 4) != 0;
      *(_BYTE *)(a2 + 4) = (a1[240] & 0x100) != 0;
      v11 = a1[263];
      if ( v11 )
      {
        *(_DWORD *)a2 = v11;
        v16 = a1[226];
        a1[263] = 0;
        ObfDereferenceObject(v16 & 0xFFFFFFF8);
      }
      else
      {
        *(_DWORD *)a2 = a1[226] & 0xFFFFFFF8;
      }
    }
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v7);
    while ( __strex(v12 - 1, (unsigned int *)v7) );
    if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v7);
    v13 = KeAbPostRelease((unsigned int)v7);
    v14 = *(_WORD *)(v6 + 308) + 1;
    *(_WORD *)(v6 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v13);
    if ( v5 )
      return 1;
LABEL_28:
    JUMPOUT(0x7C52C6);
  }
  return sub_7C52A4(v8);
}
