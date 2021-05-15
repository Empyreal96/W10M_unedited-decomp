// CmPostCallbackNotification 
 
int __fastcall CmPostCallbackNotification(int a1, int a2, int a3)
{
  int result; // r0

  if ( CmpCallBackCount )
    result = sub_8047F8();
  else
    result = a3;
  return result;
}
