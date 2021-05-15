// PopFxLogSocSubsystemBlockingTimes 
 
int __fastcall PopFxLogSocSubsystemBlockingTimes(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v7; // r5
  int v8; // r10
  int i; // r6
  int v10; // r0
  int v11; // r2
  int v13; // [sp+0h] [bp-B0h] BYREF
  int v14[2]; // [sp+8h] [bp-A8h] BYREF
  int v15[8]; // [sp+10h] [bp-A0h] BYREF
  int var80[33]; // [sp+30h] [bp-80h] BYREF
  int varg_r0[4]; // [sp+B8h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  v5 = 0;
  v6 = PopFxLookupSocSubsystemsByPlatformIdleState();
  v7 = v6;
  if ( !v6 )
    return -1073741584;
  v8 = 0;
  if ( *(_DWORD *)(v6 + 12) )
  {
    v5 = 0;
    for ( i = v6 + 16; ; i += 320 )
    {
      memset(v15, 0, sizeof(v15));
      v15[0] = a2;
      v15[1] = *(_DWORD *)(i + 24);
      v15[2] = i + 8;
      v15[4] = 0;
      v15[5] = 0;
      v15[6] = 0;
      v10 = PopPluginQuerySocSubsystemBlockingTime(PopFxProcessorPlugin, *(_DWORD *)(i + 20), v15);
      if ( !v10 )
        break;
      v14[0] = v15[4];
      v14[1] = v15[5];
      var80[0] = (int)varg_r0;
      var80[1] = 0;
      var80[2] = 1;
      var80[3] = 0;
      var80[4] = i + 44;
      var80[5] = 0;
      var80[6] = 16;
      var80[7] = 0;
      v13 = *(unsigned __int16 *)(i + 8) >> 1;
      var80[8] = (int)&v13;
      var80[9] = 0;
      var80[10] = 4;
      var80[11] = 0;
      v11 = *(unsigned __int16 *)(i + 8);
      var80[12] = *(_DWORD *)(i + 12);
      var80[13] = 0;
      var80[14] = v11;
      var80[15] = 0;
      var80[16] = i + 28;
      var80[17] = 0;
      var80[18] = 16;
      var80[19] = 0;
      var80[20] = (int)v14;
      var80[21] = 0;
      var80[22] = 8;
      var80[23] = 0;
      PopDiagTraceSleepStudyBlocker(v10, var80);
      if ( (unsigned int)++v8 >= *(_DWORD *)(v7 + 12) )
        return v5;
    }
    v5 = -1073741595;
  }
  return v5;
}
