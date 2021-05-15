// IopIsPciRootBus 
 
int __fastcall IopIsPciRootBus(int a1, _BYTE *a2, int a3, unsigned int a4)
{
  int v6; // r4
  int *v7; // r0
  int *v8; // r5
  int v9; // r3
  int *v10; // r4
  int v11; // t1
  unsigned int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a4;
  *a2 = 0;
  v6 = IoGetDeviceProperty(a1, 1, 0, 0, v13);
  if ( v6 == -1073741789 )
  {
    v7 = (int *)ExAllocatePoolWithTag(1, v13[0], 538996816);
    v8 = v7;
    if ( v7 )
    {
      v6 = IoGetDeviceProperty(a1, 1, v13[0], v7, v13);
      if ( v6 >= 0 )
      {
        v9 = *(unsigned __int16 *)v8;
        v10 = v8;
        while ( v9 )
        {
          if ( !wcsicmp((int)v10, L"ACPI\\PNP0A03") || !wcsicmp((int)v10, L"ACPI\\PNP0A08") )
          {
            *a2 = 1;
            break;
          }
          do
          {
            v11 = *(unsigned __int16 *)v10;
            v10 = (int *)((char *)v10 + 2);
          }
          while ( v11 );
          v9 = *(unsigned __int16 *)v10;
        }
        v6 = 0;
      }
      ExFreePoolWithTag((unsigned int)v8);
    }
    else
    {
      v6 = -1073741670;
    }
  }
  return v6;
}
