// _PnpGetGenericStoreProperty 
 
int __fastcall PnpGetGenericStoreProperty(int a1, int a2, unsigned __int16 *a3, int a4, _DWORD *a5, int a6, int a7, _DWORD *a8)
{
  int v12; // r4
  int v13; // r0
  int result; // r0
  int v15; // r0
  int v16; // r3
  int v17; // [sp+4h] [bp-CCh]
  int v18; // [sp+Ch] [bp-C4h]
  int v19; // [sp+10h] [bp-C0h]
  int v20; // [sp+14h] [bp-BCh]
  int v21; // [sp+18h] [bp-B8h]
  int v22; // [sp+1Ch] [bp-B4h]
  int v23; // [sp+20h] [bp-B0h]
  int v24; // [sp+24h] [bp-ACh]
  int v25; // [sp+28h] [bp-A8h]
  int v26; // [sp+2Ch] [bp-A4h]
  int v27; // [sp+30h] [bp-A0h]
  int v28; // [sp+34h] [bp-9Ch]
  int v29; // [sp+38h] [bp-98h] BYREF
  int v30; // [sp+3Ch] [bp-94h] BYREF
  int v31; // [sp+40h] [bp-90h] BYREF
  int v32; // [sp+44h] [bp-8Ch] BYREF
  int v33; // [sp+48h] [bp-88h] BYREF
  char v34[128]; // [sp+50h] [bp-80h] BYREF

  *a5 = 0;
  *a8 = 0;
  v30 = 0;
  LOBYTE(v29) = 0;
  if ( a3 )
  {
    result = RtlUnalignedStringCchLengthW(a3, 85, &v33);
    if ( result < 0 )
      return result;
  }
  v28 = *(_DWORD *)(a4 + 16);
  v27 = *(unsigned __int8 *)(a4 + 15);
  v25 = *(unsigned __int8 *)(a4 + 13);
  v26 = *(unsigned __int8 *)(a4 + 14);
  v24 = *(unsigned __int8 *)(a4 + 12);
  v22 = *(unsigned __int8 *)(a4 + 10);
  v23 = *(unsigned __int8 *)(a4 + 11);
  v21 = *(unsigned __int8 *)(a4 + 9);
  v19 = *(unsigned __int16 *)(a4 + 6);
  v20 = *(unsigned __int8 *)(a4 + 8);
  v18 = *(unsigned __int16 *)(a4 + 4);
  v12 = RtlStringCchPrintfExW((int)v34, 48, 0, 0, 2048, L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}\\%04lX");
  if ( v12 >= 0 )
  {
    v13 = PnpOpenPropertiesKey(a1, a2, v34, 1, 0, v17, &v30, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    v12 = v13;
    if ( v13 != -1073741772 )
    {
      if ( v13 < 0 )
        goto LABEL_5;
      v31 = a7;
      v15 = PnpCtxRegQueryValueIndirect(a1, v30, a3, &v32, a6, &v31, &v29);
      if ( v15 != -1073741772 && v15 != -1073741444 )
      {
        if ( !v15 || v15 == -1073741789 )
        {
          v16 = (unsigned __int16)v32;
          *a5 = (unsigned __int16)v32;
          if ( v16 != 1 )
          {
            *a8 = v31;
            if ( v15 || !a7 )
              v12 = -1073741789;
          }
        }
        else
        {
          v12 = v15;
        }
        goto LABEL_5;
      }
    }
    v12 = -1073741275;
  }
LABEL_5:
  if ( v30 )
    ZwClose();
  return v12;
}
