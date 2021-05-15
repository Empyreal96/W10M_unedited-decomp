// ExQueryBootEntropyInformation 
 
int __fastcall ExQueryBootEntropyInformation(int a1, int a2)
{
  int result; // r0
  int v3[2]; // [sp+8h] [bp-8h] BYREF

  v3[0] = a1;
  v3[1] = a2;
  result = RtlRunOnceExecuteOnce(
             (int)&ExpBootEntropyInit,
             (int (__fastcall *)(int, int, int *))ExpInitBootEntropyInformation,
             (int)v3,
             0);
  if ( result >= 0 && v3[0] != -1 )
    result = -1073741823;
  return result;
}
