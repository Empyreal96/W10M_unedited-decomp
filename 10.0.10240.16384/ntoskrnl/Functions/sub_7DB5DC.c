// sub_7DB5DC 
 
void sub_7DB5DC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r5
  int v11; // r6
  int v12; // r4
  void *v13; // [sp+18h] [bp+18h] BYREF
  va_list va; // [sp+18h] [bp+18h]
  int v15; // [sp+1Ch] [bp+1Ch]
  int v16; // [sp+20h] [bp+20h]
  int v17; // [sp+24h] [bp+24h]
  int v18; // [sp+28h] [bp+28h]
  int v19; // [sp+2Ch] [bp+2Ch]
  void *v20; // [sp+30h] [bp+30h] BYREF
  va_list va1; // [sp+30h] [bp+30h]
  int v22; // [sp+34h] [bp+34h]
  int v23; // [sp+38h] [bp+38h]
  int v24; // [sp+3Ch] [bp+3Ch]
  va_list va2; // [sp+40h] [bp+40h] BYREF

  va_start(va2, a10);
  va_start(va1, a10);
  va_start(va, a10);
  v13 = va_arg(va1, void *);
  v15 = va_arg(va1, _DWORD);
  v16 = va_arg(va1, _DWORD);
  v17 = va_arg(va1, _DWORD);
  v18 = va_arg(va1, _DWORD);
  v19 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v20 = va_arg(va2, void *);
  v22 = va_arg(va2, _DWORD);
  v23 = va_arg(va2, _DWORD);
  v24 = va_arg(va2, _DWORD);
  if ( a8 == 16 && a9 == 3 )
  {
    v12 = ZwQueryLicenseValue();
    if ( v12 < 0 )
      goto LABEL_10;
    if ( !memcmp((unsigned int)va2, (unsigned int)va1, 16) )
    {
      *(_DWORD *)v10 = v11;
      *(_DWORD *)(v10 + 4) = v11;
    }
    else
    {
      v13 = v20;
      v15 = v22;
      v16 = v23;
      if ( RtlTimeFieldsToTime((__int16 *)va, (_QWORD *)v10) != 1 )
        JUMPOUT(0x6E36F8);
    }
  }
  else
  {
    v12 = -1073741772;
  }
  if ( v12 >= 0 )
    JUMPOUT(0x6E36E8);
LABEL_10:
  JUMPOUT(0x6E36E4);
}
