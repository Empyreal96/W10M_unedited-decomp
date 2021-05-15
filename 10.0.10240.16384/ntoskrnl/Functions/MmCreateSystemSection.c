// MmCreateSystemSection 
 
int __fastcall MmCreateSystemSection(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // r6
  int v13; // r0
  int v14; // r0
  int v15; // r5
  int v16; // r4
  int v17[8]; // [sp+20h] [bp-20h] BYREF

  v11 = MiCreateSection(v17, a3, 0, a4, 16, a6, 0, a7, 0, 0, a10);
  if ( v11 < 0 )
    return sub_519158();
  v13 = v17[0];
  *a1 = v17[0];
  v14 = MiSectionControlArea(v13);
  v15 = v14;
  if ( v14 )
  {
    if ( *(_DWORD *)(v14 + 32) )
    {
      v16 = MI_REFERENCE_CONTROL_AREA_FILE(v14);
      CcZeroEndOfLastPage(v16);
      MI_DEREFERENCE_CONTROL_AREA_FILE(v15, v16);
    }
  }
  return v11;
}
