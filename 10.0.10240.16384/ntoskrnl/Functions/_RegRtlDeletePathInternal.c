// _RegRtlDeletePathInternal 
 
int __fastcall RegRtlDeletePathInternal(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v8; // r4
  int v9; // r4
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r5
  int i; // r3
  int v13; // r0
  int v14; // r0
  unsigned __int16 *v15; // r0
  int v16; // t1
  int v18; // [sp+8h] [bp-28h] BYREF
  int v19; // [sp+Ch] [bp-24h] BYREF
  int v20[8]; // [sp+10h] [bp-20h] BYREF

  v18 = 0;
  v8 = RtlUnalignedStringCchLengthW(a2, 0x7FFF, &v19);
  if ( v8 < 0 )
    return v8;
  v9 = v19 + 1;
  v10 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * (v19 + 1), 1279739218);
  v11 = v10;
  if ( !v10 )
    return -1073741801;
  v8 = RtlStringCchCopyExW(v10, v9, a2);
  if ( v8 )
    goto LABEL_26;
  for ( i = 1; ; i = 0 )
  {
    if ( i && a3 )
    {
      v13 = RegRtlDeleteTreeInternal(a1, v11, a4, 0);
      goto LABEL_17;
    }
    v14 = RegRtlOpenKeyTransacted(a1, v11, 0, 1, (int)&v18, a4);
    v8 = v14;
    if ( !v14 )
    {
      v8 = RegRtlQueryInfoKey(v18, (int)&v19, 0, v20, 0, 0);
      ZwClose();
      if ( v8 != -1073741444 && v8 )
        goto LABEL_26;
      if ( v19 || v20[0] )
      {
        v8 = -1073741535;
        goto LABEL_26;
      }
      goto LABEL_16;
    }
    if ( v14 != -1073741772 )
      break;
LABEL_16:
    v13 = RegRtlDeleteKeyTransacted(a1, v11, 0);
LABEL_17:
    v8 = v13;
    if ( v13 && v13 != -1073741772 )
      goto LABEL_26;
    v15 = wcsrchr(v11, 92);
    if ( !v15 )
      goto LABEL_26;
    do
    {
      *v15 = 0;
      if ( v15 == v11 )
        break;
      v16 = *--v15;
    }
    while ( v16 == 92 );
  }
  if ( v14 == -1073741444 )
    v8 = 0;
LABEL_26:
  ExFreePoolWithTag((unsigned int)v11);
  return v8;
}
