// CcMdlReadComplete2 
 
int __fastcall CcMdlReadComplete2(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r4
  int result; // r0

  v2 = a2;
  if ( a2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      MmUnlockPages((int)v2);
      result = IoFreeMdl((int)v2);
      v2 = v3;
    }
    while ( v3 );
  }
  return result;
}
