// WmiTraceMessage 
 
int WmiTraceMessage(int a1, int a2, int a3, _DWORD *a4, __int16 a5, ...)
{
  va_list va; // [sp+34h] [bp+1Ch] BYREF

  va_start(va, a5);
  return EtwpTraceMessageVa(a1, a2, a3, a4, a5, (unsigned int *)va, 0);
}
