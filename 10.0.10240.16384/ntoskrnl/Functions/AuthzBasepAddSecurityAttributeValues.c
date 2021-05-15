// AuthzBasepAddSecurityAttributeValues 
 
int __fastcall AuthzBasepAddSecurityAttributeValues(int a1, int a2)
{
  int v3; // r4
  int v6; // r7
  int v7; // r6
  int i; // r9
  int v9; // r3
  __int64 v10; // r2
  int v11; // r3
  int v12; // r0
  _BYTE *v13; // r0
  int v14; // r3
  _DWORD *v15; // r2
  int v16; // r0
  unsigned __int16 v17; // r3
  unsigned int v18; // r2
  int v19; // r1
  int v20; // r3
  unsigned int v21; // r3
  _DWORD *v22; // r2
  unsigned __int16 v23; // r3

  v3 = 0;
  if ( *(unsigned __int16 *)(a1 + 24) != *(unsigned __int16 *)(a2 + 8) )
    return sub_52ABE0();
  v6 = 0;
  v7 = 0;
  if ( !*(_DWORD *)(a2 + 16) )
    return v6;
  for ( i = 0; ; i += 16 )
  {
    v9 = *(unsigned __int16 *)(a1 + 24);
    if ( *(_WORD *)(a1 + 24) )
    {
      if ( *(unsigned __int16 *)(a1 + 24) <= 2u )
        goto LABEL_7;
      switch ( v9 )
      {
        case 3:
LABEL_23:
          LODWORD(v10) = *(_DWORD *)(a2 + 20) + 8 * v7;
          goto LABEL_24;
        case 6:
LABEL_7:
          v10 = *(_QWORD *)(*(_DWORD *)(a2 + 20) + 8 * v7);
          goto LABEL_8;
        case 4:
          LODWORD(v10) = i + *(_DWORD *)(a2 + 20);
LABEL_24:
          v10 = (int)v10;
LABEL_8:
          v3 = AuthzBasepFindSecurityAttributeValue(a1, a2, v10, HIDWORD(v10));
          goto LABEL_9;
        case 5:
        case 16:
          goto LABEL_23;
      }
    }
    v6 = -1073741811;
LABEL_9:
    if ( v6 < 0 )
      return v6;
    if ( v3 )
      break;
    v11 = *(unsigned __int16 *)(a2 + 8);
    v12 = 0;
    switch ( v11 )
    {
      case 3:
        v12 = *(unsigned __int16 *)(*(_DWORD *)(a2 + 20) + 8 * v7);
        break;
      case 4:
        v12 = *(unsigned __int16 *)(*(_DWORD *)(a2 + 20) + i + 8);
        break;
      case 5:
      case 16:
        v12 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 8 * v7 + 4);
        break;
    }
    v13 = AuthzBasepAllocateSecurityAttributeValue(v12);
    v3 = (int)v13;
    if ( !v13 )
      return -1073741670;
    v14 = *(unsigned __int16 *)(a2 + 8);
    if ( !*(_WORD *)(a2 + 8) )
      goto LABEL_19;
    if ( *(unsigned __int16 *)(a2 + 8) <= 2u )
      goto LABEL_18;
    if ( v14 == 3 )
    {
      v16 = (int)(v13 + 40);
      v17 = *(_WORD *)(*(_DWORD *)(a2 + 20) + 8 * v7);
      *(_DWORD *)(v3 + 28) = v3 + 40;
      *(_WORD *)(v3 + 24) = v17;
      *(_WORD *)(v3 + 26) = v17;
      v18 = v17;
      v19 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 8 * v7 + 4);
LABEL_27:
      memmove(v16, v19, v18);
      goto LABEL_19;
    }
    if ( v14 != 6 )
    {
      if ( v14 == 4 )
      {
        v16 = (int)(v13 + 40);
        v22 = (_DWORD *)(i + *(_DWORD *)(a2 + 20));
        *(_DWORD *)(v3 + 24) = *v22;
        *(_DWORD *)(v3 + 28) = v22[1];
        v23 = *(_WORD *)(*(_DWORD *)(a2 + 20) + i + 8);
        *(_DWORD *)(v3 + 36) = v3 + 40;
        *(_WORD *)(v3 + 32) = v23;
        v18 = v23;
        v19 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + i + 12);
      }
      else
      {
        if ( v14 != 5 && v14 != 16 )
          goto LABEL_19;
        v16 = (int)(v13 + 40);
        v21 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 8 * v7 + 4);
        *(_DWORD *)(v3 + 24) = v3 + 40;
        *(_DWORD *)(v3 + 28) = v21;
        v18 = v21;
        v19 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 8 * v7);
      }
      goto LABEL_27;
    }
LABEL_18:
    v15 = (_DWORD *)(*(_DWORD *)(a2 + 20) + 8 * v7);
    *((_DWORD *)v13 + 6) = *v15;
    *((_DWORD *)v13 + 7) = v15[1];
LABEL_19:
    AuthzBasepAddSecurityAttributeValueToLists((_DWORD *)a1, (_DWORD *)v3, 0, 1);
LABEL_20:
    if ( (unsigned int)++v7 >= *(_DWORD *)(a2 + 16) )
      return v6;
  }
  v20 = *(_DWORD *)(v3 + 16);
  if ( (v20 & 4) != 0 )
  {
    *(_DWORD *)(v3 + 16) = v20 & 0xFFFFFFFB;
    AuthzBasepRemoveSecurityAttributeValueFromLists(a1, v3, 0);
    --*(_DWORD *)(a1 + 40);
    goto LABEL_20;
  }
  return -1073741771;
}
