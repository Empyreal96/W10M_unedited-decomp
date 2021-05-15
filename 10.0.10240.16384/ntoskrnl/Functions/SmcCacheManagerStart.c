// SmcCacheManagerStart 
 
int __fastcall SmcCacheManagerStart(int result, int a2)
{
  int v3; // r6
  unsigned int i; // r4
  _DWORD *v5; // r5
  const __int16 *v6; // r1
  int v7; // r2
  const __int16 *v9; // r1
  int v10; // r2
  __int16 v12; // [sp+18h] [bp-38h] BYREF
  __int16 v13; // [sp+1Ah] [bp-36h]
  const __int16 *v14; // [sp+1Ch] [bp-34h]
  int v15; // [sp+20h] [bp-30h]
  int v16; // [sp+24h] [bp-2Ch]
  __int16 *v17; // [sp+28h] [bp-28h]
  int v18; // [sp+2Ch] [bp-24h]
  int v19; // [sp+30h] [bp-20h]
  int v20; // [sp+34h] [bp-1Ch]

  v3 = result;
  for ( i = 0; i < 2; ++i )
  {
    v5 = (_DWORD *)((char *)&unk_636C90 + 12 * i);
    if ( (*v5 & 1) == 0 )
    {
      if ( !i )
      {
        result = SmpUtilsGetControlDevice(result, v5 + 1, v5 + 2);
        if ( result < 0 )
          return result;
      }
      *v5 |= 1u;
    }
  }
  v6 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters";
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v7 = 0x7FFF;
  do
  {
    if ( !*(unsigned __int16 *)v6++ )
      break;
    --v7;
  }
  while ( v7 );
  if ( v7 )
  {
    v12 = 2 * (0x7FFF - v7);
    v13 = v12 + 2;
    v14 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters";
  }
  v15 = 24;
  v16 = 0;
  v18 = 576;
  v17 = &v12;
  v19 = 0;
  v20 = 0;
  result = ZwCreateKey();
  if ( result >= 0 )
  {
    ZwClose();
    v12 = 0;
    v9 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters\\CacheInfo";
    v13 = 0;
    v14 = 0;
    v10 = 0x7FFF;
    do
    {
      if ( !*(unsigned __int16 *)v9++ )
        break;
      --v10;
    }
    while ( v10 );
    if ( v10 )
    {
      v12 = 2 * (0x7FFF - v10);
      v13 = v12 + 2;
      v14 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters\\CacheInfo";
    }
    result = SmKmKeyGenStart(v3 + 256, &v12);
    if ( result >= 0 )
    {
      *(_DWORD *)(v3 + 276) = a2;
      result = 0;
    }
  }
  return result;
}
