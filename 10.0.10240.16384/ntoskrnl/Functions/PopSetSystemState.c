// PopSetSystemState 
 
int __fastcall PopSetSystemState(int result, int a2)
{
  char v3; // r4

  v3 = result;
  if ( (result & 0xFFFFFFF8) == 0 )
  {
    result = PopDiagTraceSetSystemState();
    if ( (v3 & 1) != 0 )
    {
      result = sub_5296CC(result);
    }
    else if ( (v3 & 4) != 0 )
    {
      result = PopUserPresentSet(a2);
    }
  }
  return result;
}
