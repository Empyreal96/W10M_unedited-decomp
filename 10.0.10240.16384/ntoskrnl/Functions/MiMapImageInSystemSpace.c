// MiMapImageInSystemSpace 
 
int __fastcall MiMapImageInSystemSpace(int a1, int a2, _DWORD *a3)
{
  unsigned int v6; // r2
  int v7; // r6
  int v8; // r9
  int v10; // r0
  int v11; // r5
  unsigned int *v12; // r3
  int v13; // [sp+8h] [bp-50h] BYREF
  int v14; // [sp+Ch] [bp-4Ch] BYREF
  _DWORD v15[2]; // [sp+10h] [bp-48h] BYREF
  int v16; // [sp+18h] [bp-40h] BYREF
  int v17[9]; // [sp+1Ch] [bp-3Ch] BYREF

  v16 = 0;
  memset(v17, 0, sizeof(v17));
  *a3 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a1 + 36) + 48);
  if ( !v6 )
    return -1073741701;
  if ( (a2 & 1) != 0 )
    v7 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  else
    v7 = ((v6 & 0xFFF) != 0) + (v6 >> 12);
  *(_QWORD *)&v17[5] = (unsigned __int64)(unsigned int)v7 << 12;
  v8 = MI_REFERENCE_CONTROL_AREA_FILE(a1);
  if ( (*(_DWORD *)(*(_DWORD *)(v8 + 4) + 32) & 0x10) != 0 )
    return sub_7D4F48();
  v17[4] = a1;
  v10 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v17[8] = v17[8] & 0x80000002 | ((v10 & 0x7FFFF) << 12) | 2;
  v17[7] |= 0x20u;
  v14 = v7 << 12;
  v15[0] = 0;
  v15[1] = 0;
  v11 = MmMapViewInSystemSpaceEx(&v16, &v13, &v14, v15, 1);
  MI_DEREFERENCE_CONTROL_AREA_FILE(a1, v8);
  if ( v11 < 0 )
  {
    if ( (a2 & 2) == 0 )
      return v11;
    v14 = 0;
    KiStackAttachProcess(PsInitialSystemProcess, 0, (int)(a3 + 3));
    v11 = MiMapImageInSystemProcess(a1, a2, &v13, &v14);
    if ( v11 < 0 )
    {
      KiUnstackDetachProcess((unsigned int)(a3 + 3), 0);
      return v11;
    }
    v12 = (unsigned int *)(PsInitialSystemProcess + 492);
  }
  else
  {
    v12 = dword_634F00;
  }
  a3[1] = v7;
  a3[2] = v12;
  v11 = 0;
  *a3 = v13;
  return v11;
}
