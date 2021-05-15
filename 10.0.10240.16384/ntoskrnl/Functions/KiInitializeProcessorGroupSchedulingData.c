// KiInitializeProcessorGroupSchedulingData 
 
int __fastcall KiInitializeProcessorGroupSchedulingData(int result)
{
  *(_DWORD *)(result + 1984) = result + 1984;
  *(_DWORD *)(result + 1988) = result + 1984;
  *(_DWORD *)(result + 2352) = 248 * *(_DWORD *)(result + 20) + 128;
  *(_QWORD *)(result + 2408) = KiGenerationEndTick;
  return result;
}
