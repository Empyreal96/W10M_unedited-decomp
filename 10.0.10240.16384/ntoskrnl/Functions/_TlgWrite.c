// _TlgWrite 
 
int __fastcall TlgWrite(_DWORD *a1, unsigned __int8 *a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r2
  unsigned __int16 *v9; // r1
  int v10; // r2
  int v12[8]; // [sp+10h] [bp-20h] BYREF

  v12[0] = (a2 - (unsigned __int8 *)TraceLoggingMetadata) | (*a2 << 24);
  v12[1] = *(unsigned __int16 *)(a2 + 1);
  v12[2] = *(_DWORD *)(a2 + 3);
  v8 = *(_DWORD *)(a2 + 7);
  v9 = (unsigned __int16 *)(a2 + 11);
  v12[3] = v8;
  *a6 = a1[1];
  a6[1] = 0;
  v10 = *(unsigned __int16 *)a1[1];
  a6[4] = v9;
  a6[5] = 0;
  a6[2] = v10;
  a6[3] = 2;
  a6[6] = *v9;
  a6[7] = 1;
  return ((int (__fastcall *)(_DWORD, _DWORD, int *, int, int, int, _DWORD *))EtwWriteTransfer)(
           a1[6],
           a1[7],
           v12,
           a3,
           a4,
           a5,
           a6);
}
