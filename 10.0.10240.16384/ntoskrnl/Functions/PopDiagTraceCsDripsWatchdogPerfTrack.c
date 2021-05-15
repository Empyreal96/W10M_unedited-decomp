// PopDiagTraceCsDripsWatchdogPerfTrack 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopDiagTraceCsDripsWatchdogPerfTrack(int result, int a2, int a3, int a4, unsigned int a5, char a6, unsigned __int8 a7)
{
  int v10; // r8
  __int64 v11; // kr00_8
  int v12; // r3
  unsigned int v13; // r1
  int v14; // r3
  char *v15; // r3
  _DWORD *v16; // r4
  int v17; // r5
  int v18; // r2 OVERLAPPED
  int v19; // r1 OVERLAPPED
  _DWORD v20[4]; // [sp+8h] [bp-70h] BYREF
  char v21; // [sp+18h] [bp-60h] BYREF

  v10 = result;
  if ( PopDiagHandleRegistered )
  {
    v11 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CS_DRIPS_WATCHDOG_PERFTRACK);
    if ( result )
    {
      v20[0] = v10;
      v20[1] = a2;
      v20[2] = a3;
      if ( a6 )
        v12 = (a4 != 0) | 0x200;
      else
        v12 = a4 != 0;
      v13 = (v12 & 0xFFFFFE01 | (2 * a7)) & 0xFFFF03FF;
      v14 = a5;
      if ( a5 > 0xFFFF )
        v14 = 0xFFFF;
      v20[3] = v13 | (v14 << 16);
      v15 = &v21;
      v16 = v20;
      v17 = 4;
      v18 = 0;
      v19 = 4;
      do
      {
        *(_DWORD *)v15 = v16;
        *((_DWORD *)v15 + 1) = 0;
        *((_QWORD *)v15 + 1) = *(_QWORD *)&v19;
        v15 += 16;
        ++v16;
        --v17;
      }
      while ( v17 );
      result = EtwWrite(v11, SHIDWORD(v11), (int)POP_ETW_EVENT_CS_DRIPS_WATCHDOG_PERFTRACK, 0);
    }
  }
  return result;
}
