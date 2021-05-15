// PiDevCfgResolveVariableKeyCopy 
 
int __fastcall PiDevCfgResolveVariableKeyCopy(int a1, int a2, _DWORD *a3)
{
  int v5; // r7
  int v6; // r5
  unsigned int v7; // r0
  unsigned int v8; // r3
  __int64 v9; // kr00_8
  unsigned __int16 *v10; // r1
  unsigned __int16 *v11; // r4
  int v12; // r3
  bool v13; // zf
  int v14; // r3
  unsigned int v15; // r3
  int v16; // r4
  int v18; // [sp+0h] [bp-18h] BYREF
  int v19[5]; // [sp+4h] [bp-14h] BYREF

  v18 = 0;
  v19[0] = 0;
  v5 = 0;
  v6 = PiDevCfgResolveVariableKeyHandle(a1, a2, &v18);
  if ( v6 < 0 )
  {
    v16 = v18;
    goto LABEL_32;
  }
  v6 = IopGetRegistryValue(a2, L"Delete", 0, v19);
  v7 = v19[0];
  if ( v6 >= 0 )
  {
    v8 = *(_DWORD *)(v19[0] + 4);
    if ( v8 )
    {
      if ( v8 <= 2 )
      {
        v15 = *(_DWORD *)(v19[0] + 12);
        if ( v15 >= 2 )
        {
          v12 = *(unsigned __int16 *)(*(_DWORD *)(v19[0] + 8) + 2 * (v15 >> 1) + v19[0] - 2);
          goto LABEL_14;
        }
LABEL_19:
        v14 = 0;
        goto LABEL_23;
      }
      if ( v8 == 4 )
      {
        v13 = *(_DWORD *)(v19[0] + 12) == 4;
LABEL_15:
        if ( !v13 )
          goto LABEL_19;
LABEL_17:
        v14 = 1;
LABEL_23:
        if ( v14 )
        {
          if ( *(_DWORD *)(*(_DWORD *)(v19[0] + 8) + v19[0]) )
            v5 = 0x100000;
          goto LABEL_28;
        }
        v6 = -1073741823;
LABEL_25:
        v16 = v18;
        goto LABEL_29;
      }
      if ( v8 == 7 )
      {
        v9 = *(_QWORD *)(v19[0] + 8);
        v10 = (unsigned __int16 *)(v9 + v19[0]);
        if ( HIDWORD(v9) >= 4 )
        {
          v11 = &v10[HIDWORD(v9) >> 1];
          if ( !*(v11 - 1) && !*(v11 - 2) )
            goto LABEL_17;
        }
        if ( HIDWORD(v9) == 2 )
        {
          v12 = *v10;
LABEL_14:
          v13 = v12 == 0;
          goto LABEL_15;
        }
        goto LABEL_19;
      }
    }
    v14 = 1;
    goto LABEL_23;
  }
  if ( v6 != -1073741772 )
    goto LABEL_25;
  v6 = 0;
LABEL_28:
  a3[4] = v5 | 0x8000;
  a3[5] = 0;
  v16 = 0;
  a3[6] = v18;
LABEL_29:
  if ( v7 )
    ExFreePoolWithTag(v7);
LABEL_32:
  if ( v16 )
    ZwClose();
  return v6;
}
