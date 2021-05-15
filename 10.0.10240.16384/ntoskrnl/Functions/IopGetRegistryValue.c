// IopGetRegistryValue 
 
int __fastcall IopGetRegistryValue(int a1, unsigned __int16 *a2, int a3, int *a4)
{
  int v7; // r4
  unsigned int v8; // r4
  int v9; // r4
  int v11; // r5
  int v12; // r0
  int v13; // r3
  unsigned int v14; // [sp+8h] [bp-28h]
  char v15[32]; // [sp+10h] [bp-20h] BYREF

  v7 = RtlInitUnicodeStringEx((int)v15, a2);
  if ( v7 < 0 )
    return v7;
  v8 = (2 * wcslen(a2) + 27) & 0xFFFFFFFC;
  if ( a3 )
    v9 = (v8 + a3 + 3) & 0xFFFFFFFC;
  else
    v9 = v8 + 4;
  if ( ViVerifierDriverAddedThunkListHead )
    return sub_7CB358();
  v11 = ExAllocatePoolWithTag(1, v9, 538996553);
  if ( !v11 )
    return -1073741670;
  v7 = ZwQueryValueKey();
  if ( v7 < 0 )
  {
    ExFreePoolWithTag(v11);
    if ( v7 != -2147483643 && v7 != -1073741789 )
      return v7;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v13 = 40;
      else
        v13 = 32;
      v12 = ExAllocatePoolWithTagPriority(1, v14, 538996553, v13);
    }
    else
    {
      v12 = ExAllocatePoolWithTag(1, v14, 538996553);
    }
    v11 = v12;
    if ( v12 )
    {
      v7 = ZwQueryValueKey();
      if ( v7 < 0 )
      {
        ExFreePoolWithTag(v11);
        return v7;
      }
      goto LABEL_14;
    }
    return -1073741670;
  }
LABEL_14:
  v7 = 0;
  *a4 = v11;
  return v7;
}
