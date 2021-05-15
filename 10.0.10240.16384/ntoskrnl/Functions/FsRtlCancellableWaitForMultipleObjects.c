// FsRtlCancellableWaitForMultipleObjects 
 
int __fastcall FsRtlCancellableWaitForMultipleObjects(unsigned int a1, unsigned int *a2, int a3, unsigned int *a4, int *a5, int a6)
{
  unsigned int v7; // r6
  int v8; // r5
  int v9; // lr
  __int64 v11; // r0
  __int64 v12; // kr18_8
  int *v13; // r3
  int result; // r0
  __int64 v15; // kr20_8
  unsigned int *v16; // [sp+10h] [bp-30h]
  __int64 v18[5]; // [sp+18h] [bp-28h] BYREF

  v7 = 0;
  v8 = 0;
  v9 = a3;
  v16 = a2;
  if ( a4 )
  {
    v8 = a4[1];
    v7 = *a4;
    if ( v8 < 0 )
    {
      KeQueryTickCount((int *)v18);
      v11 = (unsigned int)KeQueryTimeIncrement();
      if ( !(_DWORD)v11 )
        __brkdiv0();
      v9 = a3;
      v12 = v18[0] - (unsigned int)_rt_sdiv64(v11, *(_QWORD *)a4);
      v8 = HIDWORD(v12);
      v7 = v12;
      a2 = v16;
    }
  }
LABEL_6:
  v13 = a5;
  while ( 1 )
  {
    if ( a1 == 1 )
      result = KeWaitForSingleObject(*a2, 0, 0, (_DWORD *)1, (int *)a4);
    else
      result = KeWaitForMultipleObjects(a1, a2, v9, 0, 0, 1u, (int *)a4, v13);
    if ( result != 257 )
      return result;
    if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) != 0 )
      return -1073741749;
    if ( a6 && *(_BYTE *)(a6 + 36) )
      return -1073741536;
    a2 = v16;
    v9 = a3;
    v13 = a5;
    if ( a4 )
    {
      if ( (a4[1] & 0x80000000) != 0 )
      {
        KeQueryTickCount((int *)v18);
        v15 = v18[0];
        if ( v18[0] < __SPAIR64__(v8, v7) )
        {
          *(_QWORD *)a4 = -(__int64)((__PAIR64__(v8, v7) - v15) * (unsigned int)KeQueryTimeIncrement());
LABEL_21:
          a2 = v16;
          v9 = a3;
          goto LABEL_6;
        }
        return 258;
      }
      KeQuerySystemTime(v18);
      if ( SHIDWORD(v18[0]) > v8 )
        return 258;
      a2 = v16;
      v9 = a3;
      v13 = a5;
      if ( SHIDWORD(v18[0]) >= v8 )
      {
        if ( LODWORD(v18[0]) < v7 )
          goto LABEL_21;
        return 258;
      }
    }
  }
}
