// PfTAcquireLogEntry 
 
int __fastcall PfTAcquireLogEntry(int a1, int *a2, int a3)
{
  int result; // r0
  int v7; // r3
  int v8; // r3

  do
  {
    result = *(_DWORD *)(a1 + 16);
    if ( (unsigned int)(*(_DWORD *)(result + 8) + a3) <= *(_DWORD *)(result + 12) )
    {
      v7 = *(_DWORD *)(result + 8) + a3;
      *(_DWORD *)(result + 8) = v7;
      v8 = v7 - a3;
      goto LABEL_5;
    }
  }
  while ( PfTReplaceCurrentBuffer(a1) != -1073741823 );
  result = 0;
  v8 = 0xFFFF;
LABEL_5:
  *a2 = v8;
  return result;
}
