// NtImpersonateAnonymousToken 
 
int __fastcall NtImpersonateAnonymousToken(int a1)
{
  int v1; // r6
  int v2; // r3
  int v3; // r4
  _DWORD *v4; // r0
  int v5; // r7
  int v7; // r5
  char v8; // r3
  int v9; // r8
  int v10; // r0
  unsigned int v11; // r4
  int v12; // r6
  int v13; // [sp+8h] [bp-38h] BYREF
  int v14; // [sp+Ch] [bp-34h] BYREF
  int v15; // [sp+10h] [bp-30h] BYREF
  int v16[2]; // [sp+18h] [bp-28h] BYREF
  _DWORD *v17; // [sp+20h] [bp-20h]
  int v18; // [sp+24h] [bp-1Ch]

  v1 = 0;
  v13 = 0;
  v14 = 0;
  v16[0] = 0;
  v16[1] = 0;
  v17 = 0;
  v18 = 0;
  v2 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v3 = ObReferenceObjectByHandle(a1, 256, PsThreadType, v2, &v15);
  if ( v3 >= 0 )
  {
    SeCaptureSubjectContext(v16);
    v4 = (_DWORD *)v16[0];
    if ( !v16[0] )
      v4 = v17;
    v5 = v15;
    if ( (v4[44] & 0x4000) != 0 )
    {
      v3 = SepGetAnonymousToken(v4, &v14);
      if ( v3 >= 0 )
      {
        v3 = PsImpersonateClient(v5, v14, 1, 0, 2, 0);
        ObfDereferenceObject(v14);
      }
      goto LABEL_12;
    }
    if ( SepRegQueryDwordValue() >= 0 )
      return sub_7D6490();
    v7 = SeAnonymousLogonTokenNoEveryone;
    if ( PsIsCurrentThreadInServerSilo() )
    {
      v12 = PsGetCurrentServerSilo();
      v3 = SepCopyClientTokenAndSetSilo(v7, *(_DWORD *)(v7 + 172), v12, &v13);
      if ( v12 )
        PspDereferenceSiloObject(v12);
      v1 = v13;
      if ( v3 < 0 )
        goto LABEL_12;
      v7 = v13;
    }
    v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v3 = ObReferenceObjectByPointer(v7, 4, SeTokenObjectType, v8);
    if ( v3 >= 0 )
    {
      ObfDereferenceObject(v7);
      v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v10 = PsReferencePrimaryToken(v9);
      v11 = v10;
      if ( v10 )
      {
        if ( !SeTokenIsRestricted(v10) || SeTokenIsWriteRestricted(v11) )
        {
          ObFastDereferenceObject((_DWORD *)(v9 + 244), v11);
          v3 = PsImpersonateClient(v5, v7, v1 == 0, 0, 2, 0);
        }
        else
        {
          ObfDereferenceObject(v11);
          v3 = -1073741790;
        }
      }
      else
      {
        v3 = -1073741823;
      }
    }
LABEL_12:
    SeReleaseSubjectContext((int)v16);
    if ( v5 )
      ObfDereferenceObject(v5);
    if ( v1 )
      ObfDereferenceObject(v1);
  }
  return v3;
}
