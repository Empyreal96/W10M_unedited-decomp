// PpmIdlePsciExecute 
 
int __fastcall PpmIdlePsciExecute(int a1, int a2)
{
  if ( a2 )
    off_617A9C(17);
  HalProcessorIdle();
  return 0;
}
