// IopPnPDispatch 
 
int __fastcall IopPnPDispatch(int a1, _DWORD *a2, __int64 a3)
{
  int v4; // r7
  int *v5; // r5
  int v7; // r2
  int v8; // r4
  int v9; // r1
  _DWORD *v10; // r3
  int v11; // r4
  int v13; // r10
  int v14; // r3
  int v15; // r1
  unsigned int v16; // r8
  int v17; // r3
  unsigned int v18; // r0
  _WORD *v19; // r1
  _WORD *v20; // r2
  unsigned int v21; // r3
  GUID *v22; // r8
  int *v23; // r0
  int *v24; // r9
  int v25; // r8
  int v26; // t1
  int *v27; // r0
  int *v28; // r4
  int v29; // r0
  int v30; // r4
  int v31; // t1
  int v32; // r0
  int v33; // r3
  int v34; // r1
  int v35; // r0
  unsigned int v36; // [sp+10h] [bp-30h] BYREF
  int *v37; // [sp+14h] [bp-2Ch] BYREF
  int v38; // [sp+18h] [bp-28h] BYREF
  int v39[9]; // [sp+1Ch] [bp-24h] BYREF

  v4 = a2[24];
  v5 = 0;
  v7 = *(unsigned __int8 *)(v4 + 1);
  v37 = 0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
    case 22:
      goto LABEL_8;
    case 4:
    case 5:
      goto LABEL_69;
    case 7:
      if ( a1 == *(_DWORD *)(IopRootDeviceNode + 16) && !*(_DWORD *)(v4 + 8) )
      {
        v11 = IopGetRootDevices(&v37);
LABEL_58:
        v5 = v37;
        goto LABEL_13;
      }
      HIDWORD(a3) = *(_DWORD *)(v4 + 8);
      if ( HIDWORD(a3) != 4 )
        goto LABEL_11;
      v27 = (int *)ExAllocatePoolWithTag(1, 8, 1684303952);
      v28 = v27;
      if ( v27 )
      {
        *v27 = 1;
        v27[1] = a1;
        ObfReferenceObject(a1);
        goto LABEL_61;
      }
      goto LABEL_94;
    case 8:
      v11 = a2[6];
      HIDWORD(a3) = IopRootDeviceNode;
      if ( *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) != IopRootDeviceNode )
        goto LABEL_13;
      v22 = *(GUID **)(v4 + 8);
      if ( v22 == &GUID_ARBITER_INTERFACE_STANDARD
        || RtlCompareMemory(*(unsigned __int8 **)(v4 + 8), (int)&GUID_ARBITER_INTERFACE_STANDARD, 16) == 16 )
      {
        LODWORD(a3) = *(_DWORD *)(v4 + 16);
        v11 = 0;
        *(_DWORD *)(a3 + 16) = ArbArbiterHandler;
        HIDWORD(a3) = *(unsigned __int8 *)(v4 + 20);
        if ( HIDWORD(a3) == 2 )
        {
          HIDWORD(a3) = &IopRootIrqArbiter;
        }
        else
        {
          if ( HIDWORD(a3) != 3 )
            return sub_80D6F0();
          HIDWORD(a3) = &IopRootMemArbiter;
        }
        *(_DWORD *)(a3 + 4) = HIDWORD(a3);
      }
      else if ( v22 == &GUID_TRANSLATOR_INTERFACE_STANDARD
             || RtlCompareMemory((unsigned __int8 *)v22, (int)&GUID_TRANSLATOR_INTERFACE_STANDARD, 16) == 16 )
      {
        LODWORD(a3) = *(_DWORD *)(v4 + 16);
        *(_DWORD *)(a3 + 16) = IopTranslatorHandlerCm;
        HIDWORD(a3) = IopTranslatorHandlerIo;
        *(_DWORD *)(a3 + 20) = IopTranslatorHandlerIo;
        goto LABEL_8;
      }
      goto LABEL_13;
    case 9:
      v8 = *(_DWORD *)(v4 + 8);
      v9 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      *(_WORD *)v8 = 64;
      *(_WORD *)(v8 + 2) = 1;
      if ( a1 == *(_DWORD *)(IopRootDeviceNode + 16) )
      {
        v33 = *(_DWORD *)(v8 + 4);
        *(_DWORD *)(v8 + 12) = 0;
        *(_DWORD *)(v8 + 4) = v33 | 0x1C0;
      }
      v10 = (_DWORD *)(v8 + 24);
      *(_DWORD *)(v8 + 16) = 0;
      *(_DWORD *)(v8 + 20) = 1;
      do
        *v10++ = 4;
      while ( v10 != (_DWORD *)(v8 + 44) );
      HIDWORD(a3) = *(_DWORD *)(v8 + 12);
      if ( HIDWORD(a3) == -1 )
      {
        v36 = 4;
        if ( CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v9 + 24), 0, 17, (int)&v38, (int)v39, (int)&v36) >= 0 )
        {
          HIDWORD(a3) = v38;
          if ( v38 == 4 )
          {
            HIDWORD(a3) = v36;
            if ( v36 == 4 )
            {
              HIDWORD(a3) = v39[0];
              *(_DWORD *)(v8 + 12) = v39[0];
            }
          }
        }
      }
      goto LABEL_8;
    case 10:
      v32 = PnpGetDeviceResourcesFromRegistry(a1, 0, 4, (int *)&v37, &v36);
      goto LABEL_81;
    case 11:
      v32 = PnpGetDeviceResourcesFromRegistry(a1, 1, 2, (int *)&v37, &v36);
LABEL_81:
      HIDWORD(a3) = -1073741772;
      v11 = v32;
      if ( v32 != -1073741772 )
        goto LABEL_58;
      v11 = 0;
      goto LABEL_83;
    case 12:
      HIDWORD(a3) = *(_DWORD *)(v4 + 8);
      if ( HIDWORD(a3) != 1 )
        goto LABEL_11;
      HIDWORD(a3) = a2[7];
      if ( HIDWORD(a3) )
        goto LABEL_11;
      v30 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      v36 = 0;
      PiGetDeviceRegProperty(*(char **)(v30 + 24), (int)a2, 1, 14, 0, &v36);
      if ( !v36 )
      {
LABEL_69:
        v11 = -1073741823;
        goto LABEL_13;
      }
      v5 = (int *)ExAllocatePoolWithTag(1, v36, 1684303952);
      if ( !v5 )
        goto LABEL_94;
      v35 = PiGetDeviceRegProperty(*(char **)(v30 + 24), v34, 1, 14, (int)v5, &v36);
      v11 = v35;
      if ( v35 < 0 )
      {
        if ( v35 == -1073741275 )
          v11 = -1073741772;
        ExFreePoolWithTag((unsigned int)v5);
LABEL_83:
        v5 = 0;
      }
      goto LABEL_13;
    case 19:
      HIDWORD(a3) = *(_DWORD *)(IopRootDeviceNode + 16);
      if ( a1 == HIDWORD(a3) )
        goto LABEL_11;
      v11 = a2[6];
      if ( v11 >= 0 )
      {
        HIDWORD(a3) = a2[7];
        if ( HIDWORD(a3) )
          goto LABEL_11;
      }
      v13 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      HIDWORD(a3) = *(_DWORD *)(v4 + 8);
      if ( !HIDWORD(a3) )
        goto LABEL_47;
      if ( SHIDWORD(a3) <= 0 )
        goto LABEL_12;
      if ( SHIDWORD(a3) > 2 )
      {
        if ( HIDWORD(a3) == 3 )
        {
LABEL_47:
          v23 = (int *)ExAllocatePoolWithTag(1, *(unsigned __int16 *)(v13 + 20), 1684303952);
          v24 = v23;
          if ( v23 )
          {
            v25 = 0;
            memset(v23, 0, *(unsigned __int16 *)(v13 + 20));
            LODWORD(a3) = *(_DWORD *)(v13 + 24);
            v11 = 0;
            v5 = v24;
            if ( *(_DWORD *)(v4 + 8) )
            {
              while ( *(_WORD *)a3 )
              {
                if ( *(_WORD *)a3 == 92 && ++v25 == 2 )
                {
                  LODWORD(a3) = a3 + 2;
                  break;
                }
                LODWORD(a3) = a3 + 2;
              }
              for ( HIDWORD(a3) = *(unsigned __int16 *)a3; HIDWORD(a3); HIDWORD(a3) = v31 )
              {
                *(_WORD *)v24 = WORD2(a3);
                v24 = (int *)((char *)v24 + 2);
                v31 = *(unsigned __int16 *)(a3 + 2);
                LODWORD(a3) = a3 + 2;
              }
            }
            else
            {
              for ( HIDWORD(a3) = *(unsigned __int16 *)a3; HIDWORD(a3); HIDWORD(a3) = v26 )
              {
                if ( HIDWORD(a3) == 92 && ++v25 == 2 )
                  break;
                *(_WORD *)v24 = WORD2(a3);
                v24 = (int *)((char *)v24 + 2);
                v26 = *(unsigned __int16 *)(a3 + 2);
                LODWORD(a3) = a3 + 2;
              }
            }
            goto LABEL_13;
          }
        }
        else
        {
          if ( HIDWORD(a3) != 5 )
            goto LABEL_12;
          v29 = ExAllocatePoolWithTag(1, 78, 1684303952);
          v28 = (int *)v29;
          if ( v29 )
          {
            memmove(v29, (int)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}", 0x4Eu);
LABEL_61:
            v5 = v28;
LABEL_8:
            v11 = 0;
            goto LABEL_13;
          }
        }
LABEL_94:
        v11 = -1073741670;
        goto LABEL_13;
      }
      HIDWORD(a3) = -1073741637;
      if ( v11 == -1073741637 )
      {
        v36 = 0;
        if ( *(_DWORD *)(v4 + 8) == 1 )
          v14 = 2;
        else
          v14 = 3;
        v11 = PiGetDeviceRegProperty(*(char **)(v13 + 24), (int)a2, 7, v14, 0, &v36);
        if ( v11 == -1073741789 )
        {
          v16 = ExAllocatePoolWithTag(1, v36, 1684303952);
          if ( v16 )
          {
            if ( *(_DWORD *)(v4 + 8) == 1 )
              v17 = 2;
            else
              v17 = 3;
            v11 = PiGetDeviceRegProperty(*(char **)(v13 + 24), v15, 7, v17, v16, &v36);
            if ( v11 < 0 )
            {
              ExFreePoolWithTag(v16);
            }
            else
            {
              v18 = v36;
              v19 = 0;
              v20 = (_WORD *)v16;
              if ( v16 < v16 + 2 * (v36 >> 1) )
              {
                do
                {
                  v21 = (unsigned __int16)*v20;
                  if ( *v20 )
                  {
                    if ( v21 < 0x20 || v21 > 0x7F || v21 == 44 )
                    {
                      *v20 = 63;
                      v18 = v36;
                    }
                  }
                  else
                  {
                    if ( v19 && v20 == v19 + 1 )
                      break;
                    v19 = v20;
                  }
                  ++v20;
                }
                while ( (unsigned int)v20 < v16 + 2 * (v18 >> 1) );
              }
              v5 = (int *)v16;
            }
          }
          else
          {
            v11 = -1073741670;
          }
        }
        HIDWORD(a3) = -1073741275;
        if ( v11 == -1073741275 )
        {
LABEL_11:
          v11 = a2[6];
LABEL_12:
          v5 = (int *)a2[7];
          goto LABEL_13;
        }
      }
LABEL_13:
      LODWORD(a3) = v5;
      IopPnPCompleteRequest((int)a2, a3);
      return v11;
    default:
      goto LABEL_11;
  }
}
