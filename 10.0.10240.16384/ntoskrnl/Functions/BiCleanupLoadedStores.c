// BiCleanupLoadedStores 
 
int __fastcall BiCleanupLoadedStores(char a1)
{
  int v2; // r9
  int result; // r0
  int v4; // r7
  unsigned int v5; // r4
  int v6; // r6
  int *v7; // r5
  int v8; // r0
  int v9; // [sp+0h] [bp-20h] BYREF
  int *v10; // [sp+4h] [bp-1Ch] BYREF

  v9 = 0;
  v10 = 0;
  v2 = BiIsWinPEBoot();
  result = BiOpenKeyNonBcd(0, L"\\Registry\\Machine", 983103, &v9);
  v4 = v9;
  if ( result >= 0 )
  {
    result = BiEnumerateSubKeys(v9, &v10, &v9);
    v5 = (unsigned int)v10;
    if ( result >= 0 )
    {
      v6 = v9;
      if ( v9 )
      {
        v7 = v10;
        do
        {
          result = wcsnicmp(*v7, L"BCD", 3);
          if ( !result )
          {
            result = wcstoul((unsigned __int16 *)(*v7 + 6), 0, 10);
            if ( result != -1 )
            {
              result = BiOpenKey(v4, *v7, 131097, &v9);
              if ( result >= 0 )
              {
                v8 = BiIsSystemStore(v9);
                if ( (a1 & 0x10) != 0 )
                  return sub_813664(v8);
                if ( (a1 & 8) != 0 || v2 || !v8 )
                  result = BiUnloadHiveByHandle(v9, 0);
                else
                  result = BiCloseKey(v9);
              }
            }
          }
          ++v7;
          --v6;
        }
        while ( v6 );
      }
    }
    if ( v5 )
      result = ExFreePoolWithTag(v5);
  }
  if ( v4 )
    result = ZwClose();
  return result;
}
