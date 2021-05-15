// AdtpBuildSecurityDescriptorUnicodeString 
 
int __fastcall AdtpBuildSecurityDescriptorUnicodeString(int a1, int a2, int a3, int *a4, int a5, unsigned int *a6, _BYTE *a7)
{
  int v9; // r4
  int v10; // r0
  unsigned int v11; // r10
  unsigned __int16 *v12; // r7
  unsigned int v13; // r8
  unsigned int v14; // r2
  int v15; // r6
  unsigned __int16 *v17; // [sp+8h] [bp-58h] BYREF
  _BYTE *v18; // [sp+Ch] [bp-54h]
  int v19; // [sp+10h] [bp-50h] BYREF
  unsigned int *v20; // [sp+14h] [bp-4Ch]
  int v21; // [sp+18h] [bp-48h]
  unsigned __int16 v22[32]; // [sp+20h] [bp-40h] BYREF

  v20 = a6;
  v21 = a5;
  v18 = a7;
  v17 = 0;
  v19 = 0;
  if ( !a4 && !a3 )
    return -1073741811;
  v10 = SeConvertSecurityDescriptorToStringSecurityDescriptor(a2, a2, a1, &v17, &v19);
  v11 = (unsigned int)v17;
  v9 = v10;
  if ( v10 < 0 )
  {
    if ( v10 == -1073741801 )
      goto LABEL_22;
    if ( StringCchPrintfW(v22, 0x10u, (int)L"<0x%08X>", v10) < 0 )
      v12 = L"-";
    else
      v12 = v22;
  }
  else
  {
    v12 = v17;
  }
  v13 = wcslen(v12) + 1;
  if ( 2 * v13 > 0xFFFF )
  {
    v9 = RtlStringCbPrintfW(v22, 0x10u, (int)L"%%%%%u", 1829);
    if ( v9 < 0 )
      goto LABEL_22;
    v12 = v22;
    v13 = wcslen(v22) + 1;
  }
  v14 = *a6 + v13;
  if ( v14 < 0x400 )
  {
    v15 = v21 + 2 * *a6;
    *v20 = v14;
    *v18 = 0;
LABEL_18:
    memmove(v15, (int)v12, 2 * v13);
    if ( a4 )
    {
      *a4 = v15;
      a4[1] = 0;
      a4[2] = 2 * v13;
      a4[3] = 0;
    }
    else
    {
      *(_WORD *)a3 = 2 * (v13 - 1);
      *(_WORD *)(a3 + 2) = 2 * (v13 - 1) + 2;
      *(_DWORD *)(a3 + 4) = v15;
    }
    v11 = (unsigned int)v17;
    goto LABEL_22;
  }
  v15 = ExAllocatePoolWithTag(1, 2 * v13, 1799447891);
  if ( v15 )
  {
    *v18 = 1;
    goto LABEL_18;
  }
  v9 = -1073741801;
LABEL_22:
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v9;
}
