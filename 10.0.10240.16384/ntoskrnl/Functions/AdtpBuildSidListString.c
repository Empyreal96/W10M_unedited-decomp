// AdtpBuildSidListString 
 
int __fastcall AdtpBuildSidListString(unsigned int *a1, int a2, unsigned int *a3, int a4, int a5, _BYTE *a6)
{
  unsigned int *v6; // r1
  int v7; // lr
  int v8; // r5
  unsigned int v9; // r6
  int v10; // r7
  unsigned int v13; // r9
  int v14; // r3
  unsigned int v15; // r8
  unsigned __int8 *v16; // r0
  unsigned int v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r8
  int v22; // r1
  unsigned int v23; // r9
  int v24; // r2
  int v25; // r3
  int v26; // r2
  int v27; // r3
  __int64 v28; // r2
  int result; // r0
  int v30[2]; // [sp+0h] [bp-240h] BYREF
  int v31[2]; // [sp+8h] [bp-238h] BYREF
  int v32; // [sp+10h] [bp-230h]
  unsigned int v33; // [sp+14h] [bp-22Ch] BYREF
  _BYTE *v34; // [sp+18h] [bp-228h]
  char v35; // [sp+20h] [bp-220h] BYREF

  v6 = (unsigned int *)a5;
  v7 = a4;
  v30[0] = a4;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v34 = a6;
  v31[0] = a5;
  if ( !a1 || (v13 = *a1) == 0 )
  {
    if ( a3 )
    {
      *a3 = (unsigned int)dword_406F40;
      a3[1] = 0;
      a3[2] = 4;
      a3[3] = 0;
    }
    v8 = 0;
LABEL_24:
    if ( v8 >= 0 )
      goto LABEL_27;
    goto LABEL_25;
  }
  v14 = a1[1];
  v15 = 1;
  v32 = v14;
  if ( v13 )
  {
    do
    {
      v16 = *(unsigned __int8 **)(v14 + 4);
      v33 = 0;
      RtlLengthSidAsUnicodeString(v16, &v33);
      v17 = (v33 >> 1) + 7;
      v18 = v17 + v15;
      if ( v17 + v15 < v15 )
      {
        v8 = -1073741675;
        goto LABEL_27;
      }
      ++v9;
      v8 = 0;
      v14 = v32 + 8;
      v32 += 8;
      v15 = v18;
    }
    while ( v9 < v13 );
    if ( v18 > 0x7FFF )
    {
      v8 = -1073741811;
      goto LABEL_27;
    }
    v6 = (unsigned int *)v31[0];
    v7 = v30[0];
  }
  v19 = *v6 + v15;
  if ( v19 >= 0x400 )
  {
    v9 = ExAllocatePoolWithTag(1, 2 * v15, 1799447891);
    if ( !v9 )
    {
      v8 = -1073741801;
      goto LABEL_27;
    }
    v10 = 1;
  }
  else
  {
    v9 = v7 + 2 * *v6;
    *v6 = v19;
  }
  HIWORD(v30[0]) = 2 * v15;
  v31[0] = 0x2000000;
  v31[1] = (int)&v35;
  v21 = a1[1];
  v20 = *a1;
  v22 = 0;
  LOWORD(v30[0]) = 0;
  v30[1] = v9;
  v23 = 0;
  if ( !v20 )
  {
LABEL_19:
    if ( a3 )
    {
      LODWORD(v28) = 0;
      HIDWORD(v28) = v22 + 2;
      *(_QWORD *)(a3 + 1) = v28;
      *a3 = v9;
      a3[3] = 0;
    }
    goto LABEL_24;
  }
  while ( 1 )
  {
    v8 = RtlConvertSidToUnicodeString((unsigned __int16 *)v31, *(_BYTE **)(v21 + 4), 0);
    if ( v8 < 0 )
      break;
    RtlAppendUnicodeToString((unsigned __int16 *)v30, (int)L"\r\n\t\t%{", v24, v25);
    RtlAppendUnicodeStringToString((unsigned __int16 *)v30, (unsigned __int16 *)v31);
    ++v23;
    v8 = RtlAppendUnicodeToString((unsigned __int16 *)v30, (int)L"}", v26, v27);
    v21 += 8;
    if ( v23 >= *a1 )
    {
      v22 = LOWORD(v30[0]);
      goto LABEL_19;
    }
  }
LABEL_25:
  if ( v10 )
  {
    ExFreePoolWithTag(v9);
    LOBYTE(v10) = 0;
  }
LABEL_27:
  result = v8;
  *v34 = v10;
  return result;
}
