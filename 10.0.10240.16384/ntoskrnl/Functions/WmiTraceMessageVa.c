// WmiTraceMessageVa 
 
int __fastcall WmiTraceMessageVa(int a1, int a2, int a3, _DWORD *a4, __int16 a5, unsigned int *a6)
{
  return EtwpTraceMessageVa(a1, a2, a3, a4, a5, a6, 0);
}
