// KsepDbReadKData 
 
int __fastcall KsepDbReadKData(int a1, int a2, int a3)
{
  int v4; // r6
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r8
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r2
  int v15; // r3
  unsigned __int16 *v16; // r0
  unsigned __int16 *v17; // r5
  int v18; // r0
  int v19; // r3
  int v20; // r0
  int v21; // r7
  int v22; // r2
  int v23; // r9

  v4 = -1073741823;
  if ( !a2 )
    return v4;
  v7 = SdbFindFirstTag(a1, a2, 24577);
  if ( !v7 )
    return v4;
  v10 = SdbGetStringTagPtr(a1, v7, v8, v9);
  if ( !v10 )
    return v4;
  v11 = SdbFindFirstTag(a1, a2, 16408);
  if ( !v11 )
    return v4;
  v12 = SdbReadDWORDTag(a1, v11, 0);
  if ( v12 != 1 )
  {
    switch ( v12 )
    {
      case 4:
        v18 = SdbFindFirstTag(a1, a2, 16409);
        *(_DWORD *)a3 = v10;
        *(_DWORD *)(a3 + 4) = 4;
        *(_DWORD *)(a3 + 8) = 4;
        *(_DWORD *)(a3 + 16) = SdbReadDWORDTag(a1, v18, 0);
        v19 = a3 + 16;
        break;
      case 11:
        v20 = SdbFindFirstTag(a1, a2, 20487);
        *(_DWORD *)a3 = v10;
        *(_DWORD *)(a3 + 4) = 11;
        *(_DWORD *)(a3 + 8) = 8;
        *(_QWORD *)(a3 + 24) = SdbReadQWORDTag(a1, v20, 0, 0);
        v19 = a3 + 24;
        break;
      case 3:
        v21 = SdbFindFirstTag(a1, a2, 36869);
        v23 = SdbpGetMappedTagData(a1, v21);
        if ( v23 )
        {
          *(_DWORD *)a3 = v10;
          *(_DWORD *)(a3 + 4) = 3;
          *(_DWORD *)(a3 + 8) = SdbGetTagDataSize(a1, v21, v22, 3);
          *(_DWORD *)(a3 + 12) = v23;
          goto LABEL_16;
        }
        return v4;
      default:
        return -1073741811;
    }
    *(_DWORD *)(a3 + 12) = v19;
    goto LABEL_16;
  }
  v13 = SdbFindFirstTag(a1, a2, 24606);
  v16 = (unsigned __int16 *)SdbGetStringTagPtr(a1, v13, v14, v15);
  v17 = v16;
  if ( v16 )
  {
    *(_DWORD *)a3 = v10;
    *(_DWORD *)(a3 + 4) = 1;
    *(_DWORD *)(a3 + 8) = 2 * (wcslen(v16) + 1);
    *(_DWORD *)(a3 + 12) = v17;
LABEL_16:
    v4 = 0;
  }
  return v4;
}
