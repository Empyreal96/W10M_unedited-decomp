// KiForegroundTimerCallback 
 
int KiForegroundTimerCallback()
{
  return KiInsertQueueDpc((int)&unk_624EB8, 0, 0, 0, 0);
}
