// PspSetProcessFreezeStateCallback 
 
int PspSetProcessFreezeStateCallback()
{
  __dmb(0xBu);
  return sub_7EB064();
}
