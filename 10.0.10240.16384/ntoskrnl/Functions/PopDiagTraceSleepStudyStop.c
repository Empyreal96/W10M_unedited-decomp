// PopDiagTraceSleepStudyStop 
 
void PopDiagTraceSleepStudyStop()
{
  __int64 v0; // kr00_8
  int v1; // [sp+8h] [bp-110h] BYREF
  int v2; // [sp+Ch] [bp-10Ch] BYREF
  int v3[66]; // [sp+10h] [bp-108h] BYREF

  if ( PopDiagHandleRegistered )
  {
    v0 = *(_QWORD *)&PopDiagHandle;
    if ( EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SPM_SCENARIO_STOP) )
    {
      v3[2] = (int)&PopWdiScenarioStopEventData;
      v3[0] = byte_61E1BC & 1;
      v2 = byte_61E1BD & 1;
      v1 = ((unsigned __int8)byte_61E1BD >> 1) & 1;
      v3[3] = 0;
      v3[4] = 4;
      v3[5] = 0;
      v3[6] = (int)&unk_61E178;
      v3[7] = 0;
      v3[8] = 8;
      v3[9] = 0;
      v3[10] = (int)v3;
      v3[11] = 0;
      v3[12] = 4;
      v3[13] = 0;
      v3[14] = (int)&unk_61E1C0;
      v3[15] = 0;
      v3[16] = 8;
      v3[17] = 0;
      v3[18] = (int)&unk_61E1C8;
      v3[19] = 0;
      v3[20] = 8;
      v3[21] = 0;
      v3[22] = (int)&unk_61E1D0;
      v3[23] = 0;
      v3[24] = 8;
      v3[25] = 0;
      v3[26] = (int)&unk_61E170;
      v3[27] = 0;
      v3[28] = 8;
      v3[29] = 0;
      v3[30] = (int)&unk_61E168;
      v3[31] = 0;
      v3[32] = 4;
      v3[33] = 0;
      v3[34] = (int)&unk_61E1A8;
      v3[35] = 0;
      v3[36] = 8;
      v3[37] = 0;
      v3[38] = (int)&unk_61E1E0;
      v3[39] = 0;
      v3[40] = 1;
      v3[41] = 0;
      v3[42] = (int)&unk_61E164;
      v3[43] = 0;
      v3[44] = 4;
      v3[45] = 0;
      v3[46] = (int)&unk_61E1A0;
      v3[47] = 0;
      v3[48] = 8;
      v3[49] = 0;
      v3[50] = (int)&unk_61E1B8;
      v3[51] = 0;
      v3[52] = 4;
      v3[53] = 0;
      v3[54] = (int)&v1;
      v3[55] = 0;
      v3[56] = 4;
      v3[57] = 0;
      v3[58] = (int)&v2;
      v3[59] = 0;
      v3[60] = 4;
      v3[61] = 0;
      EtwWrite(v0, SHIDWORD(v0), (int)POP_ETW_EVENT_SPM_SCENARIO_STOP, (int)&PopDiagActivityId);
    }
  }
}
