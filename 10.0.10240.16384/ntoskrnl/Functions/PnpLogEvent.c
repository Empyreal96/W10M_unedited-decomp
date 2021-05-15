// PnpLogEvent 
 
int __fastcall PnpLogEvent(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5)
{
  int v7; // r1
  int result; // r0
  unsigned int v11; // r5
  unsigned int v12; // r3
  int v13; // r4
  int v14; // r5
  _WORD *v15; // r5

  v7 = 0;
  result = 0;
  if ( a1 )
    result = *a1 + 2;
  if ( a2 )
    v7 = *a2 + 2;
  v11 = (a5 + 41) & 0xFFFFFFFE;
  v12 = v11 + v7 + result;
  if ( v12 <= 0x98 )
  {
    result = IoAllocateGenericErrorLogEntry((unsigned __int8)v12);
    v13 = result;
    if ( result )
    {
      *(_WORD *)(result + 6) = v11;
      v14 = v11 + result;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 20) = a3;
      *(_WORD *)(result + 2) = a5;
      if ( a5 )
        memmove(result + 40, a4, a5);
      if ( a1 )
      {
        *(_WORD *)(v13 + 4) = 1;
        memmove(v14, *((_DWORD *)a1 + 1), *a1);
        v15 = (_WORD *)(v14 + *a1);
        *v15 = 0;
        v14 = (int)(v15 + 1);
      }
      if ( a2 )
      {
        ++*(_WORD *)(v13 + 4);
        memmove(v14, *((_DWORD *)a2 + 1), *a2);
        *(_WORD *)(*a2 + v14) = 0;
      }
      result = IoWriteErrorLogEntry(v13);
    }
  }
  return result;
}
