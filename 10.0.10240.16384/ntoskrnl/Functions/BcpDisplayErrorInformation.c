// BcpDisplayErrorInformation 
 
int __fastcall BcpDisplayErrorInformation(int a1, int a2, int a3, int a4, int a5, char a6)
{
  int *v6; // r8
  int v7; // r5
  int v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r1
  unsigned int *v13; // r10
  int v14; // r2
  int v15; // r4
  int v16; // r2
  int v17; // r6
  unsigned __int16 *v18; // r4
  int v19; // r5
  unsigned int v20; // t1
  char *v21; // r2
  __int64 v22; // r2
  int v24[2]; // [sp+0h] [bp-D8h] BYREF
  int v25; // [sp+8h] [bp-D0h]
  char *v26; // [sp+Ch] [bp-CCh]
  int v27; // [sp+10h] [bp-C8h]
  int v28; // [sp+18h] [bp-C0h]
  int v29; // [sp+1Ch] [bp-BCh]
  int v30[3]; // [sp+20h] [bp-B8h] BYREF
  __int64 v31; // [sp+2Ch] [bp-ACh] BYREF
  char v32; // [sp+38h] [bp-A0h] BYREF

  v6 = &dword_616150[14 * a1];
  v7 = v6[10];
  v24[0] = a4;
  v8 = v7 + dword_653574;
  v9 = v6[7];
  v10 = v6[3];
  v26 = (char *)a2;
  v27 = a1;
  v11 = *v6;
  BcpCursor = v10 + v9;
  dword_653570 = v8;
  v25 = a5;
  v13 = (unsigned int *)a3;
  BcpDisplayCriticalString(word_641618, v11, a3, a1);
  BcpDisplayCriticalCharacter(32, *v6);
  BcpDisplayCriticalString((unsigned __int16 *)(a5 + 8), *v6, v14, a1);
  v15 = v24[0];
  if ( v24[0] )
  {
    BcpDisplayCriticalCharacter(32, *v6);
    BcpDisplayCriticalCharacter(40, *v6);
    v24[1] = (int)&v32;
    v24[0] = 0x800000;
    BcpSanitizeDriverName(v15, v24);
    BcpDisplayCriticalString((unsigned __int16 *)v24, *v6, v16, a1);
    BcpDisplayCriticalCharacter(41, *v6);
  }
  v31 = *(_QWORD *)&dword_653570;
  v28 = 0;
  v29 = 0;
  v30[0] = 0;
  v25 = BcpCursor;
  v30[2] = BcpCursor;
  v24[0] = dword_653570;
  BcpSetCursorPosition(0, 0, v30);
  v17 = v27;
  v18 = (unsigned __int16 *)(a5 + 16);
  v19 = 4;
  do
  {
    v20 = *v13++;
    BcpConvertBugDataToString(v20, (int)v18);
    v21 = &BcpDisplayParameters;
    if ( BcpDisplayParameters || (a6 & 8) != 0 && (v21 = v26, v26 == (char *)317) )
    {
      BcpDisplayCriticalString(v18, *v6, (int)v21, v17);
      HIDWORD(v22) = dword_653574;
      LODWORD(v22) = 0;
      *(_QWORD *)&BcpCursor = v22;
    }
    v18 += 4;
    --v19;
  }
  while ( v19 );
  return BcpSetCursorPosition(v25, v24[0], (char *)&v31 + 4);
}
