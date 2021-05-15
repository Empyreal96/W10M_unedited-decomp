// SmKmStoreHelperSendCommand 
 
int __fastcall SmKmStoreHelperSendCommand(int a1, __int16 a2, int a3, int a4)
{
  int result; // r0

  result = SmKmStoreHelperCheckWaitCommand(a1, a4);
  if ( result != -1073741650 )
  {
    *(_WORD *)(a1 + 38) = a2;
    if ( a3 )
    {
      result = sub_511280();
    }
    else
    {
      KeSetEvent(a1 + 4, 0, 0);
      result = 0;
    }
  }
  return result;
}
