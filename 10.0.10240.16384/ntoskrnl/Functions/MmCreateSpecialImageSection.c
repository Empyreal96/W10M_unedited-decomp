// MmCreateSpecialImageSection 
 
int __fastcall MmCreateSpecialImageSection(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  int v5; // r4
  int v10; // r6
  int v11; // r5
  int result; // r0
  int v13; // r5
  int v14; // r4
  int v15; // [sp+20h] [bp-30h] BYREF
  int v16; // [sp+24h] [bp-2Ch] BYREF
  _DWORD v17[10]; // [sp+28h] [bp-28h] BYREF

  v5 = 0;
  if ( (a5 & 1) != 0 )
  {
    v10 = 0x1000000;
    v5 = 1;
  }
  else
  {
    v10 = 37748736;
  }
  if ( (a5 & 4) != 0 )
    v5 |= 8u;
  v11 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v17[0] = 0;
  v17[1] = 0;
  if ( MiCreateSection(&v15, a2, v5, v17, 16, v10, a3, a4, 0, 0, v11) < 0 )
    return sub_7F6850();
  v13 = MiSectionControlArea(v15);
  v14 = MI_REFERENCE_CONTROL_AREA_FILE(v13);
  CcZeroEndOfLastPage(v14);
  MI_DEREFERENCE_CONTROL_AREA_FILE(v13, v14);
  result = ObInsertObject(v15, 0, 983071, 0, 0, &v16);
  if ( result >= 0 )
    *a1 = v16;
  return result;
}
