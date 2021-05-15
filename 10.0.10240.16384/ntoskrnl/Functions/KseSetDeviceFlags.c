// KseSetDeviceFlags 
 
int __fastcall KseSetDeviceFlags(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r4
  int v7; // r5
  int v9[2]; // [sp+8h] [bp-20h] BYREF
  int v10; // [sp+10h] [bp-18h] BYREF
  int v11; // [sp+14h] [bp-14h]
  __int16 v12[2]; // [sp+18h] [bp-10h] BYREF
  int v13; // [sp+1Ch] [bp-Ch]
  unsigned __int16 *varg_r0; // [sp+30h] [bp+8h]
  unsigned __int16 *varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v10 = 0;
  v11 = 0;
  v9[0] = 0;
  v12[0] = 0;
  v12[1] = 0;
  v13 = 0;
  v5 = dword_6416D4;
  __dmb(0xBu);
  if ( v5 != 2 || (KseEngine & 2) != 0 )
  {
    v6 = -1073741823;
    goto LABEL_13;
  }
  if ( !a1 || !a2 )
  {
    v6 = -1073741811;
    goto LABEL_13;
  }
  v6 = KsepStringTransform((unsigned __int16 *)&v10, a1);
  if ( v6 >= 0 )
  {
    v6 = KsepRegistryCreateKey(
           L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Device",
           v11,
           v9);
    if ( v6 == -1073741772 )
    {
      v6 = KsepRegistryCreateKey(
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility",
             L"Device",
             v9);
      if ( v6 < 0 )
        goto LABEL_13;
      KsepRegistryCloseKey(v9[0]);
      v9[0] = 0;
      v6 = KsepRegistryCreateKey(
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Device",
             v11,
             v9);
    }
    if ( v6 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v12, a2);
      v7 = v9[0];
      v6 = ZwSetValueKey();
      goto LABEL_14;
    }
  }
LABEL_13:
  v7 = v9[0];
LABEL_14:
  KsepStringFree(&v10);
  if ( v7 )
    KsepRegistryCloseKey(v7);
  return v6;
}
