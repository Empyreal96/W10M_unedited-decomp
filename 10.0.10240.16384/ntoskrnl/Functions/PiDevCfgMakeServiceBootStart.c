// PiDevCfgMakeServiceBootStart 
 
int __fastcall PiDevCfgMakeServiceBootStart(unsigned __int16 *a1)
{
  int v1; // r5
  int v2; // r6
  _DWORD *v3; // r4
  int v5; // r3
  unsigned int v6; // r1
  int v8; // r9
  _DWORD *v10; // [sp+8h] [bp-40h] BYREF
  int v11; // [sp+Ch] [bp-3Ch]
  int v12[2]; // [sp+10h] [bp-38h] BYREF
  __int16 v13; // [sp+18h] [bp-30h] BYREF
  __int16 v14; // [sp+1Ah] [bp-2Eh]
  const __int16 *v15; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 v16; // [sp+20h] [bp-28h] BYREF
  __int16 v17; // [sp+22h] [bp-26h]
  int v18; // [sp+24h] [bp-24h]
  __int16 v19; // [sp+28h] [bp-20h] BYREF
  int v20; // [sp+2Ch] [bp-1Ch]

  v12[0] = 0;
  v10 = 0;
  v11 = 4;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  RtlInitUnicodeString((unsigned int)&v13, a1);
  v1 = PipOpenServiceEnumKeys((int)&v13, 131103, v12, 0, 0);
  v2 = v12[0];
  if ( v1 < 0 )
    goto LABEL_27;
  v1 = IopGetRegistryValue(v12[0], L"Start", 0, (int *)&v10);
  if ( v1 >= 0 )
  {
    v3 = v10;
    if ( v10[1] != 4 || v10[3] != 4 )
      goto LABEL_8;
    v11 = *(_DWORD *)((char *)v10 + v10[2]);
    ExFreePoolWithTag((unsigned int)v10);
    v10 = 0;
    if ( v11 == 4 || !v11 )
      goto LABEL_27;
    v1 = IopGetRegistryValue(v2, L"ImagePath", 0, (int *)&v10);
    if ( v1 >= 0 )
    {
      v3 = v10;
      v5 = v10[1];
      if ( v5 == 1 || v5 == 2 )
      {
        v6 = v10[3];
        if ( v6 >= 2 && !*(_WORD *)((char *)v10 + 2 * (v6 >> 1) + v10[2] - 2) )
        {
          PnpRegSzToString((char *)v10 + v10[2], v6, v12);
          v16 = v12[0];
          v17 = v3[3];
          v8 = (int)v3 + v3[2];
          v18 = v8;
          if ( RtlPrefixUnicodeString((unsigned __int16 *)&PiDevCfgSystemRoot, &v16, 1) )
          {
            RtlInitUnicodeString((unsigned int)&v19, (unsigned __int16 *)(v8 + 24));
            v14 = 20;
            v13 = 18;
            v15 = L"ImagePath";
            v1 = ZwSetValueKey();
            if ( v1 < 0 )
              goto LABEL_25;
            goto LABEL_23;
          }
          if ( RtlPrefixUnicodeString((unsigned __int16 *)&PiDevCfgSystem32, &v16, 1) )
          {
LABEL_23:
            v14 = 12;
            v13 = 10;
            v11 = 0;
            v15 = L"Start";
            v1 = ZwSetValueKey();
            goto LABEL_25;
          }
        }
      }
LABEL_8:
      v1 = -1073741823;
      goto LABEL_25;
    }
  }
  v3 = v10;
LABEL_25:
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
LABEL_27:
  if ( v2 )
    ZwClose();
  return v1;
}
