// PpmCheckInit 
 
void PpmCheckInit()
{
  PpmCheckCurrentPipelineId = 6;
  PpmCheckDpc = 19;
  word_61E062 = 0;
  dword_61E06C = (int)PpmCheckRun;
  dword_61E070 = 0;
  dword_61E07C = 0;
  dword_61E068 = 0;
  byte_61E061 = 3;
  PpmCheckStartDpc = 19;
  word_61E022 = 0;
  dword_61E02C = (int)PpmCheckPeriodicStart;
  dword_61E030 = 0;
  dword_61E03C = 0;
  dword_61E028 = 0;
  byte_61E021 = 3;
  PpmCheckIdleExpirationDpc = 19;
  word_61E082 = 0;
  dword_61E08C = (int)PpmIdleDurationExpiration;
  dword_61E090 = 0;
  dword_61E09C = 0;
  dword_61E088 = 0;
  byte_61E081 = 3;
}
