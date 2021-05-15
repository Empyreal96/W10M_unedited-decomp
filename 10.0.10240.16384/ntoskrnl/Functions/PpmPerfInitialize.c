// PpmPerfInitialize 
 
int PpmPerfInitialize()
{
  unsigned int v0; // r2
  int result; // r0
  char *v2; // r3

  v0 = 0;
  PpmPerfDomainHead = (int)&PpmPerfDomainHead;
  dword_68252C = (int)&PpmPerfDomainHead;
  dword_61DBD4 = 50;
  dword_61DC84 = 50;
  result = 100;
  do
  {
    v2 = (char *)&PpmDefaultProfile + v0++;
    v2[56] = 1;
    v2[232] = 1;
    v2[72] = 70;
    v2[248] = 70;
    v2[70] = 30;
    v2[246] = 30;
    v2[58] = 100;
    v2[234] = 100;
    v2[60] = 100;
    v2[236] = 100;
  }
  while ( v0 < 2 );
  dword_61DBEC = 100;
  dword_61DC9C = 100;
  dword_61DBF0 = 2;
  dword_61DCA0 = 2;
  PpmMediaBufferingWork = 0;
  dword_61F490 = (int)PpmMediaBufferingWorker;
  dword_61F494 = 0;
  dword_61F488 = 0;
  dword_61F468 = (int)PpmPerfLatencySensitivityHintWorker;
  dword_61F46C = 0;
  PpmPerfLatencyBoostWorkItem = 0;
  return result;
}
