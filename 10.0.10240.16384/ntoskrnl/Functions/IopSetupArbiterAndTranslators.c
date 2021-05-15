// IopSetupArbiterAndTranslators 
 
int __fastcall IopSetupArbiterAndTranslators(int a1)
{
  int v1; // r1
  int v2; // r7
  int v3; // r3
  unsigned int v5; // r6
  int v6; // r9
  int result; // r0
  int v8; // r2
  BOOL v9; // r10
  __int64 v10; // r4
  int v11; // r7
  _DWORD *v12; // r1
  int v13; // r2
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r7
  _DWORD *v18; // r1
  _DWORD *v19; // r0
  int v20; // [sp+8h] [bp-38h] BYREF
  int v21; // [sp+Ch] [bp-34h]
  int v22; // [sp+10h] [bp-30h] BYREF
  _DWORD *v23; // [sp+14h] [bp-2Ch] BYREF
  int v24; // [sp+18h] [bp-28h]
  int v25; // [sp+1Ch] [bp-24h]
  int v26; // [sp+20h] [bp-20h]

  v24 = 1;
  v1 = *(_DWORD *)(a1 + 40);
  v2 = 0;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 36);
  v26 = v1;
  v5 = *(unsigned __int8 *)(v3 + 1);
  v6 = 0;
  v21 = 0;
  if ( v5 == 7 )
    return sub_80DFA0();
  v8 = *(_DWORD *)(a1 + 44);
  v9 = v8 == 1 && !*(_DWORD *)a1;
  if ( v8 == 1 || !v1 )
    HIDWORD(v10) = IopRootDeviceNode;
  else
    HIDWORD(v10) = *(_DWORD *)(*(_DWORD *)(v1 + 176) + 20);
  if ( !HIDWORD(v10) )
    return -1073741686;
  while ( 1 )
  {
    if ( HIDWORD(v10) != IopRootDeviceNode || v9 || v2 )
    {
      if ( v6 )
        goto LABEL_18;
      v11 = *(_DWORD *)(HIDWORD(v10) + 16);
      if ( v11 == v1 )
      {
LABEL_17:
        v2 = v21;
LABEL_18:
        if ( !v24 )
        {
LABEL_24:
          HIDWORD(v10) = *(_DWORD *)(HIDWORD(v10) + 8);
          goto LABEL_25;
        }
        if ( IopFindResourceHandlerInfo(1, HIDWORD(v10), v5, &v23) )
          goto LABEL_20;
        if ( v5 > 0xF )
          LOWORD(v10) = 0;
        else
          LOWORD(v10) = 1 << v5;
        v14 = IopQueryResourceHandlerInterface(1, *(_DWORD *)(HIDWORD(v10) + 16), v5, &v20);
        *(_WORD *)(HIDWORD(v10) + 346) |= v10;
        if ( v14 >= 0 )
        {
          LODWORD(v10) = v20;
        }
        else
        {
          *(_WORD *)(HIDWORD(v10) + 344) |= v10;
          if ( v5 <= 0xF )
          {
LABEL_20:
            v12 = v23;
LABEL_21:
            if ( v12 )
            {
              v2 = 1;
              v21 = 1;
            }
            if ( v12 && !v6 )
            {
              result = IopTranslateAndAdjustReqDesc(*(_DWORD *)(a1 + 20));
              if ( result < 0 )
                return result;
              v13 = v25;
              v5 = *(unsigned __int8 *)(*(_DWORD *)(v25 + 36) + 1);
              if ( v5 == 7 )
                v5 = 3;
              *(_DWORD *)(v25 + 20) = *(_DWORD *)(a1 + 20);
              *(_DWORD *)(a1 + 20) = v13;
              if ( result == 288 )
                v24 = 0;
            }
            goto LABEL_24;
          }
          LODWORD(v10) = 0;
          v20 = 0;
        }
        v16 = ExAllocatePoolWithTag(257, 20, 538996816);
        v12 = (_DWORD *)v16;
        v23 = (_DWORD *)v16;
        if ( !v16 )
          return -1073741670;
        *(_BYTE *)(v16 + 8) = v5;
        *(_DWORD *)v16 = v16;
        *(_DWORD *)(v16 + 4) = v16;
        *(_QWORD *)(v16 + 12) = v10;
        v19 = *(_DWORD **)(HIDWORD(v10) + 340);
        *v12 = HIDWORD(v10) + 336;
        v12[1] = v19;
        if ( *v19 != HIDWORD(v10) + 336 )
          __fastfail(3u);
        *v19 = v12;
        *(_DWORD *)(HIDWORD(v10) + 340) = v12;
        if ( !(_DWORD)v10 )
        {
          v12 = 0;
          v23 = 0;
        }
        goto LABEL_21;
      }
      if ( IopFindResourceHandlerInfo(2, HIDWORD(v10), v5, &v22) )
        goto LABEL_13;
      if ( v5 > 0xF )
        LOWORD(v10) = 0;
      else
        LOWORD(v10) = 1 << v5;
      v15 = IopQueryResourceHandlerInterface(2, v11, v5, &v20);
      *(_WORD *)(HIDWORD(v10) + 350) |= v10;
      if ( v15 >= 0 )
      {
        v17 = v20;
      }
      else
      {
        *(_WORD *)(HIDWORD(v10) + 348) |= v10;
        if ( v5 <= 0xF )
        {
LABEL_13:
          LODWORD(v10) = v22;
LABEL_14:
          if ( (_DWORD)v10 )
          {
            v6 = 1;
            if ( (*(_DWORD *)(*(_DWORD *)(v10 + 12) + 20) & 1) != 0 && IopCallArbiter(v10, 7, *(int **)(a1 + 20)) < 0 )
            {
              v6 = 0;
            }
            else
            {
              *(_DWORD *)(a1 + 176) = v10;
              *(_BYTE *)(v10 + 52) = 0;
              *(_BYTE *)(v10 + 53) = 0;
            }
          }
          goto LABEL_17;
        }
        v17 = 0;
        v20 = 0;
      }
      LODWORD(v10) = ExAllocatePoolWithTag(257, 56, 538996816);
      v22 = v10;
      if ( !(_DWORD)v10 )
        return -1073741670;
      *(_BYTE *)(v10 + 53) = 0;
      *(_BYTE *)(v10 + 52) = 0;
      *(_DWORD *)(v10 + 44) = v10 + 44;
      *(_DWORD *)(v10 + 48) = v10 + 44;
      *(_DWORD *)(v10 + 36) = v10 + 36;
      *(_DWORD *)(v10 + 40) = v10 + 36;
      *(_DWORD *)(v10 + 20) = v10 + 20;
      *(_DWORD *)(v10 + 24) = v10 + 20;
      *(_DWORD *)(v10 + 28) = v10 + 28;
      *(_DWORD *)(v10 + 32) = v10 + 28;
      *(_DWORD *)v10 = v10;
      *(_DWORD *)(v10 + 4) = v10;
      *(_BYTE *)(v10 + 8) = v5;
      *(_DWORD *)(v10 + 16) = HIDWORD(v10);
      v18 = *(_DWORD **)(HIDWORD(v10) + 332);
      *(_DWORD *)v10 = HIDWORD(v10) + 328;
      *(_DWORD *)(v10 + 4) = v18;
      if ( *v18 != HIDWORD(v10) + 328 )
        __fastfail(3u);
      *v18 = v10;
      *(_DWORD *)(HIDWORD(v10) + 332) = v10;
      *(_DWORD *)(v10 + 12) = v17;
      if ( !v17 )
      {
        LODWORD(v10) = 0;
        v22 = 0;
      }
      goto LABEL_14;
    }
    v9 = 1;
    HIDWORD(v10) = IopFindLegacyBusDeviceNode(*(_DWORD *)a1, *(_DWORD *)(a1 + 4));
    if ( HIDWORD(v10) == IopRootDeviceNode && !**(_DWORD **)(*(_DWORD *)(a1 + 12) + 8) )
      HIDWORD(v10) = IopFindLegacyBusDeviceNode(1, 0);
LABEL_25:
    if ( !HIDWORD(v10) )
      break;
    v1 = v26;
  }
  if ( !v6 )
    return -1073741686;
  return 0;
}
