// _CmClassSubkeyCallback 
 
int __fastcall CmClassSubkeyCallback(int a1, int a2, unsigned __int16 *a3, int *a4)
{
  int v5; // r3
  unsigned int v7; // r6
  __int64 v9; // kr00_8
  char v10[2]; // [sp+8h] [bp-20h] BYREF
  unsigned __int16 v11; // [sp+Ah] [bp-1Eh]

  v5 = *a4;
  if ( ((unsigned __int8)v5 == 2 || v5 == 4)
    && CmValidateInstallerClassName(a1, a3) >= 0
    && RtlInitUnicodeStringEx((int)v10, a3) >= 0 )
  {
    v7 = v11 >> 1;
    if ( a4[1] )
      return sub_811D40();
    v9 = *((_QWORD *)a4 + 2);
    a4[5] = HIDWORD(v9) + v7;
    if ( (unsigned int)v9 > v7 )
    {
      RtlStringCchCopyExW((_WORD *)a4[3], v9, a3);
      a4[3] += 2 * v7;
      a4[4] -= v7;
    }
  }
  return 0;
}
