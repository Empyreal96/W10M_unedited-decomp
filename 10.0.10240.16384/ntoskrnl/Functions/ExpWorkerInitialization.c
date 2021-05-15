// ExpWorkerInitialization 
 
int ExpWorkerInitialization()
{
  ExpWorkerSwapinMutex = 1;
  dword_619F84 = 0;
  unk_619F88 = 0;
  byte_619F8C = 1;
  byte_619F8D = 0;
  byte_619F8E = 4;
  dword_619F90 = 0;
  dword_619F98 = (int)&dword_619F94;
  dword_619F94 = (int)&dword_619F94;
  ExpWorkersCanSwap = 1;
  if ( ExpMaximumKernelWorkerThreads <= 0x4000 )
    JUMPOUT(0x96C206);
  return sub_96C200();
}
