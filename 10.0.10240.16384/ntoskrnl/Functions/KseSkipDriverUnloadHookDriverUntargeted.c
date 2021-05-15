// KseSkipDriverUnloadHookDriverUntargeted 
 
int __fastcall KseSkipDriverUnloadHookDriverUntargeted(int a1)
{
  KsepSkipDriverUnloadEventDriverUnload(0, a1);
  return 0;
}
