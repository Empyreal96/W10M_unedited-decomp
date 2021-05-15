// IoWMISystemControl 
 
int __fastcall IoWMISystemControl(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r2
  int v6; // r7
  unsigned int v7; // r5
  int *v8; // r0
  __int64 v9; // kr00_8
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r2
  int v16; // r5
  unsigned int v18; // r7
  int v19; // r8
  int v20; // r10
  unsigned int v21; // r9
  int v22; // r3
  _WORD *v23; // lr
  unsigned int v24; // r10
  unsigned int v25; // r3
  unsigned int v26; // r2
  unsigned int v27; // r4
  int *v28; // r9
  int v29; // r10
  int *v30; // r7
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r3
  int v35; // r3
  int v36; // r0
  int v37; // r9
  int v38; // r8
  int v39; // r9
  unsigned __int16 *v40; // [sp+10h] [bp-58h] BYREF
  int v41; // [sp+14h] [bp-54h] BYREF
  int v42; // [sp+18h] [bp-50h]
  unsigned int v43; // [sp+1Ch] [bp-4Ch] BYREF
  unsigned int v44; // [sp+20h] [bp-48h]
  int *v45; // [sp+24h] [bp-44h]
  int v46; // [sp+28h] [bp-40h]
  unsigned int v47; // [sp+2Ch] [bp-3Ch]
  unsigned int v48; // [sp+30h] [bp-38h]
  int v49; // [sp+34h] [bp-34h]
  int v50; // [sp+38h] [bp-30h] BYREF
  unsigned int v51; // [sp+3Ch] [bp-2Ch]
  _DWORD v52[10]; // [sp+40h] [bp-28h] BYREF

  v3 = a3;
  v4 = *(_DWORD *)(a3 + 96);
  v6 = 0;
  v7 = *(unsigned __int8 *)(v4 + 1);
  v46 = v3;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  if ( v7 > 0xB || *(_DWORD *)(v4 + 8) != a2 )
  {
LABEL_48:
    v16 = -1073741808;
    goto LABEL_41;
  }
  v8 = WmipGuidList;
  if ( !WmipGuidList && v7 != 11 )
    return sub_81824C();
  v9 = *(_QWORD *)(v4 + 16);
  v44 = *(_DWORD *)(v4 + 16);
  if ( v7 == 11 || v7 == 8 )
  {
LABEL_12:
    switch ( v7 )
    {
      case 0u:
        if ( (unsigned int)v9 < 0x3C )
          return IoWMICompleteRequest(v8);
        v8 = (int *)WmipFindRegEntryByDevice(*(_DWORD *)(HIDWORD(v9) + 4));
        if ( !v8 )
          return IoWMICompleteRequest(v8);
        v37 = v8[2];
        v38 = v8[7];
        v8 = (int *)WmipUnreferenceRegEntry((int)v8);
        if ( !v38 )
          return IoWMICompleteRequest(v8);
        v10 = *(_DWORD *)(HIDWORD(v9) + 44);
        *(_DWORD *)(HIDWORD(v9) + 52) = v38;
        *(_DWORD *)(HIDWORD(v9) + 44) = v10 & 0xFFFFFFEF;
        v11 = (8 * v38 + 67) & 0xFFFFFFF8;
        *(_DWORD *)(HIDWORD(v9) + 48) = v11;
        if ( v11 > (unsigned int)v9 )
        {
          v14 = 0;
          v12 = 0;
          v13 = 0;
        }
        else
        {
          v12 = v11 + HIDWORD(v9);
          v13 = v9 - v11;
          v14 = HIDWORD(v9) + 60;
        }
        return WmipQueryWmiDataBlock(v37, v3, v6, 0, v38, v14, v13, v12);
      case 1u:
        v8 = (int *)WmipFindRegEntryByDevice(*(_DWORD *)(HIDWORD(v9) + 4));
        if ( !v8 )
          return IoWMICompleteRequest(v8);
        v39 = v8[2];
        WmipUnreferenceRegEntry((int)v8);
        return WmipQueryWmiDataBlock(
                 v39,
                 v3,
                 v6,
                 v43,
                 1,
                 HIDWORD(v9) + 60,
                 v9 - *(_DWORD *)(HIDWORD(v9) + 56),
                 *(_DWORD *)(HIDWORD(v9) + 56) + HIDWORD(v9));
      case 2u:
      case 3u:
        v16 = -1073741114;
        *(_DWORD *)(v3 + 24) = -1073741114;
        goto LABEL_46;
      case 4u:
      case 5u:
      case 6u:
      case 7u:
        v16 = 0;
        *(_DWORD *)(v3 + 24) = 0;
LABEL_46:
        *(_DWORD *)(v3 + 28) = 0;
        goto LABEL_42;
      case 8u:
      case 0xBu:
        v50 = 0;
        v51 = 0;
        v41 = 0;
        v42 = 0;
        v16 = WmipQueryWmiRegInfo(a2, &v41, &v50, &v40);
        v18 = v51;
        if ( v16 < 0 )
          goto LABEL_38;
        v19 = v41;
        v20 = v41 & 0x20;
        if ( (v41 & 0x20) != 0 || v51 )
        {
          v45 = WmipGuidList;
          v16 = RtlULongLongToULong(196, 0, &v43);
          if ( v16 >= 0 )
          {
            v21 = v43 + 20;
            v47 = v43 + 20;
            if ( v43 >= 0xFFFFFFEC )
              goto LABEL_57;
            v49 = (unsigned __int16)v50;
            if ( v20 )
            {
              v22 = 0;
              v43 = 0;
            }
            else
            {
              v19 |= 4u;
              v41 = v19;
              v22 = (unsigned __int16)v50 + 2;
              v43 += 20;
            }
            v23 = v40;
            if ( !v40 )
            {
              v23 = v52;
              v40 = (unsigned __int16 *)v52;
              v52[0] = 0;
              v52[1] = 0;
            }
            v24 = v22 + v21;
            v48 = v22 + v21;
            if ( v22 + v21 < v21 || (v25 = (unsigned __int16)*v23 + 2 + v24, v25 < v24) )
            {
LABEL_57:
              v16 = -1073741675;
            }
            else
            {
              v26 = v44;
              v16 = 0;
              *(_DWORD *)HIDWORD(v9) = v25;
              if ( v25 > v26 )
              {
                v42 = 4;
              }
              else
              {
                v42 = v25;
                *(_DWORD *)(HIDWORD(v9) + 4) = 0;
                *(_QWORD *)(HIDWORD(v9) + 8) = (unsigned int)v9;
                v27 = v43;
                v28 = v45;
                *(_DWORD *)(HIDWORD(v9) + 16) = 7;
                v29 = 7;
                v30 = (int *)(HIDWORD(v9) + 20);
                do
                {
                  v31 = v28[1];
                  v32 = v28[2];
                  v33 = v28[3];
                  *v30 = *v28;
                  v30[1] = v31;
                  v30[2] = v32;
                  v30[3] = v33;
                  v34 = v28[5];
                  v30[6] = v27;
                  v30[4] = v34 | v19;
                  v35 = v28[4];
                  v28 += 6;
                  v30[5] = v35;
                  v30 += 7;
                  --v29;
                }
                while ( v29 );
                v3 = v46;
                if ( (v19 & 4) != 0 )
                {
                  v36 = v47 + HIDWORD(v9) + 2;
                  *(_WORD *)(v47 + HIDWORD(v9)) = v49;
                  memmove(v36, v51, (unsigned __int16)v50);
                  v23 = v40;
                }
                *(_WORD *)(v9 + HIDWORD(v9)) = *v23;
                memmove(v9 + HIDWORD(v9) + 2, *((_DWORD *)v40 + 1), *v40);
                v18 = v51;
              }
            }
          }
LABEL_38:
          if ( v18 )
            ExFreePoolWithTag(v18);
        }
        else
        {
          v16 = -1073741808;
        }
        *(_DWORD *)(v3 + 28) = v42;
        break;
      case 9u:
        *(_DWORD *)(v3 + 28) = 0;
        goto LABEL_48;
      default:
        return -1073741808;
    }
    goto LABEL_41;
  }
  v8 = (int *)WmipFindGuid(WmipGuidList);
  if ( !v8 )
  {
    v16 = -1073741163;
    goto LABEL_41;
  }
  if ( v7 != 1 && v7 != 2 && v7 != 3 && v7 != 9
    || (v43 = *(_DWORD *)(HIDWORD(v9) + 52), (*(_DWORD *)(HIDWORD(v9) + 44) & 0x80) != 0) )
  {
    v6 = v42;
    goto LABEL_12;
  }
  v16 = -1073741162;
LABEL_41:
  *(_DWORD *)(v3 + 24) = v16;
LABEL_42:
  IofCompleteRequest(v3, 0);
  return v16;
}
