// VfPnpVerifyIrpStackUpward 
 
int __fastcall VfPnpVerifyIrpStackUpward(int *a1, int a2, int a3, int a4, int a5)
{
  int result; // r0
  int v9; // lr
  int v10; // r10
  int v11; // r7
  int v12; // r3
  BOOL v13; // r4
  int v14; // r0
  int v15; // r3
  int v16; // r3
  int v17; // r0
  int v18; // r5
  int v19; // r4
  int v20; // [sp+8h] [bp-28h]
  int v21; // [sp+Ch] [bp-24h]

  result = IovUtilIsWdmStack(*(_DWORD *)(a2 + 24));
  if ( result )
  {
    v9 = *a1;
    v10 = *(_DWORD *)(a4 + 24);
    v20 = a1[35];
    v21 = *a1;
    v11 = *(_DWORD *)(*a1 + 24);
    if ( a5 )
    {
      v12 = *(_DWORD *)(a4 + 4);
      result = a1[9] & 0x20;
      v13 = (v12 & 0x10000000) != 0;
      if ( v12 < 0 )
      {
LABEL_17:
        if ( !v13 )
          goto LABEL_22;
LABEL_18:
        if ( v11 == -1073741637 )
          v16 = 1;
        else
          v16 = 2;
        result = ViPnpVerifyMinorWasProcessedProperly(v9, a2, 0, v16, v10, 0);
        goto LABEL_22;
      }
      if ( (v12 & 0x10000000) != 0 )
        goto LABEL_18;
      if ( *(_BYTE *)(a2 + 1) != 8 )
      {
        if ( (a1[9] & 0x20) == 0 && v11 < 0 && v11 != -1073741637 )
          goto LABEL_26;
        if ( result )
        {
          v14 = 557;
LABEL_11:
          result = VfErrorReport1(v14, v10, v9);
          goto LABEL_22;
        }
        v15 = VfIoSwitchedOffNoReboot;
        __dmb(0xBu);
        if ( v15 )
          goto LABEL_22;
        if ( v11 >= 0 )
        {
          v14 = 558;
          goto LABEL_11;
        }
        if ( v11 != -1073741637 )
          goto LABEL_26;
        result = VfErrorReport1(559, v10, v9);
        v9 = v21;
        goto LABEL_17;
      }
    }
LABEL_22:
    if ( v11 == -1073741637 && (*(_DWORD *)(a3 + 4) & 0x2000000) == 0 && *(_DWORD *)(a3 + 64) != -1073741637 )
    {
      result = VfErrorReport1(534, v10, v21);
      *(_DWORD *)(a3 + 4) |= 0x2000000u;
    }
LABEL_26:
    if ( *(_BYTE *)(a2 + 1) != 23 )
      return result;
    v17 = IovUtilGetLowerDeviceObject(*(_DWORD *)(a2 + 24));
    if ( v17 )
    {
      ObfDereferenceObject(v17);
    }
    else if ( !IovUtilIsPdo(*(_DWORD *)(a2 + 24)) )
    {
      v18 = v20;
      VfErrorReport10(577, v10, *(_DWORD *)(v20 + 32), *(_DWORD *)(a2 + 24));
LABEL_30:
      v19 = *(_DWORD *)(a2 + 24);
      result = IovUtilIsDeviceObjectMarked(v19, 0);
      if ( result )
        result = VfErrorReport10(578, v10, *(_DWORD *)(v18 + 32), v19);
      return result;
    }
    v18 = v20;
    goto LABEL_30;
  }
  return result;
}
