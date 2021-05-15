// PiDevCfgResolveVariableConstant 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDevCfgResolveVariableConstant(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  unsigned int v6; // r4
  int v7; // r8
  unsigned int v8; // r5 OVERLAPPED
  __int64 v9; // kr00_8
  unsigned __int16 *v10; // r1
  unsigned __int16 *v11; // r0
  int v12; // r3
  bool v13; // zf
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r6 OVERLAPPED
  int v17; // r0
  int v18; // r7
  int v20[8]; // [sp+0h] [bp-20h] BYREF

  v20[1] = a4;
  v20[0] = 0;
  v5 = IopGetRegistryValue(a2, L"Value", 0, v20);
  v6 = v20[0];
  v7 = v5;
  if ( v5 < 0 )
    goto LABEL_28;
  v8 = *(_DWORD *)(v20[0] + 4);
  if ( !v8 )
    goto LABEL_19;
  if ( v8 <= 2 )
  {
    v15 = *(_DWORD *)(v20[0] + 12);
    if ( v15 >= 2 )
    {
      v12 = *(unsigned __int16 *)(*(_DWORD *)(v20[0] + 8) + 2 * (v15 >> 1) + v20[0] - 2);
      goto LABEL_11;
    }
LABEL_16:
    v14 = 0;
    goto LABEL_20;
  }
  if ( v8 != 4 )
  {
    if ( v8 == 7 )
    {
      v9 = *(_QWORD *)(v20[0] + 8);
      v10 = (unsigned __int16 *)(v9 + v20[0]);
      if ( HIDWORD(v9) >= 4 )
      {
        v11 = &v10[HIDWORD(v9) >> 1];
        if ( !*(v11 - 1) && !*(v11 - 2) )
          goto LABEL_14;
      }
      if ( HIDWORD(v9) == 2 )
      {
        v12 = *v10;
LABEL_11:
        v13 = v12 == 0;
        goto LABEL_12;
      }
      goto LABEL_16;
    }
LABEL_19:
    v14 = 1;
    goto LABEL_20;
  }
  v13 = *(_DWORD *)(v20[0] + 12) == 4;
LABEL_12:
  if ( !v13 )
    goto LABEL_16;
LABEL_14:
  v14 = 1;
LABEL_20:
  if ( !v14 )
  {
    v7 = -1073741823;
    goto LABEL_28;
  }
  v16 = *(_DWORD *)(v20[0] + 12);
  if ( v16 )
  {
    v17 = ExAllocatePoolWithTag(1, *(_DWORD *)(v20[0] + 12), 1667526736);
    v18 = v17;
    if ( !v17 )
    {
      v7 = -1073741670;
      goto LABEL_28;
    }
    memmove(v17, *(_DWORD *)(v6 + 8) + v6, v16);
  }
  else
  {
    v18 = 0;
  }
  *(_QWORD *)(a3 + 16) = *(_QWORD *)&v8;
  *(_DWORD *)(a3 + 24) = v18;
LABEL_28:
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v7;
}
