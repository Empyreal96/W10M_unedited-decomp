// MmGetFileNameForSection 
 
int __fastcall MmGetFileNameForSection(int a1, int *a2, int a3, int a4)
{
  int v5; // r3
  int v7; // r4
  int v8; // r0
  int v9; // r8
  int v10; // r6
  int v11; // r0
  int v12; // r4
  int v13; // r0
  int v15[8]; // [sp+8h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v5 = *(_DWORD *)(a1 + 32);
  *a2 = 0;
  if ( (v5 & 0x20) != 0 )
  {
    v8 = ExAllocatePoolWithTag(1, 1024, 538996045);
    *a2 = v8;
    if ( !v8 )
      return -1073741801;
    v9 = MiSectionControlArea(a1);
    v10 = MI_REFERENCE_CONTROL_AREA_FILE(v9);
    v11 = ObQueryNameStringMode(v10, *a2, 1024, v15, 0);
    v7 = v11;
    if ( v11 < 0 )
    {
      if ( v11 != -1073741820 )
        goto LABEL_12;
      ExFreePoolWithTag(*a2);
      v12 = v15[0] + 1024;
      if ( (unsigned int)(v15[0] + 1024) <= 0x400 )
      {
        *a2 = 0;
        MI_DEREFERENCE_CONTROL_AREA_FILE(v9, v10);
        return -1073741801;
      }
      v13 = ExAllocatePoolWithTag(1, v15[0] + 1024, 538996045);
      *a2 = v13;
      if ( !v13 )
      {
        v7 = -1073741801;
LABEL_14:
        MI_DEREFERENCE_CONTROL_AREA_FILE(v9, v10);
        return v7;
      }
      v7 = ObQueryNameStringMode(v10, v13, v12, v15, 0);
      if ( v7 < 0 )
      {
LABEL_12:
        MI_DEREFERENCE_CONTROL_AREA_FILE(v9, v10);
        ExFreePoolWithTag(*a2);
        *a2 = 0;
        return v7;
      }
    }
    v7 = 0;
    goto LABEL_14;
  }
  return -1073741751;
}
