// AlpcpImpersonateMessage 
 
int __fastcall AlpcpImpersonateMessage(int a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r7
  _BYTE *v7; // r8
  int v8; // r1
  int v9; // r6
  int v10; // r0
  int v11; // r0
  int v12; // r1
  int v13; // r0
  int v14; // r4
  int v15; // r0
  unsigned __int8 *v17; // r8
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r2
  int v21; // r3
  unsigned int v22; // r1
  _BYTE v23[88]; // [sp-4h] [bp-58h] BYREF

  v4 = 0;
  v5 = 0;
  v7 = 0;
  if ( (*(_DWORD *)(a2 + 20) & 7) != 3 )
    return -1073741790;
  if ( (*(_WORD *)(a2 + 124) & 0x4000) != 0 )
    return -1073741790;
  v8 = *(_DWORD *)(a2 + 8);
  if ( v8 != a1 && ((*(_DWORD *)(a1 + 244) & 6) != 6 || v8 != **(_DWORD **)(a1 + 8)) )
    return -1073741790;
  v9 = *(_DWORD *)(a2 + 72);
  if ( !v9 )
  {
    v10 = AlpcpReferenceConnectedPort(a1);
    v4 = v10;
    if ( v10 )
    {
      if ( (*(_DWORD *)(v10 + 152) & 0x10000) == 0 )
      {
        v14 = -1073741790;
        goto LABEL_16;
      }
      if ( (*(_DWORD *)(v10 + 244) & 0x400) != 0 )
      {
        v11 = *(_DWORD *)(a2 + 16);
        if ( !v11 )
        {
          v14 = -1073741790;
          goto LABEL_16;
        }
        v12 = v4 + 156;
        if ( a3 )
          v13 = SeCreateClientSecurityEx(v11, v12, 0, (int)v23);
        else
          v13 = SeCreateClientSecurity(v11, v12, 0, (int)v23);
        v14 = v13;
        if ( v13 < 0 )
          goto LABEL_16;
        v7 = v23;
        v5 = 1;
      }
      else
      {
        v7 = (_BYTE *)(v10 + 32);
      }
LABEL_15:
      v14 = SeImpersonateClientEx(v7, 0);
LABEL_16:
      if ( v4 )
        ObfDereferenceObject(v4);
      if ( v5 )
      {
        v15 = *((_DWORD *)v7 + 3);
        if ( *(_DWORD *)(v15 + 168) == 1 || v15 )
          ObfDereferenceObject(v15);
      }
      return v14;
    }
    return -1073741790;
  }
  v17 = (unsigned __int8 *)(v9 - 4);
  v18 = KeAbPreAcquire(v9 - 4, 0, 0);
  v19 = v18;
  do
    v20 = __ldrex(v17);
  while ( __strex(v20 | 1, v17) );
  __dmb(0xBu);
  if ( (v20 & 1) != 0 )
    v18 = ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 - 4), v18, v9 - 4);
  if ( v19 )
    *(_BYTE *)(v19 + 14) |= 1u;
  v21 = *(_DWORD *)(v9 + 76);
  if ( (v21 & 1) == 0 )
  {
    *(_DWORD *)(v9 + 76) = v21 | 2;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v17);
    while ( __strex(v22 - 1, (unsigned int *)v17) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v9 - 4));
    KeAbPostRelease(v9 - 4);
    v7 = (_BYTE *)(v9 + 16);
    goto LABEL_15;
  }
  return sub_80AE10(v18);
}
