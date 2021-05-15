// AlpcpPortQueryConnectedSidInfo 
 
int __fastcall AlpcpPortQueryConnectedSidInfo(int a1, unsigned int a2, int a3, _DWORD *a4, char a5)
{
  int v7; // r4
  unsigned __int16 *v8; // r8
  int v9; // r5
  int v10; // r0
  int v11; // r10
  unsigned int *v12; // r4
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  unsigned int v16; // r2
  int v17; // r4
  int v19; // [sp+0h] [bp-90h]
  int v20[4]; // [sp+18h] [bp-78h] BYREF
  unsigned __int16 v21[52]; // [sp+28h] [bp-68h] BYREF

  v20[2] = a1;
  v20[0] = 0;
  if ( !a1 )
    return -1073741811;
  if ( !a5 )
  {
    if ( a4 )
      *a4 = 0;
    v8 = (unsigned __int16 *)a2;
    goto LABEL_11;
  }
  if ( a4 )
    *a4 = 0;
  v7 = SeCaptureSid(a2, a5, 0, (int)v20, v19, 1, v20);
  v20[1] = v7;
  if ( v7 >= 0 )
  {
    v8 = (unsigned __int16 *)v20[0];
LABEL_11:
    v9 = 0;
    v10 = AlpcpReferenceConnectedPort(a1);
    v11 = v10;
    if ( v10 )
    {
      v12 = (unsigned int *)(v10 + 208);
      v13 = KeAbPreAcquire(v10 + 208, 0, 0);
      v14 = v13;
      do
        v15 = __ldrex(v12);
      while ( !v15 && __strex(0x11u, v12) );
      __dmb(0xBu);
      if ( v15 )
        ExfAcquirePushLockSharedEx(v12, v13, (unsigned int)v12);
      if ( v14 )
        *(_BYTE *)(v14 + 14) |= 1u;
      v9 = *(_DWORD *)(v11 + 12);
      if ( (v9 & 1) != 0 )
        v9 = 0;
      if ( v9 )
        ObfReferenceObjectWithTag(v9);
      __dmb(0xBu);
      do
        v16 = __ldrex(v12);
      while ( v16 == 17 && __strex(0, v12) );
      if ( v16 != 17 )
        ExfReleasePushLockShared(v12);
      KeAbPostRelease((unsigned int)v12);
      ObfDereferenceObject(v11);
    }
    if ( v9 )
    {
      v17 = PsReferencePrimaryToken(v9);
      SeQueryUserSidToken(v17, (int)v21, 0x44u, 0);
      ObFastDereferenceObject((_DWORD *)(v9 + 244), v17);
      v7 = 0;
      if ( !RtlEqualSid(v8, v21) )
        v7 = -1073741152;
      ObfDereferenceObjectWithTag(v9);
    }
    else
    {
      v7 = -1073741769;
    }
    if ( v8 != (unsigned __int16 *)a2 )
      SeReleaseSid((unsigned int)v8, a5, 1);
  }
  return v7;
}
