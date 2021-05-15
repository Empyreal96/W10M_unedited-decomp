// KeRemoveSystemServiceTable 
 
int __fastcall KeRemoveSystemServiceTable(int a1)
{
  if ( a1 != 1 || !dword_682090 && !dword_682010 )
    return 0;
  dword_682010 = 0;
  dword_682018 = 0;
  *(_DWORD *)algn_68201C = 0;
  return 1;
}
