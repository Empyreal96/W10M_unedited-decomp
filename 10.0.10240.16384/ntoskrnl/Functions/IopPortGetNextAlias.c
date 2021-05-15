// IopPortGetNextAlias 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopPortGetNextAlias(char a1, int a2, int a3, int a4, _QWORD *a5)
{
  bool v5; // cf
  unsigned int v6; // r1 OVERLAPPED
  int v7; // r2 OVERLAPPED
  int result; // r0

  if ( (a1 & 4) != 0 )
  {
    v5 = __CFADD__(a3, 1024);
    v6 = a3 + 1024;
  }
  else
  {
    if ( (a1 & 8) == 0 )
      return 0;
    v5 = __CFADD__(a3, 4096);
    v6 = a3 + 4096;
  }
  v7 = v5 + a4;
  if ( !v7 && v6 <= 0xFFFF )
  {
    result = 1;
    *a5 = *(_QWORD *)&v6;
    return result;
  }
  return 0;
}
