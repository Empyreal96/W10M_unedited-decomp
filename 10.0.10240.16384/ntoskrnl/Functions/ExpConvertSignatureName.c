// ExpConvertSignatureName 
 
int __fastcall ExpConvertSignatureName(int a1, int a2, unsigned int *a3, int a4, unsigned __int16 *a5, int a6)
{
  int v9; // r4
  int v10; // r7
  unsigned __int8 v12; // r8
  int v13; // r5
  int v14; // r4
  int v15; // r0
  unsigned __int16 *v16; // r5
  int v17; // r0
  unsigned __int8 v19; // [sp+10h] [bp-68h] BYREF
  char v20[3]; // [sp+11h] [bp-67h] BYREF
  int v21; // [sp+14h] [bp-64h] BYREF
  int v22[2]; // [sp+18h] [bp-60h] BYREF
  unsigned __int64 v23; // [sp+20h] [bp-58h] BYREF
  unsigned __int16 *v24; // [sp+28h] [bp-50h]
  unsigned __int64 v25; // [sp+30h] [bp-48h] BYREF
  unsigned __int64 v26; // [sp+38h] [bp-40h] BYREF
  unsigned __int64 v27; // [sp+40h] [bp-38h] BYREF
  _DWORD v28[12]; // [sp+48h] [bp-30h] BYREF

  v22[0] = 0;
  v24 = a5;
  v9 = ExpParseSignatureName(a4, a6, v28, &v21, &v26, &v25, &v19, v20);
  if ( v9 >= 0 )
  {
    v10 = (unsigned __int8)v20[0];
    if ( v20[0] == 1 && a1 == 4 )
      return ExpCreateOutputEFI(a2, a3, v28, &v21, &v26, &v25, a5, v19);
    v12 = v19;
    v13 = v21;
    if ( !v19 )
      v22[0] = v21;
    v9 = ExpFindDiskSignature((unsigned int)v28, v22, &v21, &v23, &v27, v19);
    if ( v9 >= 0 )
    {
      v14 = v22[0];
      if ( v10 == 1
        && (v13 != v22[0]
         || (_DWORD)v26 != (_DWORD)v23
         || HIDWORD(v26) != HIDWORD(v23)
         || (_DWORD)v25 != (_DWORD)v27
         || HIDWORD(v25) != HIDWORD(v27)) )
      {
        return -1073741811;
      }
      if ( a1 == 4 )
        return ExpCreateOutputEFI(a2, a3, v28, v22, &v23, &v27, v24, v12);
      v15 = ExAllocatePoolWithTag(512, 94, 1920364101);
      v16 = (unsigned __int16 *)v15;
      if ( !v15 )
        return -1073741670;
      swprintf_s(v15, 47, (int)L"\\Device\\Harddisk%lu\\Partition%lu", v21, v14);
      v9 = ExpTranslateSymbolicLink(v16, &v23);
      ExFreePoolWithTag((unsigned int)v16);
      if ( v9 < 0 )
        return v9;
      if ( a1 == 3 )
      {
        v17 = ExpCreateOutputNT(a2, a3, (char **)&v23, (int)v24);
      }
      else
      {
        if ( a1 != 1 )
        {
          v9 = -1073741811;
          goto LABEL_27;
        }
        v17 = ExpCreateOutputARC(a2, a3, &v23, v24);
      }
      v9 = v17;
LABEL_27:
      ExFreePoolWithTag(HIDWORD(v23));
      return v9;
    }
  }
  return v9;
}
