// BcpDisplayProgress 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BcpDisplayProgress(unsigned int a1, int a2)
{
  int *v3; // r7
  unsigned __int16 *v5; // r0
  int v6; // r2
  int v7; // r2
  unsigned __int16 *v8; // r0
  unsigned int v9; // r5 OVERLAPPED
  int v10; // r6 OVERLAPPED
  int v11; // r2
  int v12; // r3
  int v13; // r9
  unsigned int v14; // r8
  unsigned int v15; // r7
  int v17; // [sp+10h] [bp-60h]
  int v18[2]; // [sp+18h] [bp-58h] BYREF
  int v19; // [sp+20h] [bp-50h] BYREF
  __int64 v20; // [sp+28h] [bp-48h] BYREF
  __int64 v21; // [sp+38h] [bp-38h] BYREF
  int v22; // [sp+40h] [bp-30h]
  char v23; // [sp+48h] [bp-28h] BYREF

  v3 = &dword_616150[14 * a2];
  if ( a1 == 1 )
    v5 = (unsigned __int16 *)&unk_641640;
  else
    v5 = (unsigned __int16 *)&unk_641650;
  BcpDisplayCriticalString(v5, v3[1], 7 * a2, a2);
  v18[0] = 0x80000;
  v18[1] = (int)&v23;
  BcpConvertProgressToString(a1, (int)v18);
  BcpDisplayCriticalString((unsigned __int16 *)v18, v3[1], v6, a2);
  if ( a1 == 1 )
    v8 = (unsigned __int16 *)&unk_641648;
  else
    v8 = (unsigned __int16 *)&unk_641658;
  BcpDisplayCriticalString(v8, v3[1], v7, a2);
  *(_QWORD *)&v9 = *(_QWORD *)&BcpCursor;
  v21 = *(_QWORD *)&BcpCursor;
  v22 = dword_653574;
  if ( BcpCursorLessThan(&v21) )
  {
    v11 = v3[7];
    v12 = *(_DWORD *)(dword_641660 + 20);
    LODWORD(v20) = v9;
    v13 = *(_DWORD *)(v12 + 28);
    v14 = v11 + v3[3];
    v15 = v3[5] + v14;
LABEL_9:
    HIDWORD(v20) = v10;
    while ( BcpCursorLessThan(&v20) )
    {
      if ( BgpDisplayCharacterEx(
             32,
             (int *)dword_641660,
             v9,
             v10,
             v13,
             v13,
             (int)&v19,
             (int)v18,
             v17,
             (int)BcpWorkspace) < 0 )
        return 0;
      v9 += v19;
      LODWORD(v20) = v9;
      if ( v9 > v15 )
      {
        v9 = v14;
        LODWORD(v20) = v14;
        v10 += v18[0];
        goto LABEL_9;
      }
    }
  }
  if ( (dword_619018 & 0x1000000) == 0 )
  {
    ProgressEnd = v21;
    *(_DWORD *)algn_618F38 = v22;
  }
  return 0;
}
