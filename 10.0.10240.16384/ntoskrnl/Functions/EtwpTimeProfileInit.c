// EtwpTimeProfileInit 
 
int EtwpTimeProfileInit()
{
  KeSetIntervalProfile((int *)EtwpProfileInterval, 0);
  KeInitializeProfileCallback((int)&EtwpProfileObject, (unsigned int)EtwpProfileInterrupt, 0, 0);
  return KeStartProfile((int)&EtwpProfileObject);
}
