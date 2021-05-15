// AdtpBuildStringListString 
 
int __fastcall AdtpBuildStringListString(int *a1, int a2, int *a3, int a4, int *a5, _BYTE *a6)
{
  unsigned int v7; // r5
  int v9; // r2
  int v10; // r6
  int v11; // r1
  unsigned int v13; // r8
  int v14; // r2
  unsigned int v15; // r1
  int v16; // r6
  int v17; // r0
  int v18; // r3
  int v19; // r1
  int v20; // r2
  unsigned int v21; // r9
  unsigned __int16 *v22; // r8
  int v23; // r3
  int v24; // [sp+0h] [bp-28h] BYREF
  int *v25; // [sp+4h] [bp-24h]
  int v26; // [sp+8h] [bp-20h]

  v24 = a2;
  v25 = a3;
  v26 = a4;
  v7 = 2;
  if ( a1 && (v9 = *a1) != 0 )
  {
    v10 = a1[1];
    do
    {
      v11 = *(unsigned __int16 *)(v10 + 4);
      v10 += 12;
      v7 += v11 + 8;
      --v9;
    }
    while ( v9 );
    if ( v7 > 0xFFFF )
      return -1073741811;
    v13 = v7 >> 1;
    v14 = *a5;
    v15 = *a5 + (v7 >> 1);
    if ( v15 >= 0x400 )
    {
      v16 = ExAllocatePoolWithTag(1, 2 * v13, 1799447891);
      if ( !v16 )
        return -1073741801;
      *a6 = 1;
    }
    else
    {
      *a5 = v15;
      v16 = a4 + 2 * v14;
      *a6 = 0;
    }
    HIWORD(v24) = 2 * v13;
    v17 = a1[1];
    v18 = *a1;
    v19 = 0;
    LOWORD(v24) = 0;
    v20 = v16;
    v25 = (int *)v16;
    v21 = 0;
    if ( v18 )
    {
      v22 = (unsigned __int16 *)(v17 + 4);
      do
      {
        RtlAppendUnicodeToString((unsigned __int16 *)&v24, (int)L"\r\n\t\t", v20, v18);
        RtlAppendUnicodeStringToString((unsigned __int16 *)&v24, v22);
        v18 = *a1;
        ++v21;
        v22 += 6;
      }
      while ( v21 < *a1 );
      v20 = (int)v25;
      v19 = (unsigned __int16)v24;
    }
    if ( a3 )
    {
      *a3 = v16;
      v23 = v19 + 2;
LABEL_21:
      a3[2] = v23;
      a3[3] = 0;
      a3[1] = 0;
      return 0;
    }
    MEMORY[0] = v24;
    MEMORY[4] = v20;
  }
  else if ( a3 )
  {
    *a3 = (int)dword_406F40;
    v23 = 4;
    goto LABEL_21;
  }
  return 0;
}
