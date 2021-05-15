// PiDevCfgResolveVariableKeyValue 
 
int __fastcall PiDevCfgResolveVariableKeyValue(unsigned int **a1, int a2, int a3)
{
  int v5; // r5
  int v6; // r10
  unsigned int *v7; // r9
  unsigned int v8; // r3
  int v9; // r3
  unsigned __int16 *v11; // r4
  int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r0
  _DWORD *v16; // r4
  __int64 v17; // r6
  __int64 v18; // kr00_8
  unsigned __int16 *v19; // r1
  unsigned __int16 *v20; // r0
  int v21; // r3
  bool v22; // zf
  int v23; // r3
  unsigned int v24; // r3
  int v25; // r0
  int v26; // r8
  int v27; // r3
  _DWORD *v29; // [sp+0h] [bp-30h] BYREF
  int v30; // [sp+4h] [bp-2Ch] BYREF
  unsigned int *v31; // [sp+8h] [bp-28h] BYREF
  int v32; // [sp+Ch] [bp-24h]

  v32 = a3;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  v5 = PiDevCfgResolveVariableKeyHandle(a1, a2, &v30);
  v6 = v30;
  if ( v5 < 0 )
    goto LABEL_57;
  v5 = IopGetRegistryValue(a2, L"ValueName", 0, (int *)&v31);
  v7 = v31;
  if ( v5 >= 0 )
  {
    if ( v31[1] != 1
      || ((v8 = v31[3], v8 < 2) || *(_WORD *)((char *)v31 + 2 * (v8 >> 1) + v31[2] - 2) ? (v9 = 0) : (v9 = 1), !v9) )
    {
      v5 = -1073741823;
      goto LABEL_55;
    }
    v11 = (unsigned __int16 *)((char *)v31 + v31[2]);
    if ( *v11 != 36 )
    {
LABEL_20:
      v14 = IopGetRegistryValue(v6, v11, 0, (int *)&v29);
      v5 = v14;
      if ( v14 < 0 )
      {
        if ( v14 != -1073741772 )
          goto LABEL_25;
        v15 = IopGetRegistryValue(a2, L"DefaultValue", 0, (int *)&v29);
        v5 = v15;
        if ( v15 < 0 )
        {
          if ( v15 == -1073741772 )
          {
            v5 = 0;
            v16 = 0;
            goto LABEL_27;
          }
LABEL_25:
          v16 = v29;
          goto LABEL_53;
        }
      }
      v16 = v29;
LABEL_27:
      if ( !v16 )
      {
        v17 = 0i64;
        v26 = 0;
        goto LABEL_52;
      }
      LODWORD(v17) = v16[1];
      if ( (_DWORD)v17 )
      {
        if ( (unsigned int)v17 <= 2 )
        {
          v24 = v16[3];
          if ( v24 >= 2 )
          {
            v21 = *(unsigned __int16 *)((char *)v16 + 2 * (v24 >> 1) + v16[2] - 2);
            goto LABEL_37;
          }
LABEL_42:
          v23 = 0;
          goto LABEL_46;
        }
        if ( (_DWORD)v17 == 4 )
        {
          v22 = v16[3] == 4;
LABEL_38:
          if ( !v22 )
            goto LABEL_42;
LABEL_40:
          v23 = 1;
LABEL_46:
          if ( !v23 )
          {
            v5 = -1073741823;
            goto LABEL_53;
          }
          HIDWORD(v17) = v16[3];
          v25 = ExAllocatePoolWithTag(1, SHIDWORD(v17), 1667526736);
          v26 = v25;
          if ( !v25 )
          {
            v5 = -1073741670;
            goto LABEL_53;
          }
          memmove(v25, (int)v16 + v16[2], HIDWORD(v17));
LABEL_52:
          v27 = v32;
          *(_QWORD *)(v32 + 16) = v17;
          *(_DWORD *)(v27 + 24) = v26;
LABEL_53:
          if ( v16 )
            ExFreePoolWithTag((unsigned int)v16);
          goto LABEL_55;
        }
        if ( (_DWORD)v17 == 7 )
        {
          v18 = *((_QWORD *)v16 + 1);
          v19 = (unsigned __int16 *)((char *)v16 + v18);
          if ( HIDWORD(v18) >= 4 )
          {
            v20 = &v19[HIDWORD(v18) >> 1];
            if ( !*(v20 - 1) && !*(v20 - 2) )
              goto LABEL_40;
          }
          if ( HIDWORD(v18) == 2 )
          {
            v21 = *v19;
LABEL_37:
            v22 = v21 == 0;
            goto LABEL_38;
          }
          goto LABEL_42;
        }
      }
      v23 = 1;
      goto LABEL_46;
    }
    v31 = 0;
    v12 = PiDevCfgResolveVariable((int)a1, v11 + 1, &v31);
    v5 = v12;
    if ( v12 >= 0 )
    {
      v13 = v31[4];
      if ( v13 && (v13 <= 2 || v13 == 7) )
        v11 = (unsigned __int16 *)v31[6];
      goto LABEL_20;
    }
    if ( v12 == -1073741772 )
      goto LABEL_20;
  }
LABEL_55:
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
LABEL_57:
  if ( v6 )
    ZwClose();
  return v5;
}
