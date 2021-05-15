// PiLastGoodRevertLastKnownDirectory 
 
unsigned int __fastcall PiLastGoodRevertLastKnownDirectory(int a1, int a2)
{
  unsigned int result; // r0
  _DWORD *v5; // r4
  int v6; // r5
  int v7; // r3
  unsigned int v8; // r3
  char *v9; // r2
  unsigned int v10; // r1
  int v11; // r2
  unsigned __int16 v12[2]; // [sp+10h] [bp-278h] BYREF
  __int16 *v13; // [sp+14h] [bp-274h]
  int v14; // [sp+18h] [bp-270h]
  unsigned __int16 v15[2]; // [sp+20h] [bp-268h] BYREF
  _DWORD *v16; // [sp+24h] [bp-264h]
  int v17; // [sp+28h] [bp-260h]
  int v18; // [sp+2Ch] [bp-25Ch]
  unsigned __int16 *v19; // [sp+30h] [bp-258h]
  int v20; // [sp+34h] [bp-254h]
  int v21; // [sp+38h] [bp-250h]
  int v22; // [sp+3Ch] [bp-24Ch]
  int v23; // [sp+40h] [bp-248h]
  int v24; // [sp+44h] [bp-244h]
  int v25; // [sp+48h] [bp-240h]
  int v26; // [sp+4Ch] [bp-23Ch]
  int v27; // [sp+50h] [bp-238h]
  int v28; // [sp+54h] [bp-234h]
  __int16 v29; // [sp+58h] [bp-230h] BYREF
  char v30[558]; // [sp+5Ah] [bp-22Eh] BYREF

  v29 = 0;
  memset(v30, 0, 534);
  result = ExAllocatePoolWithTag(1, 540, 1733062736);
  v5 = (_DWORD *)result;
  if ( result )
  {
    IopFileUtilWalkDirectoryTreeTopDown(a1);
    v23 = 24;
    v24 = 0;
    v25 = a2;
    v27 = 0;
    v28 = 0;
    v26 = 576;
    if ( ZwOpenKey() >= 0 )
    {
      v6 = 1;
      while ( ZwEnumerateValueKey() >= 0 )
      {
        if ( v14 && v5[1] == 4 && v5[3] == 4 && *((_BYTE *)v5 + v5[2]) == 1 )
        {
          v13 = &v29;
          v12[0] = 0;
          v12[1] = 536;
          v16 = v5 + 5;
          v7 = v5[4];
          v15[0] = v7;
          v15[1] = v7;
          RtlAppendUnicodeToString(v12, (int)L"\\SystemRoot\\", v11, v7);
          RtlAppendUnicodeStringToString(v12, v15);
          v8 = v12[0] >> 1;
          if ( v8 > 0xD )
          {
            v9 = &v30[24];
            v10 = v8 - 13;
            do
            {
              if ( *(_WORD *)v9 == 47 )
                *(_WORD *)v9 = 92;
              v9 += 2;
              --v10;
            }
            while ( v10 );
          }
          IopFileUtilClearAttributes();
          v17 = 24;
          v18 = 0;
          v19 = v12;
          v20 = 576;
          v21 = 0;
          v22 = 0;
          ZwDeleteFile();
        }
        ++v6;
      }
      ZwDeleteKey();
      ZwClose();
    }
    result = ExFreePoolWithTag((unsigned int)v5);
  }
  return result;
}
