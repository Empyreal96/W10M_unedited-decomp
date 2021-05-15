// ViGenericSetVolumeInformation 
 
int __fastcall ViGenericSetVolumeInformation(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_SET_VOLUME_INFORMATION, 11);
}
