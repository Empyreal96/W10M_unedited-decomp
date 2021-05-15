// PiCreateDriverSwDeviceCallback 
 
int __fastcall PiCreateDriverSwDeviceCallback(int *a1, int a2, unsigned __int16 *a3, _DWORD *a4)
{
  _DWORD *v4; // r8
  unsigned __int16 *v5; // r9
  unsigned int v6; // r6
  unsigned int v7; // r5
  unsigned int v8; // r7
  unsigned __int16 *v9; // r10
  int v10; // r4
  int v11; // r2
  int v12; // r1
  int v13; // r0
  int v14; // r0
  int v15; // r8
  int v16; // r5
  int v17; // r10
  unsigned int i; // r6
  int v19; // r3
  int v20; // r2
  int v21; // r3
  unsigned __int16 *v22; // r5
  int v24; // r0
  __int16 v25; // r4
  unsigned int j; // r0
  unsigned int v27; // r4
  unsigned __int16 *v28; // r0
  unsigned __int16 *v29; // r10
  unsigned int v30; // r8
  _DWORD *v31; // r6
  unsigned __int16 *v32; // r5
  int v33; // r1
  int v34; // r2
  int v35; // r3
  unsigned int v36; // r2
  unsigned int v37; // r0
  _DWORD *v38; // r2
  unsigned __int16 *v39; // r5
  unsigned int v40; // r0
  unsigned int v42; // [sp+2Ch] [bp-19Ch] BYREF
  unsigned __int16 v43; // [sp+30h] [bp-198h] BYREF
  _BYTE v44[6]; // [sp+32h] [bp-196h]
  unsigned __int16 *v45; // [sp+38h] [bp-190h]
  unsigned __int16 *v46; // [sp+3Ch] [bp-18Ch]
  unsigned __int16 v47; // [sp+40h] [bp-188h] BYREF
  _BYTE v48[6]; // [sp+42h] [bp-186h]
  unsigned int v49; // [sp+48h] [bp-180h]
  unsigned __int16 v50; // [sp+50h] [bp-178h] BYREF
  _BYTE v51[6]; // [sp+52h] [bp-176h]
  unsigned int v52; // [sp+58h] [bp-170h] BYREF
  int v53; // [sp+5Ch] [bp-16Ch] BYREF
  unsigned __int16 *v54; // [sp+60h] [bp-168h]
  int v55; // [sp+68h] [bp-160h] BYREF
  int v56; // [sp+6Ch] [bp-15Ch]
  unsigned __int16 v57; // [sp+70h] [bp-158h] BYREF
  _BYTE v58[6]; // [sp+72h] [bp-156h]
  unsigned __int16 v59; // [sp+78h] [bp-150h] BYREF
  _BYTE v60[6]; // [sp+7Ah] [bp-14Eh]
  int *v61; // [sp+80h] [bp-148h]
  int v62; // [sp+84h] [bp-144h] BYREF
  unsigned __int16 *v63; // [sp+88h] [bp-140h]
  int v64; // [sp+8Ch] [bp-13Ch]
  unsigned __int16 *v65; // [sp+90h] [bp-138h] BYREF
  _DWORD *v66; // [sp+94h] [bp-134h] BYREF
  unsigned __int16 v67; // [sp+98h] [bp-130h] BYREF
  int v68; // [sp+9Ch] [bp-12Ch]
  int v69; // [sp+A0h] [bp-128h] BYREF
  unsigned __int16 v70[4]; // [sp+A8h] [bp-120h] BYREF
  unsigned int v71; // [sp+B0h] [bp-118h]
  unsigned int v72; // [sp+B4h] [bp-114h]
  int v73; // [sp+B8h] [bp-110h]
  int v74[2]; // [sp+C0h] [bp-108h]
  _DWORD v75[2]; // [sp+C8h] [bp-100h] BYREF
  _DWORD v76[4]; // [sp+D0h] [bp-F8h] BYREF
  _DWORD v77[58]; // [sp+E0h] [bp-E8h] BYREF

  v4 = a4;
  v45 = a3;
  v46 = 0;
  v43 = 0;
  *(_DWORD *)v44 = 0;
  *(_WORD *)&v44[4] = 0;
  v47 = 0;
  *(_DWORD *)v48 = 0;
  *(_WORD *)&v48[4] = 0;
  v50 = 0;
  *(_DWORD *)v51 = 0;
  *(_WORD *)&v51[4] = 0;
  v62 = 0;
  v63 = 0;
  v59 = 0;
  *(_DWORD *)v60 = 0;
  *(_WORD *)&v60[4] = 0;
  v57 = 0;
  *(_DWORD *)v58 = 0;
  *(_WORD *)&v58[4] = 0;
  v64 = 0;
  v52 = 0;
  v53 = 0;
  v5 = 0;
  v69 = 1;
  v49 = 0;
  v73 = 0;
  v71 = 0;
  v55 = 0;
  v56 = 0;
  v54 = 0;
  v65 = 0;
  v6 = 0;
  v7 = 0;
  v61 = a1;
  v66 = 0;
  v8 = 0;
  v72 = 0;
  v9 = 0;
  v10 = PnpCtxRegOpenKey(a1, a2, (int)a3, 0);
  if ( v10 < 0 )
    goto LABEL_64;
  memset(v77, 0, 196);
  v77[1] = 304;
  v77[2] = L"HardwareIds";
  v77[3] = &v43;
  v77[4] = 117440512;
  v77[8] = 304;
  v77[9] = L"CompatibleIds";
  v77[10] = &v47;
  v77[11] = 117440512;
  v77[15] = 288;
  v77[16] = L"ContainerId";
  v77[17] = &v50;
  v77[18] = 0x1000000;
  v77[22] = 288;
  v77[23] = L"Capabilities";
  v77[24] = &v62;
  v77[25] = 0x4000000;
  v77[29] = 288;
  v77[30] = L"Description";
  v77[31] = &v59;
  v77[32] = 0x1000000;
  v77[36] = 288;
  v77[37] = L"LocationInfo";
  v77[38] = &v57;
  v77[39] = 0x1000000;
  v10 = RtlpQueryRegistryValues(-1073741824, v46, v77, 0, 131097, 1u);
  if ( v10 < 0 )
    goto LABEL_64;
  v11 = *(_DWORD *)&v44[2];
  if ( *(_DWORD *)&v44[2] && v43 <= 2u )
  {
    RtlFreeAnsiString(&v43);
    v11 = *(_DWORD *)&v44[2];
  }
  v12 = *(_DWORD *)&v48[2];
  if ( *(_DWORD *)&v48[2] && v47 <= 2u )
  {
    RtlFreeAnsiString(&v47);
    v11 = *(_DWORD *)&v44[2];
    v12 = *(_DWORD *)&v48[2];
  }
  v13 = *(_DWORD *)&v51[2];
  if ( !*(_DWORD *)&v51[2] )
    goto LABEL_14;
  if ( v50 < 2u )
  {
    RtlFreeAnsiString(&v50);
    v11 = *(_DWORD *)&v44[2];
    v12 = *(_DWORD *)&v48[2];
    v13 = *(_DWORD *)&v51[2];
  }
  if ( !v13 || (v14 = RtlGUIDFromString(&v50, v76), v11 = *(_DWORD *)&v44[2], v12 = *(_DWORD *)&v48[2], v14 < 0) )
  {
LABEL_14:
    v76[0] = 0;
    v76[1] = 0;
    v76[2] = 0;
    v76[3] = 0;
  }
  if ( *(_DWORD *)&v60[2] && v59 < 2u )
  {
    RtlFreeAnsiString(&v59);
    v11 = *(_DWORD *)&v44[2];
    v12 = *(_DWORD *)&v48[2];
  }
  if ( *(_DWORD *)&v58[2] && v57 < 2u )
  {
    RtlFreeAnsiString(&v57);
    v11 = *(_DWORD *)&v44[2];
    v12 = *(_DWORD *)&v48[2];
  }
  if ( !v11 && !v12 )
  {
    v10 = -1073741637;
    goto LABEL_64;
  }
  v74[0] = 2;
  v74[1] = 3;
  v75[0] = v11;
  v15 = *v4;
  v75[1] = v12;
  if ( v15 != IopRootDeviceNode )
  {
    while ( 1 )
    {
      if ( *(_DWORD *)(*(_DWORD *)(v15 + 16) + 8) == PiSwDeviceDriverObject )
      {
        RtlInitUnicodeString((unsigned int)v70, L"SWD\\");
        if ( RtlPrefixUnicodeString(v70, (unsigned __int16 *)(v15 + 20), 1) )
        {
          RtlInitUnicodeString((unsigned int)&v67, (unsigned __int16 *)(*(_DWORD *)(v15 + 24) + 2 * (v70[0] >> 1)));
          RtlInitUnicodeString((unsigned int)v70, L"DRIVERENUM");
          if ( RtlPrefixUnicodeString(v70, &v67, 1) )
          {
            if ( *(_WORD *)(v68 + 2 * (v70[0] >> 1)) == 92 )
            {
              if ( !v64 )
              {
                v10 = PnpGenerateDeviceIdsHash(*(int *)&v44[2], *(int *)&v48[2], &v53);
                if ( v10 < 0 )
                  goto LABEL_62;
                if ( (v62 & 8) != 0 )
                {
                  v16 = v53;
                }
                else
                {
                  RtlInitUnicodeString((unsigned int)&v67, L"SWD\\GenericRaw");
                  v10 = RtlHashUnicodeString(&v67, 1, 0, &v52);
                  if ( v10 < 0 )
                    goto LABEL_62;
                  v16 = v52 + v53;
                }
                RtlInitUnicodeString((unsigned int)&v67, L"SWD\\Generic");
                v10 = RtlHashUnicodeString(&v67, 1, 0, &v52);
                if ( v10 < 0 )
                  goto LABEL_62;
                v64 = v52 + v16;
                v53 = v52 + v16;
              }
              if ( *(_DWORD *)(v15 + 444) == v64 )
              {
                if ( !v5 )
                {
                  v49 = 2048;
                  v5 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2048, 538996816);
                  v63 = v5;
                  if ( !v5 )
                  {
                    v10 = -1073741670;
LABEL_62:
                    v6 = 0;
                    goto LABEL_63;
                  }
                }
                v17 = v49;
                for ( i = 0; i < 2; ++i )
                {
                  v19 = v74[i];
                  v42 = v17;
                  v10 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v15 + 24), 0, v19, (int)&v69, (int)v5, (int)&v42);
                  if ( v10 < 0 || v69 != 7 || v42 < 2 )
                  {
                    *v5 = 0;
                    v10 = 0;
                  }
                  if ( i == 1 )
                  {
                    v21 = *v5;
                    v22 = v5;
                    while ( v21 )
                    {
                      if ( !wcsicmp((int)v22, L"SWD\\GenericRaw") || !wcsicmp((int)v22, L"SWD\\Generic") )
                      {
                        *v22 = 0;
                        break;
                      }
                      v22 += wcslen(v22) + 1;
                      v21 = *v22;
                    }
                  }
                  if ( v75[i] )
                  {
                    if ( !PnpCompareMultiSz((unsigned __int16 *)v75[i], (int)v5, v20, (int)v75) )
                      break;
                  }
                  else if ( *v5 )
                  {
                    break;
                  }
                }
                v8 = 0;
                v9 = 0;
                if ( i >= 2 )
                  break;
              }
            }
          }
        }
      }
      v15 = *(_DWORD *)(v15 + 8);
      if ( v15 == IopRootDeviceNode )
        goto LABEL_76;
    }
    v10 = -1073740028;
LABEL_76:
    v6 = 0;
    v7 = 0;
  }
  if ( v10 < 0 )
    goto LABEL_63;
  v24 = IopGetRegistryValue((int)v46, L"Security", 0, (int *)&v66);
  v6 = (unsigned int)v66;
  v10 = v24;
  v49 = (unsigned int)v66;
  if ( v24 >= 0 )
  {
    if ( v66[1] != 3 || (v71 = v66[3], v71 < 0x14) )
    {
      v10 = -1073741823;
LABEL_122:
      v4 = a4;
LABEL_123:
      if ( v9 )
      {
        if ( v8 )
        {
          v39 = v9;
          do
          {
            v40 = *((_DWORD *)v39 + 9);
            if ( v40 )
              ExFreePoolWithTag(v40);
            v39 += 20;
            --v8;
          }
          while ( v8 );
        }
        ExFreePoolWithTag((unsigned int)v9);
      }
      v6 = v49;
LABEL_131:
      if ( v72 )
        ExFreePoolWithTag(v72);
      v5 = v63;
      goto LABEL_64;
    }
    v73 = (int)v66 + v66[2];
  }
  else if ( v24 != -1073741772 )
  {
LABEL_63:
    v4 = a4;
    goto LABEL_64;
  }
  v4 = a4;
  if ( *a4 == IopRootDeviceNode )
  {
    if ( !RtlCreateUnicodeString((int)&v55, v45) )
      goto LABEL_87;
LABEL_92:
    for ( j = PnpGetGenericStorePropertyKeys(v61, (int)v46, 0, 0, 0, 0, &v42);
          ;
          j = PnpGetGenericStorePropertyKeys(v61, (int)v46, 0, 0, j, v27, &v42) )
    {
      v10 = j;
      if ( j != -1073741789 )
      {
        v8 = v42;
        goto LABEL_100;
      }
      v27 = v42;
      if ( v42 <= v8 )
      {
        v10 = -1073741595;
        goto LABEL_131;
      }
      if ( v7 )
      {
        ExFreePoolWithTag(v7);
        v27 = v42;
      }
      v8 = v27;
      j = ExAllocatePoolWithTag(1, 20 * v27, 538996816);
      v7 = j;
      v72 = j;
      if ( !j )
        break;
    }
    v10 = -1073741670;
LABEL_100:
    if ( v10 < 0 )
      goto LABEL_131;
    if ( v8 )
    {
      v28 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 40 * v8, 538996816);
      v29 = v28;
      v45 = v28;
      if ( !v28 )
      {
        v10 = -1073741670;
        goto LABEL_131;
      }
      memset(v28, 0, 40 * v8);
      v30 = 0;
      v31 = (_DWORD *)v7;
      v32 = v29;
      while ( 2 )
      {
        v33 = v31[1];
        v34 = v31[2];
        v35 = v31[3];
        *(_DWORD *)v32 = *v31;
        *((_DWORD *)v32 + 1) = v33;
        *((_DWORD *)v32 + 2) = v34;
        *((_DWORD *)v32 + 3) = v35;
        *((_DWORD *)v32 + 4) = v31[4];
        *((_DWORD *)v32 + 5) = 0;
        while ( 1 )
        {
          j = PnpGetGenericStoreProperty(
                (int)v61,
                (int)v46,
                0,
                (int)v31,
                (_DWORD *)v32 + 7,
                *((_DWORD *)v32 + 9),
                *((_DWORD *)v32 + 8),
                &v42);
          v10 = j;
          if ( j != -1073741789 )
            break;
          v36 = v42;
          if ( v42 <= *((_DWORD *)v32 + 8) )
          {
            v10 = -1073741595;
            goto LABEL_121;
          }
          v37 = *((_DWORD *)v32 + 9);
          if ( v37 )
          {
            ExFreePoolWithTag(v37);
            v36 = v42;
          }
          *((_DWORD *)v32 + 8) = v36;
          j = ExAllocatePoolWithTag(1, v42, 538996816);
          *((_DWORD *)v32 + 9) = j;
          if ( !j )
          {
            v10 = -1073741670;
            goto LABEL_115;
          }
        }
        *((_DWORD *)v32 + 8) = v42;
LABEL_115:
        if ( v10 < 0 )
        {
LABEL_121:
          v9 = v45;
          goto LABEL_122;
        }
        ++v30;
        v32 += 20;
        v31 += 5;
        if ( v30 < v8 )
          continue;
        break;
      }
      v9 = v45;
      v4 = a4;
    }
    if ( *(_DWORD *)&v51[2] )
      v38 = v76;
    else
      v38 = 0;
    v10 = PiSwStartCreate(
            j,
            *(_DWORD *)(*v4 + 24),
            v56,
            *(int *)&v44[2],
            *(int *)&v48[2],
            (int)v38,
            v62,
            *(int *)&v60[2],
            *(int *)&v58[2],
            v73,
            v71,
            (int)v9,
            v8);
    goto LABEL_123;
  }
  v10 = PipMakeGloballyUniqueId(*(_DWORD *)(*a4 + 16), 0, &v65);
  if ( v10 < 0 )
  {
    v54 = v65;
    goto LABEL_64;
  }
  LOWORD(v55) = 0;
  v25 = wcslen(v45);
  v54 = v65;
  HIWORD(v55) = 2 * (wcslen(v65) + v25 + 2);
  v56 = ExpAllocateStringRoutine(HIWORD(v55));
  if ( !v56 )
  {
LABEL_87:
    v10 = -1073741670;
    goto LABEL_64;
  }
  v10 = RtlUnicodeStringPrintf(&v55, (int)L"%ws&%ws", (int)v45, (int)v54);
  if ( v10 >= 0 )
    goto LABEL_92;
LABEL_64:
  RtlFreeAnsiString(&v55);
  if ( v54 )
    ExFreePoolWithTag((unsigned int)v54);
  RtlFreeAnsiString(&v43);
  RtlFreeAnsiString(&v47);
  RtlFreeAnsiString(&v50);
  RtlFreeAnsiString(&v59);
  RtlFreeAnsiString(&v57);
  if ( v6 )
    ExFreePoolWithTag(v6);
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  if ( v46 )
    ZwClose();
  if ( (int)v4[1] >= 0 )
    v4[1] = v10;
  return 0;
}
