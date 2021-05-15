// MiPfPrepareSequentialReadList 
 
int __fastcall MiPfPrepareSequentialReadList(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  int result; // r0

  *a9 = 0;
  if ( (*(_DWORD *)(a2 + 28) & 0x400) != 0 )
    result = -1073741585;
  else
    result = sub_8066E4();
  return result;
}
