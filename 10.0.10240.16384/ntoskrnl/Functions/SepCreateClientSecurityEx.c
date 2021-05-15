// SepCreateClientSecurityEx 
 
int __fastcall SepCreateClientSecurityEx(_DWORD *a1, int a2, int a3, int a4, char a5, int a6, char a7, int a8, unsigned __int8 a9, int a10, int a11)
{
  int v13; // lr
  char v14; // r6
  int v15; // r7
  int v16; // r3
  int v17; // r4
  char v18; // r3
  int result; // r0
  int v20; // r0
  int v21; // r8
  bool v22; // r3
  unsigned int v23; // r3
  int v24; // r0
  _DWORD *v25; // r0
  int v26; // r8
  int v27; // r7
  __int64 v28; // kr00_8
  int v29; // r9
  int v30; // [sp+8h] [bp-28h] BYREF
  int v31[9]; // [sp+Ch] [bp-24h] BYREF

  v30 = 0;
  v13 = 0;
  v14 = a3;
  v15 = (int)a1;
  if ( *(_BYTE *)(a2 + 8) != 1 && *(_BYTE *)(a2 + 8) )
    return sub_7F9B44();
  v16 = *(_DWORD *)(a2 + 4);
  if ( v16 < 0 || v16 > 3 )
    return -1073741659;
  if ( a4 != 2 )
  {
    v17 = a11;
    *(_BYTE *)(a11 + 17) = *(_BYTE *)(a2 + 9);
    goto LABEL_6;
  }
  if ( v16 > a6 )
  {
    if ( !a7 )
      return -1073741659;
    v13 = 1;
  }
  if ( !a6 || a6 == 1 || a3 && a6 != 3 )
  {
    if ( a7 )
    {
      v17 = a11;
      goto LABEL_37;
    }
    return -1073741659;
  }
  v22 = a5 || *(_BYTE *)(a2 + 9);
  v17 = a11;
  *(_BYTE *)(a11 + 17) = v22;
  if ( v13 )
  {
LABEL_37:
    if ( (a1[44] & 0x4000) == 0 )
    {
      if ( a8 )
      {
        v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        if ( a8 == v23 )
          v24 = *(_DWORD *)(v23 + 116);
        else
          v24 = *(_DWORD *)(a8 + 336);
        v25 = (_DWORD *)PsReferencePrimaryToken(v24);
        v26 = (int)v25;
        if ( (v25[44] & 0x4000) == 0 )
          v25 = 0;
        v27 = SepGetAnonymousToken(v25, &v30);
        ObfDereferenceObject(v26);
LABEL_47:
        if ( v27 < 0 )
          return v27;
        v15 = v30;
        result = ObInsertObject(v30, 0, 0, 0, 0, 0);
        if ( result >= 0 )
        {
          *(_DWORD *)v17 = 12;
          *(_DWORD *)(v17 + 4) = 0;
          *(_BYTE *)(v17 + 8) = 0;
          v18 = *(_BYTE *)(a2 + 9);
          *(_BYTE *)(v17 + 16) = 0;
          goto LABEL_10;
        }
        return result;
      }
      a1 = 0;
    }
    v27 = SepGetAnonymousToken(a1, &v30);
    goto LABEL_47;
  }
LABEL_6:
  if ( *(_BYTE *)(a2 + 8) )
  {
    *(_BYTE *)(v17 + 16) = 1;
    if ( a3 )
      SeGetTokenControlInformation(a1, v17 + 20);
    goto LABEL_9;
  }
  *(_BYTE *)(v17 + 16) = 0;
  if ( PsIsCurrentThreadInServerSilo() )
  {
    v28 = *(_QWORD *)(v15 + 24);
    if ( SeQueryServerSiloToken((int *)v15, &v30) >= 0 && PsIsHostSilo(v30) && v28 == 999 )
    {
      v29 = PsGetCurrentServerSilo();
      v21 = SepCopyClientTokenAndSetSilo(v15, *(_DWORD *)(a2 + 4), v29, v31);
      if ( v29 )
        PspDereferenceSiloObject(v29);
      goto LABEL_17;
    }
    v20 = SeCopyClientToken(v15, *(_DWORD *)(a2 + 4), 0, 0, 0, v31);
  }
  else
  {
    v20 = SeCopyClientToken(v15, *(_DWORD *)(a2 + 4), 0, a9, a10, v31);
  }
  v21 = v20;
LABEL_17:
  v15 = v31[0];
  if ( v21 >= 0 )
  {
LABEL_9:
    *(_DWORD *)v17 = 12;
    *(_DWORD *)(v17 + 4) = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(v17 + 8) = *(_BYTE *)(a2 + 8);
    v18 = *(_BYTE *)(a2 + 9);
LABEL_10:
    *(_DWORD *)(v17 + 12) = v15;
    *(_BYTE *)(v17 + 18) = v14;
    *(_BYTE *)(v17 + 9) = v18;
    return 0;
  }
  return v21;
}
