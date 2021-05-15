// SepLinkLogonSessions 
 
int __fastcall SepLinkLogonSessions(int a1, int a2, char a3)
{
  int v5; // r4
  _DWORD *v6; // r5
  int v7; // r4
  int v8; // r7
  int v9; // r1
  int v10; // r2
  int v11; // r6
  int v12; // r8
  int v13; // r2
  int v14; // r1
  int v15; // r2
  int v16; // r1
  unsigned int *v17; // r6
  unsigned int i; // r2
  unsigned int v19; // r1
  int v20; // r1
  int v22; // [sp+10h] [bp-48h] BYREF
  int v23; // [sp+14h] [bp-44h] BYREF
  _DWORD *v24; // [sp+18h] [bp-40h] BYREF
  int v25[2]; // [sp+20h] [bp-38h] BYREF
  int v26[12]; // [sp+28h] [bp-30h] BYREF

  v22 = 0;
  v23 = 0;
  v5 = a3;
  v6 = 0;
  v24 = 0;
  if ( !SeSinglePrivilegeCheck(SeCreateTokenPrivilege, dword_922A04, a3) )
    return -1073741727;
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 192) + 32) )
    return -1073741811;
  v7 = ObReferenceObjectByHandle(a2, 136, SeTokenObjectType, v5, v25, 0);
  v8 = v25[0];
  if ( v7 >= 0 )
  {
    v9 = *(_DWORD *)(v25[0] + 192);
    if ( *(_DWORD *)(v9 + 32) )
    {
LABEL_7:
      v7 = -1073741811;
      goto LABEL_33;
    }
    v10 = *(_DWORD *)(a1 + 192);
    if ( v10 == v9 )
    {
      v7 = 0;
      *(_DWORD *)(v10 + 24) |= 4u;
      goto LABEL_33;
    }
    if ( *(_DWORD *)(a1 + 168) != 1 || *(_DWORD *)(v25[0] + 168) != 1 )
      goto LABEL_7;
    v26[0] = 24;
    v26[1] = 0;
    v26[2] = 0;
    v26[3] = 0;
    v26[4] = 0;
    v26[5] = 0;
    v7 = SepDuplicateToken(a1, v26, 0, 1, 0, 0, 0, &v22);
    v11 = v22;
    if ( v7 < 0 )
    {
LABEL_20:
      if ( v11 )
        ObfDereferenceObjectWithTag(v11);
      if ( v6 )
      {
        v17 = v6 + 5;
        __pld(v6 + 5);
        for ( i = v6[5]; (int)(i - 1) > 0; i = v19 )
        {
          __dmb(0xBu);
          do
            v19 = __ldrex(v17);
          while ( v19 == i && __strex(i - 1, v17) );
          if ( v19 == i )
            goto LABEL_33;
        }
        if ( i != 1 )
          __fastfail(0xEu);
        v20 = v6[22];
        v25[0] = v6[1];
        v25[1] = v6[2];
        SepDeReferenceLogonSession(v25, v20);
      }
      goto LABEL_33;
    }
    v7 = SepDuplicateToken(v8, v26, 0, 1, 0, 0, 0, &v23);
    v12 = v23;
    if ( v7 < 0 )
    {
LABEL_18:
      if ( v12 )
        ObfDereferenceObjectWithTag(v12);
      goto LABEL_20;
    }
    v7 = SepReferenceLogonSession(v11 + 24, &v24);
    if ( v7 < 0 )
      goto LABEL_17;
    *(_DWORD *)(*(_DWORD *)(v11 + 192) + 32) = v11;
    v13 = *(_DWORD *)(v12 + 192);
    v14 = *(_DWORD *)(v11 + 192);
    *(_DWORD *)(v14 + 12) = *(_DWORD *)(v13 + 4);
    *(_DWORD *)(v14 + 16) = *(_DWORD *)(v13 + 8);
    *(_DWORD *)(*(_DWORD *)(v11 + 192) + 24) |= 2u;
    *(_DWORD *)(*(_DWORD *)(v12 + 192) + 32) = v12;
    v15 = *(_DWORD *)(v11 + 192);
    v16 = *(_DWORD *)(v12 + 192);
    *(_DWORD *)(v16 + 12) = *(_DWORD *)(v15 + 4);
    *(_DWORD *)(v16 + 16) = *(_DWORD *)(v15 + 8);
    *(_DWORD *)(*(_DWORD *)(v12 + 192) + 24) |= 4u;
    v7 = SepStopReferencingLogonSession(v12);
    if ( v7 < 0 || (v7 = SepStopReferencingLogonSession(v11), v7 < 0) )
    {
LABEL_17:
      v6 = v24;
      goto LABEL_18;
    }
  }
LABEL_33:
  if ( v8 )
    ObfDereferenceObjectWithTag(v8);
  return v7;
}
