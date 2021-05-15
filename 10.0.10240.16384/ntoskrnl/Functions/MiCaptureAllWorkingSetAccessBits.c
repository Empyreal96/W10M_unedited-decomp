// MiCaptureAllWorkingSetAccessBits 
 
int __fastcall MiCaptureAllWorkingSetAccessBits(int a1, int a2)
{
  int v2; // r1

  if ( a2 == 1 )
    v2 = 16;
  else
    v2 = 8;
  return MiQueueWorkingSetRequest(MiSystemPartition, v2);
}
