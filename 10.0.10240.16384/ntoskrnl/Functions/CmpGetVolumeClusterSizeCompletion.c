// CmpGetVolumeClusterSizeCompletion 
 
int __fastcall CmpGetVolumeClusterSizeCompletion(int a1, int a2, int a3)
{
  KeSetEvent(a3, 0, 0);
  return -1073741802;
}
