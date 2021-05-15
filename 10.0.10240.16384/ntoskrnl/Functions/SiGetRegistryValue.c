// SiGetRegistryValue 
 
int __fastcall SiGetRegistryValue(int a1, unsigned __int16 *a2, int a3, int a4, int *a5, unsigned int *a6)
{
  int v7; // r6
  unsigned int v8; // r0
  int v9; // r4
  int v11; // r0
  int v12; // [sp+8h] [bp-30h]
  unsigned int v13; // [sp+8h] [bp-30h]
  char v14[32]; // [sp+18h] [bp-20h] BYREF

  *a5 = 0;
  *a6 = 0;
  v7 = 0;
  v8 = RtlInitUnicodeString((unsigned int)v14, a2);
  if ( !a3 || (v9 = SiOpenRegistryKey(v8, a3), v9 >= 0) )
  {
    if ( ZwQueryValueKey() != -1073741789 )
      return sub_815954();
    v7 = ExAllocatePoolWithTag(1, v12, 1263556947);
    if ( !v7 )
      goto LABEL_14;
    v9 = ZwQueryValueKey();
    if ( v9 >= 0 )
    {
      if ( *(_DWORD *)(v7 + 4) != 1 )
      {
        v9 = -1073741788;
        goto LABEL_10;
      }
      v13 = v12 - 12;
      v11 = ExAllocatePoolWithTag(1, v13, 1263556947);
      *a5 = v11;
      if ( v11 )
      {
        memmove(v11, v7 + 12, v13);
        v9 = 0;
        *a6 = v13;
        goto LABEL_10;
      }
LABEL_14:
      v9 = -1073741670;
      goto LABEL_10;
    }
  }
LABEL_10:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v9;
}
