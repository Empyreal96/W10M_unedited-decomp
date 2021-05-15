// IoInitializeDumpStack 
 
int __fastcall IoInitializeDumpStack(int a1)
{
  int result; // r0

  result = -1073741823;
  if ( CrashdmpImageEntry )
  {
    if ( dword_637654 )
      result = dword_637654(a1, 0);
  }
  return result;
}
