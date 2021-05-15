// FsRtlpQueryValueKey 
 
int __fastcall FsRtlpQueryValueKey(int a1, int a2, int *a3, unsigned int *a4, _BYTE *a5)
{
  int v8; // r4
  int v9; // r5
  int v10; // r0
  int v11; // r4
  int v13; // [sp+Ch] [bp-34h]

  v8 = ZwOpenKey();
  if ( v8 >= 0 )
  {
    if ( a2 )
    {
      v9 = *a3;
      while ( 1 )
      {
        v10 = ZwQueryValueKey();
        v8 = v10;
        if ( v10 != -1073741789 && v10 != -2147483643 )
          break;
        if ( v9 != *a3 )
          break;
        v9 = v13;
        v11 = ExAllocatePoolWithTag(1, v13, 1752453958);
        if ( !v11 )
        {
          v8 = -1073741670;
          break;
        }
        if ( *a5 )
          ExFreePoolWithTag(*a4);
        *a5 = 1;
        *a4 = v11;
        *a3 = v13;
      }
      ZwClose();
      if ( v8 >= 0 && !*(_DWORD *)(*a4 + 12) )
        v8 = -1073741772;
    }
    else
    {
      ZwClose();
      v8 = 0;
    }
  }
  return v8;
}
