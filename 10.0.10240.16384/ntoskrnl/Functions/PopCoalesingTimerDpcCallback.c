// PopCoalesingTimerDpcCallback 
 
void PopCoalesingTimerDpcCallback()
{
  PopGetPolicyWorker(32);
  PopCheckForWork();
}
