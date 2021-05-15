// HvCountFreeLogsLockFree 
 
int __fastcall HvCountFreeLogsLockFree(int a1)
{
  int v2; // r1
  int result; // r0
  unsigned int i; // r2

  v2 = *(_DWORD *)(a1 + 96);
  result = 0;
  if ( v2 != 1 )
  {
    for ( i = 0; i < 2; ++i )
    {
      if ( i != v2 && !*(_BYTE *)(i + a1 + 120) )
        ++result;
    }
  }
  return result;
}
