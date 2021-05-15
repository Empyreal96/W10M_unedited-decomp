// CmpInitializeRegistryNode 
 
int __fastcall CmpInitializeRegistryNode(_DWORD *a1, int a2, int *a3, int a4, int a5, int a6)
{
  int v7; // r4
  int v9; // r4
  int v10; // r6
  unsigned int v11; // r2
  unsigned int v13; // r0
  int v14; // r3
  int v15; // r1
  unsigned int v16; // r2
  int v17; // r6
  _WORD *v18; // r4
  int v19; // [sp+10h] [bp-90h]
  char v20[8]; // [sp+18h] [bp-88h] BYREF
  unsigned __int16 v21[2]; // [sp+20h] [bp-80h] BYREF
  char *v22; // [sp+24h] [bp-7Ch]
  int v23; // [sp+28h] [bp-78h]
  int v24; // [sp+2Ch] [bp-74h]
  unsigned __int16 *v25; // [sp+30h] [bp-70h]
  int v26; // [sp+34h] [bp-6Ch]
  int v27; // [sp+38h] [bp-68h]
  int v28; // [sp+3Ch] [bp-64h]
  int v29; // [sp+40h] [bp-60h] BYREF
  int v30; // [sp+4Ch] [bp-54h]
  unsigned __int16 v31[4]; // [sp+50h] [bp-50h] BYREF
  char v32[16]; // [sp+58h] [bp-48h] BYREF
  char v33; // [sp+68h] [bp-38h] BYREF

  v7 = a1[3];
  v30 = a4;
  if ( !v7 )
    a1[4] = 0;
  v23 = 24;
  v24 = a2;
  v27 = 0;
  v28 = 0;
  v9 = a1[4];
  v26 = 576;
  v25 = (unsigned __int16 *)((char *)&CmTypeName + 8 * v9);
  v10 = ZwCreateKey();
  if ( v10 >= 0 )
  {
    if ( !a1[3] )
      goto LABEL_8;
    v11 = a1[4];
    if ( v11 >= 0x2A )
      return sub_80BF70();
    v13 = *(unsigned __int16 *)(a6 + 2 * v11);
    *(_WORD *)(a6 + 2 * v11) = v13 + 1;
    RtlIntegerToChar(v13, 0xAu, 12, (int)v32);
    RtlInitAnsiString((unsigned int)v31, (unsigned int)v32);
    v22 = &v33;
    v21[0] = 0;
    v21[1] = 24;
    RtlAnsiStringToUnicodeString(v21, v31, 0, 24);
    v23 = 24;
    v25 = v21;
    v27 = 0;
    v28 = 0;
    v26 = 64;
    v24 = v19;
    v10 = ZwCreateKey();
    NtClose();
    if ( v10 >= 0 )
    {
LABEL_8:
      RtlInitUnicodeString((unsigned int)v20, L"Component Information");
      v10 = ZwSetValueKey();
      if ( v10 >= 0 )
      {
        if ( !a1[10]
          || (RtlInitUnicodeString((unsigned int)v20, L"Identifier"),
              RtlInitAnsiString((unsigned int)v31, a1[11]),
              v10 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&v29, v31, 1, v14),
              v10 >= 0)
          && (v10 = ZwSetValueKey(), RtlFreeAnsiString(&v29), v10 >= 0) )
        {
          RtlInitUnicodeString((unsigned int)v20, L"Configuration Data");
          v15 = a1[12];
          if ( !v15 )
          {
            v18 = CmpConfigurationData;
LABEL_21:
            v18[4] = 0;
            v18[5] = 0;
            *((_DWORD *)v18 + 3) = 0;
LABEL_17:
            *(_DWORD *)v18 = v30;
            *((_DWORD *)v18 + 1) = a5;
            v10 = ZwSetValueKey();
            if ( v10 < 0 )
            {
              ZwClose();
            }
            else
            {
              v10 = 0;
              *a3 = v19;
            }
            return v10;
          }
          v16 = a1[9];
          v17 = v16 + 8;
          if ( v16 + 8 > CmpConfigurationAreaSize )
          {
            v18 = (_WORD *)ExAllocatePoolWithTag(1, v17, 538987843);
            if ( !v18 )
            {
              v18 = CmpConfigurationData;
              a1[9] = 0;
              a1[12] = 0;
LABEL_16:
              if ( a1[12] )
                goto LABEL_17;
              goto LABEL_21;
            }
            CmpConfigurationAreaSize = v17;
            ExFreePoolWithTag((unsigned int)CmpConfigurationData);
            v16 = a1[9];
            v15 = a1[12];
            CmpConfigurationData = v18;
          }
          else
          {
            v18 = CmpConfigurationData;
          }
          memmove((int)(v18 + 4), v15, v16);
          goto LABEL_16;
        }
      }
      NtClose();
    }
  }
  return v10;
}
