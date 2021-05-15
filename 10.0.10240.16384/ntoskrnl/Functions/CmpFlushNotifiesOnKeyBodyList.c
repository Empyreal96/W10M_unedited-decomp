// CmpFlushNotifiesOnKeyBodyList 
 
void __fastcall CmpFlushNotifiesOnKeyBodyList(int a1)
{
  if ( *(_DWORD *)(a1 + 64) != a1 + 64 )
    JUMPOUT(0x7D25A8);
  JUMPOUT(0x7D25AC);
}
