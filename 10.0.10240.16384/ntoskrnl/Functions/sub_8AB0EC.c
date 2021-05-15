// sub_8AB0EC 
 
int __fastcall sub_8AB0EC(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  unsigned int v8; // r9
  int v9; // r7
  unsigned __int16 *v10; // r6
  unsigned __int16 *v11; // r8
  int (__fastcall *v12)(int, _DWORD **, int); // r6
  _DWORD *v13; // r7
  int v14; // r3
  unsigned int v15; // r5
  unsigned int v16; // r2
  int v17; // r0
  char v19[4]; // [sp+8h] [bp-50h] BYREF
  int v20; // [sp+Ch] [bp-4Ch] BYREF
  unsigned __int16 *v21; // [sp+10h] [bp-48h] BYREF
  int (__fastcall *v22)(int, _DWORD **, int); // [sp+14h] [bp-44h]
  _DWORD *v23; // [sp+18h] [bp-40h] BYREF
  int v24; // [sp+1Ch] [bp-3Ch]
  int v25; // [sp+20h] [bp-38h]
  _DWORD *v26; // [sp+28h] [bp-30h] BYREF
  int v27; // [sp+2Ch] [bp-2Ch]
  _DWORD *v28; // [sp+30h] [bp-28h] BYREF
  int v29; // [sp+34h] [bp-24h]

  v22 = (int (__fastcall *)(int, _DWORD **, int))a3;
  v23 = (_DWORD *)a4;
  v6 = 0;
  v20 = 0;
  v21 = 0;
  v8 = 0;
  v9 = IopGetDeviceInterfaces(a1, 0, a2 != 0, 0, &v21, 0);
  v10 = v21;
  if ( v9 < 0 )
  {
    v9 = 0;
    goto LABEL_30;
  }
  v28 = 0;
  v29 = 0;
  v11 = v21;
  if ( *v21 )
  {
    v12 = v22;
    v25 = 0;
    v13 = v23;
    while ( 1 )
    {
      RtlInitUnicodeString((unsigned int)&v23, v11);
      v14 = -1;
      v19[0] = -1;
      if ( a2 )
      {
        if ( sub_8AACAC(0, (int)&v23, (int)DEVPKEY_DeviceInterface_Enabled, 17, 1, (int)v19) < 0 )
          goto LABEL_25;
        v14 = v19[0];
      }
      if ( v14 != -1 )
        break;
      v15 = (unsigned __int16)v23;
      v26 = v23;
      v27 = v24;
      if ( (unsigned __int16)v23 >= 0xAu )
      {
        LOWORD(v26) = 8;
        if ( (unsigned __int16)v23 > 8u )
        {
          v16 = 8;
          do
          {
            if ( *(_WORD *)(v24 + 2 * (v16 >> 1)) == 92 )
              break;
            v16 = (unsigned __int16)(v16 + 2);
            LOWORD(v26) = v16;
          }
          while ( v16 < (unsigned __int16)v23 );
        }
      }
      if ( RtlEqualUnicodeString((unsigned __int16 *)&v26, (unsigned __int16 *)&v28, 1) )
        goto LABEL_26;
      v17 = sub_8AAE00((int)&v26, v13, &v20);
      v6 = v20;
      if ( v17 < 0 )
        goto LABEL_26;
      if ( v20 )
      {
        if ( sub_8AAAAC(v20, a5) < 0 || sub_8AA5DC(v6, a5) < 0 )
          goto LABEL_26;
        ObfDereferenceObject(v6);
        v6 = 0;
        v20 = 0;
        if ( v12(a6, &v26, a5) >= 0 )
        {
          v28 = v26;
          v29 = v27;
        }
      }
LABEL_28:
      v11 += (v15 >> 1) + 1;
      if ( !*v11 )
      {
        v10 = v21;
        v9 = v25;
        goto LABEL_30;
      }
    }
    if ( sub_8AAA38((int)&v23, a5) >= 0 && v8 < 0x14 && v12(a6, 0, a5) >= 0 )
      ++v8;
LABEL_25:
    v15 = (unsigned __int16)v23;
LABEL_26:
    if ( v6 )
    {
      ObfDereferenceObject(v6);
      v6 = 0;
      v20 = 0;
    }
    goto LABEL_28;
  }
LABEL_30:
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  return v9;
}
