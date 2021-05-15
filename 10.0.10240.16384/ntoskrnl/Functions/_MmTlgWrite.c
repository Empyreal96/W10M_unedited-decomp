// _MmTlgWrite 
 
int __fastcall MmTlgWrite(_DWORD *a1, unsigned __int8 *a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r3
  int v8[6]; // [sp+20h] [bp-18h] BYREF

  v8[0] = (a2 - (unsigned __int8 *)TraceLoggingMetadata) | (*a2 << 24);
  v8[1] = *(unsigned __int16 *)(a2 + 1);
  v8[2] = *(_DWORD *)(a2 + 3);
  v8[3] = *(_DWORD *)(a2 + 7);
  *a6 = a1[1];
  a6[1] = 0;
  v6 = *(unsigned __int16 *)a1[1];
  a6[4] = a2 + 11;
  a6[5] = 0;
  a6[2] = v6;
  a6[3] = 2;
  a6[6] = *(unsigned __int16 *)(a2 + 11);
  a6[7] = 1;
  return EtwWriteEx(a1[6], a1[7], (int)v8, a5, 0, 0, 1, 0, 0, a5, (int)a6);
}
