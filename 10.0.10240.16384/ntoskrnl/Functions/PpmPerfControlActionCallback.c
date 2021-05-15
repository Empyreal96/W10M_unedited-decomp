// PpmPerfControlActionCallback 
 
int PpmPerfControlActionCallback()
{
  return KiInsertQueueDpc((int)&PpmCheckDpc, 0, 0, 0, 0);
}
