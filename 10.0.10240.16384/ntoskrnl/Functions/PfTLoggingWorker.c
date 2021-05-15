// PfTLoggingWorker 
 
int __fastcall PfTLoggingWorker(int a1)
{
  int v2; // r1
  int v3; // r0
  int v4; // r5
  int v5; // r9
  int v6; // r4
  __int64 v7; // r0
  unsigned __int64 v8; // r4
  int v9; // r2
  int v10; // r3
  __int64 v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r5
  unsigned __int64 v14; // r2
  bool v15; // cc
  __int64 v16; // r0
  int v17; // r4
  int v18; // r2
  int v19; // r3
  int v20; // r0
  unsigned __int64 v21; // r4
  int v22; // r2
  int v23; // r3
  unsigned int v25[2]; // [sp+10h] [bp-A8h] BYREF
  int v26; // [sp+18h] [bp-A0h]
  int v27; // [sp+1Ch] [bp-9Ch]
  int v28[2]; // [sp+20h] [bp-98h] BYREF
  unsigned int v29[4]; // [sp+28h] [bp-90h] BYREF
  int v30[32]; // [sp+38h] [bp-80h] BYREF

  v25[0] = -300000;
  v25[1] = -1;
  v26 = a1;
  v28[0] = 1294967296;
  v28[1] = -1;
  KeSetBasePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, -1);
  v29[0] = a1 + 64;
  v29[1] = a1 + 20;
  v29[2] = a1 + 4;
  v29[3] = (unsigned int)algn_643B4C;
  do
  {
    v2 = MEMORY[0xFFFF93B0];
    v27 = MEMORY[0xFFFF93B4];
    while ( 1 )
    {
      v3 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v4 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v3 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v2 != MEMORY[0xFFFF93B0] || v27 != MEMORY[0xFFFF93B4] );
  LODWORD(qword_643978) = v4 - v2;
  v5 = v26;
  HIDWORD(qword_643978) = v4 - v2;
  while ( 1 )
  {
    do
    {
      v6 = KeWaitForMultipleObjects(4u, v29, 1, 0, 0, 0, v28, v30);
      if ( v6 == 258 )
        v6 = 3;
    }
    while ( v6 >= 4 );
    LODWORD(v7) = KeResetEvent(v29[v6]);
    if ( !v6 )
      return v7;
    if ( dword_643A6C < (unsigned int)dword_643A70 )
    {
      switch ( v6 )
      {
        case 1:
          LODWORD(v21) = 0;
          do
          {
            LODWORD(v7) = PfpFlushBuffers(v7);
            HIDWORD(v21) = v7;
            if ( (!(_DWORD)v7 || (v23 = *(_DWORD *)(v5 + 52)) != 0)
              && (LODWORD(v7) = PfTGenerateTrace(v7, SHIDWORD(v7), v22, v23), (_DWORD)v7 == -1073741670) )
            {
              LODWORD(v7) = KeDelayExecutionThread(0, 0, v25);
              LODWORD(v21) = v21 + 1000;
            }
            else
            {
              LODWORD(v21) = v21 + 1;
            }
          }
          while ( v21 < 0x2710 );
LABEL_43:
          KeSetEvent(v5 + 36, 0, 0);
          break;
        case 2:
          v16 = PfpFlushBuffers(v7);
          v17 = v16;
          v20 = PfTGenerateTrace(v16, SHIDWORD(v16), v18, v19);
          if ( !v17 )
          {
            if ( v20 == -1073741670 )
              v20 = KeDelayExecutionThread(0, 0, v25);
            PfpFlushBuffers(v20);
          }
          break;
        case 3:
          LODWORD(v8) = 0;
          while ( 1 )
          {
            v7 = PfpFlushBuffers(v7);
            HIDWORD(v8) = v7;
            if ( !(_DWORD)v7 )
            {
              LODWORD(v7) = PfTGenerateTrace(0, SHIDWORD(v7), v9, v10);
              if ( (_DWORD)v7 == -1073741670 )
                break;
            }
            LODWORD(v8) = v8 + 1;
            if ( v8 >= 0x3E8 )
              goto LABEL_24;
          }
          KeDelayExecutionThread(0, 0, v25);
          do
          {
LABEL_24:
            v11 = MEMORY[0xFFFF93B0];
            while ( 1 )
            {
              v12 = MEMORY[0xFFFF900C];
              __dmb(0xBu);
              v13 = MEMORY[0xFFFF9008];
              __dmb(0xBu);
              if ( v12 == MEMORY[0xFFFF9010] )
                break;
              __dmb(0xAu);
              __yield();
            }
          }
          while ( v11 != MEMORY[0xFFFF93B0] );
          v14 = __PAIR64__(v12, v13) - qword_643978 - v11;
          if ( HIDWORD(v14) || (v15 = (unsigned int)v14 > 0xB2D05E00, v14 = 0xB2D05E0000000000ui64, v15) )
            PfTGenerateTrace(v11, SHIDWORD(v11), v14, SHIDWORD(v14));
          break;
      }
    }
    else if ( v6 == 1 )
    {
      goto LABEL_43;
    }
  }
}
