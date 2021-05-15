// MmFreePagesFromMdl 
 
int __fastcall MmFreePagesFromMdl(int a1, int a2, int a3, int a4)
{
  return MiFreePagesFromMdl(MiSystemPartition, a1, 0, a4);
}
