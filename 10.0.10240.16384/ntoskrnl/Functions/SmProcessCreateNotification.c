// SmProcessCreateNotification 
 
int __fastcall SmProcessCreateNotification(int a1, int a2)
{
  if ( (dword_636CC0 & 0xC) == 0 )
    return -1073741637;
  if ( a2 )
    return sub_7F6534();
  return -1073700352;
}
