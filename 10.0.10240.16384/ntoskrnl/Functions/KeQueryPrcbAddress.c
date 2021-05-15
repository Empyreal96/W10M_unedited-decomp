// KeQueryPrcbAddress 
 
int __fastcall KeQueryPrcbAddress(int a1)
{
  return (int)*(&KiProcessorBlock + a1);
}
