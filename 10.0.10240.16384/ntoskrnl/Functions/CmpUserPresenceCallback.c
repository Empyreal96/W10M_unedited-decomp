// CmpUserPresenceCallback 
 
int __fastcall CmpUserPresenceCallback(int a1, _DWORD *a2)
{
  CmpUserPresent = *a2 != 2;
  return 0;
}
